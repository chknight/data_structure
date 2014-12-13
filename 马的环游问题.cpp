#include<list>
#include<cstdio>
using namespace std;
void move_3up_1right(int&id, bool &visited) {
	id -= 15;
	visited = true;
}
void move_3up_1left(int&id, bool&visited) {
	id -= 17;
	visited = true;
}
void move_1up_3right(int&id, bool&visited) {
	id -= 6;
	visited = true;
}
void move__1up_3left(int&id, bool&visited) {
	id -= 10;
	visited = true;
}
void move_1down_3right(int&id, bool&visited) {
	id += 6;
	visited = true;
}
void move_1down_3left(int&id, bool&visited) {
	id += 10;
	visited = true;
}
void move_3down_1right(int&id, bool&visited) {
	id += 17;
	visited = true;
}
void move_3down_1left(int&id, bool&visited) {
	id += 15;
	visited = true;
}
bool check_3up_1right(int id, bool visited) {
	return (!visited)&&(id -15>=1);
}
bool check_3up_1left(int id, bool visited) {
	return (!visited)&&(id - 17 >= 1);
}
bool check_1up_3right(int id, bool visited) {
	return (!visited)&&(id - 6 > 0);
}
bool check__1up_3left(int id, bool visited) {
	return (!visited)&&(id - 10 > 0);
}
bool check_1down_3right(int id, bool visited) {
	return (!visited)&&(id + 6 < 65);
}
bool check_1down_3left(int id, bool visited) {
	return (!visited)&&id + 10 < 65;
}
bool check_3down_1right(int id ,bool visited) {
	return (!visited)&&id + 17 < 65;
}
bool check_3down_1left(int&id, bool visited) {
	return (!visited)&&id + 15 < 65;
}
struct node
{
	bool visited = false;
	int number;
	bool up3_right1 = false;
	bool up3_left = false;
	bool up1_right3 = false;
	bool up1_left3 = false;
	bool down1_right3 = false;
	bool down1_left3 = false;
	bool down3_left3 = false;
	bool down3_right3 = false;
};
void clear(node&block) {
	block.visited = false;
	block.up3_right1 = false;
	block.up3_left = false;
	block.up1_right3 = false;
	block.up1_left3 = false;
	block.down1_right3 = false;
	block.down1_left3 = false;
	block.down3_left3 = false;
	block.down3_right3 = false;
}
void print(list<node>blocks) {
	while (!blocks.empty()) {
		printf("%d ", blocks.front().number);
		blocks.pop_front();
	}
	printf("\n");
}
void horse(int n, node*block, int step, list<node>blocks) {
	if (step == 63) {
		print(blocks);
		return;
	}
	block[n].visited = true;
	blocks.push_back(block[n]);
	if (check_1down_3left(n, block[n].visited)) {
		move_1down_3left(n, block[n].visited);
		horse(n, block, step + 1, blocks);
	}
	else if (check_1down_3right(n,block[n].visited)) {
		move_1down_3right(n, block[n].visited);
		horse(n, block, step + 1, blocks);
	}
	else if (check_1up_3right(n, block[n].visited)) {
		move_1up_3right(n, block[n].visited);
		horse(n, block, step + 1, blocks);
	}
	else if (check__1up_3left(n, block[n].visited)) {
		move__1up_3left(n, block[n].visited);
		horse(n, block, step + 1, blocks);
	}
	else if (check_3down_1left(n, block[n].visited)) {
		move_3down_1left(n, block[n].visited);
		horse(n, block, step + 1, blocks);
	}
	else if (check_3down_1right(n, block[n].visited)) {
		move_3down_1right(n, block[n].visited);
		horse(n, block, step + 1, blocks);
	}
	else if (check_3up_1left(n, block[n].visited)) {
		move_3up_1left(n, block[n].visited);
		horse(n, block, step + 1, blocks);
	}
	else if (check_3up_1right(n, block[n].visited)) {
		move_3up_1right(n, block[n].visited);
		horse(n, block, step + 1, blocks);
	}
	else {
		clear(block[n]);
		if (!blocks.empty()) {
			blocks.pop_back();
			horse(blocks.back().number, block, step - 1, blocks);
		}
	}
}
int main() {
	int n = 1;
	node block[65];
	for (int i = 0; i < 65; i++)
	{
		block[i].number = i;
	}
	while (n != -1) {
		scanf_s("%d", &n);
		if (n == -1)
			break;
		list<node>blocks;
		horse(n, block, 0,blocks);
	}
}
