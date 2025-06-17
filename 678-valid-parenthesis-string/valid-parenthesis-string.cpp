class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0; 
        for (auto c:s) {
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                if(cmin)cmin--;
            } else if (c == '*') {
                cmax++; 
                if(cmin)cmin--;
            }
            if (cmax < 0) return false; 

        }
        return cmin == 0; 
    }
};