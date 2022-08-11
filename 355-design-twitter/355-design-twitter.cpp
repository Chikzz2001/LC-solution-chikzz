class Twitter {
    map<int,set<int>>followers;
    map<int,set<int>>following;
    vector<pair<int,int>>msgs;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        following[userId].insert(userId);
        msgs.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
       for(int i=msgs.size()-1;i>=0;i--)
       {
           if(following[userId].count(msgs[i].first))
           {
               res.push_back(msgs[i].second);
           }
           if(res.size()==10)return res;
       }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        following[followerId].erase(followeeId);
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