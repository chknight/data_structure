#ifndef NODE

#define NODE

template <class Entry>

struct Node

{

	Entry entry;

	Node<Entry> *left;

	Node<Entry> *right;

};

#endif
// 二叉树的中序遍历
#include<stack>
template <class Entry>
void inorder(Node<Entry> *root, void(*visit)(Entry &)) {
	if (root == NULL)
		return;
	Node<Entry>*sub_root = root;
	stack<Node<Entry>*>visited;
	while (sub_root || !visited.empty()) {
		while (sub_root != NULL) {
			visited.push(sub_root);
			sub_root = sub_root->left;
		}
		sub_root = visited.top();
		(*visit)(sub_root->entry);
		sub_root = sub_root->right;
		visited.pop();
	}
}