/*BOJ 2457*/
/*Greedy*/
/*���������� �� ���� ���� ��¥���� ���� �Ǵ� �� �� ���� �ʰ� ���� �� ����*/
/*���� ���� �� ���� �� �� ���� ���̶�� ���� ����*/
/*1�⳻�� ��¥ ���̴ϱ� 3�� 1���̸� 301, 11�� 1���̸� 1101 �̷� ������ �ٲٴ� ���� ��*/
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