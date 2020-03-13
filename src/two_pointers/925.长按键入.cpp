#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.length() && j < typed.length()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else if(j > 0 && typed[j] == typed[j-1]) {
                j++;
            } else {
                return false;
            }
        }
        while (j < typed.length() && j > 1) {
            if(typed[j] != typed[j-1]) {
                return false;
            }
            j++;
        }
        if (i == name.length() && j == typed.length()) {
            return true;
        } else {
            return false;
        }
    }
};