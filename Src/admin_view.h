#include <vector>
#include <iostream>
using namespace std;
#include <sstream>
#include <map>

#ifndef ADMIN_VIEV__
#define ADMIN_VIEV__


#include "tools.h"
#include "user_manager.h"
#include "book_manager.h"


class admin_view
{
private:
    user_manager& users;
    Book_manager& books;
public:
  admin_view(user_manager & users,Book_manager & books)
  :users(users),books(books){}
     void display(){
        while(1){
    vector<string>v{"View Profile","Add Book","Logout"};
    int ch=ShowReadMenu(v,"Menu");
    if(ch==1) users.activeUser()->view_profile();
    else if(ch==2){
       books.add_book();
    }
    else {
        users.setActiveUser(nullptr);
        return;
        }
  }
  }
};

#endif
 
 