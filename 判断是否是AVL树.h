#ifndef AVL_NODE

#define AVL_NODE



template <class Entry>

struct AvlNode

{

	Entry entry;

	AvlNode<Entry> *left;

	AvlNode<Entry> *right;

	int bf;                // balance factor 平衡因子

};



#endif
#include<iostream>

template<class Entry>
int get_height(AvlNode<Entry> *root, int height) {
	if (root == NULL)
		return 0;
	int max = get_height(root->left, height) > get_height(root->right, height) ? get_height(root->left, height) : get_height(root->right, height);
	return max + 1;
}

template <class Entry>

bool AVL_Tree(AvlNode<Entry> *&root, int height) {
	if (root == NULL)
		return true;
	int left_height = get_height(root->left, height);
	int right_height = get_height(root->right,height);
	return (left_height - right_height <= 1 && left_height - right_height >= -1) && AVL_Tree(root->left, left_height) && AVL_Tree(root->right, right_height);
}


// 判断一颗树是否为平衡二叉树

template <class Entry>

bool is_AVL_Tree(AvlNode<Entry> *&root) {
	int height = 0;
	return AVL_Tree(root, height);
}
