/*BOJ 12837*/
/*segment tree*/
/*1. 그냥 하나의 구간합 구하면 for 문으로 i~k 더하기*/
/*2. 구간합 구하는데 query가 여러번이면 prefix sum 이용->i~k sum=0~k의 sum-0~i-1의 sum*/
/*3. 주어진 배열 안에서의 여러 구간합 중 특정 수 만드는 구간합 개수 찾기->투포인터*/
/*4. 구간합을 구하는데 주어진 배열이 계속 바뀌는 경우->segment tree*/
/*이 문제는 중간에 계속 수가 바뀌고 구간합을 여러번 물어보기에 segment tree*/
#include<iostream>
using namespace std;
int N, Q;
int num, p, q;
long long int seg_tree[4000010] = { 0 };
void seg_update(int start, int end, int seg_idx, int want, int diff) {
	if (want < start || end < want) {
		return;
	}
	seg_tree[seg_idx] += diff;
	if (start == end) {
		return;
	}
	int middle = (start + end) / 2;
	seg_update(start, middle, seg_idx * 2, want, diff);
	seg_update(middle + 1, end, seg_idx * 2 + 1, want, diff);
}
long long int find(int start, int end, int seg_idx, int want_st, int want_ed) {
	if (want_st <= start && end <= want_ed) {
		return seg_tree[seg_idx];
	}
	if (want_ed < start || end < want_st) {
		return 0;
	}
	int middle = (start + end) / 2;
	return find(start, middle, seg_idx * 2, want_st, want_ed) +
		find(middle + 1, end, seg_idx * 2 + 1, want_st, want_ed);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> num >> p >> q;
		if (num == 1) {
			seg_update(1, N, 1, p, q);
		}
		else if (num == 2) {
			cout << find(1, N, 1, p, q) << "\n";
		}
	}
	return 0;
}