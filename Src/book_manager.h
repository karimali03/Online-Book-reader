

#include <vector>
#include <iostream>
using namespace std;
#include <sstream>
#include <map>

#ifndef book_manager__
#define book_manager__


#include "book.h"

class Book_manager
{
private:
    map<string,Book*>books;
public:
    Book_manager(){
        load_data();
    }
    ~Book_manager(){
        clear();
    }
    void clear(){
        for(auto & x : books) delete x.second;
        books.clear();
    }

    void load_data(){
        clear();
        vector<string>lines=ReadFileLines("books.txt");
        for(auto x : lines){
        vector<string>content=SplitString(x);    
        Book* book_1=new Book();
        book_1->setISBN(content[0]);
        books[content[0]]=book_1;
        book_1->setAuthorName(content[2]);
        book_1->setBookName(content[1]);
        vector<string>pages;
        for(int i=3;i<content.size();i++) pages.push_back(content[i]);
        book_1->setPages(pages);
        }
    }
     Book* getBook(int id){
         for(auto & x : books){
            id--;
            if(id==0) return x.second;
        }
        return {};
    }
     vector<string> books_list(){
        vector<string>v;
        for(auto &x : books) v.push_back(x.second->bookName());
        return v ; 
    }
    void add_book(){
        string id;
        while(1){
            cout<<"Enter ISBN : "; cin>>id;
            if(books.count(id) || id.empty()){
                cout<<"ISBN is already taken please try again\n";
                continue;
            }
               break;
            }
        Book* new_book=new Book(id);
        books[id]=new_book;
        vector<string>v;
        v.push_back(id),v.push_back(new_book->bookName());
        v.push_back(new_book->authorName());
        for(auto x : new_book->getPages()) v.push_back(x);
        string book;
        for(int i=0;i<v.size();i++){
           if(i)  book+=',';
            book+=v[i];
        }
        v.clear();
        v.push_back(book);
        WriteFileLines("books.txt",v);
        load_data();
    }

    map<string,Book*>getBooks() const { return books; }
    void setBooks(const map<string,Book*>&books_) { books = books_; }
  

};

#endif
