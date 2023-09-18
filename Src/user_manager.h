#include <vector>
#include <iostream>
using namespace std;
#include <sstream>
#include <map>

#ifndef USER_manager__
#define USER_manager__


#include "user.h"
#include "tools.h"


 class user_manager
 {
 private:
    map<string,user*>users;  
    user* active_user;
 public:
    user_manager():active_user(nullptr){
        load_data();
    };
    ~user_manager(){
        clear();
    };
    void load_data(){
        clear();
        vector<string>lines = ReadFileLines("users.txt");
        for(auto & x : lines){
        vector<string>data=SplitString(x);    
        user* admin=new user();
        admin->setUserName(data[0]);
        admin->setAdmin(data.back()=="0");
        admin->setEmail(data[3]);
        admin->setName(data[2]);
        admin->setPassword(data[1]);
        users[data[0]]=admin;
        }
    }

    void clear(){
		for (auto pair : users) {
			delete pair.second;
		}
		users.clear();
		active_user= nullptr;
	}

    void sing_in(){
         cout<<"******** sign in ********\n";
        while(1){
            string name,pass;
            cout<<"Enter user name:"; cin>>name;
            cout<<"Enter password: "; cin>>pass;
            if(users.count(name) &&users[name]->getPassword()==pass){
                active_user=users[name];
                break;
            }
            cout<<"Wrong user name or password/n";
            cout<<"please try again\n";
        }
         cout<<"*************************\n";
    }
    void add_to_files(string name){
        string add;
        add+=name;
         add.push_back(',');
        add+=users[name]->getPassword();
        add.push_back(',');
        add+=users[name]->getName();
        add.push_back(',');
        add+=users[name]->getEmail();
        add.push_back(',');
        add.push_back('0');
        vector<string>v={add};
       WriteFileLines("users.txt",v);
       load_data();
    }
    void sign_up(){
        cout<<"******** sign up ********\n";
        while(1){
            string name;
            cout<<"Enter user name (no spaces): "; cin>>name;
            if(users.count(name) || name.empty()){
                cout<<"user name is already taken please try again\n";
                continue;
            }
            user* new_user=new user(name,false);
            users[name]=new_user;
            add_to_files(name);
             break;
        }
        cout<<"*************************\n";
        sing_in();
    }
    void Acess_system(){
        vector<string>menu{"Sign Up","Login in"};
        int ch=ShowReadMenu(menu,"Menu");
        if(ch==1) sign_up();
        else sing_in();
        cout<<"Hello "<<active_user->getName()<<" | ";
        if(active_user->getAdmin()) cout<<"Admin ";
        else cout<<"User ";
        cout<<"View\n";
    }
    
    user* activeUser() const { return active_user; }
    void setActiveUser(user* activeUser) { active_user = activeUser; }

    map<string,user*>getUsers() const { return users; }
    void setUsers(const map<string,user*>&users_) { users = users_; }

 };
 
#endif
