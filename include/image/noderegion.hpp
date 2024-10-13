/*
 Class NodeRegion
*/
#include "image/region.hpp"

namespace image {
	class NodeRegion{
	private:
		NodeRegion *Next;
		Region Regi;		
	public:
		NodeRegion();
		NodeRegion(Region Regi_, NodeRegion *Next_);
		NodeRegion* getNext();
		Region getRegion();
		void setNext(NodeRegion *Next_);
		void setRegi(Region *Regi_);	
		virtual ~NodeRegion();	
	};
}
