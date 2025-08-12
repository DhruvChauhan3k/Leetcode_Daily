
class Solution {
public:
    int minimumDeletions(std::string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }

        // right_a stores the count of 'a's to the right of the current split point.
        // Initially, it's the total count of 'a's in the entire string.
        int right_a = 0;
        for (char c : s) {
            if (c == 'a') {
                right_a++;
            }
        }

        // left_b stores the count of 'b's to the left of the current split point.
        int left_b = 0;

        // Initialize min_deletions with the cost of deleting all 'a's
        // (i.e., making the string all 'b's).
        int min_deletions = right_a;

        // Iterate through the string, effectively moving the split point.
        for (char c : s) {
            if (c == 'a') {
                // If the current char is 'a', it moves from the right side
                // of the split to the left. So we decrease the count of 'a's
                // that might need to be deleted from the right.
                right_a--;
            } else { // c == 'b'
                // If the current char is 'b', it's now on the left side
                // of the split. It's a 'b' that would need to be deleted.
                left_b++;
            }

            // The cost for the current split is the sum of 'b's on the left
            // and 'a's on the right. Update the minimum.
            min_deletions = std::min(min_deletions, left_b + right_a);
        }

        return min_deletions;
    }
};
