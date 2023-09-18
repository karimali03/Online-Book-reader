#include<iostream>
#include<vector>
#include<assert.h>
#include<map>
#include<sstream>
using namespace std;


#include "tools.h"
#include "user_manager.h"
#include "book_manager.h"
#include "user_view.h"
#include "admin_view.h"

class online_book_reader
{
private:
   Book_manager* library;
   user_manager* users_data;
public:
    online_book_reader(){
        library=new Book_manager();
        users_data=new user_manager();
    }
    ~online_book_reader(){
        delete library;
        delete users_data;
        library=nullptr;
        users_data=nullptr;
    }

   void start(){
    while(1){
      users_data->Acess_system();
      if(users_data->activeUser()->getAdmin()) {
        auto admin=new admin_view(*users_data,*library);
        admin->display();
      }
      else{
        auto admin=new user_view(*users_data,*library);
        admin->display();
      }
    }
   }
};

 

int main(){
    online_book_reader sys;
    sys.start();
 return 0;
}
