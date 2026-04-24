# Project of Library Management System

ps: this report use markdown to show. Please open it in markdown

This project use linked list to manage the book 

---

### The design of class

#### class Book

This class claim the book ID, book title, author and status to store the basic information of each book. Initialized the book by ID, title and author. Each book begin with status "Available".

There are also some functions to provide port of getting basic information and change the status when you borrow or return the book.

#### Struct Book Node

This structure is used to initialize every book node. Each node has two parts: data and pointer. The data stores the Book class and the other stores a pointer which is pointing the next book node structure.

When initialized the nook node, data part enter the Book class and pointer points null point first.

#### class Library

This class is has most important logic to create linked list.

First I initialize two pointer to point the head and tail of the linked list. When there is no element in the list, both of this pointer will point null pointer.

I use insert element on the tail to add new book. When you wanna add new book, you can enter the id, title and author to create the class book while status is setting available. Then create the structure book node and enter the book class in it. If there is no element in this linked list, head and tail will equal this element. If there are some elements has already in it, let the pointer part of tail equal this book node and tail equal this element.

Overloading the add function by conveying different parameter with Book class or basic information of book.

---

### Main function

#### Search function

Overloading search function by search id and title. When you wanna find a book by id or title, I use while loop to check each book from head pointer. If there is, it will return a pointer of book node. This method let the time complexity become O(n), but it can easily delete or add book in any where of list (although this time assignment didn't allow me to design it).

#### Borrow function

Search book id to check if there is a book. If it doesn't have, it will print no book. If there is, then check the status of book. If available, you can borrow it. And the status will change by the function in class book.

#### Return function

Same as borrow function to change status.

---

### Overloading part

##### Overloading create book class function

different parameter to convey (Book class & ID, title, author)

##### Overloading search function

different parameter to convey (ID & title)

---

### Using composition

when create library class, this class has book class.

I didn't use vector or array.

But I design linked list, the element of list is a Book class.



