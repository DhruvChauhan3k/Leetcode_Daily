class Solution {
    int n;
    int ans;                               // global minimum of path-maxima
    const int INF = 1e9;
    vector<vector<int>> g;
    vector<vector<int>> best;              // best[r][c] = lowest path-maximum seen so far
    int dir[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(int r, int c, int curMax) {
        curMax = max(curMax, g[r][c]);     // update running maximum
        if (curMax >= ans) return;         // prune – cannot beat current best
        
        if (r == n - 1 && c == n - 1) {    // reached target
            ans = curMax;                  // update answer
            return;
        }
        
        for (auto& d : dir) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (curMax >= best[nr][nc]) continue; // seen a better or equal way before
            best[nr][nc] = curMax;
            dfs(nr, nc, curMax);
        }
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        g = std::move(grid);
        n   = g.size();
        ans = INF;
        best.assign(n, vector<int>(n, INF));
        
        best[0][0] = g[0][0];
        dfs(0, 0, 0);
        return ans;
    }
};
