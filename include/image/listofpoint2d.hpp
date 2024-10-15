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
		void insertFirstNode(Point2D Point_);
		void insertLastNode(Point2D Point_);
		virtual ~ListOfPoint2D();
	};
}
