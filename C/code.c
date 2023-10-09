#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 80

struct Node {
    char data[BUFFER_SIZE];
    struct Node* next;
};

void addNode(struct Node** head, char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strncpy(newNode->data, data, BUFFER_SIZE);
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FILE* fp = fopen("input.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char buf[BUFFER_SIZE];

    struct Node* regularHead = NULL;
    struct Node* vipHead = NULL;

    while (fgets(buf, BUFFER_SIZE, fp)) {
        char* name = strtok(buf, ",");
        char* type = strtok(NULL, ",");

        if (type != NULL) {
            // Remove leading/trailing whitespaces from name and type
            char* trimmedName = strtok(name, " \t\r\n");
            char* trimmedType = strtok(type, " \t\r\n");

            if (strcmp(trimmedType, "regular") == 0) {
                addNode(&regularHead, trimmedName);
            } else if (strcmp(trimmedType, "VIP") == 0) {
                addNode(&vipHead, trimmedName);
            }
        }
    }

    printf("Regular Customers:\n");
    printList(regularHead);

    printf("\nVIP Customers:\n");
    printList(vipHead);

    fclose(fp);

    // Free the linked lists
    freeList(regularHead);
    freeList(vipHead);

    return EXIT_SUCCESS;
}
