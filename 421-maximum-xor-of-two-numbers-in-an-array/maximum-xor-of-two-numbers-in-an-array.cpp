class Trie{
public:
    Trie*node[2];
    Trie*root=NULL;
    void insert(int x)
    {
        if(root==NULL)root=new Trie();
        Trie*n=root;
        for(int i=31;i>=0;i--)
        {
            int a=(x>>i)&1;
            if(n->node[a]==NULL)
            {
                n->node[a]=new Trie();
            }
            n=n->node[a];
        }
    }
    
    int get(int x)
    {
        Trie*n=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int a=!((x>>i)&1);
            if(n->node[a])
            {
                ans=ans|(1<<i);
                n=n->node[a];
            }
            else
            {
                n=n->node[!a];
            }
        }
        return ans;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie*final=new Trie();
        int ans=0;
        for(auto it:nums)final->insert(it);
        for(auto it:nums)
        {
            ans=max(ans,final->get(it));
        }
        return ans;
    }
};