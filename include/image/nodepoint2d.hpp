/*
 Class NodePoint2D
*/
#include "image/point2D.hpp"

namespace image {
	class NodePoint2D{
	private:
		NodePoint2D *Next;
		Point2D point;		
	public:	
		NodePoint2D();
		NodePoint2D(Point2D point_, NodePoint2D *Next_);
		NodePoint2D *getPointer();
		Point2D getPoint2D();
		void setPointer(NodePoint2D *Next_);
		void setPoint2D(Point2D point_);
		virtual ~NodePoint2D();
	};
}
