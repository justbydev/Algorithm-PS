#include<iostream>
using namespace std;
int N, M, K;
long long int a, b, c;
long long int num[1000000];
long long int seg_tree[4000001];
long long int init(int l, int r, int idx) {
	if (l == r) {
		return seg_tree[idx] = num[l];
	}
	int mid = (l + r) / 2;
	return seg_tree[idx] = init(l, mid, idx * 2) +
		init(mid + 1, r, idx * 2 + 1);
}
void update(int l, int r, int idx, int want, long long int diff) {
	if (want < l || r < want) {
		return;
	}
	seg_tree[idx] += diff;
	if (l != r) {
		int mid = (l + r) / 2;
		update(l, mid, idx * 2, want, diff);
		update(mid + 1, r, idx * 2 + 1, want, diff);
	}

}
long long int sum(int l, int r, int idx, int st, int ed) {
	if (st <= l && r <= ed) {
		return seg_tree[idx];
	}
	if (ed < l || r < st) {
		return 0;
	}
	int mid = (l + r) / 2;
	return sum(l, mid, idx * 2, st, ed) +
		sum(mid + 1, r, idx * 2 + 1, st, ed);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	init(0, N - 1, 1);
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			long long int diff = c - num[b - 1];
			update(0, N - 1, 1, b - 1, diff);
			num[b - 1] = c;
		}
		else if (a == 2) {
			cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}