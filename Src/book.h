

#include <vector>
#include <iostream>
using namespace std;
#include <sstream>

#ifndef book__
#define book__

class Book
{
private:
    string ISBN;
    string book_name;
    string author_name;
    vector<string>pages;
public:
    Book()=default;
    Book(const string& isbn){
        setISBN(isbn);
        string s; 
        int n;
        cout<<"Enter Book Title: "; 
        getline(cin,s); getline(cin,s);
        setBookName(s);
        cout<<"Enter Author Name: "; getline(cin,s);
        setAuthorName(s);
        while(1){
        cout<<"Enter Number of pages: "; cin>>n;
        if(n>0) break;
        cout<<"Please Enter a valid number\n";
        }
        vector<string>v(n);
        getline(cin,s);
        for(int i=0;i<n;i++) {
            cout<<"Enter content of page #"<<i+1<<": ";
            getline(cin,v[i]);
            }
        setPages(v);
    } 
    int getPagesNumber() const {
        return (int)pages.size();
    }
    bool next(int page) const{
        return page!=pages.size();
    }
    bool prev(int page) const {
        return page!=1;
    }
    string get_page(int page) const {
        stringstream s;
        s<<"Current Page "<<page<<"/"<<pages.size()<<"\n"<<pages[page-1]<<"\n";
        return s.str();
    } 
    string iSBN() const { return ISBN; }
    void setISBN(const string &iSBN) { ISBN = iSBN; }

    string bookName() const { return book_name; }
    void setBookName(const string &bookName) { book_name = bookName; }

    string authorName() const { return author_name; }
    void setAuthorName(const string &authorName) { author_name = authorName; }

    vector<string>getPages() const { return pages; }
    void setPages(const vector<string>&pages_) { pages = pages_; }
};


#endif
