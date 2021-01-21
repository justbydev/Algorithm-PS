/*BOJ 2457*/
/*Greedy*/
/*마지막으로 핀 꽃이 지는 날짜보다 빨리 피는 꽃 중 가장 늦게 지는 꽃 고르기*/
/*지는 날은 그 꽃을 볼 수 없는 날이라는 것을 주의*/
/*1년내의 날짜 비교이니까 3월 1일이면 301, 11월 1일이면 1101 이런 식으로 바꾸는 것이 편리*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, a, b, c, d;
vector<pair<int, int>> flower;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		if (flag == 0) {
			if (100 * a + b <= 301) {
				flag = 1;
			}
		}
		flower.push_back({ 100 * a + b, 100 * c + d });
	}
	if (flag == 0) {
		cout << 0;
	}
	else {
		sort(flower.begin(), flower.end());
		int cnt = 0;
		int enddate = 301;
		int idx = 0;
		while (1) {
			if (enddate >= 1201) {
				break;
			}
			int max_date = -1;
			for (; idx < N; idx++) {
				int start_d = flower[idx].first;
				int end_d = flower[idx].second;
				if (start_d == end_d) {
					continue;
				}
				if (start_d <= enddate) {
					max_date = max(max_date, end_d);
				}
				else {
					break;
				}
			}
			if (max_date == -1) {
				break;
			}
			else {
				enddate = max_date;
				cnt++;
			}
		}
		if (enddate >= 1201) {
			cout << cnt;
		}
		else {
			cout << 0;
		}
	}
	return 0;
}