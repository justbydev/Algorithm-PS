/*BOJ 2109*/
/*Greedy*/
/*날짜 역순으로 가면서 그날까지 가능한 것들을 heap에 넣음*/
/*이 heap은 강연료에 대한 max heap*/
/*그리고 날짜 바뀔때마다 max heap 검사해서 비어있지 않다면 더하기*/
/*즉, 그날 가능한 강연 중에서 강연료가 가장 비싼 것을 선택하는 방법*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, p, d;
vector<int> univ[10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		univ[d].push_back(p);
	}
	int res = 0;
	priority_queue<int> heap;
	for (int i = 10000; i >= 1; i--) {
		for (int j = 0; j < univ[i].size(); j++) {
			heap.push(univ[i][j]);
		}
		if (!heap.empty()) {
			res += (heap.top());
			heap.pop();
		}
	}
	cout << res;
	return 0;
}