class Solution {
public:
    // Find first interval where end >= target
    int firstEndGE(const vector<vector<int>>& intervals, int target) {
        int low = 0, high = intervals.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (intervals[mid][1] >= target)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    // Find first interval where start > target
    int firstStartGT(const vector<vector<int>>& intervals, int target) {
        int low = 0, high = intervals.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (intervals[mid][0] > target)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();

        // 1. Find left part (non-overlapping)
        int left = firstEndGE(intervals, newInterval[0]);
        for (int i = 0; i < left; ++i) {
            result.push_back(intervals[i]);
        }

        // 2. Merge overlapping intervals
        int right = firstStartGT(intervals, newInterval[1]);
        for (int i = left; i < right; ++i) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        result.push_back(newInterval);

        // 3. Append remaining intervals
        for (int i = right; i < n; ++i) {
            result.push_back(intervals[i]);
        }

        return result;
    }
};
