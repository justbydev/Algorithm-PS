/*BOJ 10776*/
/*Dijkstra*/
/*���ͽ�Ʈ�� �ᱹ DP��� ���� ���*/
/*���ͽ�Ʈ�� Ư¡�� �̹� ª�� �Ÿ��� ���ŵ� �Ϳ� ���ؼ��� �ٸ� ��θ� Ž������ �ʴ´�*/
/*������ �� ������ height��� �ٸ� ��Ұ� �ֱ� ������ height�� ����� 2���� DP �迭�� ����� �־�� �Ѵ�*/
/*����, �������� �� ���� �׻� minheap ���� �̾��� �Ϳ� ���ؼ� ������*/
/*���� ���� ���� minheap���� ���� ���� ���������� ���� ���� ª�� ���̶�� ���ͽ�Ʈ�� Ư¡ �������*/
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