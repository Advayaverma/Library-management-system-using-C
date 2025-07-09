#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

// Structure for each book node in the linked list
struct library {
    char book_name[20];
    char author[20];
    int pages;
    float price;
    struct library* next;
};

// Structure for each issued book node in the linked list
struct issued_book {
    char student_name[50];
    char book_name[20];
    char issue_date[20];
    struct issued_book* next;
};

// Function to add a book to the linked list
void addBook(struct library** head) {
    system("cls");
    struct library* newBook = (struct library*)malloc(sizeof(struct library));
    struct library* last = *head;

    printf("Enter book name: ");
    scanf("%s", newBook->book_name);

    printf("Enter author name: ");
    scanf("%s", newBook->author);

    printf("Enter pages: ");
    scanf("%d", &newBook->pages);

    printf("Enter price: ");
    scanf("%f", &newBook->price);

    newBook->next = NULL;

    if (*head == NULL) {
        *head = newBook;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newBook;
}

// Function to display all books in the linked list
void displayBooks(struct library* head) {
    system("cls");
    struct library* current = head;

    if (current == NULL) {
        printf("No books available in the library.\n");
        return;
    }

    printf("You have entered the following information:\n");
    while (current != NULL) {
        printf("\nBook name = %s", current->book_name);
        printf("\t Author name = %s", current->author);
        printf("\t Pages = %d", current->pages);
        printf("\t Price = %f", current->price);
        current = current->next;
    }
}

// Function to list all books by a given author
void listBooksByAuthor(struct library* head, char* author) {
    system("cls");
    struct library* current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->author, author) == 0) {
            printf("Book name = %s\t   ", current->book_name);
            printf("Author name = %s\t",current->author);
            printf("Pages = %d\t", current->pages);
            printf("Price = %f\n",current->price);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No books found by author %s\n", author);
    }
}

// Function to count the number of books in the library
int countBooks(struct library* head) {
    system("cls");
    int count = 0;
    struct library* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to issue a book
void issueBook(struct library* head, struct issued_book** issued_head) {
    system("cls");
    char bookName[20];
    char studentName[50];
    char issueDate[20];
    struct library* current = head;
    struct issued_book* newIssue = (struct issued_book*)malloc(sizeof(struct issued_book));

    printf("Enter book name to issue: ");
    scanf("%s", bookName);

    while (current != NULL) {
        if (strcmp(current->book_name, bookName) == 0) {
            printf("Enter student name: ");
            scanf("%s", studentName);
            printf("Enter issue date (DD/MM/YYYY): ");
            scanf("%s", issueDate);

            strcpy(newIssue->student_name, studentName);
            strcpy(newIssue->book_name, bookName);
            strcpy(newIssue->issue_date, issueDate);
            newIssue->next = *issued_head;
            *issued_head = newIssue;

            printf("Book issued successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Book not found in the library.\n");
}

// Function to view all issued books
void viewIssuedBooks(struct issued_book* issued_head) {
    system("cls");
    struct issued_book* current = issued_head;

    if (current == NULL) {
        printf("No books have been issued.\n");
        return;
    }

    printf("Issued Books:\n");
    while (current != NULL) {
        printf("\nStudent name = %s", current->student_name);
        printf("\t Book name = %s", current->book_name);
        printf("\t Issue date = %s", current->issue_date);
        current = current->next;
    }
}

int main() {
    struct library* head = NULL;
    struct issued_book* issued_head = NULL;
    int input;
    char author[30];

    while (1) {
        system("cls");
        printf("\n **********LIBRARY RECORD********** \n");
        printf("\n1. Add book information\n");
        printf("2. Display book information\n");
        printf("3. List all books of given author\n");
        printf("4. List the count of books in the library\n");
        printf("5. Issue a book\n");
        printf("6. View issued books\n");
        printf("0. Exit\n");

        printf("Enter one of the above: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                addBook(&head);
                break;
            case 2:
                displayBooks(head);
                break;
            case 3:
                printf("Enter author name: ");
                scanf("%s", author);
                listBooksByAuthor(head, author);
                break;
            case 4:
                printf("\nNo of books in library: %d\n", countBooks(head));
                break;
            case 5:
                issueBook(head, &issued_head);
                break;
            case 6:
                viewIssuedBooks(issued_head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\nPress any key to continue.............");
        getch();
    }

    return 0;
}

