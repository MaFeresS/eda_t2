/*
 Class ListOfRegion
*/
#include "image/noderegion.hpp"

namespace image {
	class ListOfRegion{
	private:
		NodeRegion *head;	
		int length;	
	public:
		ListOfRegion();
		void insertFirst(Region head);
		void insertLast(Region head);
		int getLengthRegion();
		NodeRegion *gethead();
		virtual ~ListOfRegion();
	};
}
