#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N, M;
int indegree[32001];
int st, ed;
queue<int> node;
vector<int> res;
vector<int> graph[32001];
void topological(void) {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			node.push(i);
		}
	}
	while (!node.empty()) {
		int now = node.front();
		node.pop();
		res.push_back(now);
		for (int nx : graph[now]) {
			indegree[nx]--;
			if (indegree[nx] == 0) {
				node.push(nx);
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> st >> ed;
		graph[st].push_back(ed);
		indegree[ed]++;
	}
	topological();
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}