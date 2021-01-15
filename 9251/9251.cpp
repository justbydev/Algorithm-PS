/*BOJ 9251*/
/*LCS dp*/
/*two String A, B*/
/*if A[i]==B[j], dp[i][j]=dp[i-1][j-1]+1*/
/*else, dp[i][j]=max(dp[i-1][j], dp[i][j-1]*/
/*dp[i-1][j-1]<=dp[i][j-1], dp[i-1][j]*/
/*|dp[i][j-1]-dp[i-1][j-1]|<=1*/
/*|dp[i-1][j]-dp[i-1][j-1]|<=1*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string A, B;
int dp[1000][1000];
int A_len, B_len;
void LCS_dp(void) {
	int flag = 0;
	for (int i = 0; i < A_len; i++) {
		if (flag == 1) {
			dp[i][0] = 1;
			continue;
		}
		if (A[i] == B[0]) {
			flag = 1;
			dp[i][0] = 1;
		}
		else {
			dp[i][0] = 0;
		}
	}
	flag = 0;
	for (int i = 0; i < B_len; i++) {
		if (flag == 1) {
			dp[0][i] = 1;
			continue;
		}
		if (A[0] == B[i]) {
			flag = 1;
			dp[0][i] = 1;
		}
		else {
			dp[0][i] = 0;
		}
	}
	for (int i = 1; i < A_len; i++) {
		for (int j = 1; j < B_len; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> A >> B;
	A_len = A.length();
	B_len = B.length();
	LCS_dp();
	cout << dp[A_len - 1][B_len - 1];
	return 0;
}