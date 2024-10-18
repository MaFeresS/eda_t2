/*
 Class ListOfPoint2D
*/
#include "image/nodepoint2d.hpp"

namespace image {
	class ListOfPoint2D{
	private:	
		NodePoint2D *Node;
		int len;	
	public:		
		ListOfPoint2D();
		NodePoint2D *getNode();
		void insertFirstNode(Point2D Point_);
		void insertLastNode(Point2D Point_);
		int getLen();
		virtual ~ListOfPoint2D();
	};
}
