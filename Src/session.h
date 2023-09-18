

#include <vector>
#include <iostream>
using namespace std;
#include <sstream>
#include <map>

#ifndef session__
#define session__

#include "book.h"
#include "tools.h"




class session
{

private:
    Book* book;
    int cur_page;
    string date;
public:
    session(Book* book):cur_page(1),book(book){
       setDate();
    };

    string session_info(){ 
	stringstream ss;
	ss <<book->bookName()<<" : "<<cur_page<<"/"<<book->getPagesNumber()
    <<" - "<<getDate();
	return ss.str();
    }
    void start_session(){
        vector<string>v{"Next Page","Previous Page","Stop Reading"};
        while(1){
            cout<<book->get_page(cur_page);
            int ch=ShowReadMenu(v,"Menu");
            if(ch==1){
                if(book->next(cur_page)) cur_page++;
                else{
                    cout<<"This is last Page\n";
                 }
            }
            else if(ch==2){
                if(book->prev(cur_page)) cur_page--;
                else{
                    cout<<"This is First Page\n";
                }
            }
            else {
                cout<<"       End session       \n";
                setDate();
                return;
            }
        }
    }
    string getDate() const { return date; }
    void setDate() { date =current_date(); }

    int curPage() const { return cur_page; }
    void setCurPage(int curPage) { cur_page = curPage; }
};

#endif
