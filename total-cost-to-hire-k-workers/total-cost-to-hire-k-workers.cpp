class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
            priority_queue<int, vector<int>, greater<int> >pq1,pq2;
            long long int ans=0;
            int n=costs.size();
            unordered_map<int,int>m;
            int st=c-1,e=n-c;
            for(int i=0;i<c;i++)
            {
                // if(i==n)break;
                pq1.push(costs[i]);
                m[i]++;
            }
            for(int i=n-1;i>=n-c;i--)
            {
                if(m.find(i)==m.end())
                {
                     pq2.push(costs[i]);
                      m[i]++;
                }
            }
            for(int i=1;i<=k;i++)
            {
                if(pq2.empty())
                {
                    ans+=pq1.top();
                    pq1.pop();
                    st++;
                }
                else if(pq1.empty())
                {
                    ans+=pq2.top();
                    pq2.pop();
                    e--;
                }
               
            else if(pq1.top()<=pq2.top() or pq2.empty())
            {
                ans+=pq1.top();
                pq1.pop();
                st++;
            }
            else if(pq2.top()<pq1.top() or pq1.empty())
            {
                ans+=pq2.top();
                pq2.pop();
                e--;
            }
             if(st<n)
                {
                    if(m.find(st)==m.end())
                    {
                      pq1.push(costs[st]);
                      m[st]++;
                    }
                }
                if(e>=0)
                {
                    if(m.find(e)==m.end())
                    {
                      pq2.push(costs[e]);
                      m[e]++;
                    }
                }
            }
            return ans;
    }
};