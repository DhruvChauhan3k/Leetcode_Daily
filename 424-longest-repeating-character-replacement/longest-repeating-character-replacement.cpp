class Solution {
public:
     int characterReplacement(string s, int k) {
        unordered_map<char, int> alphabets;
        int ans = 0;
        int left = 0;
        int right = 0;
        int maxf = 0;

        for (right = 0; right < s.size(); right++) {
            alphabets[s[right]]++;
            maxf = max(maxf, alphabets[s[right]]);

             if((right - left + 1) - maxf > k) {
                alphabets[s[left]]--;
                left++;
            } 
            ans = max(ans, (right - left + 1));
            
        }

        return ans;
    }
};
