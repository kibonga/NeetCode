// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Design_twitter.h"

int main()
{
  Twitter* twitter = new Twitter();

  int user1 = add_user(twitter);
  int user2 = add_user(twitter);
  int user3 = add_user(twitter);
  int user4 = add_user(twitter);
   
  // User1
  follow(twitter, user1, 2);
  follow(twitter, user1, 3);
  follow(twitter, user1, 4);

  // User2 
  follow(twitter, user2, 1);
  follow(twitter, user2, 4);

  // User3
  follow(twitter, user3, 1);
  follow(twitter, user3, 2);

  // User4 
  follow(twitter, user4, 1);
  follow(twitter, user4, 3);

  postTweet(twitter, user1);  
  postTweet(twitter, user1);  
  postTweet(twitter, user3);  
  postTweet(twitter, user2);  
  postTweet(twitter, user2);  
  postTweet(twitter, user4);  
  postTweet(twitter, user4);  

  vector<int> feed;
  getNewsFeed(twitter, user1, feed);

  cout << "Tweet ids = ";
  for(auto& f : feed) {
    cout << f << " "; 
  }
  cout << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
