// project of library management sysytem using Linked list complish
#include <iostream>
#include <string>
#include <iomanip>

// create Book class to store each book methods and variables
class Book{
private:
    int bookID;
    std::string title;
    std::string author;
    bool available;

public:
    // initialize book with parameter
    Book(int id, std::string T, std::string A):bookID(id), title(T), author(A), available(true) {}

    // change display true or false to available and borrowed
    void displayStatus() const {
        if(available == true){
            std::cout << std::setw(18) << "Available";
        }else{std::cout << std::setw(18) << "Borrowed";}
    }

    // display onr book information
    void displayBookInfo() const{
        std::cout << std::left;
        std::cout << std::setw(14) << bookID << std::setw(17) << title << std::setw(17) << author;
        displayStatus();
        std::cout << "\n";
    };

    // change status of book when borrow and return
    void BorrowBook(){
        available = false;
    };
    void ReturnBook(){
        available = true;
    };

    // return information of a book
    int getBookID() {return bookID;}
    std::string getTitle() {return title;}
    std::string getAuthor() {return author;}
    bool isAvailable() {return available;}
};

// create Node structure of each book to use linked list
struct BookNode{
    Book book;
    BookNode* next;

    BookNode(Book B):book(B), next(nullptr){} 
};

class Library{
private:
    // include BookNode that has class Book which uses composition
    // define head and tail element of linked list
    BookNode* head;
    BookNode* tail;
public:
    Library():head(nullptr), tail(nullptr) {}       // initialized with null pointer

    void addNewBook(const int id, const std::string title, const std::string author){
        Book b(id, title, author);
        BookNode* booknode = new BookNode(b);
        if (tail == nullptr){
            head = booknode;
            tail = booknode;
        }else{
            tail->next = booknode;
            tail = booknode;
        }
        std::cout << "Book Added!\n";
    }

    // overloading addNewBook function for different parameter
    void addNewBook(Book b){
        BookNode* booknode = new BookNode(b);
        if (tail == nullptr){
            head = booknode;
            tail = booknode;
        }else{
            tail->next = booknode;
            tail = booknode;
        }
        std::cout << "Book Added!\n";
    }

    void displayAllBook() const{
        std::cout << "\nBook ID       Title            Author           Status\n";
        BookNode* p = head;
        if(p == nullptr){
            std::cout << "There is no book!\n";
            return;}
        while(p != nullptr){
            p->book.displayBookInfo();
            p = p->next;
        }
        std::cout << "\n";
    }

    // Overloading search book function by book ID and title
    BookNode* searchBook(const int id) const{
        BookNode* p = head;
        int BookID;
        while(p != nullptr){
            BookID = p->book.getBookID();
            if (id == BookID){
                return p;
            }else{p = p->next;}
        }
        return nullptr;
    }

    BookNode* searchBook(const std::string title) const{
        BookNode* p = head;
        std::string Title;
        while(p != nullptr){
            Title = p->book.getTitle();
            if(Title == title){
                return p;
            }else{p = p->next;}
        }
        return nullptr;
    }

    void borrowBook(const int id){
        BookNode* q = searchBook(id);
        if(q == nullptr){
            std::cout << "No book id.\n";
            return;
        }
        else if(q->book.isAvailable() == false){
            std::cout << "Book has been borrowed.\n";
        }else{
            q->book.BorrowBook();
            std::cout << "Book borrowed successfully.\n";
            return;
        }
    }
    void returnBook(const int id){
        BookNode* q = searchBook(id);
        if(q == nullptr){
            std::cout << "\nNo book id has been registered.\n";
            std::cout << "Do you wanna add this book?(y/n)";
            char flag;
            std::cin >> flag;
            if(flag == 'y'){
                std::string t;
                std::cout << "Enter the Book Title: ";
                getline(std::cin, t);
                std::string a;
                std::cout << "Enter the author: ";
                getline(std::cin, a);
                addNewBook(id, t, a);
            }
            else{return;}
        }
        else if(q->book.isAvailable() == true){
            std::cout << "The book has in library.\n";
            return;
        }
        else{
            q->book.ReturnBook();
            std::cout << "Book returned successfully\n";
            return;
        }
    }
};

void cleanInput();

int main(){
    Library library;
    short choice;
    do{
        // initialize the operate
        std::cout << "\n=============== Library Management System ===============\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display All Books\n";
        std::cout << "3. Search Book By ID\n";
        std::cout << "4. Search Book By Title\n";
        std::cout << "5. Borrow Book\n";
        std::cout << "6. Return Book\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        while(!(std::cin >> choice) || choice > 7 || choice < 1){
            std::cout << "Invalid choice. Enter again: ";
            cleanInput();
        }
        cleanInput();
        switch(choice)
        {
            case 1:{
                std::string t;
                std::cout << "Enter the Book Title: ";
                getline(std::cin, t);
                int id;
                std::cout << "Enter the Book ID: ";
                std::cin >> id;
                std::string a;
                std::cout << "Enter the author: ";
                std::cin.ignore();
                getline(std::cin, a);
                Book b(id, t, a);
                library.addNewBook(b);
                break;
            }


            // Display all information of every book
            case 2:{
                std::cout << "\nDisplaying Books:\n";
                library.displayAllBook();
                break;
            }

            // Overloading the search book function by entering book ID
            case 3:{
                int SearchID;
                std::cout << "\nEnter which book ID you wanna search: ";
                while(!(std::cin >> SearchID)){
                    std::cout << "Enter a valid ID again: ";
                    cleanInput();
                }
                cleanInput();
                BookNode* q = library.searchBook(SearchID);
                if(q == nullptr){
                    std::cout << "There is no book ID is " << SearchID << "\n";
                }else{
                    std::cout << "\nThe book is found\n";
                    q->book.displayBookInfo();
                }
                break;
            }

            // Overloading the search book function by entering title
            case 4:{
                std::string SearchTitle;
                std::cout << "\nEnter which book title you wanna search: ";
                getline(std::cin, SearchTitle);
                BookNode* q = library.searchBook(SearchTitle);
                if(q == nullptr){
                    std::cout << "There is no book title is " << SearchTitle << "\n";
                }else{
                    std::cout << "\nThe book is found\n";
                    q->book.displayBookInfo();
                }
                break;
            }

            // check whether can borrow a book(check the available of Book)
            case 5:{
                int id;
                std::cout << "\nBorrowing a book:\n";
                std::cout << "Enter book ID to borrow: ";
                while(!(std::cin >> id)){
                    std::cout << "Enter a valid book id again.\n";
                    cleanInput();
                }
                cleanInput();
                library.borrowBook(id);
                break;
            }

            // Returning the book by enter book id. If no book id, check whether need to create
            case 6:{
                int id;
                std::cout << "\nReturning a book:\n";
                std::cout << "Enter book ID to return: ";
                while(!(std::cin >> id)){
                    std::cout << "Enter a vaild book id again.\n";
                    cleanInput();
                }
                cleanInput();
                library.returnBook(id);
                break;
            }

            // when choice equal 7. Then ended exit the library system
            case 7:{
                std::cout << "Thanks for using. Bye!\n";
                break;
            }
            default:{
                std::cout << "Operate Wrong!";
                break;
            }
        } 
    } while(choice != 7);

    std::cin.ignore();
    std::cin.get();
    return 0;
}

// clean the cin when invalid variable enter
void cleanInput(){
    std::cin.clear();
    std::cin.ignore(1000000, '\n');
}