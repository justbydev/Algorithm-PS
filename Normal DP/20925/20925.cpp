/*BOJ 20925*/
/*DP*/
/*2-dimensional DP*/
/*dp[time][locate]=>현재 time이고 locate에 있을 때의 경험치의 최댓값*/
#include<iostream>
#include<algorithm>
using namespace std;
int N, T;
int dist[200][200];
int dp[1001][200];
int minimum[200];
int experience[200];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> minimum[i] >> experience[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
		}
	}
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j < 200; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (minimum[i] == 0) {
			dp[0][i] = 0;
		}
	}
	for (int i = 1; i <= T; i++) {//i is time
		for (int j = 0; j < N; j++) {//j is now locate
			for (int k = 0; k < N; k++) {//k is just before locate
				if (j == k) {//계속 같은 위치에 머무르는 경우
					if (dp[i - 1][j] >= 0) {
						dp[i][j] = max(dp[i][j], dp[i - 1][j] + experience[j]);
					}
				}
				else {//다른 곳으로 이동한 경우
					int time = i - dist[k][j];
					if (time >= 0) {//이동할 때 걸리는 시간 측정
						if (dp[time][k] >= 0 && dp[time][k] >= minimum[j]) {//이전 위치에 도착한 경우 & 이전 위치에서 현재위치로 올때 최소 경험치 조건 만족 여부
							dp[i][j] = max(dp[i][j], dp[time][k]);
						}
					}
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		res = max(res, dp[T][i]);
	}
	cout << res;
	return 0;
}