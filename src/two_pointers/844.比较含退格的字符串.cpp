#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int len1 = 0, len2 = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] != '#') {
                S[len1++] = S[i];
            } else {
                if (len1 > 0) {
                    len1--;
                }
            }
        }
        for (int j = 0; j < T.length(); j++) {
            if (T[j] != '#') {
                T[len2++] = T[j];
            } else {
                if (len2 > 0) {
                    len2--;
                }
            }
        }
        if (len1 != len2) {
            return false;
        } else {
            for (int k = 0; k < len1; k++) {
                if (S[k] != T[k]) {
                    return false;
                }
            }
        }
        return true;
    }
};