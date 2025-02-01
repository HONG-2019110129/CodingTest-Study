#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1000000

struct Point {
    int x, y, time;
};

int n, m;
vector<string> grid;
vector<vector<int>> ghost_time; // 유령이 각 위치에 도달하는 최소 시간
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 유령 이동 시간을 BFS로 계산
void bfs_ghost(queue<Point>& ghosts) {
    while (!ghosts.empty()) {
        Point g = ghosts.front(); ghosts.pop();
        for (int i = 0; i < 4; i++) {
            int nx = g.x + dx[i], ny = g.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (ghost_time[nx][ny] > g.time + 1) {
                    ghost_time[nx][ny] = g.time + 1;
                    ghosts.push({nx, ny, g.time + 1});
                }
            }
        }
    }
}

// 남우 이동 경로 탐색
bool bfs_namu(Point start, Point exit) {
    queue<Point> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push(start);
    visited[start.x][start.y] = true;
    
    while (!q.empty()) {
        Point p = q.front(); q.pop();
        
        // 출구에 도착하면 탈출 성공
        if (p.x == exit.x && p.y == exit.y) return true;
        
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i], ny = p.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && grid[nx][ny] != '#') { // 벽이 아니고 방문한 적 없는 곳
                    if (p.time + 1 < ghost_time[nx][ny]) { // 유령보다 먼저 도착 가능할 때만 이동
                        visited[nx][ny] = true;
                        q.push({nx, ny, p.time + 1});
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    ghost_time.assign(n, vector<int>(m, INF));
    queue<Point> ghosts;
    Point namu, exit;
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'G') {
                ghosts.push({i, j, 0});
                ghost_time[i][j] = 0;
            } else if (grid[i][j] == 'N') {
                namu = {i, j, 0};
            } else if (grid[i][j] == 'D') {
                exit = {i, j, 0};
            }
        }
    }
    
    // 유령 이동 BFS 실행
    bfs_ghost(ghosts);
    
    // 남우 탈출 가능 여부 확인
    cout << (bfs_namu(namu, exit) ? "Yes" : "No") << endl;
    return 0;
}