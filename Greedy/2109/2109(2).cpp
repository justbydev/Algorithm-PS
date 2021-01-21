/*BOJ 2109*/
/*Greedy*/
/*ù��° ������ ����, �ι�° ���ɳ�¥ �������� �������� ����*/
/*���� �Ȱ� ���� �� ������ ���� ���� ������ ����*/
/*������ ������ �ִ��� ���� ��¥�� ������ ����*/
/*�� �� �ִ� ��¥�� ������ �� ���� ����, ������ ���þ���*/
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