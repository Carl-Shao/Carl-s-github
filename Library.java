public class Library {

    /**
     * identify variable of Library
     * and to count whole books of Library
     */
    private Book[] books;

    private static int count;

    // Constructor of Library
    public Library(int MAXSIZE) {
        books = new Book[MAXSIZE];
        count = 0;
    }

    // add book to library
    public boolean addBook(Book book) {
        if (count < books.length) {
            books[count] = book;
            count++;
            return true;
        }
        else {
            System.out.println("Library is full.");
            return false;
        }
    }

    // display all the book
    public void displayBooks() {
        if (count == 0) {
            System.out.println("Library is empty.");
            return;
        }

        for (int i = 0; i < count; i++) {
            System.out.println(books[i]);
        }
    }

    // according to ISBN to borrow books
    public boolean borrowBook(String isbn) {
        if (count == 0) {
            System.out.println("Library is empty.");
            return false;
        }
        for(int i = 0; i < count; i++) {
            if (books[i].getIsbn().equals(isbn)) {
                if (books[i].isAvailable()) {
                    books[i].setAvailable(false);
                    return true;
                }
                else {
                    System.out.println(books[i].getTitle() + " is not available.");
                    return false;
                }
            }
        }
        System.out.println("There is no " + isbn);
        return false;
    }

    // according to ISBN to return books
    public boolean returnBook(String isbn) {
        if (count == 0) {
            System.out.println("Library is empty.");
            return false;
        }
        for(int i = 0; i< count; i++) {
            if (books[i].getIsbn().equals(isbn)) {
                if (!books[i].isAvailable()) {
                    books[i].setAvailable(true);
                    return true;
                }
                else {
                    System.out.println(books[i].getTitle() + " is not borrowed.");
                    return false;
                }
            }
        }
        System.out.println("There is no " + isbn);
        return false;
    }

    // search
    public void searchByAuthor(String author) {
        if (count == 0) {
            System.out.println("Library is empty.");
            return;
        }
        for (int i = 0; i < count; i++) {
            if (books[i].getAuthor().equals(author)) {
                System.out.println(books[i]);
                return;
            }
        }
        System.out.println("No matching with " + author);
    }

    public void searchByTitle(String title) {
        if (count == 0) {
            System.out.println("Library is empty.");
            return;
        }
        for (int i = 0; i < count; i++) {
            if (books[i].getAuthor().equals(title)) {
                System.out.println(books[i]);
                return;
            }
        }
        System.out.println("No matching with " + title);
    }
}
