#include "Profile.h"
#include <sstream>

// Initialize profile with owner
void Profile::init(const User& owner)
{
    _owner = owner;
    _page.init();
    _friends.init();
}

// Clear profile data (friends list and page posts)
void Profile::clear()
{
    _friends.clear();
    _page.clearPosts();
}

// Return owner (by copy)
User Profile::getOwner() const
{
    return _owner;
}

// Set new status in the owner's page
void Profile::setStatus(const std::string& new_status)
{
    _page.setStatus(new_status);
}

// Add new post
void Profile::addPostToProfilePage(const std::string& post)
{
    _page.addLineToPosts(post);
}

// Clear all posts from the page
void Profile::clearPage()
{
    _page.clearPosts();
}

// Add new friend to the friends list
void Profile::addFriend(const User& friend_to_add)
{
    _friends.add(friend_to_add);
}

// Get formatted page (status + posts)
std::string Profile::getPage() const
{
    std::ostringstream out;
    out << "Status: " << _page.getStatus() << "\n";
    out << "*******************\n";
    out << "*******************\n";
    out << _page.getPosts();
    return out.str();
}

// Get all friends’ usernames separated by commas
std::string Profile::getFriends() const
{
    std::ostringstream out;
    UserNode* curr = _friends.get_first();

    while (curr != nullptr)
    {
        out << curr->get_data().getUserName();
        curr = curr->get_next();
        if (curr != nullptr)
            out << ",";
    }
    return out.str();
}

// Get friends whose usernames are same length as owner’s username
std::string Profile::getFriendsWithSameNameLength() const
{
    std::ostringstream out;
    UserNode* curr = _friends.get_first();
    size_t len = _owner.getUserName().length();
    bool first = true;

    while (curr != nullptr)
    {
        const std::string& friendName = curr->get_data().getUserName();
        if (friendName.length() == len)
        {
            if (!first)
                out << ",";
            out << friendName;
            first = false;
        }
        curr = curr->get_next();
    }
    return out.str();
}
