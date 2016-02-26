/******************************************************************************
 * File: Trailblazer.cpp
 *
 * Implementation of the graph algorithms that comprise the Trailblazer
 * assignment.
 */

#include "Trailblazer.h"
#include "TrailblazerGraphics.h"
#include "TrailblazerTypes.h"
#include "TrailblazerPQueue.h"
#include "queue.h"
#include <math.h>
#include "random.h"
using namespace std;

/* Function: shortestPath
 * 
 * Finds the shortest path between the locations given by start and end in the
 * specified world.	 The cost of moving from one edge to the next is specified
 * by the given cost function.	The resulting path is then returned as a
 * Vector<Loc> containing the locations to visit in the order in which they
 * would be visited.	If no path is found, this function should report an
 * error.
 *
 * In Part Two of this assignment, you will need to add an additional parameter
 * to this function that represents the heuristic to use while performing the
 * search.  Make sure to update both this implementation prototype and the
 * function prototype in Trailblazer.h.
 */
Vector<Loc> shortestPath(Loc start,
             Loc end,
             Grid<double>& world,
             double costFn(Loc from, Loc to, Grid<double>& world), double heuristic (Loc start, Loc end, Grid<double>& world)) {

	//Vector to store final path
    Vector<Loc> path;
    //priority queue to store unvisited location nodes
    TrailblazerPQueue<LocNode*> pq;
    //Set to store vistied locations; Map to store seen locations.
    Set<Loc> visitedLocs;
    Map<Loc, LocNode*> seenLocs;
    //Vector for deleting nodes
    Vector<LocNode*> nodes;
    
    //LocNode* setup - set a front to NULL and have the startNode point to it since the first Node will need
    //to have it's previous be NULL.
    LocNode* front = NULL;
    LocNode* startNode = new LocNode(start, 0);
    nodes.add(startNode);
    startNode->prev = front;
    
    //Set all locations to be grey to start.
    for (int i = 0; i < world.numCols(); i++) {
        for (int j = 0; j < world.numRows(); j++) {
            Loc loc;
            loc.col = i;
            loc.row = j;
            colorCell(world, loc, GRAY);
        }
    }
    
    //Color the start location to be Yellow and add it to the priority queue with a priority of zero.
    colorCell(world, start, YELLOW);
    pq.enqueue(startNode, startNode->cost+heuristic(start, end, world));
    seenLocs.put(start, startNode);
    
    while (!pq.isEmpty()) {
        LocNode* curNode = pq.dequeueMin();
        colorCell(world, curNode->loc, GREEN);
        visitedLocs.add(curNode->loc);
        
        //If you have reached the end - follow the pointers back to the start, adding them to a stack as you go. Then pop the stack back into the path Vector so that they are
        //returned in the proper order - start to finish.
        if (curNode->loc == end) {
            Stack<Loc> backPath;
            backPath.push(curNode->loc);
            while (curNode->prev != NULL) {
                curNode = curNode->prev;
                backPath.push(curNode->loc);
            }
            while(!backPath.isEmpty()) {
                path.add(backPath.pop());
            }
            for (int i = 0; i < nodes.size(); i++) {
                LocNode* node = nodes[i];
                delete node;
            }
            return path;
        }
        //If you have not reached the end - look at all of the neighbors of curNode. Check to see if that neighbor has been visited yet. IF it has not, create a new NeighborNode
        //that has a cost of the curNode plus it's edgeCost. Set it's previous pointer to curNode.
        else {
            for (int dx=-1; dx<=1; dx++){
                for (int dy=-1; dy<=1; dy++) {
                    if (dx!=0 || dy!=0) {
                        Loc neighbor;
                        neighbor.col = curNode->loc.col+dx;
                        neighbor.row = curNode->loc.row+dy;
                        if (world.inBounds(neighbor.row, neighbor.col)) {
                            if (!visitedLocs.contains(neighbor)) {
                                double edgeCost = costFn(curNode->loc, neighbor, world);
                                LocNode* neighborNode = new LocNode(neighbor, curNode->cost + edgeCost);
                                nodes.add(neighborNode);
                                neighborNode->prev = curNode;
                                
                                //If the neighborNode is already in the seen map - pull out the node that is there and look at it's cost. If it's cost is greater than the new
                                //node's cost, then it should be replaced by the new node. To do so, put the neighborNode into the seenLocs map and enqueue the new neighborNode.
                                //the existing seenNode will still be in the pq but since it's priority is greater, by the time it is dequeued, it will already have been visited
                                //and thus discarded at the first check for whether or not it has been visited.
                                if (seenLocs.containsKey(neighborNode->loc)) {
                                    LocNode* seenNode = seenLocs.get(neighborNode->loc);
                                    if (seenNode->cost > neighborNode->cost) {
                                        seenLocs.put(neighborNode->loc, neighborNode);
                                        pq.enqueue(neighborNode, neighborNode->cost+heuristic(neighborNode->loc, end, world));
                                    }
                                }
                                //If the neighborNode is not already in the seen map - color it Yellow and enqueue it into the pq. Also add it to the seen Map.
                                else {
                                    colorCell(world, neighbor, YELLOW);
                                    pq.enqueue(neighborNode, neighborNode->cost+heuristic(neighborNode->loc, end, world));
                                    seenLocs.put(neighborNode->loc, neighborNode);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < nodes.size(); i++) {
        LocNode* node = nodes[i];
        delete node;
    }
    
    if (path.isEmpty()) {
        error("There is no path between these points");
    }
    return path;
}

//Place each node into its own cluster.
//Insert all edges in the graph into a priority queue.
//While there are two or more clusters remaining.
//Dequeue an edge (e) from the pq.
//If the endpoints of edge are not in the same cluster:
//Merge the clusters containing the endpoints of the edge.
//Add edge to the spanning tree.
//Return the spanning tree.




Set<Edge> createMaze(int numRows, int numCols) {
	Set <Edge> maze;
    
    //make cluster as set
    Vector<Set<Loc> > clusters;
    
    TrailblazerPQueue<Edge> pq;
    
    for (int i = 0; i < numCols; i++) {
        for (int j = 0; j < numRows; j++) {
            Loc loc;
            loc.col = i;
            loc.row = j;
            Set<Loc> cluster;
            cluster.add(loc);
            clusters.add(cluster);
            while (i+1 <= numCols) {
                Loc endLoc;
                endLoc.col = i+1;
                endLoc.row = j;
                Edge endEdge = makeEdge(loc, endLoc);
                double d = randomReal(0, numCols*numRows);
                pq.enqueue(endEdge, d);
                if (j-1 >= 0) {
                    Loc oneEnd;
                    oneEnd.col = i+1;
                    oneEnd.row = j-1;
                    Edge topEdge = makeEdge(loc, oneEnd);
                    double d = randomReal(0, numCols* numRows);
                    pq.enqueue(topEdge, d);
                }
                if (j+1 <= numRows) {
                    Loc end;
                    end.col = i+1;
                    end.row = j+1;
                    Edge bottomEdge = makeEdge(loc, end);
                    double d = randomReal(0, numCols* numRows);
                    pq.enqueue(bottomEdge, d);
                }
            }
        }
    }
    
    Set<Loc> newCluster;
    while (clusters.size() >= 2) {
        Edge edge = pq.dequeueMin();
        for (int i = 0; i < clusters.size(); i++) {
            Set<Loc> cluster = clusters[i];
            if (cluster.contains(edge.start)) {
                if (cluster.contains(edge.end)) {
                    //do nothing
                }
                else {
                    maze.add(edge);
                    for (Loc loc : cluster) {
                        newCluster.add(loc);
                    }
                    for (int j = 0; j < clusters.size(); j++) {
                        Set <Loc> endCluster = clusters[i];
                        if (endCluster.contains(edge.end)) {
                            for (Loc endLoc : endCluster) {
                                newCluster.add(endLoc);
                            }
                        }
                    }
                }
            }
        }
    }
    
    return maze;
}
