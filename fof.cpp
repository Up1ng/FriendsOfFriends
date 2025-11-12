#include "fof.hpp"

Post::Post(const string &t, const string &a, const string &tx)
{
    time = t;
    author = a;
    text = tx;
}

void SocialNetwork::addFriends(const string &user, const vector<string> &list)
{
    friends[user] = list;
}

void SocialNetwork::addPost(const string &time, const string &author, const string &text)
{
    posts.push_back(Post(time, author, text));
}

void SocialNetwork::showFriendFeed(const string &user)
{
    cout << "Лента друзей для " << user << ":\n";
    if (!friends.count(user))
    {
        cout << "Нет друзей!\n";
        return;
    }

    for (auto &p : posts)
    {
        for (auto &f : friends[user])
        {
            if (p.author == f)
            {
                cout << p.time << " " << p.author << ": " << p.text << endl;
            }
        }
    }
}

void SocialNetwork::showFriendsOfFriendsFeed(const string &user)
{
    cout << "\nЛента друзей и друзей друзей для " << user << ":\n";

    if (!friends.count(user))
    {
        cout << "Нет друзей!\n";
        return;
    }

    for (auto &p : posts)
    {
        for (auto &f : friends[user])
        {
            if (p.author == f)
            {
                cout << p.time << " " << p.author << ": " << p.text << endl;
            }
        }
    }

    for (auto &p : posts)
    {
        for (auto &f : friends[user])
        {
            for (auto &ff : friends[f])
            {
                if (p.author == ff && ff != user)
                {
                    cout << p.time << " " << p.author << ": " << p.text << endl;
                }
            }
        }
    }
}

int SocialNetwork::countHandshakes(const string &start, const string &target)
{
    if (start == target)
        return 0;

    queue<pair<string, int>> q;
    map<string, bool> visited;

    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        string user = cur.first;
        int dist = cur.second;

        for (auto &f : friends[user])
        {
            if (!visited[f])
            {
                if (f == target)
                    return dist + 1;
                visited[f] = true;
                q.push({f, dist + 1});
            }
        }
    }

    return -1;
}
