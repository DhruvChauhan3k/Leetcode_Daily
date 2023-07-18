class Bank {
public:
vector<long long>bal;
int n=0;
    Bank(vector<long long>& balance) {
        bal=balance;
        n=bal.size();
    }
    
    bool transfer(int a1, int a2, long long m) {
        if(a1<1 or a1>n or a2<1 or a2>n)return false;
        if(bal[a1-1]>=m)
        {
            bal[a1-1]-=m;
            bal[a2-1]+=m;
        }
        else
        {
            return false;
        }
        return true;
    }

    bool deposit(int a, long long m) {
        if(a<1 or a>n)return false;
        bal[a-1]+=m;
        return true;
    }
    
    bool withdraw(int a, long long m) {
        if(a<1 or a>n)return false;
        if(bal[a-1]<m)return false;
        bal[a-1]-=m;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */