#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, C, input;
vector<int> house;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		house.push_back(input);
	}
	sort(house.begin(), house.end());
	int left, right;
	left = 0; right = house[house.size() - 1] - house[0];
	int res = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int idx = 0;
		int cnt = C - 1;
		for (int i = 1; i < house.size(); i++) {
			if (cnt <= 0) {
				break;
			}
			if (house[i] - house[idx] >= mid) {
				idx = i;
				cnt--;
			}
		}
		if (cnt <= 0) {
			res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << res;
	return 0;
}