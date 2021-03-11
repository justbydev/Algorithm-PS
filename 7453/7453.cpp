/*BOJ 7453*/
/*upper bound lower bound*/
/*lower bound: key �� �̻��� ���� ó�� ������ ��*/
/*upper bound: key �� �ʰ��� ���� ó�� ������ �� */
/*upper_bound-lower_bound: key ���� ����*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long int a, b, c, d;
vector<long long int> A, B, C, D;
vector<long long int> AB, CD;
long long int res = 0;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		A.push_back(a); B.push_back(b); C.push_back(c); D.push_back(d);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());
	int idx = 0;
	for (int i = 0; i < AB.size(); i++) {
		int begin = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		int end = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		res += (end - begin);
	}

	cout << res;
	return 0;
}