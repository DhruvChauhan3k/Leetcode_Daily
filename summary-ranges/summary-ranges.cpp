class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.size()==0)return ans;
        string s=to_string(nums[0]);
        int check=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]+1)
            {
               if(check+1!=i)
               {
                 s+="->"+to_string(nums[i-1]);
                 ans.push_back(s);
                 check=i;
                 s=to_string(nums[i]);
               }
               else
               {
                   ans.push_back(s);
                   check=i;
                   s=to_string(nums[i]);
               }
            }
        }
        if(check!=nums.size()-1)
        {
            s+="->"+to_string(nums[nums.size()-1]);
            ans.push_back(s);
        }
        else
        {
            s=to_string(nums[nums.size()-1]);
            ans.push_back(s);
        }
        return ans;
    }
};