#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int L, C;
vector<char> alpha;
char input;
char mo[5] = { 'a', 'e', 'i', 'o', 'u' };
void dfs(string now, int cnt, int idx, int m, int j) {
	if (cnt == L) {
		if (m >= 1 && j >= 2) {
			cout << now << "\n";
		}
		return;
	}
	if (idx >= C) {
		return;
	}
	for (int i = idx; i < C; i++) {
		string tmp = now;
		tmp = tmp + alpha[i];
		int flag = 0;
		for (int k = 0; k < 5; k++) {
			if (alpha[i] == mo[k]) {
				dfs(tmp, cnt + 1, i + 1, m + 1, j);
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			dfs(tmp, cnt + 1, i + 1, m, j + 1);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> input;
		alpha.push_back(input);
	}
	sort(alpha.begin(), alpha.end());
	for (int i = 0; i < C; i++) {
		string now = "";
		now = now + alpha[i];
		int flag = 0;
		for (int j = 0; j < 5; j++) {
			if (alpha[i] == mo[j]) {
				dfs(now, 1, i + 1, 1, 0);
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			dfs(now, 1, i + 1, 0, 1);
		}
	}
	return 0;
}