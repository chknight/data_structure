#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
bool compare(string str1, string str2) {
	int i = 0;
	while (i < str1.length() && i < str2.length()) {
		if (str1[i] > str2[i])
			return true;
		if (str1[i] < str2[i])
			return false;
		i++;
	}
	if (str1.length() < str2.length()) {
		int n = str1.length() - 1;
		if (str1[n] > str2[n + 1])
			return true;
		else
			return false;
	}
	if (str1.length() > str2.length()) {
		int n = str2.length()-1;
		if (str1[n + 1] > str2[n])
			return true;
		else
			return false;
	}
}
int main() {
	vector<string>substrings;
	int n, m;
	cin >> n;
	int i;
	int k, l;
	string temp;
	for (i = 1; i <= n; ++i) {
		cin >> m;
		int j;
		string hehe;
		substrings.clear();
		for (j = 0; j < m; ++j) {
			cin >> hehe;
			substrings.push_back(hehe);
		}
		vector<string>::iterator it2;
		for (k = 0; k < m; ++k) {
			vector<string>::iterator it1 = substrings.begin();
			for (l = 0; l < m - k - 1; ++l) {
				it2 = it1;
				it2++;
				if (compare(*it1, *it2)) {
					string temp;
					temp = *it1;
					*it1 = *it2;
					*it2 = temp;
				}
				it1++;
			}
		}
		it2 = substrings.begin();
		string output;
		while (it2 != substrings.end()) {
			output += *it2;
			it2++;
		}
		cout << output << endl;
	}
	system("pause");
	return 0;
}