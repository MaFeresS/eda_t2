/*
 Class ListOfRegion
*/
#include "image/noderegion.hpp"

namespace image {
	class ListOfRegion{
	private:
		NodeRegion *head;		
	public:
		ListOfRegion();
		void insertFirst(Region head);
		void insertLast(Region head);
		virtual ~ListOfRegion();
	};
}
