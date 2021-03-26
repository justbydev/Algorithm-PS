/*BOJ 2494*/
/*DP*/
/*DP�� ����ؾ� �ϴ� �� �˰ڴµ� dp �迭�� ��� �����ؾ� ������ keypoint*/
/*�ᱹ �� ȸ���� ������ �޴� �� �������� ȸ���ϴ� �� ���̱� �����̹Ƿ� �װ� ����*/
/*����, ���� ȸ���� 0~9�������̱� ������ dp �迭 ���� ����*/
/*dp[i][j]=i��° ���縦 �� ������ �������� �������� j�� ȸ�������� ��*/
/*cnt[i][j]=i��° ���簡 �� ���� �������� �������ζ��� ���� j�϶� i��° ���� ȸ���� ��*/
/*DP �� �ƴ϶� trace���� �ؾ� �ϴ� ����*/
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
	int now_num = (before[idx] + leftturn ) % 10;//���� �Ϳ� ���� ���� ȸ�� �� ����
	int left, right;
	if (want[idx] < now_num) {
		left = want[idx] - now_num + 10;
		right = now_num - want[idx];
	}
	else if (want[idx] >= now_num) {
		left = want[idx] - now_num;
		right = now_num - want[idx] + 10;
	}
	int left_cnt=left+dfs_dp(idx + 1, (leftturn+left)%10);//�������� ������ ���� �ּڰ�
	int right_cnt=right+dfs_dp(idx + 1, leftturn);//���������� ������ ���� �ּڰ�
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