/*BOJ 19236*/
/*DFS backtracking*/
/*이전 상태 저장->물고기 이동->상어 이동(모든 경우의 수에 대해)->shark_eating()->...->다시 돌아오면 이전 상태 다시 복구*/
/*전형적인 backtracking 문제*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a, b;
int x[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int y[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int map[4][4];
int res;
vector<pair<pair<int, int>, int>> fish[17];
int fish_moving(int nowx, int nowy, int dir) {
	int nowdir = dir;
	while (1) {
		int nx = nowx + x[nowdir];
		int ny = nowy + y[nowdir];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
			nowdir++;
			if (nowdir >= 9) {
				nowdir = 1;
			}
			continue;
		}
		if (map[nx][ny] == -1) {
			nowdir++;
			if (nowdir >= 9) {
				nowdir = 1;
			}
			continue;
		}
		return nowdir;
	}
}
void shark_eating(int sharkx, int sharky, int sharkdir, int eating) {
	res = max(res, eating);
	int map_tmp[4][4];
	vector<pair<pair<int, int>, int>> fish_tmp[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map_tmp[i][j] = map[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		fish_tmp[i].push_back({ {0, 0}, 0 });
	}
	for (int i = 1; i <= 16; i++) {
		fish_tmp[i][0].first.first = fish[i][0].first.first;
		fish_tmp[i][0].first.second = fish[i][0].first.second;
		fish_tmp[i][0].second = fish[i][0].second;
	}
	for (int i = 1; i <= 16; i++) {
		if (fish[i][0].second != -1) {
			int nowx = fish[i][0].first.first;
			int nowy = fish[i][0].first.second;
			int dir = fish[i][0].second;
			int move_dir = fish_moving(nowx, nowy, dir);
			fish[i][0].first.first = nowx + x[move_dir];
			fish[i][0].first.second = nowy + y[move_dir];
			fish[i][0].second = move_dir;
			if (map[nowx + x[move_dir]][nowy + y[move_dir]] == 0) {
				map[nowx][nowy] = 0;
				map[nowx + x[move_dir]][nowy + y[move_dir]] = i;
			}
			else {
				int temp = map[nowx][nowy];
				map[nowx][nowy] = map[nowx + x[move_dir]][nowy + y[move_dir]];
				map[nowx + x[move_dir]][nowy + y[move_dir]] = temp;
				int change_fish_num = map[nowx][nowy];
				fish[change_fish_num][0].first.first = nowx;
				fish[change_fish_num][0].first.second = nowy;
			}
		}
	}
	map[sharkx][sharky] = 0;
	while (1) {
		sharkx = sharkx + x[sharkdir];
		sharky = sharky + y[sharkdir];
		if (sharkx < 0 || sharkx >= 4 || sharky < 0 || sharky >= 4) {
			break;
		}
		if (map[sharkx][sharky] == 0) {
			continue;
		}
		int eat_fish = map[sharkx][sharky];
		int shark_now_dir = fish[eat_fish][0].second;
		map[sharkx][sharky] = -1;
		fish[eat_fish][0].second = -1;
		shark_eating(sharkx, sharky, shark_now_dir, eating + eat_fish);
		map[sharkx][sharky] = eat_fish;
		fish[eat_fish][0].second = shark_now_dir;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = map_tmp[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		fish[i][0].first.first = fish_tmp[i][0].first.first;
		fish[i][0].first.second = fish_tmp[i][0].first.second;
		fish[i][0].second = fish_tmp[i][0].second;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int sharkx, sharky, sharkdir;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			fish[a].push_back({ {i, j}, b });
			map[i][j] = a;
		}
	}
	sharkx = sharky = 0;
	sharkdir = fish[map[0][0]][0].second;
	fish[map[0][0]][0].second = -1;
	int tmp = map[0][0];
	map[0][0] = -1;
	shark_eating(sharkx, sharky, sharkdir, tmp);
	cout << res;
	return 0;
}