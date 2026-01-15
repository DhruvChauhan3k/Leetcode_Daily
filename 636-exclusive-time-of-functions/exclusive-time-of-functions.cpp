class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st; // Stores function IDs
        vector<int> ans(n, 0); // Size should be n, not logs.size()
        int prevTime = 0;

        for (const string& log : logs) {
            stringstream ss(log);
            string id_str, type, timestamp_str;

            // Fix: Use single quotes for the delimiter ':'
            getline(ss, id_str, ':');
            getline(ss, type, ':');
            getline(ss, timestamp_str, ':');

            int id = stoi(id_str);
            int timestamp = stoi(timestamp_str);

            if (type == "start") {
                if (!st.empty()) {
                    // Record time for the function currently on top before it gets paused
                    ans[st.top()] += timestamp - prevTime;
                }
                st.push(id);
                prevTime = timestamp;
            } else {
                // Function ends: add the last bit of time (inclusive +1)
                ans[st.top()] += timestamp - prevTime + 1;
                st.pop();
                // Next possible start time is the next integer
                prevTime = timestamp + 1;
            }
        }
        return ans;
    }
};