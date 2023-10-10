#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct Twitter {
  map<int, vector<int>> users;
  vector<pair<int, int>> tweets;
};

int add_user(Twitter* twitter) {
  int lastId = twitter->users.end()->first;
  twitter->users[lastId+1] = {};
  return lastId + 1;
}

void follow(Twitter* twitter, int userId, int followsId) {
  twitter->users[userId].push_back(followsId);
}

void unfollow(Twitter* twitter, int userId, int unfollowId) {
  vector<int>& user_follows = twitter->users[userId];
  for(int i=0; i<user_follows.size(); i++) {
    if(user_follows[i] == unfollowId) {
      auto u = user_follows.begin() + i;
      user_follows.erase(u);
    }
  }
}

void postTweet(Twitter* twitter, int userId) {
  int tweetId = 1;

  if(twitter->users.find(userId) == twitter->users.end()) {
    cout << "Could not find user with id " << userId;
    return;
  }

  if(!twitter->tweets.empty()) {
    tweetId = twitter->tweets.back().second + 1;
  }

  twitter->tweets.push_back(make_pair(userId, tweetId));

}

vector<int> getNewsFeed(Twitter* twitter, int userId, vector<int>& feed) {

  if(twitter->users.find(userId) == twitter->users.end()) {
    cout << "Could not find user with id " << userId;
    return feed;
  }

  int i = 10;

  vector<pair<int, int>>& tweets = twitter->tweets;
  vector<int> users = twitter->users[userId];
  int j = tweets.size() - 1;
  while(i > 0 && j >= 0) {

    pair<int, int> t = tweets[j];
    int target = t.first;

    auto it = find(users.begin(), users.end(), target);

    if(it != users.end() || (target == userId)) {
      feed.push_back(t.second);
      i--;
    }

    j--;
  }
  
  return feed;
}
