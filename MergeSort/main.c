/*
Jorge Aranda
CS 2600
Homework 2: Column Sorter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// typedef of a node structure
typedef struct node {
    struct node *next;
    char name[50], fruit[50];
    int number;
} Node;

// Creates the start of a list of nodes
Node *createList() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}   

// Adds nodes to the list.
// Automatically sorts list according to column number chosen in command line
void addNode(Node *head, char *name, int number, char *fruit, int columnNumber) {
    // Creates node and adds variable to it
    Node *node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->number = number;
    strcpy(node->fruit, fruit);

    // Checks if this is the first entry
    if (head->next == NULL){
        head->next = node;
        node->next = NULL;
    }
    else{
        // If it is not the first entry, goes through list to check where 
        // the node should be inserted (automatically sorts, no sorting algorithm used)
        // iterator and trail help make the insertions easier
        Node *iterator = head->next;
        Node *trail = head;
        switch(columnNumber){
            // Sorts by first column
            case 1:
                // Checks right away to see if the first value is greater than the node being added
                if (iterator->name[0] > node->name[0]){
                    trail->next = node;
                    node->next = iterator;
                }
                // If the first value is less than the nodes value, checks if it is last node in list
                else if (iterator->next == NULL){
                    iterator->next = node;
                    node->next = NULL;
                }
                // If the first two cases aren't satisfied, iterates through the list until 
                // it finds where the node should be inserted
                else {
                    while(iterator->name[0] < node->name[0]) {
                        if (iterator->next != NULL) {
                            trail = iterator;
                            iterator = iterator->next;
                        }
                        // In this case, it is the last node, to avoid getting an error
                        // it breaks out of the loop
                        else 
                            break;
                    }
                    
                    // Checks to see if the compared characters are the same
                    bool sameLetter = false;
                    if (iterator->name[0] == node->name[0]){
                        sameLetter = true;
                        int i = 0;
                        // If they are the same, it iterates through the string to find which is greater
                        while(iterator->name[i] == node->name[i]){
                            i++;
                        }
                        // If the nodes value is greater, it iterates up to insert the node in its position
                        if (iterator->name[i] > node->name[i]){
                            trail->next = node;
                            node->next = iterator;
                        }
                        // Checks to see if it is the last node in the list
                        else if (iterator->next == NULL) {
                            iterator->next = node;
                            node->next = NULL;
                        }
                        // iterates and inserts node
                        else {
                            trail = iterator;
                            iterator = iterator->next;
                            trail->next = node;
                            node->next = iterator;   
                        }
                    }
                    // Inserts node
                    if (!sameLetter){
                        if (iterator->next == NULL) {
                            iterator->next = node;
                            node->next = NULL;
                        }
                        else {
                            trail->next = node;
                            node->next = iterator;
                        }
                    }
                }
            break;
            // Sorts column by second column
            // Similar logic as first case
            case 2:
                if (iterator->number > node->number){
                    trail->next = node;
                    node->next = iterator;
                }
                else if (iterator->next == NULL){
                    iterator->next = node;
                    node->next = NULL;
                }
                else {
                    bool isLast = false;
                    while(iterator->number < node->number){
                        if (iterator->next != NULL) {
                            trail = iterator;
                            iterator = iterator->next;
                        }
                        else {
                            iterator->next = node;
                            node->next = NULL;
                            isLast = true;
                            break;
                        }
                    }
                    if (!isLast){
                        trail->next = node;
                        node->next = iterator;
                    }
                }
            break;
            // Sorts by third column
            // Same exact logic as first case
            case 3:
                if (iterator->name[0] > node->name[0]){
                    trail->next = node;
                    node->next = iterator;
                }
                else if (iterator->next == NULL){
                    iterator->next = node;
                    node->next = NULL;
                }
                else {
                    while(iterator->name[0] < node->name[0]) {
                        if (iterator->next != NULL) {
                            trail = iterator;
                            iterator = iterator->next;
                        }
                        else 
                            break;
                    }
                    bool sameLetter = false;
                    if (iterator->name[0] == node->name[0]){
                        sameLetter = true;
                        int i = 0;
                        while(iterator->name[i] == node->name[i]){
                            i++;
                        }
                        if (iterator->name[i] > node->name[i]){
                            trail->next = node;
                            node->next = iterator;
                        }
                        else if (iterator->next == NULL) {
                            iterator->next = node;
                            node->next = NULL;
                        }
                        else {
                            trail = iterator;
                            iterator = iterator->next;
                            trail->next = node;
                            node->next = iterator;   
                        }
                    }
                    if (!sameLetter){
                        if (iterator->next == NULL) {
                            iterator->next = node;
                            node->next = NULL;
                        }
                        else {
                            trail->next = node;
                            node->next = iterator;
                        }
                    }
                }
            break;
            default:
            break;
        }
    }
}

// Function that frees up the allocated memory of list
void freeList(Node *head){
    while (head->next)
    {
        Node *node = head;
        head = node->next;
        free(node);
    }
}

// Function that adds user input until they state otherwise
void addToList(Node *head, int columnNumber){
    char name[50], fruit[50];
    int number;
    bool isDone = false;
    while(!isDone){
        printf("Enter a name: ");
        scanf("%s", name);
        printf("Enter an integer: ");
        scanf("%d", &number);
        printf("Enter a fruit: ");
        scanf("%s", fruit);
        addNode(head, name, number, fruit, columnNumber);
        char choice;
        printf("Would you like to add more to the list? (Y/N): ");
        scanf(" %c", &choice);
        if(toupper(choice) != 'Y')
            isDone = true;
    }
} 

// Prints list
void printList(Node *head){
    Node *iterator = head;
    while(iterator->next) {
        iterator = iterator->next;
        printf("%s,%d,%s\n", iterator->name, iterator->number, iterator->fruit);
    }
}

// Main function to test code
// Uses examples from homework sheet
// User can add to the list
int main(int argc, char *argv[]) {
    Node *head = createList();
    addNode(head, "Sam", 15, "banana", atoi(argv[1]));
    addNode(head, "Julie", 23, "grape", atoi(argv[1]));
    addNode(head, "Scott", 12, "kiwi", atoi(argv[1]));
    printList(head);

    char choice;
    printf("\nWould you like to add more data? (Y/N): ");
    scanf(" %c", &choice);
    if(toupper(choice) == 'Y'){
        addToList(head, atoi(argv[1]));
        printList(head);
    }
    freeList(head);
    return 0;
}