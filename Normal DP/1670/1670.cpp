/*BOJ 1670*/
/*DP*/
/*�ߺ��Ǵ� ���� ����*/
/*�Ѹ��� �ٸ� ����� �Ǽ��ϸ� �� ���� ���� ����, ������ ������ ����*/
/*����, ������ ������ ��� ���� ���� �̹� ����� dp ���� ���ϸ� ��*/
/*�Ѹ� ������ ��� �� ����� ���ؼ��� �ϸ� �Ǵ� ������ �ٸ� ��� �������� �� ���� �̹� �ߺ��Ǳ� ������*/
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