/*BOJ 10424*/
/*���� ����*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, input;
vector<pair<int, int>> num;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		num.push_back({ input, i + 1 });
	}//input�� �߰�, i+1�� �⸻
	sort(num.begin(), num.end());//�߰� �������� ����
	for (int i = 0; i < N; i++) {
		cout << num[i].first - num[i].second << "\n";
	}
	return 0;
}