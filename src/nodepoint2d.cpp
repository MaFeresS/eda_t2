/* implementation of the class NodePoint2D
 */
#include "image/nodepoint2d.hpp"

namespace image {
    NodePoint2D::NodePoint2D(): point(0,0), Next(nullptr){

    }
    NodePoint2D::NodePoint2D(Point2D point_, NodePoint2D *Next_): point(point_), Next(Next_){

    }
    NodePoint2D *NodePoint2D::getPointer(){
        return Next;
    }
    Point2D NodePoint2D::getPoint2D(){
        return point;
    }
    void NodePoint2D::setPointer(NodePoint2D *Next_){
        Next=Next_;
    }
    void NodePoint2D::setPoint2D(Point2D point_){
        point=point_;
    }
    NodePoint2D::~NodePoint2D(){

    }
};