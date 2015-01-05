#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
int main() {
	int t;
	scanf("%d", &t);
	int m, n;
	int card;
	int id;
	int max;
	for (int i = 0; i < t; ++i) {
		int count = 0;
		max = 0;
		scanf("%d%d", &n, &m);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &card);
			if (card > max)
				max = card;
		}
		for (int j = 0; j < m; ++j) {
			scanf("%d", &id);
			if (id < max)
				count++;
		}
		printf("%d\n", 50 * count);
	}
	system("pause");
	return 0;
}