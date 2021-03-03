/*BOJ 20925*/
/*DP*/
/*2-dimensional DP*/
/*dp[time][locate]=>���� time�̰� locate�� ���� ���� ����ġ�� �ִ�*/
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
				if (j == k) {//��� ���� ��ġ�� �ӹ����� ���
					if (dp[i - 1][j] >= 0) {
						dp[i][j] = max(dp[i][j], dp[i - 1][j] + experience[j]);
					}
				}
				else {//�ٸ� ������ �̵��� ���
					int time = i - dist[k][j];
					if (time >= 0) {//�̵��� �� �ɸ��� �ð� ����
						if (dp[time][k] >= 0 && dp[time][k] >= minimum[j]) {//���� ��ġ�� ������ ��� & ���� ��ġ���� ������ġ�� �ö� �ּ� ����ġ ���� ���� ����
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