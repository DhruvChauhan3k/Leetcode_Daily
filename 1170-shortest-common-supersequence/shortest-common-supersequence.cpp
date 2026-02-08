#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // 1. Standard LCS DP Table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 2. Backtrack to construct the string
        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                // Character is common (LCS), add it once
                ans += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                // Moving Up: str1[i-1] is not in LCS, so we must add it to Supersequence
                ans += str1[i - 1];
                i--;
            } else {
                // Moving Left: str2[j-1] is not in LCS, so we must add it to Supersequence
                ans += str2[j - 1];
                j--;
            }
        }

        // 3. Add remaining characters
        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        // 4. Reverse result
        reverse(ans.begin(), ans.end());
        return ans;
    }
};