public class Book {

    /**
     * identify variable of Book
     */
    private String title;

    private String author;

    private String isbn;

    private boolean isAvailable;

    public Book(String title, String author, String isbn, boolean isAvailable) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.isAvailable = isAvailable;
    }

    /**
     * Getter and Setter function
     */
    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void setAvailable(boolean available) {
        isAvailable = available;
    }

    /**
     * Overriding toString function
     */
    @Override
    public String toString() {
        return "Title: " + title +
                ", Author: " + author +
                ", ISBN: " + isbn +
                ", Available: " + (isAvailable ? "yes" : "No");
    }
}
