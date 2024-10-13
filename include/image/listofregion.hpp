/*
 Class ListOfRegion
*/
#include "image/noderegion.hpp"

namespace image {
	class ListOfRegion{
	private:
		ListOfRegion *Next;
		NodeRegion *Node;		
	public:
		ListOfRegion();
		ListOfRegion(ListOfRegion *Next, NodeRegion *Node);
		void setList(ListOfRegion *Next);
		void setNode(NodeRegion *Node);	
		virtual ~ListOfRegion();
	};
}
