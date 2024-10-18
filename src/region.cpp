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

    Region::Region(int id, int size, ListOfPoint2D points): id(id), size(size), points(points){

    }

    int Region::getID(){
        return id;
    }

    int Region::getsize(){
        return size;
    }

    void Region::showRegion(int height, int width){
        int display[height*width];
        std::memset(display,0,height*width);

    }

    bool Region::isPart(int x_, int y_){
        NodePoint2D *Node=points.getNode();
        while(Node!=nullptr){
            if((Node->getPoint2D()).getX()==x_ && (Node->getPoint2D()).getY()==y_){
                return true;
            }
            Node=Node->getPointer();
        }
        return false;
    }

    Region::~Region(){
        
    }
}