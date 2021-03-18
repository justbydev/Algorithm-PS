/*BOJ 10776*/
/*Dijkstra*/
/*다익스트라도 결국 DP라는 것을 기억*/
/*다익스트라 특징상 이미 짧은 거리로 갱신된 것에 대해서는 다른 경로를 탐색하지 않는다*/
/*하지만 이 문제는 height라는 다른 요소가 있기 때문에 height를 고려해 2차원 DP 배열을 만들어 주어야 한다*/
/*또한, 도착지에 올 때는 항상 minheap 에서 뽑아진 것에 대해서 따진다*/
/*같은 점에 대해 minheap에서 가장 먼저 뽑혀나오는 것이 가장 짧은 것이라는 다익스트라 특징 기억하자*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int K, N, M, a, b, t, h;
int A, B;
typedef struct _info {
	int end;
	int time;
	int height;
}info;
typedef struct _heap {
	int vertex;
	int total_t;
	int total_h;
}heap;
struct compare {
	bool operator()(heap& first, heap& second) {
		return first.total_t > second.total_t;
	}
};
vector<info> graph[2001];
int dist[2001][201];
int dijkstra(void) {
	dist[A][0] = 0;
	priority_queue<heap, vector<heap>, compare> minheap;
	minheap.push({ A, 0, 0 });
	while (!minheap.empty()) {
		int now = minheap.top().vertex;
		int now_t = minheap.top().total_t;
		int now_h = minheap.top().total_h;
		minheap.pop();
		if (now == B) {
			return now_t;
		}
		if (dist[now][now_h] < now_t) {
			continue;
		}
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].end;
			int next_t = graph[now][i].time;
			int next_h = graph[now][i].height;
			if (now_h + next_h >= K) {
				continue;
			}
			if (dist[next][now_h + next_h] > now_t + next_t) {
				dist[next][now_h + next_h] = now_t + next_t;
				minheap.push({ next, now_t + next_t, now_h + next_h });
			}
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> K >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t >> h;
		graph[a].push_back({ b, t, h });
		graph[b].push_back({ a, t, h });
	}
	cin >> A >> B;
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 200; j++) {
			dist[i][j] = 1e9;
		}
	}
	cout << dijkstra();
	return 0;
}