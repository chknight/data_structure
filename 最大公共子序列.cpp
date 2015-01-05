#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
int numbers[1000][1000];
using namespace std;
void lcs(char* str1, char* str2) {
	int m = strlen(str1);
	int n = strlen(str2);
	for (int i = 0; i <= n; ++i)
		numbers[0][i] = 0;
	for (int i = 0; i <= m; ++i)
		numbers[i][0] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (str1[i-1] == str2[j-1]) {
				numbers[i][j] = numbers[i - 1][j - 1] + 1;
			}
			else {
				numbers[i][j] = numbers[i - 1][j] > numbers[i][j - 1] ? numbers[i - 1][j] : numbers[i][j - 1];
			}
		}
	}
	cout << numbers[m][n] << endl;
	return;
}
int main() {
	char str1[1000];
	char str2[1000];
	while (scanf("%s%s", str1, str2)!=EOF) {
		lcs(str1, str2);
	}
	system("pause");
	return 0;
}