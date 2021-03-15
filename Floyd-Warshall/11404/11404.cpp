/*BOJ 11404*/
/*Floyd warshall*/
/*거쳐가는 노드가 기준*/
/*노드 개수가 아닌 실제 거쳐가는 노드 자체가 기준이 되는 것*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a, b, c;
int dist[101][101];
void floyd(void) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				if (dist[i][k] == 1e9 || dist[k][j] == 1e9) {
					continue;
				}
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			dist[i][j] = 1e9;
			if (i == j) {
				dist[i][j] = 0;
			}
		}
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 1e9) {
				cout << 0 << " ";
			}
			else {
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}