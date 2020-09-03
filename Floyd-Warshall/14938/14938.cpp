#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, r;
int item[101];
int a, b, c;
int dist[101][101];
void floyd(void) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == k || i == j || j == k) {
					continue;
				}
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = 1e9;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 1; i <= r; i++) {
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	floyd();
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m) {
				now += item[j];
			}
		}
		res = max(res, now);
	}
	cout << res;
	return 0;
}