/*BOJ 1238*/
/*Dijkstra*/
/*inverse direction Dijkstra*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, M, X;
int st, ed, v;
int toX[1001];
int fromX[1001];
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> inverse_graph[1001];
void DJK(vector<pair<int, int>> G[], int choice) {
	priority_queue<pair<int, int>> heap;
	heap.push({ 0, X });
	while (!heap.empty()) {
		pair<int, int> now = heap.top();
		heap.pop();
		int nw_d = -now.first;
		int nw = now.second;
		for (int i = 0; i < G[nw].size(); i++) {
			int nxt_d = G[nw][i].second;
			int nxt = G[nw][i].first;
			if (choice == 0) {
				if (toX[nxt] == 987654321 || toX[nxt] > nw_d + nxt_d) {
					toX[nxt] = nw_d + nxt_d;
					heap.push({ -toX[nxt], nxt });
				}
			}
			else if (choice == 1) {
				if (fromX[nxt] == 987654321||fromX[nxt]>nw_d+nxt_d) {
					fromX[nxt] = nw_d + nxt_d;
					heap.push({ -fromX[nxt], nxt });
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> X;
	for (int i = 1; i <= M; i++) {
		cin >> st >> ed >> v;
		graph[st].push_back({ ed, v });
		inverse_graph[ed].push_back({ st, v });
	}
	for (int i = 1; i <= 1000; i++) {
		if (i == X) {
			toX[i] = fromX[i] = 0;
		}
		else {
			toX[i] = fromX[i] = 987654321;
		}
	}
	DJK(inverse_graph, 0);
	DJK(graph, 1);
	int res = 0;
	for (int i = 1; i <= N; i++) {
		res = max(res, toX[i] + fromX[i]);
	}
	cout << res;
	return 0;
}