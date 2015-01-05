#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
void insert_heap(int*nums, int low, int high, int&current) {
	int large = 2 * low + 1;
	while (large <= high) {
		if (large < high&&nums[large] < nums[large + 1])
			large++;
		if (current >= nums[large]) {
			break;
		}
		else {
			nums[low] = nums[large];
			low = large;
			large = 2 * low + 1;
		}
	}
	nums[low] = current;
}
void print(int*nums, int size) {
	for (int i = 0; i < size-1; ++i)
		printf("%d ", nums[i]);
	printf("%d\n", nums[size-1]);
}
void heap(int*nums, int size) {
	int low;
	for (low = size / 2 - 1; low >= 0; low--) {
		int current = nums[low];
		insert_heap(nums, low, size - 1, current);
	}
}
void heap_sort(int*nums, int size) {
	int current;
	int last_unsorted;
	heap(nums, size);
	print(nums, size);
	for (last_unsorted = size - 1; last_unsorted > 0; last_unsorted--) {
		current = nums[last_unsorted];
		nums[last_unsorted] = nums[0];
		insert_heap(nums, 0, last_unsorted - 1, current);
		print(nums, size);
	}
}
int main() {
	int n;
	while (cin >> n) {
		int * nums = new int[n];
		for (int i = 0; i < n; ++i) {
			scanf("%d", &nums[i]);
		}
		heap_sort(nums, n);
	}
	return 0;
}