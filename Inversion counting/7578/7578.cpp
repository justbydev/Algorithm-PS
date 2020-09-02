#include<iostream>
#include<vector>
using namespace std;
int N, input;
int A[1000001];
int seg_tree[2000001];
vector<int> B;
int sum(int l, int r, int idx, int st, int ed) {
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
void update(int l, int r, int idx, int want, int diff) {
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
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		A[input] = i;
	}
	B.push_back(-1);
	for (int i = 1; i <= N; i++) {
		cin >> input;
		B.push_back(A[input]);
	}
	long long int res = 0;
	for (int i = 1; i <= N; i++) {
		int st = B[i];
		res += sum(1, N, 1, st + 1, N);
		update(1, N, 1, st, 1);
	}
	cout << res;
	return 0;
}