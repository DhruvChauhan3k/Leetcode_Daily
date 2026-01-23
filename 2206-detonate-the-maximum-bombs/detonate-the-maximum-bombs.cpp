class Solution {
public:
    // Standard DFS to count reachable nodes
    int dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        int count = 1;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                count += dfs(neighbor, graph, visited);
            }
        }
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        // 1. Build the Graph (Adjacency List)
        // graph[i] will store a list of all bombs that bomb 'i' can detonate
        vector<vector<int>> graph(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                // Use Long Long to prevent overflow
                long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                
                // Distance Formula optimized: (x1-x2)^2 + (y1-y2)^2 <= r1^2
                // We avoid sqrt() because it's slow and imprecise
                long long distSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                long long rSq = r1 * r1;
                
                if (distSq <= rSq) {
                    graph[i].push_back(j);
                }
            }
        }
        
        // 2. Run DFS from every node
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            ans = max(ans, dfs(i, graph, visited));
        }
        
        return ans;
    }
};