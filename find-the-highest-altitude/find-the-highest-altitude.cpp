class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0,maxi=0;
        for(auto it:gain)
        {
            curr+=it;
            maxi=max(curr,maxi);
        }
        return maxi;
    }
};