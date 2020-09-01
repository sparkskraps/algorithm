/***********************************
 *       Binary Search Tree        *
 * ********************************/
#include <iostream>
#include <queue>

template <typename Key, typename Value>
class Bst
{
	public:
		Bst()
		  : m_root_node(NULL)
		{
		}

		typedef struct Node
		{
			Node() = default;
			Node(Key &k, Value &v)
			  : m_key(k), m_value(v)
			{
			}
			Key m_key;
			Value m_value;
			struct Node *lChild;
			struct Node *rChild;
		}Node;

		void add_to_bst(Key k, Value v)
		{
			Node *newNode = new Node(k, v);
			m_root_node = add_to_bst(m_root_node, newNode);
		}

		void print_tree_by_bfs()
		{
			if(NULL == m_root_node)
				return;

			std::cout << "wtf\n";
			m_queue.push(m_root_node);	
			while(!m_queue.empty())
			{
				Node *pTmpNode = m_queue.front();
			    m_queue.pop();
				std::cout << pTmpNode->m_value << " ";
			    if(pTmpNode->lChild)
					m_queue.push(pTmpNode->lChild);
			    if(pTmpNode->rChild)
					m_queue.push(pTmpNode->rChild);
			}
			std::cout << "\n";
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
				pRootNode->m_value = pNewNode->m_value;
			}

			return pRootNode;
		}

	private:
		Node *m_root_node;
		std::queue<Node *> m_queue;
};

int main()
{
	Bst<int, int> bstTree;
	bstTree.add_to_bst(4, 5);
	bstTree.add_to_bst(0, 4);
	bstTree.add_to_bst(3, 7);
	bstTree.add_to_bst(2, 6);
	bstTree.add_to_bst(4, 9);
	bstTree.add_to_bst(6, 2);

	bstTree.print_tree_by_bfs();

	return 0;
}
