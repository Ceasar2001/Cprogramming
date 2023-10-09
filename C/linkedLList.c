#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* last_node = *head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

void delete(struct node** head, int data) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == data) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct node* curr_node = *head;
    while (curr_node->next != NULL && curr_node->next->data != data) {
        curr_node = curr_node->next;
    }

    if (curr_node->next == NULL) {
        return;
    }

    struct node* temp = curr_node->next;
    curr_node->next = curr_node->next->next;
    free(temp);
}

void print_list(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
     struct node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Original list: ");
    print_list(head);

    delete(&head, 3);
    printf("List after deleting 3: ");
    print_list(head);

    return 0;
}