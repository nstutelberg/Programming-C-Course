// HW #15, Nolan Stutelberg
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining struct and setting the length of the chars to be 100 since I have to set a value, and all data points are <100
typedef struct Book
{
    char title[100];
    char author[100];
    int year;
    struct Book *next;
} Book;

void initializeList(Book **head);
void appendDataToList(Book **head, char *title, char *author, int year);
void readDataFromFile(Book **head, const char *filename);
void writeToFile(Book *head, const char *filename);
void printRecord(Book *head);
void readAndAppendFromBinary(Book **head, const char *filename);
void insertBookManually(Book **head);

int main()
{
    printf("HW #15, Nolan Stutelberg\n");

    Book *head = NULL;
    int initialCaseVal;
    char filename[100] = "HW14Data.txt";
    char binaryFileName[100] = "books.bin";

    // Setting this value to 0 so if the user enters any input besides the 7 options, the loop will exit
    initialCaseVal = 0;

    while (initialCaseVal != 5)
    {
        printf("1. Initialize List\n");
        printf("2. Append data from file\n");
        printf("3. Write to binary file\n");
        printf("4. Print a record\n");
        printf("5. Exit\n");
        printf("6. Read from binary file and append to linked list\n");
        printf("7. Insert a book manually\n");
        printf("Enter an option from above -> ");
        scanf("%d", &initialCaseVal);

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }

        switch (initialCaseVal)
        {
        case 1:
            initializeList(&head);
            break;
        case 2:
            readDataFromFile(&head, filename);
            break;
        case 3:
            writeToFile(head, binaryFileName);
            break;
        case 4:
            printRecord(head);
            break;
        case 5:
            // Using the same initializeList function, because the function is set up to free memory if the list exists
            initializeList(&head);
            break;
        case 6:
            readAndAppendFromBinary(&head, binaryFileName);
            break;
        case 7:
            insertBookManually(&head);
            break;
        default:
            printf("Enter a valid choice you silly billy. Try again\n");
        }
    }
    return 0;
}

void initializeList(Book **head)
{
    // If linked list exists, deallocate memory and reset the head of the list to NULL to make it empty again
    Book *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}

void appendDataToList(Book **head, char *title, char *author, int year)
{
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (newBook)
    {
        // Appending data to linked list using the struct defined at the top of the program to structure the data file
        strcpy(newBook->title, title);
        strcpy(newBook->author, author);
        newBook->year = year;
        newBook->next = NULL;
        if (*head == NULL)
        {
            *head = newBook;
        }
        else
        {
            Book *current = *head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newBook;
        }
    }
}

void readDataFromFile(Book **head, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file)
    {
        char title[100], author[100];
        int year;

        // Setting the format to read the data from the file , knowing the data is separated by
        // newline characters and has an integer as the last item to be read
        while (fscanf(file, " %[^\n] %[^\n] %d\n", title, author, &year) == 3)
        {
            appendDataToList(head, title, author, year);
        }
        fclose(file);
    }
}

void writeToFile(Book *head, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file)
    {
        Book *current = head;
        while (current)
        {
            fwrite(current, sizeof(Book), 1, file);
            current = current->next;
        }
        fclose(file);
    }
}

void printRecord(Book *head)
{
    int numRecords = 0;
    int recordToPrint;
    Book *current = head;

    // Count the number of records so it can be used in the print statements
    while (current)
    {
        numRecords++;
        current = current->next;
    }

    if (numRecords > 0)
    {
        printf("Enter what record you want to print. Options are: 1 to %d -> ", numRecords);
        scanf("%d", &recordToPrint);
    }
    else
    {
        printf("There are no records found. Try again and make sure you initialize the list and the data is populated from the txt file.\n");
    }

    // Print the record specified by the user
    current = head;
    for (int count = 1; count < recordToPrint; count++)
    {
        current = current->next;
    }
    printf("Record %d: %s, %s, %d\n", recordToPrint, current->title, current->author, current->year);
}

void readAndAppendFromBinary(Book **head, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file)
    {
        Book binaryData;
        while (fread(&binaryData, sizeof(Book), 1, file))
        {
            appendDataToList(head, binaryData.title, binaryData.author, binaryData.year);
        }
        fclose(file);
    }
}

void insertBookManually(Book **head)
{
    char title[100], author[100];
    int year;
    printf("Enter the title of the book please -> ");
    scanf(" %[^\n]", title);
    printf("Enter the author name please -> ");
    scanf(" %[^\n]", author);
    printf("Enter the year of publication please -> ");
    scanf("%d", &year);

    appendDataToList(head, title, author, year);
}

/*
Sample output:

HW #15, Nolan Stutelberg
1. Initialize List
2. Append data from file
3. Write to binary file
4. Print a record
5. Exit
6. Read from binary file and append to linked list
7. Insert a book manually
Enter an option from above -> 1
1. Initialize List
2. Append data from file
3. Write to binary file
4. Print a record
5. Exit
6. Read from binary file and append to linked list
7. Insert a book manually
Enter an option from above -> 2
1. Initialize List
2. Append data from file
3. Write to binary file
4. Print a record
5. Exit
6. Read from binary file and append to linked list
7. Insert a book manually
Enter an option from above -> 3
1. Initialize List
2. Append data from file
3. Write to binary file
4. Print a record
5. Exit
6. Read from binary file and append to linked list
7. Insert a book manually
Enter an option from above -> 4
Enter what record you want to print. Options are: 1 to 15 -> 15
Record 15: C Primer Plus, Prata, Stephen, 2014
1. Initialize List
2. Append data from file
3. Write to binary file
4. Print a record
5. Exit
6. Read from binary file and append to linked list
7. Insert a book manually
Enter an option from above -> 6
1. Initialize List
2. Append data from file
3. Write to binary file
4. Print a record
5. Exit
6. Read from binary file and append to linked list
7. Insert a book manually
Enter an option from above -> 4
Enter what record you want to print. Options are: 1 to 30 -> 29
Record 29: The Hitchiker's guide to the Universe, Adams, Douglas, 1979
1. Initialize List
2. Append data from file
3. Write to binary file
4. Print a record
5. Exit
6. Read from binary file and append to linked list
7. Insert a book manually
Enter an option from above -> 7
Enter the title of the book please -> Diary of a Wimpy Kid: Greg Heffley Commits Tax Fraud
Enter the author name please -> Me
Enter the year of publication please -> 2023
1. Initialize List
2. Append data from file
3. Write to binary file
4. Print a record
5. Exit
6. Read from binary file and append to linked list
7. Insert a book manually
Enter an option from above -> 5

*/