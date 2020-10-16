#include <iostream>
#include "Book.h"
using namespace std;

/*
Name: Book.cpp
Author: Kyle White
Date: 10/16/2020
Description: The Book class allows the user to create objects which store information
in the private members title, authors, publisher, and ISBN. Methods include
setters, getters, a print function, as well the default and two overloaded constructors.
*/

// The default constructor initializes all fields.
Book::Book() {
    title;
    authors;
    publisher;
    ISBN;
}

// The constructor accepts arguments for all four fields and sets them accordingly.
Book::Book(string title, int ISBN, string authors, string publisher) {
    this->title = title;
    this->authors = authors;
    this->publisher = publisher;
    this->ISBN = ISBN;
}

// This constructor creates a book object with empty fields except for ISBN, only for searching
// function.
Book::Book(int ISBN) {
    this->ISBN = ISBN;
    title;
    authors;
    publisher;
}

// Destructor
Book::~Book() {
}

// The setTitle method sets the book object title field to the provided argument.
void Book::setTitle(string title) {
    this->title = title;
}

// The setAuthors method sets the book object authors field to the provided argument.
void Book::setAuthors(string authors) {
    this->authors = authors;
}

// The setPublisher method sets the book object publisher field to the provided argument.
void Book::setPublisher(string publisher) {
    this->publisher = publisher;
}

// The setISBN method sets the book object ISBN field to the provided argument.
void Book::setISBN(int ISBN) {
    this->ISBN = ISBN;
}

// getTitle method returns the title.
string Book::getTitle() {
    return title;
}

// getAuthors method returns the authors.
string Book::getAuthors() {
    return authors;
}

// getPublisher method returns the publisher.
string Book::getPublisher() {
    return publisher;
}

// getISBN method returns the ISBN.
int Book::getISBN() {
    return ISBN;
}

// The print function prints the contents of the book object.
void Book::print() {
    cout << this->getTitle() << endl;
    cout << this->getAuthors() << endl;
    cout << this->getPublisher() << endl;
    cout << this->getISBN() << endl;
    cout << endl;
}