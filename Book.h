#ifndef BOOK
#define BOOK

#include <string>
using namespace std;

/*
Name: Book.h
Author: Kyle White
Date: 10/16/2020
Description: Header file for the Book class, which defines
the private members and all methods.
*/

class Book
{
private:
    string title;
    string authors;
    string publisher;
    int ISBN;
    
public:
    Book();
    Book(string title, int ISBN, string authors, string publisher);
    Book(int ISBN);
    ~Book();

    void setTitle(string title);
    void setAuthors(string authors);
    void setPublisher(string publisher);
    void setISBN(int ISBN);
    string getTitle();
    string getAuthors();
    string getPublisher();
    int getISBN();
    void print();
};
#endif