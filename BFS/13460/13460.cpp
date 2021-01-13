/*BOJ 13460*/
/*BFS*/
/*direction*/
/*moves until it can't*/
/*check visit both red and blue*/
#include<iostream>
#include<queue>
using namespace std;
int N, M;
char board[10][10];
bool visit[10][10][10][10];
int rx, ry, bx, by, ox, oy;
int r_flag, b_flag, r_nx, r_ny, b_nx, b_ny;
void move(int color, int nx, int ny, int dx, int dy) {
	int tmpx, tmpy;
	tmpx = nx; tmpy = ny;
	while (1) {
		if (board[tmpx][tmpy] == '#') {
			tmpx -= dx; tmpy -= dy;
			break;
		}
		if (board[tmpx][tmpy] == 'O') {
			if (color == 0) {
				r_flag = 1;
			}
			else if (color == 1) {
				b_flag = 1;
			}
			break;
		}
		if (color == 0) {
			if (tmpx == b_nx && tmpy == b_ny) {
				tmpx -= dx; tmpy -= dy;
				break;
			}
		}
		else if (color == 1) {
			if (tmpx == r_nx && tmpy == r_ny) {
				tmpx -= dx; tmpy -= dy;
				break;
			}
		}
		tmpx += dx; tmpy += dy;
	}
	if (color == 0) {
		r_nx = tmpx; r_ny = tmpy;
	}
	else if (color == 1) {
		b_nx = tmpx; b_ny = tmpy;
	}
}
int bfs(void) {
	queue<pair<int, int>> red;
	queue<pair<int, int>> blue;
	queue<int> count;
	red.push({ rx, ry });
	blue.push({ bx, by });
	count.push(0);
	visit[rx][ry][bx][by] = true;
	while (!red.empty()) {
		pair<int, int> r_now = red.front();
		red.pop();
		pair<int, int> b_now = blue.front();
		blue.pop();
		int cnt = count.front();
		count.pop();
		if (cnt >= 10) {
			continue;
		}
		//left
		r_flag = b_flag  = 0;
		r_nx = r_ny = b_nx = b_ny = -1;
		if (r_now.second < b_now.second) {
			move(0, r_now.first, r_now.second, 0, -1);
			move(1, b_now.first, b_now.second, 0, -1);
		}
		else {
			move(1, b_now.first, b_now.second, 0, -1);
			move(0, r_now.first, r_now.second, 0, -1);
		}
		if (r_flag == 1 && b_flag == 0) {
			return cnt + 1;
		}
		else if (r_flag == 0 && b_flag == 0) {
			if (visit[r_nx][r_ny][b_nx][b_ny] == false) {
				red.push({ r_nx, r_ny });
				blue.push({ b_nx, b_ny });
				count.push(cnt + 1);
				visit[r_nx][r_ny][b_nx][b_ny] = true;
			}
		}
		//right
		r_flag = b_flag = 0;
		r_nx = r_ny = b_nx = b_ny = -1;
		if (r_now.second < b_now.second) {
			move(1, b_now.first, b_now.second, 0, 1);
			move(0, r_now.first, r_now.second, 0, 1);
		}
		else {
			move(0, r_now.first, r_now.second, 0, 1);
			move(1, b_now.first, b_now.second, 0, 1);
		}
		if (r_flag == 1 && b_flag == 0) {
			return cnt + 1;
		}
		else if (r_flag == 0 && b_flag == 0) {
			if (visit[r_nx][r_ny][b_nx][b_ny] == false) {
				red.push({ r_nx, r_ny });
				blue.push({ b_nx, b_ny });
				count.push(cnt + 1);
				visit[r_nx][r_ny][b_nx][b_ny] = true;
			}
		}
		//up
		r_flag = b_flag = 0;
		r_nx = r_ny = b_nx = b_ny = -1;
		if (r_now.first < b_now.first) {
			move(0, r_now.first, r_now.second, -1, 0);
			move(1, b_now.first, b_now.second, -1, 0);
		}
		else {
			move(1, b_now.first, b_now.second, -1, 0);
			move(0, r_now.first, r_now.second, -1, 0);
		}
		if (r_flag == 1 && b_flag == 0) {
			return cnt + 1;
		}
		else if (r_flag == 0 && b_flag == 0) {
			if (visit[r_nx][r_ny][b_nx][b_ny] == false) {
				red.push({ r_nx, r_ny });
				blue.push({ b_nx, b_ny });
				count.push(cnt + 1);
				visit[r_nx][r_ny][b_nx][b_ny] = true;
			}
		}
		//down
		r_flag = b_flag = 0;
		r_nx = r_ny = b_nx = b_ny = -1;
		if (r_now.first < b_now.first) {
			move(1, b_now.first, b_now.second, 1, 0);
			move(0, r_now.first, r_now.second, 1, 0);
		}
		else {
			move(0, r_now.first, r_now.second, 1, 0);
			move(1, b_now.first, b_now.second, 1, 0);
		}
		if (r_flag == 1 && b_flag == 0) {
			return cnt + 1;
		}
		else if (r_flag == 0 && b_flag == 0) {
			if (visit[r_nx][r_ny][b_nx][b_ny] == false) {
				red.push({ r_nx, r_ny });
				blue.push({ b_nx, b_ny });
				count.push(cnt + 1);
				visit[r_nx][r_ny][b_nx][b_ny] = true;
			}
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				rx = i; ry = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				bx = i; by = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'O') {
				ox = i; oy = j;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < M; b++) {
					visit[i][j][a][b] = false;
				}
			}
		}
	}
	cout << bfs();
	return 0;
}