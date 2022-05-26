#CS300 - Data Structures - A Bookstore Application

The class `Book` includes the following members:
+ title, 
+ authors, 
+ publisher, 
+ ISBN

Member functions to perform the various operations on the objects of `Book` are included, such as setters, getters, constructors, and destructors.

A `BookstoreManager` class which creates a dynamic array of type `Book` provides the following operations on books in the array within a given time-complexity.

## The Functionalities available in BookstoreManager
| Function   | Time-complexity |
|----------|:-------------:|
| ``` isEmpty() ``` : returns true if the array is empty, otherwise false | O(1) |
| ``` isFull() ```: returns true if the array is full, otherwise false | O(1) |
| ``` listSize() ```: prints the number of books in the array | O(1) |
| ``` print() ```: prints the content of the array | O(n) |
| ``` insert(Book) ```: asks user to enter new book info, and it adds the book to the array in sorted order. If array is full, it’ll double the size of the array | O(n) |
| ``` remove(Book) ```: asks user to enter ISBN info, and it removes the book from the array; shifts the other elements up in the array. Prints “Not Found” if search fails | O(n) |
| ``` removePublisher(string) ```: asks user to enter publisher name, and it removes all the books with the same publisher from the array; shifts the other elements up in the array. Prints “Not Found” if search fails. | O(n) |   
| ``` search(Book) ```: asks user to enter ISBN or title, and prints the content of the book. Prints “Not Found”, if book is not found | O(logn) |  


## Sample Output:
###### user inputs are given in bold

> true
>
> Enter book title: **C++: Programming Basics**  
> Enter authors: **Nathan Clark**  
> Enter ISBN: **154296**  
> Enter publisher: **CreateSpace**  
>  
> Enter book title: **Data Structures & Algorithm Analysis in C++**  
> Enter authors: **Mark Weiss**  
> Enter ISBN: **132847**  
> Enter publisher: **Pearson**  
>  
> Enter book title: **Introduction to Programming Using Python**  
> Enter authors: **Daniel Liang**  
> Enter ISBN: **147231**  
> Enter publisher: **Pearson**  
>  
> Enter book title: **Introduction to Algorithms**  
> Enter authors: **Thomas H. Cormen , Charles E. Leiserson**  
> Enter ISBN: **189352**  
> Enter publisher: **MIT**  
>  
> Data Structures & Algorithm Analysis in C++  
> by Mark Weiss  
> 132847  
> Pearson  
>  
> Introduction to Programming Using Python  
> Daniel Liang  
> 147231  
> Pearson  
>   
> C++: Programming Basics  
> by Nathan Clark  
> 154296  
> CreateSpace  
>   
> Introduction to Algorithms  
> Thomas H. Cormen , Charles E. Leiserson  
> 189352  
> MIT  
>   
> Searching…  
> ISBN: **147231**  
> Introduction to Programming Using Python  
> Daniel Liang  
> 147231  
> Pearson  
>   
> Removing…  
> ISBN: **154296**  
>   
> Data Structures & Algorithm Analysis in C++  
> by Mark Weiss  
> 132847  
> Pearson  
>   
> Introduction to Programming Using Python  
> Daniel Liang  
> 147231  
> Pearson  
>   
> Introduction to Algorithms  
> Thomas H. Cormen , Charles E. Leiserson  
> 189352  
> MIT  
>   
> Removing all books for a publisher  
> Publisher: **Pearson**  
>   
> Introduction to Algorithms  
> Thomas H. Cormen , Charles E. Leiserson  
> 189352  
> MIT    
> 1  
