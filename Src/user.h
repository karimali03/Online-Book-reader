#include <vector>
#include <iostream>
using namespace std;
#include <sstream>
#include <map>

#ifndef USER__
#define USER__


#include "session.h"
#include "tools.h"



class user
{
private:
    string user_name;
    string password;
    string name;
    string email;
    vector<session>sessions;
    bool admin;
public:
    user()=default;
    user(const string &user,bool rule){
        string s;
        setUserName(user);
        setAdmin(rule);
        cout<<"Enter password (no spaces): ";
        cin>>s; setPassword(s);
        cout<<"Enter your name: ";
        getline(cin,s);getline(cin,s); setName(s);
        cout<<"Enter your email: ";
        cin>>s; setEmail(s);
    }
    void view_profile(){
        cout<<"******* my profile *******\n";
        cout<<"Name "<<getName()<<"\n";
        cout<<"Email "<<getEmail()<<"\n";
        cout<<"User Name "<<userName()<<"\n";
         cout<<"**************************\n";
    }
    void Create_session(Book* book){
        sessions.push_back(session(book));
        sessions.back().start_session();
    }
    vector<string> sessions_info(){
        vector<string>v;
        for(int i=0;i<sessions.size();i++) 
        v.push_back(sessions[i].session_info());
        return v; 
    }
    string userName() const { return user_name; }
    void setUserName(const string &userName) { user_name = userName; }

    string getPassword() const { return password; }
    void setPassword(const string &password_) { password = password_; }

    string getName() const { return name; }
    void setName(const string &name_) { name = name_; }

    string getEmail() const { return email; }
    void setEmail(const string &email_) { email = email_; }

    bool getAdmin() const { return admin; }
    void setAdmin(bool admin_) { admin = admin_; }

    vector<session>getSessions() const { return sessions; }
    void setSessions(const vector<session>&sessions_) { sessions = sessions_; }

};

#endif
