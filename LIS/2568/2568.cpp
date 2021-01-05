/*BOJ 2568*/
/*LIS using O(nlong) way*/
/*tracking LIS*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, a, b;
vector<pair<int, int>> AB;
vector<int> lis;
vector<pair<int,int>> pos;
bool connect[500001];
void trans_LIS(void) {
	lis.push_back(AB[0].second);
	pos.push_back({ 0, AB[0].first });
	for (int i = 1; i < N; i++) {
		int last = lis[lis.size() - 1];
		a = AB[i].first;
		b = AB[i].second;
		if (last < b) {
			lis.push_back(b);
			pos.push_back({ lis.size() - 1, a });
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), b) - lis.begin();
			lis[idx] = b;
			pos.push_back({ idx, a });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= 500000; i++) {
		connect[i] = false;
	}
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		AB.push_back({ a, b });
		connect[a] = true;
	}
	sort(AB.begin(), AB.end());
	trans_LIS();
	cout << N - lis.size() << "\n";
	int now = lis.size() - 1;
	for (int i = pos.size() - 1; i >= 0; i--) {
		if (now < 0) {
			break;
		}
		if (now == pos[i].first) {
			connect[pos[i].second] = false;
			now--;
		}
	}
	for (int i = 1; i <= 500000; i++) {
		if (connect[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}