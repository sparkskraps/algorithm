#include <iostream>
#include <queue>

class Tree
{
	private:
		struct TreeNode
		{
			TreeNode() = default;
			TreeNode(int data_){
				data = data_;
			}
			int data;
			TreeNode *lChild;
			TreeNode *rChild;
		};
	public:
		Tree()
		  : pRoot(NULL)
		{
		}

		void create_tree()
		{
			std::cout << "Please input node data : \n";
			pRoot = create_tree(pRoot);
		}

		void reverse_tree()
		{
			reverse_tree(pRoot);
		}

		void destroy_tree()
		{
		
		}

		void level_visit_tree()
		{
			if(NULL == pRoot)
				return;
			std::queue<TreeNode *> queue;
			queue.push(pRoot);
			while(!queue.empty())
			{
				TreeNode *pTmpNode = queue.front();
				queue.pop();
				std::cout << pTmpNode->data << " ";
				if(pTmpNode->lChild)
					queue.push(pTmpNode->lChild);
				if(pTmpNode->rChild)
					queue.push(pTmpNode->rChild);
			}
			std::cout << "\n";
		}

	private:
		// Create a tree in pre visist order, use special value `-1` to specify the TreeNode is `NULL`.
		TreeNode *create_tree(TreeNode *pRoot)
		{
			int data;
			std::cin >> data;
			if(-1 == data)
				return NULL;
			TreeNode *pTreeNode = new TreeNode(data);
			pRoot = pTreeNode;
			pRoot->lChild = create_tree(pRoot->lChild);
			pRoot->rChild = create_tree(pRoot->rChild);

			return pRoot;
		}

		void reverse_tree(TreeNode *pRoot)
		{
			if(NULL == pRoot)
				return;

			TreeNode *pTmpNode = pRoot->lChild;
			pRoot->lChild = pRoot->rChild;
			pRoot->rChild = pTmpNode;
			reverse_tree(pRoot->lChild);
			reverse_tree(pRoot->rChild);
		}

		TreeNode *pRoot;
};

int main()
{
	Tree tree;
	tree.create_tree();
	tree.level_visit_tree();
	tree.reverse_tree();
	tree.level_visit_tree();

	return 0;
}
