#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Post
{
public:
    string time;
    string author;
    string text;

    Post(const string &t, const string &a, const string &tx);
};

class SocialNetwork
{
private:
    map<string, vector<string>> friends;
    vector<Post> posts;

public:
    void addFriends(const string &user, const vector<string> &list);
    void addPost(const string &time, const string &author, const string &text);
    void showFriendFeed(const string &user);
    void showFriendsOfFriendsFeed(const string &user);
    int countHandshakes(const string &start, const string &target);
};