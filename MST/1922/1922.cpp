/*BOJ 1922*/
/*MST*/
/*Kruskal*/
/*find cycle using union-find*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, a, b, c;
priority_queue<pair<int, pair<int,int>>> minheap;
int parent[1001];
int res = 0;
int find_parent(int now) {
	if (parent[now] == -1) {
		return now;
	}
	return parent[now] = find_parent(parent[now]);
}
void Kruskal(void) {
	while (!minheap.empty()) {
		pair<int, pair<int, int>> tmp = minheap.top();
		minheap.pop();
		int weight = tmp.first;
		int first = tmp.second.first;
		int second = tmp.second.second;
		int parent_first = find_parent(first);
		int parent_second = find_parent(second);
		if (parent_first != parent_second) {
			parent[parent_first] = parent_second;
			res += (-weight);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c;
		minheap.push({ -c,  {a, b} });
	}
	for (int i = 1; i <= 1000; i++) {
		parent[i] = -1;
	}
	Kruskal();
	cout << res;
	return 0;
}