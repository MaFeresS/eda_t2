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
		Region(int id, int size, ListOfPoint2D points);
		void showRegion();
        virtual ~Region(); 		
	};
}
