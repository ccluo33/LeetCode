#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    vector<int> stack;
    vector<int> min_stack;
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push_back(INT_MAX);
    }
    
    void push(int x) {
        stack.push_back(x);
        if (x <= min_stack.back()) {
            min_stack.push_back(x);
        }
    }
    
    void pop() {
        int x = stack.back();
        stack.pop_back();
        if (x == min_stack.back()) {
            min_stack.pop_back();
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

