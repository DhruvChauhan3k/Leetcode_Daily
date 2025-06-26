#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<vector<int>> g;
    
    // --- can we reach (n-1,n-1) if the water is at level t? (standard BFS) ---
    bool canReach(int t) {
        if (g[0][0] > t) return false;          // start already under water
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        q.emplace(0, 0);
        vis[0][0] = 1;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == n - 1 && c == n - 1) return true;     // reached goal
            
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (vis[nr][nc] || g[nr][nc] > t) continue; // blocked or already seen
                vis[nr][nc] = 1;
                q.emplace(nr, nc);
            }
        }
        return false;                                      // no path at this t
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        g.swap(grid);
        n = g.size();
        
        int lo = max(g[0][0], g[n-1][n-1]);   // water must be at least this high
        int hi = n * n - 1;                   // max possible elevation
        
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (canReach(mid)) hi = mid;      // path exists → try lower water
            else               lo = mid + 1;  // need deeper water
        }
        return lo;                            // == hi
    }
};
