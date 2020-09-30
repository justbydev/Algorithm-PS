#include<iostream>
using namespace std;
int N, M;
int money[10001];
int k, v, w;
int parent[10001];
int find(int num) {
	if (parent[num] == num) {
		return num;
	}
	return parent[num] = find(parent[num]);
}
void Union(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	if (money[root_a] < money[root_b]) {
		parent[root_b] = root_a;
	}
	else {
		parent[root_a] = root_b;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) {
		cin >> money[i];
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> v >> w;
		Union(v, w);
	}
	int res = 0;
	for (int i = 1; i <= N; i++) {
		if (parent[i] == i) {
			res += money[i];
			k -= money[i];
		}
		if (k < 0) {
			res = -1;
			break;
		}
	}
	if (res == -1) {
		cout << "Oh no";
	}
	else {
		cout << res;
	}
	return 0;
}