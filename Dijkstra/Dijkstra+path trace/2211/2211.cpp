/*BOJ 2211*/
/*Dijkstra*/
/*path of Dijkstra*/
/*시작점을 제외한 모든 점은 반드시 단 1개의 이전 점을 가진다*/
/*그래프의 정점의 개수가 N개라면 다익스트라 결과 N-1개의 간선을 지난다*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int A, B, C;
vector<pair<int, int>> graph[1001];
int dijk[1001];
bool visit[1001];
int before[1001];
void dijkstra(void) {
	priority_queue<pair<int, int>> minheap;
	dijk[1] = 0;
	minheap.push({ 0, 1 });
	while (!minheap.empty()) {
		pair<int, int> now_tmp = minheap.top();
		minheap.pop();
		int now_dist = -now_tmp.first;
		int now_idx = now_tmp.second;
		visit[now_idx] = true;
		for (int i = 0; i < graph[now_idx].size(); i++) {
			int next_idx = graph[now_idx][i].first;
			int next_dist = graph[now_idx][i].second;
			if (!visit[next_idx]) {
				if (dijk[next_idx] == -1||dijk[next_idx]>now_dist+next_dist) {
					dijk[next_idx] = now_dist + next_dist;
					minheap.push({ -dijk[next_idx], next_idx });
					before[next_idx] = now_idx;
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		graph[A].push_back({ B, C });
		graph[B].push_back({ A, C });
	}
	for (int i = 1; i <= N; i++) {
		dijk[i] = -1;
		visit[i] = false;
	}
	dijkstra();
	cout << N - 1 << "\n";
	for (int i = 2; i <= N; i++) {
		cout << i << " " << before[i] << "\n";
	}
	return 0;
}