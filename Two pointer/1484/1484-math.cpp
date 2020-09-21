#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int G;
vector<int> divisor;
void get_divisor(int num) {
	divisor.push_back(1);
	for (int i = 2; i < num; i++) {
		if (num%i == 0) {
			divisor.push_back(i);
		}
	}
	divisor.push_back(num);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> G;
	vector<int> res;
	get_divisor(G);
	for (int i = 0; i < divisor.size(); i++) {
		int one = divisor[i];
		int two = G / divisor[i];
		if ((one + two) % 2 == 0) {
			int cur = (one + two) / 2;
			int prev = (one - two) / 2;
			if (cur > 0 && prev > 0) {
				res.push_back(cur);
			}
		}
	}
	sort(res.begin(), res.end());
	if (res.size() == 0) {
		cout << -1;
	}
	else {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << "\n";
		}
	}
	return 0;
}