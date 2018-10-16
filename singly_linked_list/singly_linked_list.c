#include <stdio.h>
#include <stdlib.h>


struct Node {
    struct Node *NextNode;
    int value;
};

void addNode(struct Node *last, struct Node *node) {
    last->NextNode = node;
}

void print(struct Node *start) {
    while(start != NULL) {
        printf("%d->", start->value);
        start = start->NextNode;
    }
    printf("\n");
}

int main() {
    struct Node *node1 = NULL;
    struct Node *node2 = NULL;
    struct Node *node3 = NULL;
    struct Node *node4 = NULL;

    // allocate 3 nodes in the heap   
    node1 = (struct Node*)malloc(sizeof(struct Node));  
    node2 = (struct Node*)malloc(sizeof(struct Node)); 
    node3 = (struct Node*)malloc(sizeof(struct Node));
    node4 = (struct Node*)malloc(sizeof(struct Node)); 


    node1->value = 5;
    addNode(node1, node2);
    node2->value = 6;
    addNode(node2, node3);
    node3->value = 7;
    addNode(node3, node4);
    node4->value = 6;
    addNode(node4, NULL);

    print(node1);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    
    printf("Execution successful and memory freed.\n");
}

