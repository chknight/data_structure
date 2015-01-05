#include<iostream>
#include<cstdlib>
using namespace std;
int find_egg_way(int egg, int basket) {
	if (egg == 1 || basket == 1) {
		return 1;
	}
	else if (egg <= basket) {
		return 1 + find_egg_way(egg, egg - 1);
	}
	else if (egg > basket) {
		return find_egg_way(egg - basket, basket) + find_egg_way(egg, basket - 1);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int eggs, bascket;
		cin >> eggs >> bascket;
		cout << find_egg_way(eggs, bascket) << endl;
	}
	system("pause");
	return 0;
}