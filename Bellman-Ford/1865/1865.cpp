#include<iostream>
#include<vector>
using namespace std;
long long int dist[501];
int TC;
int N, M, W, S, E, T;
vector<pair<int, pair<int, int>>> edge;
int bellman_ford(void) {
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int time = edge[j].first;
			int st = edge[j].second.first;
			int ed = edge[j].second.second;
			if (dist[ed] > dist[st] + time) {
				if (i == N) {
					return 0;
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
	cin >> TC;
	for (int t = 0; t < TC; t++) {
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			edge.push_back({ T, {S, E} });
			edge.push_back({ T, {E, S} });
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			edge.push_back({ -T, {S, E} });
		}
		for (int i = 0; i <= 500; i++) {
			dist[i] = 1e9;
		}
		if (bellman_ford()) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
		edge.clear();
	}
	return 0;
}