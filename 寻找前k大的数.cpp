#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
void insert_heap(int*nums, int low, int high, int&current) {
	int large = 2 * low + 1;
	while (large <= high) {
		if (large < high&&nums[large] > nums[large + 1])
			large++;
		if (current <= nums[large]) {
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
	for (int i = 0; i < size - 1; ++i)
		printf("%d ", nums[i]);
	printf("%d\n", nums[size - 1]);
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
	for (last_unsorted = size - 1; last_unsorted > 0; last_unsorted--) {
		current = nums[last_unsorted];
		nums[last_unsorted] = nums[0];
		insert_heap(nums, 0, last_unsorted - 1, current);
	}
}
int main() {
	int n, k;
	int i;
	while (cin >> n >> k) {
		if (k != 0) {
			int *nums = new int[k];
			for (i = 0; i < k; ++i) {
				scanf("%d", &nums[i]);
			}
			heap(nums, k);
			int temp;
			while (i < n) {
				scanf("%d", &temp);
				if (temp > nums[0]) {
					int current = temp;
					insert_heap(nums, 0, k - 1, current);
				}
				i++;
			}
			heap_sort(nums, k);
			print(nums, k);
		}
		else {
			printf("\n");
		}
    }
	system("pause");
	return 0;
}