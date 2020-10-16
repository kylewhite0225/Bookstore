#include <string>
#include "Book.h"
using namespace std;

/*
Name: BookstoreManager.h
Author: Kyle White
Date: 10/16/2020
Description: Header file for the BookstoreManager class, which defines
the private members and all methods.
*/

class BookstoreManager
{
private:
    Book* pArr;
    int size;
    int entries;
    void sortBookstore();
    int binarySearch(Book* arr, int l, int r, int ISBN);
    void insertSorted(Book* arr, int entries, Book b, int size);
    
public:
    BookstoreManager();
    ~BookstoreManager();

    void isEmpty();
    void isFull();
    void listSize();
    void print();
    void insert(Book b);
    void remove(Book remove);
    void removePublisher(string removePub);
    void search(Book b);
};