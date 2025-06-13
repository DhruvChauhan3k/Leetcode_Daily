class Twitter {
public:
    vector<pair<int,int>>all;
    vector<vector<int>>foll;
    Twitter() {
        foll.resize(501,vector<int>(501,-1));
    }
    
    void postTweet(int uid, int tid) {
        all.push_back({uid,tid});
    }
    
    vector<int> getNewsFeed(int u) {
        vector<int>ans;
        int x=all.size()-1;
        while(x>=0 and ans.size()!=10)
        {
            int temp=all[x].first;
            if(temp==u or foll[u][temp]==1)
            {
                ans.push_back(all[x].second);
            }
            x--;
        }
        return ans;
    }
    
    void follow(int foo, int fee) {
        foll[foo][fee]=1;
    }
    
    void unfollow(int foo, int fee) {
        foll[foo][fee]=-1;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */