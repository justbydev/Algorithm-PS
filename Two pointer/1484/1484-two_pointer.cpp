#include<iostream>
#include<vector>
using namespace std;
int G;
vector<int> res;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> G;
	int cur, prev;
	cur = prev = 1;
	while (1) {
		if (cur > G) {
			break;
		}
		int gap = cur * cur - prev * prev;
		if (gap < G) {
			cur++;
		}
		else if (gap == G) {
			res.push_back(cur);
			cur++; prev++;
		}
		else if (gap > G) {
			prev++;
		}
	}
	if (res.empty()) {
		cout << -1;
	}
	else {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << "\n";
		}
	}
	return 0;
}