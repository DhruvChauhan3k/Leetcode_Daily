class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>v={1,2,3,4,5,6,7,8,9};
        vector<int>ans;
        for(int i=0;i<9;i++)
        {
            int no=0;
            for(int j=i;j<9;j++)
            {
                no=no*10+v[j];
                if(no>=low and no<=high)ans.push_back(no);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};