class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,int>>r(9),c(9),b(9);
        int cnt=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')continue;
                int x=board[i][j]-'0';
                cout<<x<<endl;
                if(r[i].find(x)!=r[i].end())return false;
                if(c[j].find(x)!=c[j].end())return false;
                int dn=(i/3)*3+j/3;
                if(b[dn].find(x)!=b[dn].end())return false;
                b[dn][x]++;
                r[i][x]++;
                c[j][x]++;
            }
        }
        return true;
    }
};