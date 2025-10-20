class dsu
{
public:
	vector<int>size,parent;
	dsu(int n)
	{
     size.resize(n+1,1);
     parent.resize(n+1);
    for(int i=0;i<=n;i++)
	{
		parent[i]=i;
	}
	}
	int findpar(int x)
	{
		if(x==parent[x])return x;
		return parent[x]=findpar(parent[x]);
	}
	void join(int a,int b)
	{
		int c=findpar(a);
		int d=findpar(b);
		if(c==d)return;
		if(size[c]<size[d])
		{
            parent[c]=d;
			size[d]+=size[c];
			
		}
		else
		{
			size[c]+=size[d];
			parent[d]=c;
		}
	}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>m;
        dsu ds(accounts.size());
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
               string temp=accounts[i][j];
               if(m.find(temp)==m.end())
               {
                   m[temp]=i;
               }
               else
               {
                   ds.join(m[temp],i);
               }
            }
        }
        vector<vector<string>>ans(accounts.size()),final;
        for(auto it:m)
        {
            string a=it.first;
            int b=ds.findpar(it.second);
            ans[b].push_back(a);
        }
        for(int i=0;i<ans.size();i++)
        {
            vector<string>temp;
            if(ans[i].size()>0)
            {
                temp.push_back(accounts[i][0]);
                sort(ans[i].begin(),ans[i].end());
                for(auto it:ans[i])
                {
                    temp.push_back(it);
                }
                final.push_back(temp);
            }
        }
        return final;
    }
};