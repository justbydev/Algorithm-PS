/*BOJ 2073*/
/*DP*/
/*거리를 기준으로 하는 DP*/
/*이미 정해진 거리가 나와있고 세부적인 거리의 합으로 목표를 이루는 것이므로*/
/*거리로 DP*/
/*또한, 사용 개수를 한개씩 늘리면서 파악*/
/*새로 늘린 것은 무조건 사용한다는 전제*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int D, P;
long long int L, C;
typedef struct _info {
	long long int L;
	long long int C;
}info;
vector<info> flow;
long long int dp[100001];//거리 기준의 dp, dp[i]=i의 거리를 만들 때의 최솟값
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> D >> P;
	for (int i = 1; i <= P; i++) {
		cin >> L >> C;
		flow.push_back({ L, C });
	}
	for (int i = 0; i <= D; i++) {
		dp[i] = -1;
	}
	dp[0] = 0;
	for (int pipe = 0; pipe < P; pipe++) {
		for (int length = D; length >=1; length--) {
			if (flow[pipe].L > length) {
				continue;
			}
			int remain = length - flow[pipe].L;
			if (remain == 0) {
				if (dp[length] == -1) {
					dp[length] = flow[pipe].C;
				}
				else {
					dp[length] = max(dp[length], flow[pipe].C);
				}
			}
			else {
				if (dp[remain] != -1) {
					dp[length] = max(dp[length], min(dp[remain], flow[pipe].C));
				}
			}
		}
	}
	
	cout << dp[D];
	return 0;
}