#include <iostream>
#include "BookstoreManager.h"
using namespace std;

/*
Name: BookstoreManager.cpp
Author: Kyle White
Date: 10/16/2020
Description: The BookstoreManager class includes the private members pArr, size, entries
and two helper functions binarySearch and insertSorted. Public functions are provided to
access private members as well as search, remove, remove all matching one publisher, insert,
list size, print, and state if full or empty.
*/

int BookstoreManager::binarySearch(Book* arr, int start, int end, int ISBN)
{ 
    if (end >= start) { 
        // Calculate mid
        int mid = start + (end - start) / 2; 
  
        // If the element is present at the middle, return mid
        if (arr[mid].getISBN() == ISBN) 
            return mid; 
  
        // If element is smaller than mid, then it is located in left subarray 
        if (arr[mid].getISBN() > ISBN)
            // Recursively call binarySearch with the left subarray.
            return binarySearch(arr, start, mid - 1, ISBN); 
  
        // Else the element is located in the right subarray
        // Recursively call binarySearch with the right subarray.
        return binarySearch(arr, mid + 1, end, ISBN); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
}

void BookstoreManager::insertSorted(Book* arr, int entries, Book b, int size) {
    int i;
    // Loop through array from final element until the loop reaches a 
    for(i = entries - 1; (i >= 0 && arr[i].getISBN() > b.getISBN()); i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = b;
}


// Default constructor sets the size of the bookstore to 5, sets number of entries to 0,
// and sets pArr to a new Book array.
BookstoreManager::BookstoreManager() {
    this->size = 5;
    this->entries = 0;
    this->pArr = new Book[size];
}

// Destructor deletes pArr
BookstoreManager::~BookstoreManager() {
    delete[] pArr;
}

// The isEmpty function prints true if the number of entries is equal to 0.
void BookstoreManager::isEmpty() {
    if (entries == 0) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl; 
    }
}

// The isFull function prints true if the number of entries is equal to the size of the array.
void BookstoreManager::isFull() {
    if (entries == size) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

// The listSize function prints the current number of entries.
void BookstoreManager::listSize() {
    cout << "Current size: " << this->entries << endl;
}

// The print function loops through the array and prints out each element stored in each Book object.
void BookstoreManager::print() {
    for (int i = 0; i < entries; i++) {
        cout << pArr[i].getTitle() << endl;
        cout << pArr[i].getAuthors() << endl;
        cout << pArr[i].getPublisher() << endl;
        cout << pArr[i].getISBN() << endl;
        cout << endl;
    }
}

// The insert function uses the helper function insertSorted to insert a new element 
// in sorted order into the array. It increases capacity as needed.
void BookstoreManager::insert(Book b) {
    // Use binarySearch function to search for currently existing ISBNs.
    // Returns index of found item, otherwise returns -1 if not found.
    int ISBN = b.getISBN();
    int result = binarySearch(this->pArr, 0, this->entries, ISBN);
    if (result != -1) {
        cout << "Error: ISBN already exists in bookstore." << endl;
        return;
    }
    
    // If the array is at maximum capacity, create a new array with size*2
    // then loop through original array and add the new element with insertSorted function.
    if (this->entries >= this->size) {
        Book* newArr = new Book[this->size*2];
        for (int i = 0; i < entries; i++) {
            newArr[i] = this->pArr[i];
        }
        delete[] pArr;
        pArr = newArr;
        this->size = size*2;
        insertSorted(this->pArr, this->entries, b, this->size);
        this->entries++;
    // If array is not at maximum capacity, add new element using insertSorted function.    
    } else {
        insertSorted(this->pArr, this->entries, b, this->size);
        this->entries++;
    }
}

// The remove function first searches for the element, then shifts all values to the left
void BookstoreManager::remove(Book remove) {
    // search for remove in array, break when i reaches the matching element
    int i;
    for (i = 0; i < entries; i++) {
        if (pArr[i].getISBN() == remove.getISBN()) {
            break;
        }
    }
    // if remove is in array, decrease entries and shift values to the left, removing remove
    if (i < entries) {
        for (int j = i; j < entries; j++) {
            pArr[j] = pArr[j+1];
        }
        entries--;
        cout << endl;
    } else if (i == entries) {
        cout << "Not found." << endl;
    }
}

// The removePublisher method first creates a pointer to a new book array newArr,
// then it creates a new integer newEntries to keep track of how many objects are
// copied into the new array. The loop finds any non-matching values and copies them,
// then the old array is deleted before the pointer is assigned to the new array
// and the current entries value is set to newEntries.
void BookstoreManager::removePublisher(string removePub) {
    // Create a new Book* array to copy non-matching items into
    Book* newArr = new Book[this->size];
    // Create newEntries to keep track of new index as items are copied over
    int newEntries = 0;
    // Loop through existing array
    for (int i = 0; i < entries; i++) {
        string currentPublisher = pArr[i].getPublisher();
        // if the currentPublisher value does NOT match removePub, it gets copied
        // into the new array
        if (currentPublisher != removePub) {
            newArr[newEntries] = this->pArr[i];
            newEntries++;
        }
    }
    // Delete old array
    delete[] pArr;
    // Assign pArr to the new array
    pArr = newArr;
    // Assign entries to newEntries;
    this->entries = newEntries;
}

// The search method calls upon the recursive binarySearch function
// to return the index of the found item (or prints Not Found). Then the
// print method is called.
void BookstoreManager::search(Book b) {
    int ISBN = b.getISBN();
    // Driver code for binarySearch function. Returns index of found item, otherwise returns
    // -1 if not found.
    int result = binarySearch(this->pArr, 0, this->entries, ISBN);
    if (result == -1) {
        cout << "Not found." << endl;
    } else {
        this->pArr[result].print();
    }
}