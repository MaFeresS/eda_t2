/*
 Class ListOfPoint2D
*/
#include "nodepoint2d.hpp"

namespace image {
	class ListOfPoint2D{
	private:	
		ListOfPoint2D *Next;
		NodePoint2D *Node;	
	public:		
		ListOfPoint2D();
		ListOfPoint2D(ListOfPoint2D *Next, NodePoint2D *Node);
		ListOfPoint2D getList();
		NodePoint2D getNode();
		void setList(ListOfPoint2D *Next);
		void setNode(NodePoint2D *Node);
		virtual ~ListOfPoint2D();
	};
}
