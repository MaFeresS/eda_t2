/* implementation of the class NodeRegion
 */
#include <iostream>
#include <vector>
#include "image/noderegion.hpp"

namespace image{
    NodeRegion::NodeRegion(): Next(nullptr), Regi(nullptr){

    }
    NodeRegion::NodeRegion(NodeRegion *Next_, Region *Regi_): Next(Next_), Regi(Regi_){
        
    }
    NodeRegion *NodeRegion::getNext(){
        return Next;
    }
    Region *NodeRegion::getRegion(){
        return Regi;
    }
    void NodeRegion::setNext(NodeRegion *Next_){
        Next=Next_;
    }
    void NodeRegion::setRegi(Region *Regi_){
        Regi=Regi_;
    }
    NodeRegion::~NodeRegion(){
        
    }
}

