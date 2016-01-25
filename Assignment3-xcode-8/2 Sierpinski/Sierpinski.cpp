/*
 * File: Sierpinski.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Sierpinski problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "gwindow.h"
#include "gobjects.h"
#include <math.h>

using namespace std;

void recursivePermute (string prefix, string rest) {
    if (rest == "") {
        cout << prefix << endl;
    }
    else {
        for (int i = 0; i < rest.length(); i++) {
            string newPrefix = prefix + rest[i];
            string newRest = rest.substr(0, i) + rest.substr(i + 1);
            recursivePermute(newPrefix, newRest);
        }
    }
}

void listPermutations(string str) {
    recursivePermute("", str);
}



void drawFractalLine (GWindow gw, int start, int length, int base, int angle, int order) {
    GPoint rightSide = gw.drawPolarLine(start + length, base, length, angle*2);
    GPoint leftSide = gw.drawPolarLine(start, base, length, angle);
    GPoint bottom = gw.drawPolarLine(start, base, length, angle - angle);
    
    if (order > 0) {
     
        
    }
    
}

void MoveSingleDisk (char start, char finish) {
    cout << start << " -> " << finish << endl;
}

void MoveTower(int n, char start, char finish, char temp) {
    if (n==1) {
        MoveSingleDisk(start, finish);
    }
    else {
        MoveTower(n-1, start, temp, finish);
        MoveSingleDisk(start, finish);
        MoveTower(n-1, temp, start, finish);
    }
}









////This function draws a Sierpinski Triangle. At each order, the number of internal triangles increases. Order 0 is a plain triangle.
void sierpinskiTriange (GWindow gw, int start, int length, int base, int angle, int order) {
    //The three points create the initial triangle. the rightside draws a line from the right point of hte triangle at a 120 degree angle at a distance of length. The left side does the same but starting from the left side and going for a 60 degree angle. The bottom line forms the base of the triangle and has a 0 degree angle. Each time the function is called, a triangle is drawn.
        GPoint rightSide = gw.drawPolarLine(start + length, base, length, angle*2);
        GPoint leftSide = gw.drawPolarLine(start, base, length, angle);
        GPoint bottom = gw.drawPolarLine(start, base, length, angle - angle);
    // if the order is 0 - the below call will not occur and just a triangle will be drawn with the originally input dimensions. If the order is more than 0, it will draw 3 triangles within the original triangle.
    if (order > 0) {
        //This triangle will form in the left side of the initial triangle
        sierpinskiTriange(gw, start, length/2, base, angle, order -1);
        //This triangle will form on the right side of the initial triangle
        sierpinskiTriange(gw, start+length/2, length/2, base, angle, order-1);
        //This triangle will form at the top of the initial triangle.
        sierpinskiTriange(gw, (start+leftSide.getX())/2, length/2, (base + leftSide.getY())/2.0, angle, order-1);
        //Each time it draws the triangle it decreases the order by 1 and draws three more triangles until the order is 0;
    }
}


int main() {
    GWindow gw;
//    
//    MoveTower(2, 'a', 'b', 'c');
//    
//    drawFractalLine(gw, 200, 50, 200, 60, 0);
    
    sierpinskiTriange(gw, 100, 200, 250, 60, 3);
    
//    listPermutations("ABCDE");
    
    return 0;
}




























//GPoint average (GPoint p0, GPoint p1) {
//
//    int p0X = p0.getX();
//    int p0Y = p0.getY();
//    int p1X = p1.getX();
//    int p1Y = p1.getY();
//
//    int newX = (p0X + p1X)/2;
//    int newY = (p0Y + p1Y)/2;
//
//    GPoint newPoint = GPoint(newX, newY);
//    return newPoint;
//}

//void drawLeftSide (GWindow gw, GPoint startPoint, GPoint middle, GPoint endPoint, GPoint leftSide, GPoint rightSide){
//
//    gw.drawLine(average(startPoint, middle), average(startPoint, average(startPoint, leftSide)));
//    gw.drawLine(middle, average(startPoint, leftSide));
//    gw.drawLine(average(middle, endPoint), average(middle, average(endPoint,rightSide)));
//    gw.drawLine(average(average(startPoint, leftSide), average(endPoint, rightSide)), average(average(startPoint, leftSide), leftSide));
//
//}
//
//void drawRightSide (GWindow gw, GPoint startPoint, GPoint middle, GPoint endPoint, GPoint leftSide, GPoint rightSide) {
//
//    gw.drawLine(middle, average(endPoint, rightSide));
//    gw.drawLine(average(startPoint, middle), average(middle, average(startPoint, leftSide)));
//    gw.drawLine(average(middle, endPoint), average(endPoint, average(endPoint, rightSide)));
//    gw.drawLine(average(average(startPoint, leftSide), average(endPoint, rightSide)), average(average(endPoint, rightSide), rightSide));
//}
//
//void drawTopLine (GWindow gw, GPoint startPoint, GPoint middle, GPoint endPoint, GPoint leftSide, GPoint rightSide) {
//
//    gw.drawLine(average(startPoint, leftSide), average(endPoint, rightSide));
//    gw.drawLine(average(startPoint, average(startPoint, leftSide)), average(middle, average(startPoint, leftSide)));
//    gw.drawLine(average(middle, average(endPoint, rightSide)), average(endPoint, average(endPoint, rightSide)));
//    gw.drawLine(average(average(startPoint, leftSide), leftSide), average(average(endPoint, rightSide), rightSide));
//}











