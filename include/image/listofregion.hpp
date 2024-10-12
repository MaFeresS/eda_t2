/*
 Class ListOfRegion
*/
#include "image/region.hpp"

namespace image {
	class ListOfRegion{
	private:
		ListOfRegion *Next;
		Region *Regi;		
	public:
		ListOfRegion();
		ListOfRegion(ListOfRegion *Next, Region *Regi);
		void setList(ListOfRegion *Next);
		void setNode(Region *Regi);	
		virtual ~ListOfRegion();
	};
}
