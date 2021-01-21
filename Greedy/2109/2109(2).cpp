/*BOJ 2109*/
/*Greedy*/
/*첫번째 강연료 기준, 두번째 가능날짜 기준으로 오름차순 정렬*/
/*아직 안간 강연 중 강연료 가장 높은 순으로 선택*/
/*선택한 강연을 최대한 늦은 날짜에 가도록 설정*/
/*갈 수 있는 날짜가 있으면 그 강연 선택, 없으면 선택안함*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int p, d;
vector<pair<int, int>> univ;
bool day[10001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		univ.push_back({ -p, -d });
	}
	for (int i = 1; i <= 10000; i++) {
		day[i] = false;
	}
	sort(univ.begin(), univ.end());
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = -univ[i].second; j > 0; j--) {
			if (day[j] == false) {
				day[j] = true;
				res += (-univ[i].first);
				break;
			}
		}
	}
	cout << res;
	return 0;
}