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

    void Region::showRegion(){

    }

    Region::~Region(){
        
    }
}