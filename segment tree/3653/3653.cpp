/*BOJ 3653*/
/*segtree tree*/
/*using subsum of segtree tree*/
#include<iostream>
using namespace std;
int k, n, m, q, book_idx, tmp;
int book[100001];
int seg_tree[800010];
int segtree_init(int start, int end, int seg_idx) {
	if (start == end) {
		if (start <= m) {
			seg_tree[seg_idx] = 0;
		}
		else {
			seg_tree[seg_idx] = 1;
		}
		return seg_tree[seg_idx];
	}
	int middle = (start + end) / 2;
	return seg_tree[seg_idx]=segtree_init(start, middle, seg_idx * 2) +
		segtree_init(middle + 1, end, seg_idx * 2 + 1);
}
int segtree_find(int start, int end, int seg_idx, int st_want, int ed_want) {
	if (st_want <= start && end <= ed_want) {
		return seg_tree[seg_idx];
	}
	if (ed_want < start || end < st_want) {
		return 0;
	}
	int middle = (start + end) / 2;
	return segtree_find(start, middle, seg_idx * 2, st_want, ed_want) +
		segtree_find(middle + 1, end, seg_idx * 2 + 1, st_want, ed_want);
}
void segtree_update(int start, int end, int seg_idx, int want, int diff) {
	if (want<start || want>end) {
		return;
	}
	seg_tree[seg_idx] += diff;
	if (start == end) {
		return;
	}
	int middle = (start + end) / 2;
	segtree_update(start, middle, seg_idx * 2, want, diff);
	segtree_update(middle + 1, end, seg_idx * 2 + 1, want, diff);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> k;
	for (int test = 0; test < k; test++) {
		cin >> n >> m;
		tmp = m + 1;
		for (int i = 1; i <= n; i++) {
			book[i] = tmp++;
		}
		segtree_init(1, n + m, 1);
		book_idx = m;
		for (int i = 0; i < m; i++) {
			cin >> q;
			cout << segtree_find(1, n + m, 1, 1, book[q]-1) << " ";
			segtree_update(1, n + m, 1, book[q], -1);
			book[q] = book_idx--;
			segtree_update(1, n + m, 1, book[q], 1);
		}
		cout << "\n";
	}
	return 0;
}