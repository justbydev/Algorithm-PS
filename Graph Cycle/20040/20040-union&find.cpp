#include<iostream>
using namespace std;
int n, m;
int a, b;
int parent[500000];
int find(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = find(parent[now]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int res = 0;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (res != 0) {
			continue;
		}
		int root_a = find(a);
		int root_b = find(b);
		if (i == 1) {
			parent[root_a] = root_b;
		}
		else {
			if (root_a == root_b) {
				res = i;
			}
			else {
				parent[root_a] = root_b;
			}
		}
	}
	cout << res;
	return 0;
}