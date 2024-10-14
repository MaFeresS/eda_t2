/* implementation of the class Region
 */
#include "image/region.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>

namespace image{

    Region::Region(): id(), size(), points(){

    }

    void Region::showRegion(){

    }

    Region::~Region(){
        
    }
}

bool visited[imagesize]; //figure out how to get imagesize, move to "main"
for(int i=0;i<imagesize;i++){
    visited[i]=false;
}

image::ListOfPoint2D DFS(Point2D start){
    image::ListOfPoint2D points;
    std::stack<Point2D> pointStack;
    pointStack.push(start);
    int cord[2]={start.getX(),start.getY()};
    //check neighbors for both visited and value in order nsew

}

//DFSHeper