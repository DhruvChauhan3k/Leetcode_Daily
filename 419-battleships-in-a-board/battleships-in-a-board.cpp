class Solution {
public:
void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&visited){
    visited[i][j]=1;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int newX=dx[k]+i;
        int newY=dy[k]+j;
        if(newX>=0 and newX<board.size() and newY>=0 and newY<board[0].size() and visited[newX][newY]==-1 and board[newX][newY]=='X'){
            dfs(newX,newY,board,visited);
        }
    }
}
    int countBattleships(vector<vector<char>>& board) {
        int r=board.size(),c=board[0].size();
        vector<vector<int>>visited(r,vector<int>(c,-1));
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(visited[i][j]==-1 and board[i][j]=='X'){
                    ans++;
                    dfs(i,j,board,visited);
                }
            }
        }
        return ans;
    }
};