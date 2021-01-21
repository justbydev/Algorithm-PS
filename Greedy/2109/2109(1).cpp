/*BOJ 2109*/
/*Greedy*/
/*��¥ �������� ���鼭 �׳����� ������ �͵��� heap�� ����*/
/*�� heap�� �����ῡ ���� max heap*/
/*�׸��� ��¥ �ٲ𶧸��� max heap �˻��ؼ� ������� �ʴٸ� ���ϱ�*/
/*��, �׳� ������ ���� �߿��� �����ᰡ ���� ��� ���� �����ϴ� ���*/
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