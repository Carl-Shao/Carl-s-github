import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Library library = new Library(10);

        // add some new books to init library
        library.addBook(new Book("C++ Primer Plus", "Stephen Prata", "947001", true));
        library.addBook(new Book("Computer Systems A Programmer's Perspective ", "Randal E. Bryant", "947002", true));
        library.addBook(new Book("Computer Networking A Top-Down Approach", "James F. Kurose", "947003", true));

        int choice;
        do {
            // print information to get the choice
            System.out.println("\n\nWelcome to the Library Management System");
            System.out.println("1. View all books");
            System.out.println("2. Borrow a book");
            System.out.println("3. Return a book");
            System.out.println("4. Search for a book");
            System.out.println("5. Exit");
            System.out.print("Please enter your choice: ");
            choice = input.nextInt();
            input.nextLine();

            // according to the choice you give
            switch (choice) {
                case 1:
                    System.out.println("\n--- All Books ---");
                    library.displayBooks();
                    break;
                case 2:
                    System.out.print("Enter the ISBN of the book to borrow: ");
                    String borrowIsbn = input.nextLine();
                    if (library.borrowBook(borrowIsbn)) {
                        System.out.println("Successfully borrowed the book!");
                    }
                    break;
                case 3:
                    System.out.print("Enter the ISBN of the book to return: ");
                    String returnIsbn = input.nextLine();
                    if (library.returnBook(returnIsbn)) {
                        System.out.println("Successfully returned the book!");
                    }
                    break;
                case 4:
                    System.out.println("Do you want to search by TITLE or AUTHOR ?");
                    String options = input.nextLine();
                    // judge if it is title or author
                    if (options.equalsIgnoreCase("title")) {
                        System.out.print("Enter title to search: ");
                        String title = input.nextLine();
                        System.out.println("\n--- Search Result ---");
                        library.searchByTitle(title);
                    } else if (options.equalsIgnoreCase("author")) {
                        System.out.print("Enter author to search: ");
                        String author = input.nextLine();
                        System.out.println("\n--- Search Result ---");
                        library.searchByAuthor(author);
                    }

                    break;
                case 5:
                    System.out.println("Thank you for using the library system. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice, please try again.");
            }
        } while (choice != 5);
        input.close();
    }
}