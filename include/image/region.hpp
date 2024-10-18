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
		int getID();
		int getsize();
		void showRegion(int height, int width);
		bool isPart(int x_, int y_);
        virtual ~Region(); 		
	};
}
