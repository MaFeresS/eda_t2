/* implementation of the class NodeRegion
 */
#include <iostream>
#include <vector>
#include "image/noderegion.hpp"

namespace image{
    NodeRegion::NodeRegion(): Regi(), Next(nullptr){

    }
    NodeRegion::NodeRegion(Region Regi_, NodeRegion *Next_): Regi(Regi_), Next(Next_){
        
    }
    NodeRegion *NodeRegion::getNext(){
        return Next;
    }
    Region NodeRegion::getRegion(){
        return Regi;
    }
    void NodeRegion::setNext(NodeRegion *Next_){
        Next=Next_;
    }
    void NodeRegion::setRegi(Region *Regi_){
        Regi=*Regi_;
    }
    NodeRegion::~NodeRegion(){
        
    }
}

