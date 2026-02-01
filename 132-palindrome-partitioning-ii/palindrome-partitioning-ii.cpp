class Solution {
public:
    vector<int> cutMemo;
    vector<vector<int>> palMemo; // -1: unknown, 0: false, 1: true
    string str;

    // Recursive function to check palindrome and store result
    bool isPalindrome(int i, int j) {
        if (i >= j) return true; // Base case: single char or empty
        
        if (palMemo[i][j] != -1) return palMemo[i][j] == 1;

        if (str[i] == str[j]) {
            // Check the inner part
            bool val = isPalindrome(i + 1, j - 1);
            palMemo[i][j] = val ? 1 : 0;
            return val;
        }
        
        // If characters don't match
        return palMemo[i][j] = 0; // Return false (0)
    }

    int solve(int i, int n) {
        if (i == n) return 0;
        if (cutMemo[i] != -1) return cutMemo[i];

        int minCuts = 1e9;
        
        for (int j = i; j < n; j++) {
            // Calculate palindrome check "On the Go"
            if (isPalindrome(i, j)) {
                minCuts = min(minCuts, 1 + solve(j + 1, n));
            }
        }
        return cutMemo[i] = minCuts;
    }

    int minCut(string s) {
        str = s;
        int n = s.size();
        cutMemo.assign(n, -1);
        // Initialize palindrome memo with -1
        palMemo.assign(n, vector<int>(n, -1));

        return solve(0, n) - 1;
    }
};