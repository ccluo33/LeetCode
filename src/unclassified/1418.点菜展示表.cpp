#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
 * @lc app=leetcode.cn id=1418 lang=cpp
 *
 * [1418] 点菜展示表
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foodItem;
        set<string>::iterator fiter;
        vector<vector<string>> table(501); 
        set<int> tableNumber;
        set<int>::iterator titer;
        vector<vector<string>> res;
        for (int i = 0; i < orders.size(); i++) {
            tableNumber.insert(stoi(orders[i][1]));
            foodItem.insert(orders[i][2]);
            table[stoi(orders[i][1])].push_back(orders[i][2]);
        }
        vector<string> r1;
        r1.push_back("Table");
        for (fiter = foodItem.begin(); fiter != foodItem.end(); fiter++) {
            r1.push_back(*fiter);
        }
        res.push_back(r1);
        for (titer = tableNumber.begin(); titer != tableNumber.end(); titer++) {
            vector<string> r;
            r.push_back(to_string(*titer));
            for (fiter = foodItem.begin(); fiter != foodItem.end(); fiter++) {
                int cnt = 0;
                for (string tmp: table[*titer]) {
                    if (tmp == *fiter) {
                        cnt++;
                    }
                }
                r.push_back(to_string(cnt));
            }
            res.push_back(r);    
        }
        return res;
    }
};
// @lc code=end

