/*
 Class NodeRegion
*/
#include "image/region.hpp"

namespace image {
	class NodeRegion{
	private:
		NodeRegion *Next;
		Region *Regi;		
	public:
		NodeRegion();
		NodeRegion(NodeRegion *Next_, Region *Regi_);
		NodeRegion getNext();
		Region getRegion();
		void setNext(NodeRegion *Next_);
		void setRegi(Region *Regi_)	
		virtual ~NodeRegion();	
	};
}
