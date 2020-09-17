#include<iostream>
#include<cstring>
using namespace std;
int N, M, H;
int a, b;
bool ladder[31][11];
int res = 4;
int ladder_progress(void) {
	for (int i = 1; i <= N; i++) {
		int garo = 1;
		int sero = i;
		while (1) {
			if (garo > H) {
				break;
			}
			if (ladder[garo][sero]) {
				sero++;
			}
			else if (sero != 1 && ladder[garo][sero - 1] == true) {
				sero--;
			}
			garo++;
		}
		if (sero != i) {
			return -1;
		}
	}
	return 1;
}
void dfs(int garo, int sero, int new_cnt, int cnt) {
	if (res != 4) {
		return;
	}
	if (new_cnt == cnt) {
		if (ladder_progress() == 1) {
			res = cnt;
		}
		return;
	}
	for (int i = garo; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (i == garo && j <= sero) {
				continue;
			}
			if (ladder[i][j] || ladder[i][j - 1]||ladder[i][j+1]) {
				continue;
			}
			ladder[i][j] = true;
			dfs(i, j, new_cnt + 1, cnt);
			ladder[i][j] = false;
			if (res != 4) {
				return;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> H;
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 10; j++) {
			ladder[i][j] = false;
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		ladder[a][b] = true;
	}
	for (int i = 0; i < 4; i++) {
		dfs(1, 0, 0, i);
		if (res != 4) {
			cout << res;
			return 0;
		}
	}
	cout << -1;
	return 0;
}