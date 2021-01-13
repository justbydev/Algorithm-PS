/*BOJ 15686*/
/*2<=N<=50, 1<=M<=13*/
/*Brute Force*/
/*just choose maxinum number of chicken is the best*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N, M, num;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> not_crash;
int res = -1;
void choice_chicken(int idx, int choice_num) {
	if (choice_num == M) {
		int total = 0;
		for (int i = 0; i < house.size(); i++) {
			pair<int, int> tmp = house[i];
			int hx = tmp.first; int hy = tmp.second;
			int now_dist = -1;
			for (int j = 0; j < not_crash.size(); j++) {
				int now = not_crash[j];
				pair<int, int> tmp2 = chicken[now];
				int cx = tmp2.first; int cy = tmp2.second;
				if (now_dist == -1) {
					now_dist = abs(cx - hx) + abs(cy - hy);
				}
				else {
					now_dist = min(now_dist, abs(cx - hx) + abs(cy - hy));
				}
			}
			total += now_dist;
		}
		if (res == -1) {
			res = total;
		}
		else {
			res = min(res, total);
		}
	}
	else if (idx >= chicken.size()) {
		return;
	}
	else {
		not_crash.push_back(idx);
		choice_chicken(idx + 1, choice_num + 1);
		not_crash.pop_back();
		choice_chicken(idx + 1, choice_num);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (num == 1) {
				house.push_back({ i, j });
			}
			else if (num == 2) {
				chicken.push_back({ i, j });
			}
		}
	}
	choice_chicken(0, 0);
	cout << res;
	return 0;
}