#include<cstdio>
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int m, n;
	while (cin >> m >> n) {
		int count = 0;
		string house[1000];
		for (int i = 0; i < n; ++i)
			house[i] = "NULL";
		string temp;
		for (int i = 0; i < m; ++i) {
			cin >> temp;
			int index = 0;
			for (int j = 0; j < temp.length(); ++j) {
				index += temp[j] - 'a'+1;
			}
			bool whether = true;
			index = index%n;
			int times = 0;
			while (house[index] != "NULL"&&index < n) {
				if (house[index] != "NULL") {
					index = (index + 1) % n;
					times++;
				}
				if (times >= n)
					break;
			}
			count += times + 1;
			if (whether && times < n) {
				house[index] = temp;
			}
		}
		for (int i = 0; i < n; ++i) {
				cout << i << ":" << house[i] << endl;
		}
		cout << fixed << setprecision(3) << double(count) / m << endl;;
	}
	return 0;
}