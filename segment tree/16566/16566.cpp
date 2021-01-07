/*BOJ 16566*/
/*segmen tree*/
/*finding minimum value*/
#include<iostream>
#include<algorithm>
using namespace std;
int N, M, K;
int chulsu[4000001];
int minsu, num;
int query[10000];
int seg_tree[4000001 * 4];
int init(int start, int end, int seg_idx) {
	if (start == end) {
		return seg_tree[seg_idx] = chulsu[start];
	}
	int mid = (start + end) / 2;
	return seg_tree[seg_idx] =
		min(init(start, mid, seg_idx * 2), init(mid + 1, end, seg_idx * 2 + 1));
}
int find_q(int want_st, int want_ed, int start, int end, int seg_idx) {
	if (end < want_st || want_ed < start) {
		return N + 1;
	}
	if (want_st <= start && end <= want_ed) {
		return seg_tree[seg_idx];
	}
	int mid = (start + end) / 2;
	return min(find_q(want_st, want_ed, start, mid, seg_idx * 2),
		find_q(want_st, want_ed, mid + 1, end, seg_idx * 2 + 1));
}
int update(int want_idx, int value, int start, int end, int seg_idx) {
	if (want_idx<start || want_idx>end) {
		return seg_tree[seg_idx];
	}
	if (start == end) {
		return seg_tree[seg_idx] = value;
	}
	int mid = (start + end) / 2;
	int leftvalue = update(want_idx, value, start, mid, seg_idx * 2);
	int rightvalue = update(want_idx, value, mid + 1, end, seg_idx * 2 + 1);
	return seg_tree[seg_idx] = min(leftvalue, rightvalue);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		chulsu[i] = N + 1;
	}
	for (int i = 1; i <= M; i++) {
		cin >> num;
		chulsu[num] = num;
	}
	init(1, N, 1);
	for (int i = 0; i < K; i++) {
		cin >> query[i];
	}
	for (int i = 0; i < K; i++) {
		int res = find_q(query[i] + 1, N, 1, N, 1);
		cout << res << "\n";
		chulsu[res] = N + 1;
		update(res, N + 1, 1, N, 1);
	}
	return 0;
}