#include "Page.h"

void Page::init()
{
    _status = "";
    _posts = "";
}

std::string Page::getStatus() const
{
    return _status;
}

std::string Page::getPosts() const
{
    return _posts;
}

void Page::setStatus(const std::string& new_status)
{
    _status = new_status;
}

void Page::addLineToPosts(const std::string& new_line)
{
    if (!_posts.empty())
        _posts += "\n"; // add new line before appending
    _posts += new_line;
}

void Page::clearPosts()
{
    _posts.clear();
}
