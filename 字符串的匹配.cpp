#include<iostream>
#include<cstdio>
using namespace std;
void getNext(int *code, int*next, int n) {
	int i = 0;
	int k = -1;
	while (i < n) {
		if (k == -1 || code[i] == code[k]) {
			i++;
			k++;
			if (code[i] != code[k])
				next[i] = k;
			else
				next[i] = next[k];
		}
		else {
			k = next[k];
		}
	}
	for (i = 0; i < n; ++i) {
		cout << next[i] << ' ';
	}
	cout << endl;
}
void compare(int *next, int*code, int*gate, int n, int m) {
	int i = 0;
	int j = 0;
	while (i < m&&j < n) {
		if (j == -1 || code[j] == gate[i]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == n)
		printf("%d\n", i - j);
	else
		printf("no solution\n");
}
int main() {
	int n;
	int m;
	int i;
	while (cin >> n) {
		int *code = new int[n];
		int*next = new int[n];
		for (i = 0; i < n; ++i) {
			scanf_s("%d", &code[i]);
			next[i] = -1;
		}
		cin >> m;
		int*gate = new int[m];
		for (i = 0; i < m; ++i) {
			scanf_s("%d", &gate[i]);
		}
		getNext(code, next, n);
		compare(next, code, gate, n, m);
		cout << "hehe" << endl;
	}
	system("pause");
	return 0;
}