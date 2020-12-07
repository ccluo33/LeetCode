#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        multimap<int, int> mp;
        vector<int> res;
        queue<int> q;
        vector<int> circle;
        vector degree(numCourses, 0);
        int nums = 0;
        multimap<int, int>::iterator iter;
        for (int i = 0; i < prerequisites.size(); i++) {
            mp.insert(make_pair(prerequisites[i][1], prerequisites[i][0]));
            degree[prerequisites[i][0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            res.push_back(temp);
            q.pop();
            nums = mp.count(temp);
            for (iter = mp.find(temp); nums > 0; nums--) {
                degree[iter->second]--;
                if (degree[iter->second] == 0) {
                    q.push(iter->second);
                }
                iter++;
            }
        }
        if (res.size() != numCourses) {
            return circle;
        } else {
            return res;
        }
    }
};
// @lc code=end

