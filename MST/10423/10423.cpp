#include<iostream>
#include<queue>
using namespace std;
int N, M, K;
int u, v, w, input, first;
int res = 0;
int parent[1001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
	greater<pair<int, pair<int, int>>>> heap;
int find(int node) {
	if (parent[node] == node) {
		return node;
	}
	return parent[node] = find(parent[node]);
}
void kruskal(void) {
	while (!heap.empty()) {
		pair<int, pair<int, int>> now = heap.top();
		heap.pop();
		int w = now.first; int st = now.second.first; int ed = now.second.second;
		int root_st = find(st);
		int root_ed = find(ed);
		if (root_st == root_ed) {
			continue;
		}
		res += w;
		parent[root_st] = root_ed;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= 1000; i++) {
		parent[i] = i;
	}
	cin >> first;
	for (int i = 2; i <= K; i++) {
		cin >> input;
		parent[input] = first;
	}
	for (int i = 1; i <= M; i++) {
		cin >> u >> v >> w;
		heap.push({ w, {u, v} });
	}
	kruskal();
	cout << res;
	return 0;
}