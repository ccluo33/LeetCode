#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        while(i < A.size() && j < B.size()) {
            if (A[i][0] > B[j][1]) {
                j++;
            } else if (B[j][0] > A[i][1]) {
                i++;
            } else {
                // 判断A[i]和B[j]的交点
                vector<int> p;
                p.push_back(max(A[i][0], B[j][0]));
                p.push_back(min(A[i][1], B[j][1]));
                result.push_back(p);
                if (A[i][1] > B[j][1]) {
                    j++;
                } else {
                    i++;
                }
            }
        } 
        return result;
    }
};