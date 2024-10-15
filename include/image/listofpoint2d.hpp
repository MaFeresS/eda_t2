/*
 Class ListOfPoint2D
*/
#include "nodepoint2d.hpp"

namespace image {
	class ListOfPoint2D{
	private:	
		NodePoint2D *Node;	
	public:		
		ListOfPoint2D();
		NodePoint2D *getNode();
		void insertFirstNode(Point2D Node_);
		void insertLastNode(Point2D Node_);
		virtual ~ListOfPoint2D();
	};
}
