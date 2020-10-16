#include<iostream>
#include<vector>
using namespace std;
int N, a, p;
char t;
int have[123457];
bool visit[123457];
vector<int> graph[123457];
long long int dfs(int now) {
	long long int sheep = 0;
	visit[now] = true;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (visit[next]) {
			continue;
		}
		sheep += dfs(next);
	}
	if (have[now] >= 0) {
		return sheep + have[now];
	}
	else if (have[now] < 0) {
		sheep += have[now];
		if (sheep <= 0) {
			return 0;
		}
		else {
			return sheep;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	have[1] = 0;
	for (int i = 2; i <= N; i++) {
		cin >> t >> a >> p;
		graph[i].push_back(p);
		graph[p].push_back(i);
		if (t == 'S') {
			have[i] = a;
		}
		else if (t == 'W') {
			have[i] = -a;
		}
	}
	for (int i = 1; i <= N; i++) {
		visit[i] = false;
	}
	cout << dfs(1);
	return 0;
}