#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
template <class Record>
void swap(Record*a, Record*b) {
	Record temp = *a;
	*a = *b;
	*b = temp;
}
template <class Record>
Record* partation(Record* startPointer, Record* endPointer) {
	Record *index = startPointer;
	endPointer--;
	Record key = *index;
	swap(index, endPointer);
	while (startPointer < endPointer) {
		if (key > *startPointer) {
			swap(index, startPointer);
			index++;
		}
		startPointer++;
	}
	swap(index, endPointer);
	return index;
}
template <class Record>
void quick_sort(Record* startPointer, Record* endPointer) {
	if (startPointer >= endPointer)
		return;
	Record *index = partation(startPointer, endPointer);
	quick_sort(startPointer, index);
	quick_sort(index + 1, endPointer);

}
int main() {
	int hehe[5] = { 12, 2, 7, 6, 3 };
	quick_sort(hehe, hehe + 5);
	for (int i = 0; i < 5; ++i)
		cout << hehe[i] << " ";
	system("pause");
}