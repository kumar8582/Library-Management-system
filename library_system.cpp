#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int year;
    string publisher;

    Book(int bookId, string bookTitle, string bookAuthor, int pubYear, string pub) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        year = pubYear;
        publisher = pub;
    }

    void display() const {
        cout << left << setw(10) << id
             << setw(30) << title
             << setw(20) << author
             << setw(10) << year
             << setw(20) << publisher << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id, year;
        string title, author, publisher;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Publication Year: ";
        cin >> year;
        cin.ignore();
        cout << "Enter Publisher: ";
        getline(cin, publisher);

        books.push_back(Book(id, title, author, year, publisher));
        cout << "\nBook added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo books available in the library.\n";
            return;
        }

        cout << "\nList of Books:\n";
        cout << left << setw(10) << "ID"
             << setw(30) << "Title"
             << setw(20) << "Author"
             << setw(10) << "Year"
             << setw(20) << "Publisher" << endl;
        cout << string(90, '-') << endl;

        for (const auto& book : books) {
            book.display();
        }
    }

    void searchBookById() {
        int id;
        cout << "\nEnter Book ID to search: ";
        cin >> id;

        for (const auto& book : books) {
            if (book.id == id) {
                cout << "\nBook Found:\n";
                book.display();
                return;
            }
        }
        cout << "\nBook with ID " << id << " not found.\n";
    }

    void updateBook() {
        int id;
        cout << "\nEnter Book ID to update: ";
        cin >> id;

        for (auto& book : books) {
            if (book.id == id) {
                cout << "Updating book details...\n";
                cin.ignore();
                cout << "Enter new Title: ";
                getline(cin, book.title);
                cout << "Enter new Author: ";
                getline(cin, book.author);
                cout << "Enter new Year: ";
                cin >> book.year;
                cin.ignore();
                cout << "Enter new Publisher: ";
                getline(cin, book.publisher);

                cout << "\nBook updated successfully.\n";
                return;
            }
        }
        cout << "\nBook with ID " << id << " not found.\n";
    }

    void deleteBook() {
        int id;
        cout << "\nEnter Book ID to delete: ";
        cin >> id;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                cout << "\nBook deleted successfully.\n";
                return;
            }
        }
        cout << "\nBook with ID " << id << " not found.\n";
    }
};

// Main function for the menu system
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.searchBookById(); break;
            case 4: lib.updateBook(); break;
            case 5: lib.deleteBook(); break;
            case 6: cout << "\nThank you for using the system!\n"; break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
