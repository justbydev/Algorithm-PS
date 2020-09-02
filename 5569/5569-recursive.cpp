#include<iostream>
#define D 100000
using namespace std;
int w, h;
int dp[100][100][2][2];
int dfs_dp(int x, int y, int dir, int before_dir) {
	if (x < 0 || x >= h || y < 0 || y >= w) {
		return 0;
	}
	if (x == h - 1 && y == w - 1) {
		return 1;
	}
	if (before_dir == -1) {
		if (dir == 0) {
			return (dfs_dp(x, y + 1, dir, dir) % D +
				dfs_dp(x + 1, y, 1, 0) % D) % D;
		}
		else if (dir == 1) {
			return (dfs_dp(x + 1, y, dir, dir) % D +
				dfs_dp(x, y + 1, 0, 1) % D) % D;
		}
	}
	else {
		if (dp[x][y][dir][before_dir]) {
			return dp[x][y][dir][before_dir];
		}
		if (dir == 0) {
			if (dir == before_dir) {
				return dp[x][y][dir][before_dir] = (dfs_dp(x, y + 1, 0, 0) % D +
					dfs_dp(x + 1, y, 1, 0) % D) % D;
			}
			else {
				return dp[x][y][dir][before_dir] = dfs_dp(x, y + 1, 0, 0) % D;
			}
		}
		else if (dir == 1) {
			if (dir == before_dir) {
				return dp[x][y][dir][before_dir] = (dfs_dp(x, y + 1, 0, 1) % D +
					dfs_dp(x + 1, y, 1, 1) % D) % D;
			}
			else {
				return dp[x][y][dir][before_dir] = dfs_dp(x + 1, y, 1, 1) % D;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> w >> h;
	cout << (dfs_dp(0, 1, 0, -1) % D + dfs_dp(1, 0, 1, -1) % D) % D;
	return 0;
}