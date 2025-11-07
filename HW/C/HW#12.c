#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the doubly linked list
struct Node {
    char name[50];
    char phone[20];
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node with given name and phone number
struct Node* createNode(char* name, char* phone) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to add a new node to the end of the doubly linked list
void appendNode(struct Node** head, char* name, char* phone) {
    struct Node* newNode = createNode(name, phone);
    
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, make the new node the head
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;  // Attach the new node to the end
        newNode->prev = temp;  // Set the previous pointer of the new node
    }
}

// Function to display the list in reverse order
void displayRev(struct Node* first) {
    // Find the last node
    struct Node* last = first;
    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    // Traverse the list in reverse order and print the names and phone numbers
    while (last != NULL) {
        printf("Name: %s, Phone: %s\n", last->name, last->phone);
        last = last->prev;  // Move to the previous node
    }
}

int main() {
    struct Node* head = NULL;  // Initialize an empty list
    
    // Append some nodes to the list
    appendNode(&head, "John Doe", "123-456-7890");
    appendNode(&head, "Alice Smith", "234-567-8901");
    appendNode(&head, "Bob Johnson", "345-678-9012");
    
    printf("Display in reverse order:\n");
    displayRev(head);  // Call the function to display in reverse order

    return 0;
}
