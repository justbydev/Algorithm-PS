/*BOJ 10840*/
/*sliding window*/
/*set using->c++의 set은 기본적으로 balanced binary tree로 되어 있음*/
/*따라서 검색의 경우도 logn의 시간복잡도를 가지기 때문에 빠르다*/
#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
string a, b;
int N, M, ans = 0;
set<vector<int>> cnt_alpha;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b;
	N = a.length();
	M = b.length();
	for (int st = 0; st < N; st++) {
		vector<int> alpha(26);
		for (int ed = st; ed < N; ed++) {
			alpha[a[ed] - 'a']++;
			cnt_alpha.insert(alpha);
		}
	}
	vector<int> total(26);
	for (int i = 0; i < M; i++) {
		total[b[i] - 'a']++;
	}
	for (int len = M; len >= 1; len--) {
		vector<int> alpha(26);
		alpha = total;
		int st = 0, ed = len - 1;
		while (1) {
			if (ed >= M) {
				break;
			}
			if (cnt_alpha.count(alpha)) {
				cout << len;
				return 0;
			}
			alpha[b[st++] - 'a']--;
			if (++ed < M) {
				alpha[b[ed] - 'a']++;
			}
		}
		total[b[len - 1] - 'a']--;
	}
	cout << ans;
	return 0;
}