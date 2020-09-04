#include<iostream>
#include<string>
using namespace std;
bool dp[50][50][50][3][3];
string S;
bool dfs(int A, int B, int C, string now) {
	if (A == 0 && B == 0 && C == 0) {
		cout << now;
		return true;
	}
	if (now.length() == 1) {
		if (A >= 1) {
			if (dfs(A - 1, B, C, now + 'A')) {
				return true;
			}
		}
		if (B >= 1 && now[0] != 'B') {
			if (dfs(A, B - 1, C, now + 'B')) {
				return true;
			}
		}
		if (C >= 1 && now[0] != 'C') {
			if (dfs(A, B, C - 1, now + 'C')) {
				return true;
			}
		}
	}
	else {
		int before = now[now.length() - 1] - 'A';
		int be_before = now[now.length() - 2] - 'A';
		if (dp[A][B][C][before][be_before]) {
			return false;
		}
		dp[A][B][C][before][be_before] = true;
		if (A >= 1) {
			if (dfs(A - 1, B, C, now + 'A')) {
				return true;
			}
		}
		if (B >= 1 && before != 1) {
			if (dfs(A, B - 1, C, now + 'B')) {
				return true;
			}
		}
		if (C >= 1 && before != 2 && be_before != 2) {
			if (dfs(A, B, C - 1, now + 'C')) {
				return true;
			}
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> S;
	int A, B, C;
	A = B = C = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'A')A++;
		else if (S[i] == 'B')B++;
		else if (S[i] == 'C')C++;
	}
	if (S.length() == 1) {
		cout << S;
	}
	else if (S.length() == 2) {
		if (B >= 2 || C >= 2) {
			cout << -1;
		}
		else {
			cout << S;
		}
	}
	else {
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				for (int k = 0; k < 50; k++) {
					for (int a = 0; a < 3; a++) {
						for (int b = 0; b < 3; b++) {
							dp[i][j][k][a][b] = false;
						}
					}
				}
			}
		}
		bool check = false;
		if (A >= 1) {
			check = dfs(A - 1, B, C, "A");
		}
		if (B >= 1 && check == false) {
			check = dfs(A, B - 1, C, "B");
		}
		if (C >= 1 && check == false) {
			check = dfs(A, B, C - 1, "C");
		}
		if (check == false) {
			cout << -1;
		}
	}
	return 0;
}