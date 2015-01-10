#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
class node
{
public:
	node();
	~node();
	node*bunch[30];
	string getResult(){ return result; }
	string result;
};

node::node()
{
	for (int i = 0; i < 30; ++i) {
		bunch[i] = 0;
	}
	result = "";
}

node::~node()
{

}
int main() {
	string temp = "hehe";
	int i = 0;
	node dictionary;
	node* now;
	while (temp != "") {
		getline(cin, temp);
		if (temp == "")
			break;
		string key;
		string word;
		now = &dictionary;
		int position = temp.find(' ');
		word = temp.substr(0, position);
		key = temp.substr(position + 1);
		int index;
		for (i = 0; i < key.length(); ++i) {
			index = key[i] - 'a';
			if (now->bunch[index] == 0) {
				now->bunch[index] = new node;
			}
			now = now->bunch[index];
		}
		now->result = word;
	}
	string hehe;
	while (cin >> hehe) {
		int index;
		bool have = true;;
		i = 0;
		now = &dictionary;
		while (i < hehe.length()) {
			index = hehe[i] - 'a';
			if (now->bunch[index] == 0) {
				have = false;
				break;
			}
			else
			{
				now = now->bunch[index];
			}
			i++;
		}
		if (have&&i >= hehe.length() - 1&&now->result != "")
			cout << now->result << endl;
		else
			printf("eh\n");
	}
	system("pause");
	return 0;
}