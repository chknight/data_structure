#include<cstdio>
#include<iostream>
using namespace std;
template <class Record>
struct Node
{
	Record entry;
	Node<Record> *next;
};
template <class Record>
class Sortable_list

{
public:
	Sortable_list() {
		head = 0;
	}
	~Sortable_list() {
		while (head != 0) {
			Node<Record>*temp = head->next;
			delete head;
			head = temp;
		}
	}

	// 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，以此类推

	// 输入数据中，position满足 0 <= position <= 链表元素数量

	void insert(int position, const Record &entry) {
		if (head == 0) {
			head = new Node < Record > ;
			head->entry = entry;
			head->next = 0;
			return;
		}
		int i = 0;
		Node<Record> *new_node = new Node<Record>;
		new_node->entry = entry;
		Node<Record>*previous, *following;
		previous = head;
		following = head->next;
		if (position == 0) {
			new_node->next = head;
			head = new_node;
			return;
		}
		while (i < position-1) {
			previous = previous->next;
			following = previous->next;
			i++;
		}
		previous->next = new_node;
		new_node->next = following;
	}



	// 输出链表的内容，每两个元素之间用一个空格隔开，最后一个元素之后没有空格，并且需要换行

	void print() {
		Node<Record>*temp = head;
		while (temp != 0) {
			cout << temp->entry;
			temp = temp->next;
			if (temp != 0)
				printf(" ");
		}
		printf("\n");
	}

	Node<Record>* connect(Node<Record>*list1, Node<Record>*list2) {
		Node<Record>*last_sorted;
		Node<Record>combined;
		last_sorted = &combined;
		while (list1 != 0 && list2 != 0) {
			if (list1->entry <= list2->entry)
			{
				last_sorted->next = list1;
				list1 = list1->next;
				last_sorted = last_sorted->next;
			}
			else {
				last_sorted->next = list2;
				list2 = list2->next;
				last_sorted = last_sorted->next;
			}
		}
		if (list1 == 0)
			last_sorted->next = list2;
		else
			last_sorted->next = list1;
		return combined.next;
	}

	Node<Record> *cut_list(Node<Record>*list_head) {
		Node<Record>*position, *MidPoint, *second_half;
		if ((MidPoint = list_head) == 0)
			return 0;
		position = MidPoint->next;
		while (position != 0) {
			position = position->next;
			if (position != 0) {
				position = position->next;
				MidPoint = MidPoint->next;
			}
		}
		second_half = MidPoint->next;
		MidPoint->next = 0;
		return second_half;
	}

	void merge(Node<Record>*&sub_list)  {
		if (sub_list != 0 && sub_list->next != 0) {
			Node<Record>*second_list = cut_list(sub_list);
			merge(sub_list);
			merge(second_list);
			sub_list = connect(sub_list, second_list);
		}
	}

	// 对链表进行归并排序，你可以添加一些辅助函数，但不能改动类的成员变量
	void merge_sort() {
		merge(head);
	}
private:

	Node<Record> *head;                                     // 链表头指针

};
void he(Node<int>*a,Node<int>*b) {
	delete a;
	a = b;
}
int main() {
	Sortable_list<int> list;
	int temp;
	int i = 0;
	int hehe = 20;
	while (i < 10) {
		list.insert(i, hehe);
		hehe--;
		i++;
	}
	list.merge_sort();
	list.print();
	system("pause");
	return 0;
}