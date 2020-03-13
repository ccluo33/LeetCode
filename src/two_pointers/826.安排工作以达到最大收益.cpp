#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res = 0, j = 0, temp = 0;
        vector<pair<int, int>> m;
        for (int i = 0; i < difficulty.size(); i++) {
            m.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(m.begin(), m.end());
        sort(worker.begin(), worker.end());
        
        for (int i = 0; i < worker.size(); i++) {
            while(j < difficulty.size() && j >= 0 && m[j].first <= worker[i]) {
                temp = max(temp, m[j++].second);
            }
            res += temp;
        }
        return res;
    }
};