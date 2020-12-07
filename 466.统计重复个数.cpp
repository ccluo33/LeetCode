#include <iostream>
#include <cstring>
using namespace std;
/*
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 */

// @lc code=start
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) {
            return 0;
        }            
        // index s2中的索引
        // s1cnt 当前s1的个数
        // s2cnt 当前s2的个数
        int s1cnt = 0, index = 0, s2cnt = 0;
        // recall使我们用来找循环节的变量，它是一个哈希映射
        // 如何找循环节？假设我们遍历了s1cnt个s1，此时匹配到了第s2cnt个s2中的第index个字符
        // 如果我们之前遍历了s1cnt'个s1时，匹配到的是第s2cnt'个s2中同样的第index个字符，那么就有循环节了
        // 我们用(s1cnt', s2cnt', index)和(s1cnt, s2cnt, index)表示两次包含相同index的匹配结果
        // 那么哈希映射中的键就是index，值就是(s1cnt', s2cnt')这个二元组
        // 循环节就是:
        //      - 前s1cnt'个s1包含了s2cnt'个s2
        //      - 以后的每(s1cnt - s1cnt')个s1包含了(s2cnt - s2cnt')个s2
        // 那么还会剩下(n1 - s1cnt') % (s1cnt - s1cnt') 个s1, 我们对这些与s2进行暴力匹配
        // 注意此时s2要从第index个字符开始匹配
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        while (true) {
            // 多遍历一个s1，看看能不能找到循环节
            ++s1cnt;
            for (char ch: s1) {
                if (ch == s2[index]) {
                    index++;
                    if (index == s2.size()) {
                        index = 0;
                        s2cnt++;
                    }
                }
            }

            // 还没有找到循环节，所有的s1就用完了
            if (s1cnt == n1) {
                return s2cnt/n2;
            }

            // 出现了之前的index, 表示找到了循环节
            if (recall.count(index)) {    // map的count方法在有该key时返回1，没有该key时返回0
                int pre_s1cnt = recall[index].first;
                int pre_s2cnt = recall[index].second;
                // 前s1cnt'个s1包含了s2cnt'个s2
                pre_loop = {pre_s1cnt, pre_s2cnt};
                // 以后的每(s1cnt - s1cnt')个s1包含了(s2cnt - s2cnt')个s2
                in_loop = {s1cnt - pre_s1cnt, s2cnt - pre_s2cnt};
                break;
            } else {
                recall[index] = {s1cnt, s2cnt};
            }
        }    
        // ans存储的是S1包含的s2的数量，考虑之前的pre_loop和in_loop
        int ans = pre_loop.second + (n1 - pre_loop.first) / in_loop.first * in_loop.second;
        // S1的末尾还剩下一些s1， 我们暴力进行匹配, 剩下的长度即为rest
        int rest = (n1 - pre_loop.first) % in_loop.first;
        for (int i = 0; i < rest; i++) {
            for (char ch: s1) {
                if (s2[index] == ch) {
                    index++;
                    if (index == s2.size()) {
                        ans++;
                        index = 0;
                    }
                }
            }
        }
        // S1包含ans个s2, 那么就包含ans/n2个S2 
        return ans/n2;
    }
};
// @lc code=end

