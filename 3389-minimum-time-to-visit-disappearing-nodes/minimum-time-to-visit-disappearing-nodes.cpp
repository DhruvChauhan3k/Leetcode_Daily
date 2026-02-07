class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // 1. Build Adjacency List
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // 2. Standard Dijkstra Setup
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, -1); // Initialize with -1 (unreachable)
        
        // Start at node 0
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Lazy Deletion: If we found a shorter path to u before, skip this one
            // Also crucial: If this path arrived AFTER u disappeared, ignore it (though the 'if' below handles this too)
            if (d > dist[u] && dist[u] != -1) continue;

            for (auto& [v, weight] : adj[u]) {
                int newTime = d + weight;
                
                // CRITICAL CHECK:
                // 1. Is this path shorter than what we found before?
                // 2. AND does the node 'v' still exist at 'newTime'?
                if (newTime < disappear[v] && (dist[v] == -1 || newTime < dist[v])) {
                    dist[v] = newTime;
                    pq.push({newTime, v});
                }
            }
        }

        return dist;
    }
};