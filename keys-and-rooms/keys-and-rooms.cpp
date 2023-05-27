class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        int n=rooms.size();
        q.push(0);
        // vector<int>degree(n,0);
        // for(int i=0;i<n;i++)
        // {
        //     for(auto it:rooms[i])
        //     {
        //         if(it==i)continue;
        //         degree[it]++;
        //     }
        // }
        // degree[0]=0;
        int x=0;
        vector<int>visit(n,0);
        visit[0]=1;
        while(!q.empty())
        {
            x++;
            int k=q.front();
            q.pop();
           for(auto it:rooms[k])
           {
            //    degree[it]--;
               if(visit[it]==0)
               {
                   visit[it]=1;
                   q.push(it);
               }
           }
        }
        if(x==n)return true;
        return false;
    }
};