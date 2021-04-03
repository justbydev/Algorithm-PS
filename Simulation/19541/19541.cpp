/*BOJ 19541*/
/*simulation*/
/*시간순 역계산*/
#include<iostream>
#include<vector>
using namespace std;
int N, M;
int k, num;
vector<int> group[100000];
int infect[100000];
int test[100000];
int res[100000];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> num;
			group[i].push_back(num - 1);
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> infect[i];
		res[i]=test[i] = infect[i];
	}
	vector<int> group_infect;
	for (int i = M - 1; i >= 0; i--) {
		int non_infect = 0;
		for (int j = 0; j < group[i].size(); j++) {
			if (test[group[i][j]] == 0) {
				non_infect = 1;
			}
			else {
				group_infect.push_back(group[i][j]);
			}
		}
		if (non_infect == 1) {
			for (int j = 0; j < group_infect.size(); j++) {
				test[group_infect[j]] = 0;
				res[group_infect[j]] = 0;
			}
		}
		group_infect.clear();
	}
	vector<int> group_noinfect;
	for (int i = 0; i < M; i++) {
		int yes_infect = 0;
		for (int j = 0; j < group[i].size(); j++) {
			if (test[group[i][j]] == 1) {
				yes_infect = 1;
			}
			else {
				group_noinfect.push_back(group[i][j]);
			}
		}
		if (yes_infect == 1) {
			for (int j = 0; j < group_noinfect.size(); j++) {
				test[group_noinfect[j]] = 1;
			}
		}
		group_noinfect.clear();
	}
	for (int i = 0; i < N; i++) {
		if (infect[i] != test[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << "\n";
	for (int i = 0; i < N; i++) {
		cout << res[i] << " ";
	}
	return 0;
}