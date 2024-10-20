/* implementation of the class ListOfRegion
 */
#include "image/listofregion.hpp"

namespace image {

    ListOfRegion::ListOfRegion(): head(nullptr){
        length = 0;
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

    void ListOfRegion::insertLast(Region reg){
        NodeRegion *node = new NodeRegion(reg,nullptr);
        if(head == nullptr){
            head = node;
        }
        else{
            NodeRegion *currentNode = head;
            while(currentNode ->getNext() != nullptr){
                currentNode = currentNode->getNext();
            }
            currentNode ->setNext(node);
        }
        length++;
    }

    int ListOfRegion::getLengthRegion(){
        return length;
    }

    NodeRegion *ListOfRegion::gethead(){
        return head;
    }

    ListOfRegion::~ListOfRegion(){

    }
}