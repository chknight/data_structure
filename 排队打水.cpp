#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<iostream>
using namespace std;
struct person {
	int time;
	int index;
};
int main() {
	int n;
	person student[10000];
	int time = 0;
	int total = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &student[i].time);
		student[i].index = i + 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (student[j].time > student[j + 1].time) {
				person temp = student[j];
				student[j] = student[j + 1];
				student[j + 1] = temp;
			}
		}
	}
	printf("%d", student[0].index);
	time += student[0].time;
	for (int i = 1; i < n; ++i) {
		printf(" %d",student[i].index);
		total += time;
		time += student[i].time;
	}
	cout << endl << fixed << setprecision(2) << double(total)/n << endl;
	system("pause");
	return 0;
}