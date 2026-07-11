class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweet;
    unordered_map<int, unordered_set<int>> follower;
    int timer = 0;
    Twitter() {

    }
    void postTweet(int userId, int tweetId)
    {
        tweet[userId].push_back({timer++, tweetId});
    }
    vector<int> getNewsFeed(int userId)
    {
        vector<pair<int, int>> pairs;
        vector<int> ans;
        for (auto &p : tweet[userId])
        pairs.push_back(p);
        for (int followee : follower[userId])
        {
            for (auto &p : tweet[followee])
            pairs.push_back(p);
        }
        sort(pairs.begin(), pairs.end(),
            [](pair<int,int> a, pair<int,int> b)
            {
                return a.first > b.first;
            });
        for (int i = 0; i < min(10, (int)pairs.size()); i++)
        ans.push_back(pairs[i].second);
        return ans;
    }
    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
        return;
        follower[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId)
    {
        follower[followerId].erase(followeeId);
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