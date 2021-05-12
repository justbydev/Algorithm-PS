/*BOJ 17130*/
/*DFS Ȱ���� DP*/
/*dp[i][j]=(i, j)���� �ʹ����� ���� ��� ��� �ִ� ����*/
/*��, dp[i][j]=-1�� ��� (i, j)���� �ʹ����� ���� ��� ����*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<char>> map;
int N, M;
int sx, sy;
int dx[3] = { 1, 0, -1 };
int dy[3] = { 1, 1, 1 };
char input;
int dp[1000][1000];
int dfs_dp(int nowx, int nowy) {
	if (dp[nowx][nowy] != -2) {//������ �ѹ� �Դ� ���̶��
		return dp[nowx][nowy];
	}
	if (nowy == M - 1) {//������ ������ ���� ������ ���
		if (map[nowx][nowy] == 'O') {//�װ��� �ʹ��̶�� Ż�� ����
			return 0;
		}
		else {//�ʹ��� �ƴ϶� Ż�� �Ұ����̶� -1 return
			return -1;
		}
	}
	int ret = -1;
	for (int i = 0; i < 3; i++) {
		int nx = nowx + dx[i];
		int ny = nowy + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {//������ ����
			continue;
		}
		if (map[nx][ny] == '#') {//��
			continue;
		}
		int now = dfs_dp(nx, ny);
		if (now != -1) {//-1�� �ƴ϶�� ���� �ʹ����� ������ ��� �����Ѵٴ� ��
			if (ret == -1) {
				ret = now;
			}
			else {
				ret = max(ret, now);
			}
		}
	}
	if (ret == -1) {//�� ������ ���� �� �ʹ��� ���� ���
		if (map[nowx][nowy] == 'O') {//���� ���� ��ġ�� �ʹ��� ��� Ż�� ����
			ret = 0;
		}
	}
	else {//�� ������ ���� �� �ʹ� �ִ� ���
		if (map[nowx][nowy] == 'C') {//���� ���� ��ġ�� ����̶�� +1
			ret += 1;
		}
	}
	return dp[nowx][nowy] = ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<char> now;
		for (int j = 0; j < M; j++) {
			cin >> input;
			if (input == 'R') {
				sx = i; sy = j;
			}
			now.push_back(input);
			dp[i][j] = -2;//dp �迭�� ó���� -2�� ����
		}
		map.push_back(now);
	}
	cout << dfs_dp(sx, sy);
	return 0;
}