class DetectSquares {
public:
    // 2D array to store the frequency of each point (0 <= x, y <= 1000)
    int cnt[1001][1001] = {};
    
    // List to store all points added so far (to iterate over them)
    vector<pair<int, int>> points;

    DetectSquares() {
        // Reset the array (optional in LeetCode as it's fresh per test case, 
        // but good practice)
    }
    
    void add(vector<int> point) {
        // 1. Update frequency in O(1)
        cnt[point[0]][point[1]]++;
        
        // 2. Store the point in our list for iteration
        points.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int qx = point[0];
        int qy = point[1];
        int ans = 0;

        // Iterate through all existing points to find potential diagonals
        for (auto& p : points) {
            int px = p.first;
            int py = p.second;

            // Step 1: Filter invalid diagonals
            // If the point is the same as query, or if |dx| != |dy|, it's not a square diagonal
            if (abs(qx - px) != abs(qy - py) || qx == px) {
                continue;
            }

            // Step 2: Calculate the coordinates of the other two missing corners
            // We have Query(qx, qy) and Point(px, py). 
            // The other corners must be at (qx, py) and (px, qy).
            
            // Step 3: Add the product of their frequencies
            // If any corner doesn't exist, count is 0, so adding 0 changes nothing.
            ans += cnt[qx][py] * cnt[px][qy];
        }
        
        return ans;
    }
};