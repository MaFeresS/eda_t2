/* implementation of the class ListOfPoint2D
 */

#include "image/listofpoint2d.hpp"

namespace image{
    ListOfPoint2D::ListOfPoint2D(): Next(nullptr), Node(nullptr){

    }
    ListOfPoint2D::ListOfPoint2D(ListOfPoint2D *Next_, NodePoint2D *Node_): Next(Next_), Node(Node_){

    }
    ListOfPoint2D *ListOfPoint2D::getList(){
        return Next;
    }
	NodePoint2D *ListOfPoint2D::getNode(){
        return Node;
    }
	void ListOfPoint2D::setList(ListOfPoint2D *Next_){
        Next=Next_;
    }
	void ListOfPoint2D::setNode(NodePoint2D *Node_){
        Node=Node_;
    }
    ListOfPoint2D::~ListOfPoint2D(){
        
    }
}