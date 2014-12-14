#include<list>
#include<cstdio>
#include<iostream>
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
	id += 10;
	visited = true;
}
void move_1down_3left(int&id, bool&visited) {
	id += 6;
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
	return (!visited)&&(id + 10 < 65);
}
bool check_1down_3left(int id, bool visited) {
	return (!visited)&&id + 6 < 65;
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
	bool up3_left1 = false;
	bool up1_right3 = false;
	bool up1_left3 = false;
	bool down1_right3 = false;
	bool down1_left3 = false;
	bool down3_left1 = false;
	bool down3_right1 = false;
};
void clear(node&block) {
	block.visited = false;
	block.up3_right1 = false;
	block.up3_left1 = false;
	block.up1_right3 = false;
	block.up1_left3 = false;
	block.down1_right3 = false;
	block.down1_left3 = false;
	block.down3_left1 = false;
	block.down3_right1 = false;
}
void print(list<node>blocks) {
	while (!blocks.empty()) {
		printf("%d ", blocks.front().number);
		blocks.pop_front();
	}
	printf("\n");
}
void horse(int n, node*block, int step, list<node>blocks) {
	bool visit = block[n].visited;
	block[n].visited = true;
	if (!visit)
 	    blocks.push_back(block[n]);
	if (step == 63) {
		print(blocks);
		return;
	}
	int temp = n;
	if (check_1down_3left(n, block[n].down1_left3)) {
		move_1down_3left(n,block[n].down1_left3);
		if (!block[temp].visited) {
		move_1down_3left(n, block[n].down1_left3);
		horse(n, block, step + 1, blocks);
	    } else {
	    	horse(n, block, step, blocks);
	    }
	}
	else if (check_1down_3right(n,block[n].down1_right3)) {
		move_1down_3right(temp, block[n].down1_right3);
		if (!block[temp].visited) {
		move_1down_3right(n, block[n].down1_right3);
		horse(n, block, step + 1, blocks);
	    } else {
	    	horse(n, block, step, blocks);
	    }
	}
	else if (check_1up_3right(n, block[n].up1_right3)) {
		move_1up_3right(temp, block[n].up1_right3);
		if (!block[temp].visited) {
		move_1up_3right(n, block[n].up1_right3);
		horse(n, block, step + 1, blocks);
	    } else {
	    	horse(n, block, step, blocks);
	    }
	}
	else if (check__1up_3left(n, block[n].up1_left3)) {
		move__1up_3left(temp, block[n].up1_left3);
		if (!block[temp].visited) {
		move__1up_3left(n, block[n].up1_left3);
		horse(n, block, step + 1, blocks);
	    } else {
	    	horse(n, block, step, blocks);
	    }
	}
	else if (check_3down_1left(n, block[n].down3_left1)) {
		move_3down_1left(temp, block[n].down3_left1);
		if (!block[temp].visited) {
		move_3down_1left(n, block[n].down3_left1);
		horse(n, block, step + 1, blocks);
	    } else {
	    	horse(n, block, step, blocks);
	    }
	}
	else if (check_3down_1right(n, block[n].down3_right1)) {
		move_3down_1right(temp, block[n].down3_right1);
		if (!block[temp].visited) {
		move_3down_1right(n, block[n].down3_right1);
		horse(n, block, step + 1, blocks);
	    } else {
	    	horse(n, block, step, blocks);
	    }
	}
	else if (check_3up_1left(n, block[n].up3_left1)) {
		move_3up_1left(temp, block[n].down3_left1);
		if (!block[temp].visited) {
		move_3up_1left(n, block[n].up3_left1);
		horse(n, block, step + 1, blocks);
	    } else {
	    	horse(n, block, step, blocks);
	    }
	}
	else if (check_3up_1right(n, block[n].up3_right1)) {
		move_3up_1right(temp, block[n].up3_right1);
		if  (!block[temp].visited) {
		move_3up_1right(n, block[n].up3_right1);
		horse(n, block, step + 1, blocks);
	    } else {
	    	horse(n, block, step, blocks);
	    }
	}
	else {
		clear(block[n]);
		blocks.pop_back();
		horse(blocks.back().number, block, step - 1, blocks);
	}
	return;
}
int main() {
	int n = 1;
	node block[65];
	for (int i = 0; i < 65; i++)
	{
		block[i].number = i;
	}
	while (n != -1) {
		cin >> n;
		if (n == -1)
			break;
		list<node>blocks;
		horse(n, block, 0,blocks);
	}
}
