#include<stack>
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
// 二叉树的先序遍历

template <class Entry>
void preorder(Node<Entry> *root, void(*visit)(Entry &)) {
	if (root == NULL)
		return;
	Node<Entry>*sub_root = root;
	stack < Node<Entry>*>visited;
	while (sub_root||!visited.empty()) {
		while (sub_root != NULL) {
			(*visit)(sub_root->entry);
			visited.push(sub_root);
			sub_root = sub_root->left;
		}
		sub_root = visited.top();
		sub_root = sub_root->right;
		visited.pop();
	}
}
