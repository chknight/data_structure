#include<iostream>
#include<string>
#include<stack>
#include<cstdlib>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		bool whether = true;
		int temp;
		stack<int>bullet;
		int all[10];
		for (int j = 0; j < 10; ++j) {
			cin >> all[j];
		}
		int j = 1;
		int k = 0;
		while (k < 10) {
			while (j <= all[k]) {
				bullet.push(j);
				j++;
			}
			if (all[k] == bullet.top()) {
				bullet.pop();
			}
			k++;
		}
		if (bullet.empty())
			cout << "Yes" << endl;
		else
		{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}