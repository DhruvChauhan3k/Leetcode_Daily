class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<digits.size();i++)
        {
            for(int j=i+1;j<digits.size();j++)
            {
                for(int k=j+1;k<digits.size();k++)
                {
                    vector<int>temp(6,0);
                    temp[0]=digits[i]*100+10*digits[j]+digits[k];
                    temp[1]=digits[i]*100+digits[j]+10*digits[k];
                    temp[2]=digits[i]*10+100*digits[j]+digits[k];
                    temp[3]=digits[i]+100*digits[j]+digits[k]*10;
                    temp[4]=digits[i]*10+digits[j]+digits[k]*100;
                    temp[5]=digits[i]+10*digits[j]+100*digits[k];
                    for(auto it:temp )
                    {
                        if(m.find(it)==m.end() and it<1000 and it>=100 and it%2==0)
                        {
                            m[it]++;
                            ans.push_back(it);
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};