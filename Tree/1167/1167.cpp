/*BOJ 1167*/
/*Diameter of Tree*/
/*DFS of Tree*/
/*visit all path in Tree*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int V;
vector<pair<int, int>> tree[100001];
int node;
int num, dist;
bool visit[100001];
int res = 0;
int tree_dfs(int now) {
	int first, second;
	first = second = 0;
	visit[now] = true;
	for (int i = 0; i < tree[now].size(); i++) {
		pair<int, int> tmp = tree[now][i];
		int next = tmp.first;
		int n_dist = tmp.second;
		if (visit[next]) {
			continue;
		}
		visit[next] = true;
		int nxt = n_dist + tree_dfs(next);
		if (first == 0) {
			first = nxt;
		}
		else {
			int mx = max(first, max(nxt, second));
			int mn = min(first, min(nxt, second));
			second = (first + second + nxt) - mx - mn;
			first = mx;
		}
	}
	res = max(res, first + second);
	return first;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> V;
	for (int i = 1; i <= V; i++) {
		cin >> node;
		visit[node] = false;
		while (1) {
			cin >> num;
			if (num == -1) {
				break;
			}
			cin >> dist;
			tree[node].push_back({ num, dist });
		}
	}
	visit[1] = true;
	tree_dfs(1);
	cout << res;
	return 0;
}