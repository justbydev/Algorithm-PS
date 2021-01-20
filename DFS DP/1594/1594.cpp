/*BOJ 1594*/
/*DFS+DP*/
#include<iostream>
#include<string>
using namespace std;
string number;
string res;
int res_score;
int visit[1000];//그 인덱스까지 구성된 점수 저장
int oh_check(string sub) {
	int flag = 1;
	for (int i = 1; i < sub.length(); i++) {
		if (sub[i - 1] != sub[i]) {
			flag = 0;
		}
	}
	return flag;
}
int ggang_check(string sub) {
	if (sub[0] == sub[1] || sub[0] == sub[2] || sub[1] == sub[2]) {
		return 1;
	}
	else {
		return 0;
	}
}
int compare_str(string zero, string one) {
	for (int i = 0; i < zero.length(); i++) {
		if ((zero[i] - '-') < (one[i] - '-')) {
			return 0;
		}
		else if ((zero[i] - '-') > (one[i] - '-')) {
			return 1;
		}
	}
	return 0;
}
void dfs(int idx, int score, string now) {
	if (visit[idx]>=score) {//기존 값 이하이면 더 이상 진행할 필요 없음
		return;
	}
	if (idx == number.length() - 1) {
		return;
	}
	if (idx > number.length()) {
		return;
	}
	if (idx == number.length()) {
		string check = now.substr(0, now.length() - 1);
		if (res_score == -1) {
			res_score = score;
			res = check;
			return;
		}
		if (res_score < score) {
			res_score = score;
			res = check;
		}
		else if (res_score == score) {
			int comp = compare_str(res, check);
			if (comp == 1) {
				res_score = score;
				res = check;
			}
		}
		return;
	}
	visit[idx] = score;
	int two_score = score + 2 * oh_check(number.substr(idx, 2));
	dfs(idx + 2, two_score, now + number.substr(idx, 2) + "-");
	if (idx + 2 <= number.length() - 1) {
		int oh = oh_check(number.substr(idx, 3));
		if (oh == 1) {
			dfs(idx + 3, score + 2, now + number.substr(idx, 3) + "-");
		}
		else {
			int three_score = score + ggang_check(number.substr(idx, 3));
			dfs(idx + 3, three_score, now + number.substr(idx, 3) + "-");
		}
		
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> number;
	for (int i = 0; i < 1000; i++) {
		visit[i] = -1;
	}
	res_score = -1;
	dfs(0, 0, "");
	cout << res;
	return 0;
}