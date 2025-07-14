    class Node{
        public:
        Node*next=NULL;
        Node*prev=NULL;
        int val;
        int key;
        Node(int key,int val){
        this->val=val;
        this->key=key;
        }
    };

class LRUCache {
public:
    int size=0;
    unordered_map<int,Node*>m;
    Node*start;
    Node*end;

    LRUCache(int capacity) {
        size=capacity;
        m.clear();
        start=new Node(-1,-1);
        end=new Node(-1,-1);
        start->next=end;
        end->prev=start;
    }
    void del(Node*tmp){
        Node*back=tmp->prev;
        Node*front=tmp->next;
        back->next=front;
        front->prev=back;
        size++;
    }

    void add(Node*tmp){
        if(size==0){
           Node*tmp=start->next;
           del(tmp);
           m.erase(tmp->key);
        }
        tmp->next=end;
        Node*tmp2=end->prev;
        tmp2->next=tmp;
        end->prev=tmp;
        tmp->prev=tmp2;
        size--;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
             Node*tmp=m[key];
             del(tmp);
             add(tmp);
             return tmp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)==m.end()){
            Node*tmp=new Node(key,value);
            add(tmp);
            m[key]=tmp;
        }
        else
        {
            Node*tmp=m[key];
            tmp->val=value;
            del(tmp);
            add(tmp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */