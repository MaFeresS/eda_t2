/*
 Class NodePoint2D
*/
#include "image/point2D.hpp"

namespace image {
	class NodePoint2D{
	private:
		NodePoint2D *Nptr;
		Point2D point;		
	public:	
		NodePoint2D();
		NodePoint2D(Point2D point, NodePoint2D *Nptr);
		NodePoint2D *getPointer();
		Point2D *getPoint2D();
		void setPointer(NodePoint2D *Nptr);
		void setPoint2D(Point2D point);
		virtual ~NodePoint2D();
	};
}
