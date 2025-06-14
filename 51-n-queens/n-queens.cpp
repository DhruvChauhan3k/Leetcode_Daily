class Solution {
public:
    bool check(vector<string>&temp,int &n,int r,int &c)
    {
        //col cond
        for(int i=0;i<r;i++)
        {
            if(temp[i][c]=='Q')
            {
                return false;
            }
        }
        //check left wing
        for(int i=r-1,j=c-1;i>=0 and j>=0;j--,i--)
        {
            if(temp[i][j]=='Q')
            {
                return false;
            }
        }
        //check right wing
        for(int i=r-1,j=c+1;i>=0 and j<n ;i--, j++)
        {
            if(temp[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    void generate(vector<vector<string>>&ans,vector<string>&temp,int i,int &n)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int z=0;z<n;z++)
        {
            temp[i][z]='Q';
            if(check(temp,n,i,z))generate(ans,temp,i+1,n);
            temp[i][z]='.';
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        generate(ans,temp,0,n);
        return ans;
    }
};