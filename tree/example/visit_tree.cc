#include <iostream>
#include <string>
#include <queue>

#include "../comm/bst.hpp"

using namespace bst_tree;

int main()
{
	Bst<std::string, int> b;
	b.add_to_bst("aaa", 1);
	b.add_to_bst("ddd", 3);
	b.add_to_bst("ccc", 5);
	b.add_to_bst("fff", 9);
	b.add_to_bst("eee", 7);
	b.add_to_bst("ggg", 7);

	int value = 0;
	int ret = b.search_bst("ddd", &value);
	if(-1 == ret)
		std::cout << "Not found" << "\n";
	else
		std::cout << "The value of key `ddd` is : " << value << "\n";

	std::cout << "visit bst in inOrder :\n";
	b.in_order_visit();
	std::cout << "\nvisit bst in levle :\n";
	b.level_visit();

	//	b.deleteMinKey();
	//	std::cout << "visit bst in levle : " << " ";
	//	b.levelVisit();
	//	b.deleteMaxKey();

	// std::cout << "Before delete, tree size is : " << b.getSize() << " ";
	// b.deleteKey("ddd");
	// std::cout << "visit bst in levle : " << " ";
	// std::cout << "After delete `ddd`, tree size is : " << b.getSize() << " ";
	// b.levelVisit();

	return 0;
}

