bool comp(pair<int,int>a,pair<int,int>b)
{
    return a.first<=b.first;
}
class Solution {
public:
    long long int check(vector<pair<long long int,long long int>>&v,long long int x)
    {
        long long int take=0;
        for(long long int i=0;i<v.size();i++)
        {
            take+=v[i].second;
            if(take>=x)return v[i].first;
        }
        return x;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        unordered_map<long long int,long long int>m;
        long long int n=nums.size(),ans=0;
        for(long long int i=0;i<n;i++)
        {
            m[nums[i]]+=cost[i];
        }
        vector<pair<long long int,long long int>>v;
        long long int sum=0;
        for(auto it:m)
        {
            v.push_back({it.first,it.second});
            sum+=it.second;
        }
        sort(v.begin(),v.end(),comp);
        long long int x=check(v,sum/2+1);
        for(long long int i=0;i<v.size();i++)
        {
            ans+=(abs(v[i].first-x)*(v[i].second));
        }
        return ans;
    }
};