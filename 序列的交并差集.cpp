#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int m, n;
	while (cin >> m >> n) {
		int *a = new int[m];
		int *b = new int[n];
		int *c = new int[m + n];
		int size_c = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &b[i]);
		}
		int i = 0, j = 0;
		for (i = 0; i < m; ++i) {
			for (j = 0; j < n; ++j) {
				if (a[i] == b[j]) {
					printf("%d ", a[i]);
					c[size_c] = a[i];
					size_c++;
					break;
				}
			}
		}
		printf("\n");
		for (i = 0; i < m; ++i)
			printf("%d ", a[i]);
		for (j = 0; j < n; ++j) {
			for (i = 0; i < m; ++i) {
				if (a[i] == b[j])
					break;
			}
			if (i == m)
				printf("%d ", b[j]);
		}
		printf("\n");
		for (i = 0, j = 0; i < m&&j < size_c; ++i) {
			if (a[i] != c[j])
				printf("%d ", a[i]);
			else
				j++;
		}
		while (i < m) {
			printf("%d ", a[i]);
			i++;
		}
		printf("\n");
	}
	return 0;
}