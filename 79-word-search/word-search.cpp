class Solution {
public:
    bool dfs(vector<vector<char>>& board,string&word,int i,int j,int x)
    {
        if(x>=word.size())return true;
        if(i>=board.size() or j>=board[0].size() or board[i][j]!=word[x])return false;
        char tmp=board[i][j];
        board[i][j]='*';
        bool a=dfs(board,word,i+1,j,x+1);
        bool b=dfs(board,word,i,j+1,x+1);
        bool c=dfs(board,word,i-1,j,x+1);
        bool d=dfs(board,word,i,j-1,x+1);
        board[i][j]=tmp;
        return a or b or c or d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                // vector<vector<bool>>visited(board.size()+1,vector<bool>(board[0].size()+1,false));
                if(dfs(board,word,i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};