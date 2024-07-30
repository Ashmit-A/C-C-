#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void addBook();
void displayBooks();
void listBooksByAuthor();
void countBooks();

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. List Books by Author\n");
        printf("4. Count Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                listBooksByAuthor();
                break;
            case 4:
                countBooks();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    fgets(library[book_count].title, MAX_TITLE_LEN, stdin);
    library[book_count].title[strcspn(library[book_count].title, "\n")] = '\0';

    printf("Enter book author: ");
    fgets(library[book_count].author, MAX_AUTHOR_LEN, stdin);
    library[book_count].author[strcspn(library[book_count].author, "\n")] = '\0';

    book_count++;
    printf("Book added successfully.\n");
}

void displayBooks() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("List of Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("------------\n");
    }
}

void listBooksByAuthor() {
    char author[MAX_AUTHOR_LEN];
    printf("Enter author name: ");
    fgets(author, MAX_AUTHOR_LEN, stdin);
    author[strcspn(author, "\n")] = '\0';

    printf("Books by %s:\n", author);
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(library[i].author, author) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found by this author.\n");
    }
}

void countBooks() {
    printf("Total number of books in the library: %d\n", book_count);
}
