#include<iostream>
#include<vector>
using namespace std;
int N, M, A, B, C;
vector<pair<int, pair<int, int>>> edge;
long long int dist[501];
int bellman_ford(void) {
	for (int i = 0; i <= 500; i++) {
		dist[i] = 1e9;
	}
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int time = edge[j].first;
			int st = edge[j].second.first;
			int ed = edge[j].second.second;
			if (dist[st] == 1e9) {
				continue;
			}
			if (dist[ed] > dist[st] + time) {
				if (i == N) {
					return -1;
				}
				dist[ed] = dist[st] + time;
			}
		}
	}
	return 1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A >> B >> C;
		edge.push_back({ C, {A, B} });
	}
	int flag = bellman_ford();
	if (flag == -1) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == 1e9) {
				cout << -1 << "\n";
			}
			else {
				cout << dist[i] << "\n";
			}
		}
	}
	return 0;
}