/*BOJ 12837*/
/*segment tree*/
/*1. �׳� �ϳ��� ������ ���ϸ� for ������ i~k ���ϱ�*/
/*2. ������ ���ϴµ� query�� �������̸� prefix sum �̿�->i~k sum=0~k�� sum-0~i-1�� sum*/
/*3. �־��� �迭 �ȿ����� ���� ������ �� Ư�� �� ����� ������ ���� ã��->��������*/
/*4. �������� ���ϴµ� �־��� �迭�� ��� �ٲ�� ���->segment tree*/
/*�� ������ �߰��� ��� ���� �ٲ�� �������� ������ ����⿡ segment tree*/
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