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

#include<stack>

// �������ĺ������

template <class Entry>

void postorder(Node<Entry> *root, void(*visit)(Entry &)) {
	if (root == NULL)
		return;
	Node<Entry>*sub_root = root;
	postorder(root->left, visit);
	postorder(root->right, visit);
	(*visit)(root->entry);
}