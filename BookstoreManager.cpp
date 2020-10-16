#include <iostream>
#include "BookstoreManager.h"
using namespace std;

int BookstoreManager::binarySearch(Book* arr, int l, int r, int ISBN)
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid].getISBN() == ISBN) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid].getISBN() > ISBN) 
            return binarySearch(arr, l, mid - 1, ISBN); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, ISBN); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
}

void BookstoreManager::insertSorted(Book* arr, int entries, Book b, int size) {
    int i;
    for(i = entries - 1; (i >= 0 && arr[i].getISBN() > b.getISBN()); i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = b;
}



BookstoreManager::BookstoreManager() {
    this->size = 5;
    this->entries = 0;
    this->pArr = new Book[size];
}

BookstoreManager::~BookstoreManager() {
    delete[] pArr;
}

void BookstoreManager::isEmpty() {
    if (entries == 0) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl; 
    }
}

void BookstoreManager::isFull() {
    if (entries == size) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

void BookstoreManager::listSize() {
    cout << "Current size: " << this->entries << endl;
}

void BookstoreManager::print() {
    for (int i = 0; i < entries; i++) {
        cout << pArr[i].getTitle() << endl;
        cout << pArr[i].getAuthors() << endl;
        cout << pArr[i].getPublisher() << endl;
        cout << pArr[i].getISBN() << endl;
        cout << endl;
    }
}

void BookstoreManager::insert(Book b) {
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
    } else {
        insertSorted(this->pArr, this->entries, b, this->size);
        this->entries++;
    }
}

void BookstoreManager::remove(Book remove) {
    //cout << "removing" << endl;
    // search for del in array
    int i;
    for (i = 0; i < entries; i++) {
        if (pArr[i].getISBN() == remove.getISBN()) {
            break;
        }
    }
    // if del is in array, decrease entries and shift values to the left, removing del
    if (i < entries) {
        for (int j = i; j < entries; j++) {
            pArr[j] = pArr[j+1];
        }
        entries--;
    } else if (i == entries) {
        cout << "Not found." << endl;
    }
}

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