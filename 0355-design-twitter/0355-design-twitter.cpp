class Twitter {
public:

    // user -> tweets
    // pair = {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // user -> people they follow
    unordered_map<int, unordered_set<int>> following;

    int time = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {

        time++;

        tweets[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        // {time, tweetId, userId, index}
        priority_queue<
            tuple<int, int, int, int>
        > pq;

        // User must see their own tweets
        following[userId].insert(userId);

        // Put latest tweet of every followed user
        for (int user : following[userId]) {
            if (tweets[user].empty())
                continue;
            int index = tweets[user].size() - 1;

            auto [t, tweetId] = tweets[user][index];

            pq.push({t, tweetId, user, index});
        }

        vector<int> ans;

        // We only need 10 tweets
        while (!pq.empty() && ans.size() < 10) {

            auto [t, tweetId, user, index] = pq.top();
            pq.pop();

            ans.push_back(tweetId);

            // Add the previous tweet of this user
            if (index > 0) {

                index--;

                auto [prevTime, prevTweetId] =
                    tweets[user][index];

                pq.push({
                    prevTime,
                    prevTweetId,
                    user,
                    index
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};