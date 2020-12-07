#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int res = 0;
        int n = grid.size(), m = 0;
        if (n > 0) {
            m = grid[0].size();
        }
        int X[] = {0, 0, -1, 1};
        int Y[] = {-1, 1, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    q.push(make_pair(i, j));
                    grid[i][j] = '2';
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int newX = x + X[k];
                            int newY = y + Y[k];
                            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1') {
                                grid[newX][newY] = '2';
                                q.push(make_pair(newX, newY));
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

