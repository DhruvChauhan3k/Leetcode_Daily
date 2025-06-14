
class Solution {
public:
    void dfs(Node*node,Node*copy,vector<Node*>&visit)
    {
        // Node*x=node;
        visit[node->val]=copy;
 
        for(auto it:node->neighbors)
        {
            if(visit[it->val]==NULL)
            {
                Node*temp=new Node(it->val);
                (copy->neighbors).push_back(temp);
                dfs(it,temp,visit);
            }
            else
            {
             (copy->neighbors).push_back(visit[it->val]);   
            }
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        Node*copy=new Node(node->val,{});
        vector<Node*>visit(101,NULL);
        dfs(node,copy,visit);
        return copy;
    }
};