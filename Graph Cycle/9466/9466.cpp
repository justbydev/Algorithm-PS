#include<iostream>
using namespace std;
int T, n;
int num;
int want[100001];
bool visit[100001];
int group[100001];
int dfs(int st, int now) {
	if (visit[now]) {
		if (group[now] == 0) {
			return now;
		}
		else {
			return -1;
		}
	}
	visit[now] = true;
	int flag = dfs(st, want[now]);
	if (flag == -1) {
		group[now] = -1;
		return -1;
	}
	else {
		group[now] = 1;
		if (flag == now) {
			return -1;
		}
		else {
			return flag;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> num;
			want[i] = num;
		}
		for (int i = 1; i <= n; i++) {
			visit[i] = false;
			group[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false) {
				dfs(i, i);
			}
		}
		
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (group[i]==-1) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}