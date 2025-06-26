#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        using State = tuple<int,int,int>;                 // (worstHeightSoFar, r, c)
        priority_queue<State, vector<State>, greater<State>> pq;

        vector<vector<int>> best(n, vector<int>(n, INT_MAX));
        best[0][0] = grid[0][0];
        pq.emplace(grid[0][0], 0, 0);

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [cost, r, c] = pq.top(); pq.pop();
            if (r == n - 1 && c == n - 1) return cost;   // first pop of goal = answer
            if (cost > best[r][c]) continue;             // stale entry

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                int nextCost = max(cost, grid[nr][nc]);  // worst height along this path
                if (nextCost < best[nr][nc]) {
                    best[nr][nc] = nextCost;
                    pq.emplace(nextCost, nr, nc);
                }
            }
        }
        return -1;                                       // grid always solvable, so unreachable
    }
};
