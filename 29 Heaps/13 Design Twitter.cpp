class Twitter
{
    struct Tweet
    {
        int tweetId;
        int time;
        Tweet(int a, int b) : tweetId(a), time(b) {};
    };
    int time;
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> followings;

    class cmp
    {
    public:
        bool operator()(Tweet &a, Tweet &b) { return a.time > b.time; }
    };

public:
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back(Tweet(tweetId, time++));
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<Tweet, vector<Tweet>, cmp> pq;
        // my post
        if (tweets.find(userId) != tweets.end())
        {
            for (auto el : tweets[userId])
            {
                pq.push(el);
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        // my following posts
        if (followings.find(userId) != followings.end())
        {
            for (auto el : followings[userId])
            {
                if (tweets.find(el) != tweets.end())
                {
                    for (auto el2 : tweets[el])
                    {
                        pq.push(el2);
                        if (pq.size() > 10)
                            pq.pop();
                    }
                }
            }
        }
        vector<int> ans;
        while (!pq.empty())
        {
            auto [tweetId, time] = pq.top();
            pq.pop();
            ans.push_back(tweetId);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        if (followeeId == followerId)
            return;
        followings[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followings.find(followerId) != followings.end())
        {
            followings[followerId].erase(followeeId);
        }
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