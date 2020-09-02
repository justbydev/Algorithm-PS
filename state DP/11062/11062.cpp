#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int dp[1000][1000];
int T, N, input;
vector<int> subsum;
vector<int> num;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int sm = 0;
		for (int j = 0; j < N; j++) {
			cin >> input;
			num.push_back(input);
			sm += input;
			subsum.push_back(sm);
		}
		if (N == 1) {
			cout << num[0] << "\n";
		}
		else if (N == 2) {
			cout << max(num[0], num[1]) << "\n";
		}
		else {
			for (int i = 0; i < N; i++) {
				dp[i][i] = num[i];
			}
			for (int i = 0; i < N - 1; i++) {
				dp[i][i + 1] = max(num[i], num[i + 1]);
			}
			for (int gap = 2; gap < N; gap++) {
				for (int st = 0, ed = st + gap; ed < N; st++, ed++) {
					dp[st][ed] = max(num[st] + (subsum[ed] - subsum[st + 1] + num[st + 1]) - dp[st + 1][ed],
						num[ed] + (subsum[ed - 1] - subsum[st] + num[st]) - dp[st][ed - 1]);
				}
			}
			cout << dp[0][N - 1] << "\n";
		}
		num.clear();
		subsum.clear();
		for (int i = 0; i < N; i++) {
			memset(dp[i], 0, sizeof(int)*N);
		}
	}
	return 0;
}