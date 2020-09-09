/******************************************************
 * Count the number of occurrences of specified word.**
 * ****************************************************/

#include <iostream>

#include "../comm/file_parser.hpp"
#include "../comm/bst.hpp"

using namespace bst_tree;
using namespace file_parser;

int main()
{
	std::vector<std::string> word_vec;
	Bst<std::string, int> bstTree;
	FileParser fileParser("a.txt");
	fileParser.parse_content(word_vec);

	for(auto &word : word_vec)
		bstTree.add_to_bst(word, 1);

	int value;
	int res = bstTree.get_value_by_key("add", &value);
	if(0 == res)
		std::cout << "The word `add` appears " << value << " times\n";
	else
		std::cout << "not found\n";

	return 0;
}

