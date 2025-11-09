#pragma once
#include <string>

class Page
{
public:
    // Initialize an empty page (empty status and posts)
    void init();

    // Getters
    std::string getStatus() const;
    std::string getPosts() const;

    // Setters / actions
    void setStatus(const std::string& new_status);
    void addLineToPosts(const std::string& new_line);
    void clearPosts(); // clear only posts, keep status

private:
    std::string _status;
    std::string _posts; // all posts separated by '\n'
};
