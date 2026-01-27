class Solution {
public:
    // Graph: Node -> {Neighbor, Weight}
    unordered_map<string, vector<pair<string, double>>> graph;

    double bfs(string start, string end) {
        // Reject if nodes don't exist in our graph
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
            return -1.0;
        }
        
        // Queue stores {current_node, current_product_from_start}
        queue<pair<string, double>> q;
        q.push({start, 1.0});
        
        unordered_set<string> visited;
        visited.insert(start);
        
        while (!q.empty()) {
            auto [currNode, currVal] = q.front();
            q.pop();
            
            // Found the target? Return the accumulated product
            if (currNode == end) {
                return currVal;
            }
            
            for (auto& neighbor : graph[currNode]) {
                string nextNode = neighbor.first;
                double edgeWeight = neighbor.second;
                
                if (visited.find(nextNode) == visited.end()) {
                    visited.insert(nextNode);
                    // Multiply the weight as we traverse
                    q.push({nextNode, currVal * edgeWeight});
                }
            }
        }
        
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 1. Build the Graph
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            
            graph[u].push_back({v, val});       // u / v = val
            graph[v].push_back({u, 1.0 / val}); // v / u = 1 / val
        }
        
        // 2. Process Queries
        vector<double> results;
        for (auto& q : queries) {
            results.push_back(bfs(q[0], q[1]));
        }
        
        return results;
    }
};