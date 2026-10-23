
class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int timestamp = 0;

public:
    Twitter() {
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        for (auto tweet : tweets[userId]) {
            maxHeap.push(tweet);
        }

        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                maxHeap.push(tweet);
            }
        }

        vector<int> feed;
        while (!maxHeap.empty() && feed.size() < 10) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return feed;
    }
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
