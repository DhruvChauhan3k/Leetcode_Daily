#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Memoization table initialized to -1
    int memo[366]; // days.length is at most 365

    int solve(int i,vector<int>&days,vector<int>&costs) {
        // Base Case: If we have covered all travel days, cost is 0
        if (i >= days.size()) {
            return 0;
        }

        // Check Memoization
        if (memo[i] != -1) {
            return memo[i];
        }

        // Option 1: Buy 1-Day Pass
        // Covers current day, move to next index i+1
        int option1 = costs[0] + solve(i + 1,days,costs);

        // Option 2: Buy 7-Day Pass
        // Use lower_bound to find the first day that is >= days[i] + 7
        // (i.e., the first day NOT covered by this pass)
        int j = lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin();
        int option2 = costs[1] + solve(j,days,costs);

        // Option 3: Buy 30-Day Pass
        // Find the first day that is >= days[i] + 30
        int k = lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin();
        int option3 = costs[2] + solve(k,days,costs);

        // Store and return the minimum cost
        return memo[i] = min({option1, option2, option3});
    }

    int mincostTickets(vector<int>& d, vector<int>& c) {
        // Initialize memo with -1
        fill(begin(memo), end(memo), -1);
        
        return solve(0,d,c);
    }
};