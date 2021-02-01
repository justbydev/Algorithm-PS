/*BOJ 20129*/
/*use of vector*/
/*emplace_back &struct*/
/*vector erase and insert O(n), so time limit*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int p1, p2, p3, p4;
string number;
char oper_which[5];
struct Each {
	bool Type;
	long long int Number;
	char Operator;
	Each(long long int N) {
		this->Type = false;
		this->Number = N;
		this->Operator = NULL;
	}
	Each(char O) {
		this->Type = true;
		this->Number = 0;
		this->Operator = O;
	}
};
vector<Each> num;
vector<Each> temp;
void remove_zero() {
	long long now = 0;
	for (int i = 0; i < number.length(); i++) {
		if (number[i] >= '0'&&number[i] <= '9') {
			now = now * 10 + (number[i] - '0');
		}
		else {
			num.emplace_back(now);
			num.emplace_back(number[i]);
			now = 0;
		}
	}
	num.emplace_back(now);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> p1 >> p2 >> p3 >> p4;
	cin >> number;
	remove_zero();
	oper_which[p1] = '+'; oper_which[p2] = '-'; oper_which[p3] = '*'; oper_which[p4] = '/';
	for (int i = 4; i >= 0; i--) {
		char now_oper = oper_which[i];
		for (int j = num.size() - 1; j >= 0; j--) {
			if (num[j].Type == false) {
				temp.push_back(num[j]);
			}
			else if (num[j].Type==true&&num[j].Operator != now_oper) {
				temp.push_back(num[j]);
			}
			else if (num[j].Operator == now_oper) {
				long long int before = temp.back().Number;
				j--;
				long long int after = num[j].Number;
				temp.pop_back();
				if (now_oper == '+') {
					temp.emplace_back(before + after);
				}
				else if (now_oper == '-') {
					temp.emplace_back(before - after);
				}
				else if (now_oper == '/') {
					temp.emplace_back(before / after);
				}
				else if (now_oper == '*') {
					temp.emplace_back(before*after);
				}
			}
		}
		reverse(temp.begin(), temp.end());
		num = temp;
		temp.clear();
	}
	cout << num[0].Number;
	return 0;
}