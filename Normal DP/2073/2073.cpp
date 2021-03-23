/*BOJ 2073*/
/*DP*/
/*�Ÿ��� �������� �ϴ� DP*/
/*�̹� ������ �Ÿ��� �����ְ� �������� �Ÿ��� ������ ��ǥ�� �̷�� ���̹Ƿ�*/
/*�Ÿ��� DP*/
/*����, ��� ������ �Ѱ��� �ø��鼭 �ľ�*/
/*���� �ø� ���� ������ ����Ѵٴ� ����*/
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
long long int dp[100001];//�Ÿ� ������ dp, dp[i]=i�� �Ÿ��� ���� ���� �ּڰ�
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