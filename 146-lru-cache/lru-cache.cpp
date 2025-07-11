class LRUCache {
public:
    class Node {
    public: 
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newnode) {
        Node* temp = tail->prev;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = tail;
        tail->prev = newnode;
    }

    void deleteNode(Node* delnode) {
        Node* prevv = delnode->prev;
        Node* nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int ans = resNode->val;

            deleteNode(resNode);
            addNode(resNode);

            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* curr = m[key];
            deleteNode(curr);
            addNode(curr);
            curr->val = value;
            return;
        }

        if (m.size() == cap) {
            Node* lru = head->next;     // ✅ LRU is right after head
            m.erase(lru->key);
            deleteNode(lru);
        }
            Node *tmp=new Node(key,value);
            addNode(tmp);
            m[key]=tmp;
    }
};
