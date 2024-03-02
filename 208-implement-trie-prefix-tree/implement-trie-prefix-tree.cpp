class Trie {
public:
int end;
Trie *node[26];
Trie*root;
    Trie() {
        end=0;
        for(int i=0;i<26;i++)node[i]=NULL;
        root=NULL;
    }
    
    void insert(string word) {
        if(root==NULL)root=new Trie();
        Trie*n=root;
        for(auto x:word)
        {
            if(n->node[x-'a']==NULL)n->node[x-'a']=new Trie();
            n=n->node[x-'a'];
        }
        n->end++;
    }
    
    bool search(string word) {
        if(root==NULL)return false;
        Trie*n=root;
        for(auto it:word)
        {
            if(n->node[it-'a']==NULL)return false;
            n=n->node[it-'a'];
        }
        return n->end>0;
    }
    
    bool startsWith(string word) {
        if(root==NULL)return false;
        Trie*n=root;
        for(auto it:word)
        {
            if(n->node[it-'a']==NULL)return false;
            n=n->node[it-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */