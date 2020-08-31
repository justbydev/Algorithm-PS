#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[500][500];
vector<pair<int, int>> arr;
int N, r, c;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		arr.push_back({ r, c });
	}
	for (int i = 0; i <= N - 2; i++) {
		dp[i][i + 1] = arr[i].first*arr[i].second*arr[i + 1].second;
	}
	int st, ed, gap;
	gap = 2;
	while (1) {
		st = 0; ed = st + gap;
		if (ed >= N) {
			break;
		}
		while (1) {
			if (ed >= N) {
				break;
			}
			for (int k = st; k < ed; k++) {
				if (k == st) {
					dp[st][ed] = dp[st][k] + dp[k + 1][ed] + arr[st].first*arr[k].second*arr[ed].second;
				}
				else {
					dp[st][ed] = min(dp[st][ed], dp[st][k] + dp[k + 1][ed] + arr[st].first*arr[k].second*arr[ed].second);
				}
			}

			st++; ed++;
		}
		gap++;
	}
	cout << dp[0][N - 1];
	return 0;
}