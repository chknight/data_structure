#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
int min(int*numbers, int n, int k) {
	for (int i = 0; i < k; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (numbers[j] < numbers[min])
			{
				min = j;
			}
		}
		if (min != i) {
			int temp = numbers[i];
			numbers[i] = numbers[min];
			numbers[min] = temp;
		}
	}
	if (k % 2 == 0) {
		return (numbers[k / 2] + numbers[k / 2 - 1]) / 2;
	}
	else {
		return numbers[k / 2];
	}
}
int max(int*numbers, int n, int k) {
	for (int i = 0; i < k; ++i) {
		int max = i;
		for (int j = i + 1; j < n; ++j) {
			if (numbers[j] > numbers[max])
			{
				max = j;
			}
		}
		if (max != i) {
			int temp = numbers[i];
			numbers[i] = numbers[max];
			numbers[max] = temp;
		}
	}
	if (k % 2 == 0) {
		return (numbers[k/2]+numbers[k/2-1])/2;
	}
	else {
		return numbers[k / 2];
	}
}
int main() {
	int t;
	int nums[100000];
	scanf("%d", &t);
	int n;
	int k;
	for (int i = 0; i < t; ++i){
		scanf("%d%d", &n, &k);
		for (int j = 0; j < n; ++j)
			scanf("%d", &nums[j]);
		printf("%d\n", max(nums, n, k) - min(nums, n, k));
	}
	system("pause");
	return 0;
}