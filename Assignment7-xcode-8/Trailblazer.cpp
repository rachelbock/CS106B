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
             double costFn(Loc from, Loc to, Grid<double>& world)) {

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
    pq.enqueue(startNode, 0);
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
                                        pq.enqueue(neighborNode, neighborNode->cost);
                                    }
                                }
                                //If the neighborNode is not already in the seen map - color it Yellow and enqueue it into the pq. Also add it to the seen Map.
                                else {
                                    colorCell(world, neighbor, YELLOW);
                                    pq.enqueue(neighborNode, neighborNode->cost);
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

Set<Edge> createMaze(int numRows, int numCols) {
	// TODO: Fill this in!
	error("createMaze is not implemented yet.");
    return Set<Edge>();
}
