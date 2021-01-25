/*BOJ 2661*/
/*1<=N<=80*/
/*string compare*/
/*back tracking*/
/*track all ways*/
#include<iostream>
#include<string>
using namespace std;
int N;
string res;
int comp_str(int one_st, int one_ed, int two_st, int two_ed) {
	if (one_st < 0) {
		return -1;
	}
	string one = res.substr(one_st, one_ed - one_st + 1);
	string two = res.substr(two_st, two_ed - two_st + 1);
	if (one.compare(two) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int trace(int idx) {
	if (idx == N) {
		return 1;
	}
	int ret;
	for (int i = 1; i <= 3; i++) {
		if (res[idx - 1] - '0' == i) {
			continue;
		}
		res = res + to_string(i);
		int gap = 1;
		int flag = 0;
		while (1) {
			int two_ed = idx;
			int two_st = idx - gap + 1;
			int one_ed = two_st - 1;
			int one_st = one_ed - gap + 1;
			int str_flag = comp_str(one_st, one_ed, two_st, two_ed);
			if (str_flag == -1) {
				break;
			}
			else if (str_flag == 1) {
				flag = 1;
				break;
			}
			gap++;
		}
		if (flag == 1) {
			res = res.substr(0, idx);
			continue;
		}
		ret = trace(idx + 1);
		if (ret == 1) {
			return 1;
		}
		else if (ret == -1) {
			res = res.substr(0, idx);
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	if (N == 1) {
		cout << "1";
	}
	else {
		res = "1";
		if (trace(1) == -1) {
			res = "2";
			if (trace(1) == -1) {
				res = "3";
			}
		}
		cout << res;
	}
	return 0;
}