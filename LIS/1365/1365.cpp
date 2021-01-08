#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, num;
vector<pair<int, int>> line;
vector<int> lis;
void trans_lis(void) {
	lis.push_back(line[0].second);
	for (int i = 1; i < N; i++) {
		int left = line[i].first;
		int right = line[i].second;
		int last = lis[lis.size() - 1];
		if (last < right) {
			lis.push_back(right);
		}
		else {
			int lis_idx = lower_bound(lis.begin(), lis.end(), right) - lis.begin();
			lis[lis_idx] = right;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		line.push_back({ i + 1, num });
	}
	trans_lis();
	cout<<N-lis.size();
	return 0;
}