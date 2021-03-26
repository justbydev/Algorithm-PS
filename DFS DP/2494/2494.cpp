/*BOJ 2494*/
/*DP*/
/*DP를 사용해야 하는 건 알겠는데 dp 배열을 어떻게 구성해야 할지가 keypoint*/
/*결국 위 회전의 영향을 받는 건 왼쪽으로 회전하는 것 뿐이기 때문이므로 그거 기준*/
/*또한, 왼쪽 회전은 0~9까지만이기 때문에 dp 배열 형성 가능*/
/*dp[i][j]=i번째 나사를 위 나사의 영향으로 왼쪽으로 j번 회전시켰을 때*/
/*cnt[i][j]=i번째 나사가 위 나사 영향으로 왼쪽으로때의 숫자 j일때 i번째 나사 회전한 값*/
/*DP 뿐 아니라 trace까지 해야 하는 문제*/
#include<iostream>
using namespace std;
int N, before[10001], want[10001];
char tmp;
int dp[10000][10];
int cnt[10000][10];
int dfs_dp(int idx, int leftturn) {
	if (idx == N) {
		return 0;
	}
	if (dp[idx][leftturn] != -1) {
		return dp[idx][leftturn];
	}
	int ret = 0;
	int now_num = (before[idx] + leftturn ) % 10;//위의 것에 의해 왼쪽 회전 후 숫자
	int left, right;
	if (want[idx] < now_num) {
		left = want[idx] - now_num + 10;
		right = now_num - want[idx];
	}
	else if (want[idx] >= now_num) {
		left = want[idx] - now_num;
		right = now_num - want[idx] + 10;
	}
	int left_cnt=left+dfs_dp(idx + 1, (leftturn+left)%10);//왼쪽으로 돌렸을 때의 최솟값
	int right_cnt=right+dfs_dp(idx + 1, leftturn);//오른쪽으로 돌렸을 때의 최솟값
	if (left_cnt < right_cnt) {
		ret = left_cnt;
		cnt[idx][now_num] = left;
	}
	else {
		ret = right_cnt;
		cnt[idx][now_num] = -right;
	}
	return dp[idx][leftturn] = ret;
}
void trace(int idx, int leftturn) {
	if (idx == N) {
		return;
	}
	int now_num = (before[idx] + leftturn) % 10;
	cout << idx + 1 << " " << cnt[idx][now_num] << "\n";
	if (cnt[idx][now_num] < 0) {
		trace(idx + 1, leftturn);
	}
	else {
		trace(idx + 1, (leftturn + cnt[idx][now_num] + 10) % 10);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		before[i] = tmp - '0';
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		want[i] = tmp - '0';
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = -1;
		}
	}
	dfs_dp(0, 0);
	cout << dp[0][0] << "\n";
	trace(0, 0);
	return 0;
}