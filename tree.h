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


// ����������Ĳ��Һ���

// ����target���ڵ�λ�ã����target���ڶ���������У��򷵻ظý���ָ��

// ���򷵻�NULL

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



// ����������Ĳ��뺯��

// ��target���뵽����������У�����������Ľ����������������

// 1����������������е�Ԫ��С�ڸý���Ԫ��

// 2����������������е�Ԫ�ش��ڸý���Ԫ��

// 3��ͬһ��Ԫ���ڶ����������ֻ�����һ��

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

// �����������ɾ������

// ���target���ڶ���������У���ɾ���������򲻽����κβ���

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