#include<iostream>
#include<vector>
using namespace std;
vector<int> graph[501];
bool parent[501];
bool visit[501];
int n, m, a, b, c;
int dfs(int before, int now) {
	if (visit[now] == true) {
		return 1;
	}
	visit[now] = true;
	int flag = 0;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (visit[next] == true && next == before) {
			continue;
		}
		flag += dfs(now, next);
	}
	if (flag > 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	c = 1;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			parent[i] = false;
			visit[i] = false;
			graph[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
			parent[a] = true;
			parent[b] = true;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false) {
				if (parent[i] == false) {
					cnt++;
					visit[i] = true;
				}
				else {
					if (dfs(-1, i) == 0) {
						cnt++;
					}
				}
			}
		}
		cout << "Case " << c << ": ";
		if (cnt == 0) {
			cout << "No trees." << "\n";
		}
		else if (cnt == 1) {
			cout << "There is one tree." << "\n";
		}
		else {
			cout << "A forest of " << cnt << " trees." << "\n";
		}
		c++;
	}
	return 0;
}