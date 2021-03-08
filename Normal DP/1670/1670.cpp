/*BOJ 1670*/
/*DP*/
/*중복되는 것을 주의*/
/*한명이 다른 사람과 악수하면 그 선을 경계로 왼쪽, 오른쪽 구역이 생김*/
/*왼쪽, 오른쪽 구역의 사람 수에 대해 이미 저장된 dp 값을 곱하면 됨*/
/*한명 기준을 잡고 그 사람에 대해서만 하면 되는 이유는 다른 사람 기준으로 한 것은 이미 중복되기 때문에*/
#include<iostream>
using namespace std;
int N;
long long int dp[10001];
long long int MoD = 987654321;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i <= 1000; i++) {
		dp[i] = -1;
	}
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= N; i+=2) {
		dp[i] = 0;
		for (int j = 0; j <= i - 2; j += 2) {
			int left = j;
			int right = i - j - 2;
			dp[i] += (dp[left] * dp[right]) % MoD;
			dp[i] = dp[i] % MoD;
		}
	}
	cout << dp[N];
	return 0;
}