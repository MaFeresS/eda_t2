/* implementation of the class ListOfRegion
 */
#include "image/listofregion.hpp"

namespace image {

    ListOfRegion::ListOfRegion(): head(nullptr){
        
    }

    void ListOfRegion::insertFirst(Region reg){
        NodeRegion *node = new NodeRegion(reg,nullptr);
        if(head == nullptr){
            head = node;
        }
        else{
            node ->setNext(head);
            head = node;
        }
    }

    ListOfRegion::~ListOfRegion(){

    }
}