/**
 * Class Image
 */
#include "listofregion.hpp"
#include <string>

namespace image {
	class Image; 
	typedef unsigned char uchar;
	

	class Image{
	private:
		int width;
		int height;
		int th_value;
		uchar* data;
		bool *visited;
	public:
		Image();
		Image(int w, int h);
		Image(int w, int h, uchar* _data);
		void threshold(); 
    	int getValue(int row, int col);
		void show();
		ListOfRegion getRegions();
		Region regionMaker(int x, int y, int id);
		ListOfPoint2D DFS(Point2D start);
		bool getVisited(int row, int col);
		void visitPixel(int row, int col);
		Point2D DFSfindNeighbor(Point2D current);
		void showRegion(Region region);
        virtual ~Image(); 
		static Image* readImage(std::string &path);        
	};
}
