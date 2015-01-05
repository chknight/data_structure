#include<list>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
struct Matrix {
	char what;
	int row;
	int col;
	bool left;
	bool right;
	bool up;
	bool down;
	bool visited;
};
Matrix matrix[20][20];
void dfs(int m, int n) {
	list<Matrix>visited;
	matrix[0][0].visited = true;
	visited.push_back(matrix[0][0]);
	while (!visited.empty()) {
		int row = visited.back().row;
		int col = visited.back().col;
		if (visited.back().what == '1') {
			visited.pop_back();
			continue;
		}
		if (row == m - 1 && col == n - 1)
			break;
		if (row - 1 >= 0&&row-1 < m&&visited.back().up == false) {
			if (matrix[row-1][col].visited != true) {
				matrix[row-1][col].visited = true;
				visited.back().up = true;
				visited.push_back(matrix[row - 1][col]);
			}
			else
			{
				visited.back().up = true;
			}
		}
		else if (row + 1 >= 0 && row+1< m&&visited.back().down == false) {
			if (!matrix[row + 1][col].visited) {
				matrix[row + 1][col].visited = true;
				visited.back().down = true;
				visited.push_back(matrix[row + 1][col]);
			}
			else {
				visited.back().down = true;
			}
		}
		else if (col - 1 >= 0 && col - 1< n&&visited.back().left == false) {
			if (!matrix[row][col-1].visited) {
				matrix[row ][col-1].visited = true;
				visited.back().left = true;
				visited.push_back(matrix[row][col-1]);
			}
			else {
				visited.back().left = true;
			}
		}
		else if (col + 1 >= 0 && col + 1< n&&visited.back().right == false) {
			if (!matrix[row][col + 1].visited) {
				matrix[row][col + 1].visited = true;
				visited.back().right = true;
				visited.push_back(matrix[row][col + 1]);
			}
			else {
				visited.back().right = true;
			}
		}
		else {
			visited.pop_back();
		}
	}
	if (visited.empty())
		cout << "no";
	else {
		while (!visited.empty()) {
			cout << "(" << visited.front().row << "," << visited.front().col << ")";
			if (visited.size() > 1)
				cout << ' ';
			visited.pop_front();
		}
	}
	cout << endl;
}
int main() {
	int t;
	int m, n;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> m >> n;
		for (int j = 0; j < m; ++j) {
			string numbers;
			cin >> numbers;
			for (int k = 0; k < n; ++k) {
				matrix[j][k].what = numbers[k];
				matrix[j][k].row = j;
				matrix[j][k].col = k;
				matrix[j][k].left = false;
				matrix[j][k].right = false;
				matrix[j][k].up = false;
				matrix[j][k].down = false;
				matrix[j][k].visited = false;
			}
		}
		dfs(m, n);
	}
	system("pause");
	return 0;
}