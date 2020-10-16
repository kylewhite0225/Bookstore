#include <iostream>
#include "Book.h"
using namespace std;

Book::Book() {
    title;
    authors;
    publisher;
    ISBN;
}

Book::Book(string title, int ISBN, string authors, string publisher) {
    this->title = title;
    this->authors = authors;
    this->publisher = publisher;
    this->ISBN = ISBN;
}

Book::Book(int ISBN) {
    this->ISBN = ISBN;
    title;
    authors;
    publisher;
}

Book::~Book() {
}

void Book::setTitle(string title) {
    this->title = title;
}

void Book::setAuthors(string authors) {
    this->authors = authors;
}

void Book::setPublisher(string publisher) {
    this->publisher = publisher;
}

void Book::setISBN(int ISBN) {
    this->ISBN = ISBN;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthors() {
    return authors;
}

string Book::getPublisher() {
    return publisher;
}

int Book::getISBN() {
    return ISBN;
}

void Book::print() {
    cout << this->getTitle() << endl;
    cout << this->getAuthors() << endl;
    cout << this->getPublisher() << endl;
    cout << this->getISBN() << endl;
    cout << endl;
}