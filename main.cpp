#include "fof.hpp"

int main()
{
     SocialNetwork net;

     net.addFriends("vasya", {"kolya", "petya", "sasha"});
     net.addFriends("sasha", {"vasya", "cool123", "petya"});
     net.addFriends("cool123", {"kolya"});
     net.addFriends("kolya", {"cool123"});

     net.addPost("2014-10-20T08:00:00", "vasya", "Блин, сегодня опять понедельник :(");
     net.addPost("2014-10-20T08:05:00", "cool123", "Ура, понедельник!!!");
     net.addPost("2014-10-20T08:39:00", "kolya", "Какой сегодня день?");

     net.showFriendFeed("vasya");
     net.showFriendsOfFriendsFeed("vasya");

     cout << "\nРукопожатий между vasya и kolya: "
          << net.countHandshakes("vasya", "kolya") << endl;

     cout << "Рукопожатий между vasya и cool123: "
          << net.countHandshakes("vasya", "cool123") << endl;

     return 0;
}
