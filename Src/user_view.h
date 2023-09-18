#include <vector>
#include <iostream>
using namespace std;
#include <sstream>
#include <map>

#ifndef USER_VIEV__
#define USER_VIEV__


#include "tools.h"
#include "user_manager.h"
#include "book_manager.h"





class user_view
{
private:
    user_manager& users;
    Book_manager& books;
public:
  user_view(user_manager & users,Book_manager & books)
  :users(users),books(books){}
  
    void display(){
        while(1){
    vector<string>v{"View Profile","List & select from my Reading History"
    ,"List & select from Available Books","Logout"};
    int ch=ShowReadMenu(v,"Menu");
    if(ch==1) users.activeUser()->view_profile();
    else if(ch==2){
        vector<string>v=users.activeUser()->sessions_info();
        if(v.empty()){
            cout<<"There is no old sessions\n\n";
            continue;
        }
        int ch=ShowReadMenu(v,"Menu");
        if(ch==0) continue;
        users.activeUser()->getSessions()[ch-1].start_session();
    }
    else if(ch==3){
        vector<string>v=books.books_list();
        int ch=ShowReadMenu(v,"Menu");
        users.activeUser()->Create_session(books.getBook(ch));
    }
    else {
        users.setActiveUser(nullptr);
        return;
        }
  }
  }
};


#endif
