#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        string res = dominoes;
        int i = 0, j= 0;
        for (int k = 0; k < dominoes.size(); k++) {
            if (dominoes[k] == '.') {
                while ((j <= k || dominoes[j] == '.') && j < dominoes.size()-1) {
                    j++;
                }
                // 判断位置k应该倒向哪一边
                if (dominoes[j] != '.' && dominoes[i] != '.') {
                    if (dominoes[j] ==  dominoes[i]) {
                        res[k] = dominoes[i];
                    } else if (dominoes[j] == 'L' && dominoes[i] == 'R') {
                        if (j - k > k - i) {
                            res[k] = dominoes[i];
                        } else if (j - k < k - i) {
                            res[k] = dominoes[j];
                        }
                    }
                } else if (dominoes[j] == 'L') {
                    res[k] = dominoes[j];
                } else if (dominoes[i] == 'R') {
                    res[k] = dominoes[i];
                }
            } else {
                i = k;
            }
        }
        return res;
    }
};