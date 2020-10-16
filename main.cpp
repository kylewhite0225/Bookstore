#include <iostream>
#include <sstream>
#include "Book.h"
#include "BookstoreManager.h"

using namespace std;

int main() { 
    BookstoreManager bookstoreManager;

    //prints true if the bookstore is empty
    bookstoreManager.isEmpty();

    //insert 4 books
    string title, authors, publisher;
    int isbn;
    string isbnStr;
    for(int i=0;i<4;i++){
        cout << "Enter book title: ";
        // cin>>title;
        getline(cin, title);
        cout << "Enter authors: ";
        // cin>>authors;
        getline(cin, authors);
        cout << "Enter isbn: "; 
        getline(cin, isbnStr);
        cout << "Enter publisher: ";
        // cin>>publisher;
        getline(cin, publisher);
        stringstream convert(isbnStr);
        convert >> isbn;
        Book aBook(title, isbn, authors, publisher);
        bookstoreManager.insert(aBook); 
        cout<<endl;
    }

    //print bookstore
    bookstoreManager.print();

    //search for books
    cout<< "Searching..." <<endl;
    cout<<"ISBN:";
    cin>>isbn;
    Book b2(isbn);
    bookstoreManager.search(b2);

    //remove a book
    cout<< "Removing..." <<endl;
    cout<<"ISBN:";
    cin>>isbn;
    Book b1(isbn);
    bookstoreManager.remove(b1);

    //print bookstore
    bookstoreManager.print();

    //remove books from a particular publisher
    cout<<"Removing publisher"<<endl;
    cout<<"Publisher:";
    cin>>publisher; 
    bookstoreManager.removePublisher(publisher);

    //print bookstore
    bookstoreManager.print();


    //prints the number of books 
    bookstoreManager.listSize();

}

// assume ISBN is a unique value
// delete all ISBN that are duplicates