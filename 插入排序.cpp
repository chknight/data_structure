#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;
struct num
{
	int index;
	int number;
	int next;
	bool start;
};
void print(num*nums, int start, int max) {
	int index = start;
	for (int i = 0; i < max; ++i) {
		printf("%d ", nums[index].number);
		index = nums[index].next;
	}
	printf("\n");
}
void insert_sort(num*nums, int max, int n, int bot, int top) {
	if (max == n) {
		return;
	}
	if (nums[max].number < nums[bot].number) {
		nums[max].next = bot;
		nums[top].next = max + 1;
		bot = max;
		print(nums, bot, n);
		insert_sort(nums, max + 1, n, bot, top);
	} else if (nums[max].number > nums[top].number) {
		nums[top].next = max;
		top = max;
		insert_sort(nums, max + 1, n, bot, top);
	}
	else {
		int i = bot;
		bool did = false;
		while (i != top) {
			int next = nums[i].next;
			if (nums[i].number <= nums[max].number&&nums[next].number >= nums[max].number) {
				nums[max].next = next;
				nums[i].next = max;
				nums[top].next = max + 1;
				print(nums, bot, n);
				did = true;
				insert_sort(nums, max + 1, n, bot, top);
				break;
			}
			i = next;
		}
		if (!did) {
			print(nums, bot, n);
			insert_sort(nums, max + 1, n, bot, top);
		}
	}
}
int main() {
	int n;
	cin >> n;
	num * nums = new num[n];
	for (int i = 0; i < n; ++i) {
		scanf_s("%d", &nums[i].number);
		nums[i].index = i;
		nums[i].next = i + 1;
		nums[i].start = false;
	}
	nums[0].start = true;
	insert_sort(nums, 0, n, 0, 0);
	system("pause");
	return 0;
}