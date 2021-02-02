/*BOJ 10830*/
/*calculation of vector*/
/*matrix multiplication*/
/*div and conquer*/
#include<iostream>
#include<vector>
using namespace std;
int N, num;
long long int B;
vector<vector<int>> A;
vector<vector<int>> res;
vector<vector<int>> mul(vector<vector<int>> one, vector<vector<int>> two) {
	vector<vector<int>> middle;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			for (int k = 0; k < N; k++) {
				tmp = (tmp + one[i][k] * two[k][j]) % 1000;
			}
			temp.push_back(tmp);
		}
		middle.push_back(temp);
	}
	return middle;
}
vector<vector<int>> div(long long int square) {
	if (square == 1) {
		return A;
	}
	vector<vector<int>> mid;
	if (square % 2 == 0) {
		mid = div(square / 2);
		return mul(mid, mid);
	}
	else if (square % 2 == 1) {
		mid = div(square - 1);
		return mul(mid, A);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			cin >> num;
			tmp.push_back(num);
		}
		A.push_back(tmp);
	}
	res = div(B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << res[i][j]%1000 << " ";
		}
		cout << "\n";
	}
	return 0;
}