/*BOJ 1197*/
/*MST*/
/*using Kruskal*/
#include<iostream>
#include<queue>
using namespace std;
int V, E, A, B, C;
int parent[10001];
priority_queue<pair<int, pair<int, int>>> edge;
int find_parent(int node) {
	if (node == parent[node]) {
		return node;
	}
	return parent[node] = find_parent(parent[node]);
}
int kruskal(void) {
	int cnt = 1;
	int res = 0;
	pair<int, pair<int, int>> now = edge.top();
	edge.pop();
	res += (-now.first);
	parent[now.second.second] = now.second.first;
	while (cnt < V - 1) {
		pair<int, pair<int, int>> now = edge.top();
		edge.pop();
		int dist = -now.first;
		int st = now.second.first;
		int ed = now.second.second;
		int parent_st = find_parent(st);
		int parent_ed = find_parent(ed);
		if (parent_st != parent_ed) {
			parent[parent_st] = parent_ed;
			res += dist;
			cnt++;
		}
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> V >> E;
	for (int i = 1; i <= E; i++) {
		cin >> A >> B >> C;
		edge.push({ -C, {A, B} });
	}
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	cout<<kruskal();
	return 0;
}