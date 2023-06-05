class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;       //to store all susbets
        vector<int> curr;         //to store current individual subset (that we will build)
        sort(nums.begin(),nums.end());      //sort the array so that duplicates are adjacent 
        helper(nums,ans,curr,0);       //we start from index 0
        return ans;
        
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int idx)
    {
       if(idx==nums.size())
       {
           ans.push_back(temp);
           return;
       }
       temp.push_back(nums[idx]);
       helper(nums,ans,temp,idx+1);
       temp.pop_back();
       while(idx<nums.size()-1 and nums[idx]==nums[idx+1])idx++;
       helper(nums,ans,temp,idx+1);
    }  
};