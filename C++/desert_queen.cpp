#include <bits/stdc++.h>
using namespace std;

int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isPositionValid(int x, int y, int size, const vector<vector<char>>& map) {
    return x >= 0 && x < size && y >= 0 && y < size && map[x][y] != 'M';
}

int findMinimumWater(int size, const vector<vector<char>>& map, pair<int, int> startPos, pair<int, int> endPos) {
    vector<vector<int>> minCost(size, vector<int>(size, INT_MAX));
    queue<pair<int, int>> bfsQueue;

    bfsQueue.push(startPos);
    minCost[startPos.first][startPos.second] = 0;

    while (!bfsQueue.empty()) {
        auto [currentX, currentY] = bfsQueue.front();
        bfsQueue.pop();

        for (int d = 0; d < 4; d++) {
            int nextX = currentX + directions[d][0];
            int nextY = currentY + directions[d][1];

            if (isPositionValid(nextX, nextY, size, map)) {
                int cost = (map[currentX][currentY] == 'T' && map[nextX][nextY] == 'T') ? 0 : 1;
                if (minCost[currentX][currentY] + cost < minCost[nextX][nextY]) {
                    minCost[nextX][nextY] = minCost[currentX][currentY] + cost;
                    bfsQueue.push({nextX, nextY});
                }
            }
        }
    }

    return minCost[endPos.first][endPos.second];
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> map(n, vector<char>(n));
    pair<int, int> startPos, endPos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') startPos = {i, j};
            if (map[i][j] == 'E') endPos = {i, j};
        }
    }

    int result = findMinimumWater(n, map, startPos, endPos);
    cout << result << endl;

    return 0;
}