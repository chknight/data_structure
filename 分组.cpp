#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main() {
	int size[20];
	int group[20][1000];
	int n, t;
	while (cin >> n >> t) {
		int lucky_number;
		int count = 0;
		for (int i = 0; i < t; ++i)
			size[i] = 0;
		for (int i = 0; i < n; ++i) {
			cin >> lucky_number;
			int index = lucky_number%t;
			group[index][size[index]] = lucky_number;
			size[index] += 1;
			count += size[index];
		}
		for (int i = 0; i < t; ++i) {
			for (int j = size[i]-1; j >= 0; --j)
				cout << group[i][j] << " ";
			cout << endl;
		}
		cout << fixed << setprecision(3) << double(count) / n << endl;
	}
	return 0;
}