/*BOJ 2493*/
/*stack*/
/*stack의 top과 비교하고 왼쪽에 있는 탑 중 현재 탑보다 높이 작은 애들은 다 버림*/
/*어차피 수신 받을 때 나보다 작은 왼쪽에 있는 탑들은 받을 수 없기 때문에*/
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