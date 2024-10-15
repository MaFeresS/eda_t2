/* implementation of the class ListOfPoint2D
 */

#include "image/listofpoint2d.hpp"

namespace image{
    ListOfPoint2D::ListOfPoint2D(): Node(nullptr){

    }
	NodePoint2D *ListOfPoint2D::getNode(){
        return Node;
    }
	void ListOfPoint2D::insertFirstNode(Point2D Point_){
        NodePoint2D * node = new NodePoint2D(Point_,nullptr);
        if(Node == nullptr){
            Node = node;
        }
        else{
            node ->setPointer(Node);
            Node = node;
        }
    }
    void ListOfPoint2D::insertLastNode(Point2D Point_){
        NodePoint2D * node = new NodePoint2D(Point_,nullptr);
        if(Node == nullptr){
            Node = node;
        }
        else{
            NodePoint2D *currentNode = Node;
            while(currentNode ->getPointer() != nullptr){
                currentNode = currentNode->getPointer();
            }
            currentNode ->setPointer(node);
        }
    }
    ListOfPoint2D::~ListOfPoint2D(){
        
    }
}