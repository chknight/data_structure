#ifndef NODE

#define NODE
#include<cstdio>


template <class Entry>

struct Node

{

	Entry entry;

	Node<Entry> *left;

	Node<Entry> *right;



	Node(const Entry &en)

	{

		entry = en;

		left = NULL;

		right = NULL;
	}
};
#endif


// 二叉查找树的查找函数

// 查找target所在的位置，如果target存在二叉查找树中，则返回该结点的指针

// 否则返回NULL

template <class Entry>

Node<Entry>* BSTree_search(Node<Entry> *root, Entry &target) {
	if (root == NULL)
		return NULL;
	if (root->entry == target)
		return root;
	else if (root->entry > target)
		return BSTree_search(root->left, target);
	else if (root->entry < target)
		return BSTree_search(root->right, target);
}



// 二叉查找树的插入函数

// 将target插入到二叉查找树中，二叉查找树的结点满足以下条件：

// 1、任意结点的左子树中的元素小于该结点的元素

// 2、任意结点的右子树中的元素大于该结点的元素

// 3、同一个元素在二叉查找树中只会出现一次

template <class Entry>

void BSTree_insert(Node<Entry> *&root, const Entry &target) {
	if (root == NULL) {
		root = new Node<Entry>(target);
		return;
	}
	if (root->entry == target){
		return;
	}
	else if (root->entry < target) {
		BSTree_insert(root->right, target);
		return;
	}
	else {
		BSTree_insert(root->left, target);
		return;
	}
}

// 二叉查找树的删除函数

// 如果target存在二叉查找树中，则删除它，否则不进行任何操作

template <class Entry>

void BSTree_remove(Node<Entry> *&root, const Entry &target) {
	Node<Entry>*root_to_delete;
	if (root == NULL)
		return;
	if (target == root->entry)
		remove(*&root);
	else if (root->entry > target) {
		BSTree_remove(root->left, target);
	}
	else if (root->entry < target) {
		BSTree_remove(root->right, target);
		return;
	}
}
template <class Entry>
void remove(Node<Entry>*&root) {
	Node<Entry>*root_to_delete;
	if (root->left == NULL) {
		root_to_delete = root;
		root = root->right;
	}
	else if (root->right == NULL) {
		root_to_delete = root;
		root = root->left;
	}
	else {
		root_to_delete = root->left;
		Node<Entry>*parent = root;
		while (root_to_delete->right != NULL) {
			parent = root_to_delete;
			root_to_delete = root_to_delete->right;
		}
		root->entry = root_to_delete->entry;
		if (parent == root)
			root->left = root_to_delete->left;
		else
			parent->right = root_to_delete->left;
	}
	delete root_to_delete;
	return;
}