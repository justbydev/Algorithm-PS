#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N, M;
int U, V, P;
int S, D;
int graph[500][500];
int dist[500];
vector<int> before_vertex[500];//각각의 vertex에 오기 전 거친 바로 전 vertex를 저장하는 vector
void dijk(void) {
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	heap.push({ 0, S });
	while (!heap.empty()) {
		pair<int, int> now = heap.top();
		heap.pop();
		int nw_w = now.first;
		int nw = now.second;
		for (int i = 0; i < N; i++) {
			if (nw == i || graph[nw][i] == 0) {
				continue;
			}
			if (dist[i] == -1) {//아직 한번도 방문하지 않은 vertex는 지금 방문한 경로가 최소값
				dist[i] = nw_w + graph[nw][i];
				heap.push({ dist[i], i });
				before_vertex[i].push_back(nw);
			}
			else if (dist[i] == nw_w + graph[nw][i]) {//만약 기존 경로와 같은 cost를 가진 다른 경로가 있는 경우 이거도 또다른 최단경로이므로 포함
				before_vertex[i].push_back(nw);
			}
			else if (dist[i] > nw_w + graph[nw][i]) {//기존에 있던 경로보다 더 짧은 경로가 나오면 기존 경로는 더 이상 최단 경로가 아니므로 before_vertex를 clear하고 새롭게 push
				dist[i] = nw_w + graph[nw][i];
				heap.push({ dist[i], i });
				before_vertex[i].clear();
				before_vertex[i].push_back(nw);
			}
		}
	}
}
void trace_back(int now) {//도착지점부터 역으로 출발지점까지 경로 탐색
	if (now == S) {
		return;
	}
	for (int before : before_vertex[now]) {
		graph[before][now] = 0;
		trace_back(before);
	}
}
void almost_dijk(void) {
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	heap.push({ 0, S });
	while (!heap.empty()) {
		pair<int, int> now = heap.top();
		heap.pop();
		int nw_w = now.first;
		int nw = now.second;
		for (int i = 0; i < N; i++) {
			if (i == nw || graph[nw][i] == 0) {
				continue;
			}
			if (dist[i] == -1 || dist[i] > nw_w + graph[nw][i]) {
				dist[i] = nw_w + graph[nw][i];
				heap.push({ dist[i], i });
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}
		cin >> S >> D;
		for (int i = 1; i <= M; i++) {
			cin >> U >> V >> P;
			graph[U][V] = P;
		}
		memset(dist, -1, sizeof(dist));
		dijk();
		trace_back(D);
		memset(dist, -1, sizeof(dist));
		almost_dijk();
		cout << dist[D] << "\n";
		for (int i = 0; i < 500; i++) {
			memset(graph[i], 0, sizeof(int) * 500);
		}
		for (int i = 0; i < 500; i++) {
			before_vertex[i].clear();
		}
	}
	return 0;
}