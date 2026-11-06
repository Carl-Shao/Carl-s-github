## Report of Mini Project 2

### Design Choices
I designed this project use OOP. I create two class. 
The responsibility of the Book class is to store information for one book. 
It also provides some method for you to get or set variable. 
ToString method is very easy for you to print information.

The Library class uses an array of Book to manage all books;
You can add books by construct function.
You can also choose to display all the book.
The business logic part such as borrowing and returning is implemented in here;

In Main file, I use do-while loop to get your choice for operating library management system.
And switch to call function which has been identified in Library to implement.

### Some Challenge
1. I want to use "for(Book b : books)" before. 
But I only give three books in library. There are still some null parts in array.
Then I have to change it to "for (int i = 0; i < count; i++)";
2. At the first time when I implement borrow function, 
I just used "count--". Then there is a bug. 
When I tested this system, I find my book disappear from my library.
Then the variable of isAvailable doesn't work 
and it still in Library array but count is only two.


