#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    struct Node *prev;
    char *value;
};

struct DoublyLL {
    struct Node *root;
};

// Function to add a char * to a given Node.
void addValue(struct Node *node, char *value) {
    // Add the char value to the node.
    node->value = value;
}

void addNode(struct Node *node, char *value) {
}

// Print list from left to right.
void printListFwd(struct Node *node) {
    while(node->next != NULL) {
        printf("%s", node->value);
        node = node->next;
    }
    printf("%s", node->value);
}

// Print the list from right to left.
void printListBack(struct Node *node) {
    while(node->prev != NULL) {
        printf("%s", node->value);
        node = node->prev;
    }
    printf("%s", node->value);
}

int main() {
    // Declare the linked list nodes.
    struct Node *node1;
    struct Node *node2;
    struct Node *node3;

    // Now allocate the memory for each node in the list.
    node1 = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));

    // Add values to the nodes.
    addValue(node1, "This is node1 containing some secret information.\n");
    addValue(node2, "I am connected to node 1!\n");
    addValue(node3, "I am the last node in the list.\n");

    // Point the nodes to each other.
    node1->prev = NULL;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = NULL;

    // Now print out the linked list.
    printf("Linked list forward print:\n");
    printListFwd(node1);
    printf("\n");
    printf("Linked list backward print:\n");
    printListBack(node3);

    // Free the node's memory.
    free(node1);
    free(node2);
    free(node3);
}