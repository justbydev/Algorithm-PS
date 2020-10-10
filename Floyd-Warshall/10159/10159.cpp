#include<iostream>
using namespace std;
int check[101][101];
int N, M, a, b;
void floyd_warshall(void) {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) {
					continue;
				}
				if (check[i][k] == 1 && check[k][j] == 1) {
					check[i][j] = 1;
				}
				else if (check[i][k] == -1 && check[k][j] == -1) {
					check[i][j] = -1;
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				check[i][j] = 2;
			}
			else {
				check[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		check[a][b] = 1;
		check[b][a] = -1;
	}
	floyd_warshall();
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (check[i][j] == 0) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}