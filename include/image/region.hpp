/*
 Class Region
*/
#include "image/listofpoint2d.hpp"

namespace image {
	class Region{
	private:
		int id;
		int size;
		ListOfPoint2D points;	
	public:
		Region();
		void showRegion();
        virtual ~Region(); 		
	};
}
