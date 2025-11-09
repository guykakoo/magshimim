#pragma once
#include <string>
#include "User.h"
#include "Page.h"
#include "UserList.h"

class Profile
{
public:
    void init(const User& owner);
    void clear();

    // Getters
    User getOwner() const;
    std::string getPage() const;
    std::string getFriends() const;
    std::string getFriendsWithSameNameLength() const;

    // Actions
    void setStatus(const std::string& new_status);
    void addPostToProfilePage(const std::string& post);
    void clearPage();
    void addFriend(const User& friend_to_add);

private:
    User _owner;
    Page _page;
    UserList _friends;
};
