class Solution {
public:
   
    int maximumDetonation(vector<vector<int>>& bombs) {
        int maxi=0;
        // sort(bombs.begin(),bombs.end(),comp);
        int n=bombs.size();
        // vector<int>visit(n,-1);
        for(int i=0;i<n;i++)
        {
        //    if(visit[i]==1)continue;
        //    visit[i]=1;
           queue<pair<int,int>>q;
           q.push({i,bombs[i][2]});
           int curr=0;
           vector<int>visit2(n,-1);
           visit2[i]=1;
           while(!q.empty())
           {
               curr++;
               int a=q.front().first;
               int r=q.front().second;
               q.pop();
               for(int j=0;j<n;j++)
               {
                   if(j==a)continue;
                   long long int k=abs(bombs[a][0]-bombs[j][0]);
                   k=k*k;
                   long long int l=abs(bombs[a][1]-bombs[j][1]);
                   l=l*l;
                   if(sqrt(k+l)<=r and visit2[j]==-1)
                   {
                       visit2[j]=1;
                       q.push({j,bombs[j][2]});
                   }
               }
           }
           maxi=max(maxi,curr);
        }
        return maxi;
    }
};