#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int main() {
	int n, m;
	int ac[300][300];
	int noac[300][300];
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ac[i][j] = 0;
			noac[i][j] = 0;
		}
	}
	int id, num, accept;
	while (cin >> id >> num >> accept) {
		if (accept == 1)
			ac[id - 1][num - 1]++;
		else
			noac[id - 1][num - 1]++;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j)
			cout << ac[i][j] << " " << noac[i][j]<< " ";
		cout << ac[i][m - 1] << " " << noac[i][m-1]<<endl;
	}
	system("pause");
	return 0;
}