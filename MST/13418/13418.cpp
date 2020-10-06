#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, A, B, C;
vector<pair<int, int>> graph[1001];
int parent[1001];
int find(int vertex) {
	if (parent[vertex] == vertex) {
		return vertex;
	}
	return parent[vertex] = find(parent[vertex]);
}
int min_prim() {
	int res = 0;
	bool visit[1001];
	for (int i = 0; i <= N; i++) {
		visit[i] = false;
	}
	visit[0] = true;
	priority_queue<pair<int, pair<int, int>>> heap;
	for (int i = 0; i < graph[0].size(); i++) {
		pair<int, int> now = graph[0][i];
		int weight = now.second;
		int ed = now.first;
		heap.push({ -weight, {0, ed} });
	}
	while (!heap.empty()) {
		pair<int, pair<int, int>> now = heap.top();
		heap.pop();
		int weight = now.first;
		int st = now.second.first;
		int ed = now.second.second;
		int root_st = find(st);
		int root_ed = find(ed);
		if (root_st != root_ed) {
			res += (-weight);
			parent[root_st] = root_ed;
			int nw;
			if (visit[st] == false) {
				visit[st] = true;
				nw = st;
			}
			else {
				visit[ed] = true;
				nw = ed;
			}
			for (int i = 0; i < graph[nw].size(); i++) {
				pair<int, int> next = graph[nw][i];
				int nx_w = next.second;
				int nx_ed = next.first;
				if (visit[nx_ed] == false) {
					heap.push({ -nx_w, {nw, nx_ed} });
				}
			}
		}
	}
	return res;
}
int max_prim() {
	int res = 0;
	bool visit[1001];
	for (int i = 0; i <= N; i++) {
		visit[i] = false;
	}
	visit[0] = true;
	priority_queue<pair<int, pair<int, int>>> heap;
	for (int i = 0; i < graph[0].size(); i++) {
		pair<int, int> now = graph[0][i];
		int weight = now.second;
		int ed = now.first;
		heap.push({ weight, {0, ed} });
	}
	while (!heap.empty()) {
		pair<int, pair<int, int>> now = heap.top();
		heap.pop();
		int weight = now.first;
		int st = now.second.first;
		int ed = now.second.second;
		int root_st = find(st);
		int root_ed = find(ed);
		if (root_st != root_ed) {
			res += weight;
			parent[root_st] = root_ed;
			int nw;
			if (visit[st] == false) {
				visit[st] = true;
				nw = st;
			}
			else {
				visit[ed] = true;
				nw = ed;
			}
			for (int i = 0; i < graph[nw].size(); i++) {
				pair<int, int> next = graph[nw][i];
				int nx_w = next.second;
				int nx_ed = next.first;
				if (visit[nx_ed] == false) {
					heap.push({ nx_w, {nw, nx_ed} });
				}
			}
		}
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	cin >> A >> B >> C;
	graph[A].push_back({ B, 1 - C });
	graph[B].push_back({ A, 1 - C });
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		graph[A].push_back({ B, 1 - C });
		graph[B].push_back({ A, 1 - C });
	}
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	int best = min_prim();
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	int worst = max_prim();
	cout << worst * worst - best * best;
	return 0;
}