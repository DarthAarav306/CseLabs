// Base class Book
class Book {
    private int id;
    private String title;
    private String author;
    private boolean available;

    // Constructor
    public Book(int id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.available = true; // Default available status is true
    }

    // Display method (to be overridden)
    public void display() {
        System.out.println("ID: " + id + ", Title: " + title + ", Author: " + author);
    }
}


// Subclass Novel that extends Book
class Novel extends Book {
    private String genre;

    // Constructor
    public Novel(int id, String title, String author, String genre) {
        super(id, title, author); // Call to the superclass constructor
        this.genre = genre;
    }

    // Overriding display method
    @Override
    public void display() {
        System.out.println("Novel:");
        super.display(); // Call the superclass display method
        System.out.println("Genre: " + genre);
    }
}


// Subclass Textbook that extends Book
class Textbook extends Book {
    private String subject;

    // Constructor
    public Textbook(int id, String title, String author, String subject) {
        super(id, title, author); // Call to the superclass constructor
        this.subject = subject;
    }

    // Overriding display method
    @Override
    public void display() {
        System.out.println("Textbook:");
        super.display(); // Call the superclass display method
        System.out.println("Subject: " + subject);
    }
}


// Library class to manage books
class Library {
    private static final int MAX_BOOKS = 100;
    private static Book[] bookDatabase = new Book[MAX_BOOKS]; // Array to store books
    static int bookCount = 0; // To keep track of the number of books in the library

    // Static block to initialize the library with some books
    static {
        bookDatabase[bookCount++] =
                new Novel(1, "The Catcher in the Rye", "J.D. Salinger", "Fiction");
        bookDatabase[bookCount++] = new Novel(2, "To Kill a Mockingbird", "Harper Lee", "Fiction");
        bookDatabase[bookCount++] = new Novel(3, "1984", "George Orwell", "Science Fiction");
        bookDatabase[bookCount++] = new Textbook(4, "Calculus", "James Stewart", "Maths");
        bookDatabase[bookCount++] =
                new Textbook(5, "Introduction to Java", "John Smith", "Computer Science");
    }

    // Method to add a book to the library
    public static void addBook(Book book) {
        if (bookCount < MAX_BOOKS) {
            bookDatabase[bookCount++] = book;
        } else {
            System.out.println("Library is at maximum capacity. Cannot add more books.");
        }
    }

    // Method to retrieve all books
    public static Book[] getAllBooks() {
        return bookDatabase;
    }
}


// Main class to demonstrate the functionality
public class BookDemo {
    public static void main(String[] args) {
        // Add a new Novel to the Library
        Library.addBook(new Novel(6, "The Lord of the Rings", "J.R.R. Tolkien", "Fantasy"));

        // Retrieve all books from the library
        Book[] books = Library.getAllBooks();

        // Display book details
        System.out.println("Library Book Information:");
        for (int i = 0; i < Library.bookCount; i++) {
            books[i].display();
            System.out.println();
        }
    }
}
