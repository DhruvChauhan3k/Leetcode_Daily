class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 0;
        int n = s.size();

        for (int center = 0; center < n; ++center) {
            // Odd-length palindromes (center at s[center])
            
            expandAroundCenter(s, center, center, start, maxLen);
            // Even-length palindromes (center between s[center] and s[center+1])
            expandAroundCenter(s, center, center + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                maxLen = len;
                start = left;
            }
            --left;
            ++right;
        }
    }
};
