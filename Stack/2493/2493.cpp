/*BOJ 2493*/
/*stack*/
/*stack�� top�� ���ϰ� ���ʿ� �ִ� ž �� ���� ž���� ���� ���� �ֵ��� �� ����*/
/*������ ���� ���� �� ������ ���� ���ʿ� �ִ� ž���� ���� �� ���� ������*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int N, num;
stack<pair<int,int>> tp;
vector<pair<int, int>> height;
int ans[500001] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	height.push_back({ -1, -1 });
	for (int i = 1; i <= N; i++) {
		cin >> num;
		height.push_back({ num, i });
	}
	tp.push(height[1]);
	for (int i = 2; i <= N; i++) {
		while (!tp.empty()) {
			if (tp.top().first > height[i].first) {
				ans[i] = tp.top().second;
				tp.push(height[i]);
				break;
			}
			else if (tp.top().first < height[i].first) {
				tp.pop();
			}
		}
		if (tp.empty()) {
			tp.push(height[i]);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}