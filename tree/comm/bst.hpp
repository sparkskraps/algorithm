/***********************************
 *       Binary Search Tree        *
 * ********************************/
#ifndef BST_H
#define BST_H

#include <queue>

namespace bst_tree
{
template <typename Key, typename Value>
class Bst
{
	public:
		Bst()
		  : pRootNode(NULL)
		{
		}

		typedef struct Node
		{
			Node() = default;
			Node(const Key &k, const Value &v)
			  : m_key(k), m_value(v)
			{
			}
			Key m_key;
			Value m_value;
			struct Node *lChild;
			struct Node *rChild;
		}Node;

		void add_to_bst(const Key &k, const Value &v)
		{
			Node *newNode = new Node(k, v);
			pRootNode = add_to_bst(pRootNode, newNode);
		}

		int get_value_by_key(const Key &k, int *value)
		{
			if(value == NULL)
				return -1;
			Node *pNode = get_value_by_key(pRootNode, k);
			if(NULL == pNode)
				return -1;
			*value = pNode->m_value;
			return 0;
		}

		int search_bst(const Key &k, int *value)
		{
			Node *pRetNode = search_bst(pRootNode, k);

			if(pRetNode == NULL)
				return -1;
			*value = pRetNode->m_value;
			return 0;
		}

		void level_visit()
		{
			if(NULL == pRootNode)
				return;

			m_queue.push(pRootNode);	
			while(!m_queue.empty())
			{
				Node *pTmpNode = m_queue.front();
			    m_queue.pop();
				std::cout << pTmpNode->m_key << " ";
			    if(pTmpNode->lChild)
					m_queue.push(pTmpNode->lChild);
			    if(pTmpNode->rChild)
					m_queue.push(pTmpNode->rChild);
			}
			std::cout << "\n";
		}

		void in_order_visit()
		{
			return in_order_visit(pRootNode);
		}

	protected:
		Node *add_to_bst(Node *pRootNode, Node *pNewNode)
		{
			if(NULL == pRootNode)
			{
				pRootNode = pNewNode;
				pRootNode->lChild = NULL;
				pRootNode->rChild = NULL;
				// std::cout << "fuck1\n";
				return pRootNode;
			}
			if(pNewNode->m_key < pRootNode->m_key)
			{
				pRootNode->lChild = add_to_bst(pRootNode->lChild, pNewNode);
			}
			else if(pNewNode->m_key > pRootNode->m_key)
			{
				pRootNode->rChild = add_to_bst(pRootNode->rChild, pNewNode);
			}
			else
			{
				pRootNode->m_value += 1;
			}

			return pRootNode;
		}

		Node *get_value_by_key(Node *pNode, const Key &k)
		{
			if(pNode == NULL)
				return NULL;

			if(pNode->m_key < k)
			{
				return get_value_by_key(pNode->rChild, k);
			}
			else if(pNode->m_key > k)
			{
				return get_value_by_key(pNode->lChild, k);
			}
			else
			{
				return pNode;
			}
		}

		Node *search_bst(Node *pRootNode, const Key &k)
		{
			if(pRootNode == NULL)
				return NULL;
			if(pRootNode->m_key == k)
				return pRootNode;
			else if(pRootNode->m_key < k)
			{
				search_bst(pRootNode->rChild, k);
			}
			else
			{
				search_bst(pRootNode->lChild, k);
			}
		}

		void in_order_visit(Node *pRootNode)
		{
			if(pRootNode == NULL)
				return;

			if(pRootNode->lChild)
				in_order_visit(pRootNode->lChild);
			std::cout << pRootNode->m_key << " ";
			if(pRootNode->rChild)
				in_order_visit(pRootNode->rChild);
		}

	private:
		Node *pRootNode;
		std::queue<Node *> m_queue;
};
}
#endif

#if 0
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
#endif
