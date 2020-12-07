#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        struct node {
            int x, y;
        } Node;
        int n = matrix.size(), m = matrix[0].size();
        int X[4] = {0, 0, -1, 1};
        int Y[4] = {-1, 1, 0, 0};
        queue<node> q;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (matrix[x][y] == 0) {
                    Node.x = x, Node.y = y;
                    q.push(Node);
                } else {
                    matrix[x][y] = -1;
                }
            }
        }
        while (!q.empty()) {
            node top = q.front();
            int x = top.x, y = top.y;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = x + X[i];
                int newY = y + Y[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && matrix[newX][newY] == -1) {
                    matrix[newX][newY] = matrix[x][y] + 1;
                    Node.x = newX, Node.y = newY;
                    q.push(Node);
                }
            }
        }
        return matrix;
    }
};
// @lc code=end

