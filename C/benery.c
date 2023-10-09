#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void displayFormat(struct Node* root, int space) {
    if (root == NULL)
        return;
    int i;
    space += 5;
    displayFormat(root->right, space);
    printf("\n");
    for (i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    displayFormat(root->left, space);
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

bool search(struct Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* minValueNode = findMin(root->right);
        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int numNodes, value;
    char choice;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter the value of the node: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Binary Search Tree Format:\n");
    displayFormat(root, 0);

    do {
        printf("\nDo you want to insert a new node? (Y/N): ");
        scanf(" %c", &choice);
        if (choice == 'Y' || choice == 'y') {
            printf("Enter the value of the new node: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Node inserted successfully.\n");
            printf("Updated Binary Search Tree Format:\n");
            displayFormat(root, 0);
        }
    } while (choice == 'Y' || choice == 'y');

    do {
        printf("\nDo you want to search for a node? (Y/N): ");
        scanf(" %c", &choice);
        if (choice == 'Y' || choice == 'y') {
            printf("Enter the value of the node to search: ");
            scanf("%d", &value);
            bool found = search(root, value);
            if (found)
                printf("Node found in the binary search tree.\n");
            else
                printf("Node not found in the binary search tree.\n");
        }
    } while (choice == 'Y' || choice == 'y');

    do {
        printf("\nDo you want to delete a node? (Y/N): ");
        scanf(" %c", &choice);
        if (choice == 'Y' || choice == 'y') {
            printf("Enter the value of the node to delete: ");
            scanf("%d", &value);
            bool found = search(root, value);
            if (found) {
                root = deleteNode(root, value);
                printf("Node deleted successfully.\n");
                printf("Updated Binary Search Tree Format:\n");
                displayFormat(root, 0);
            } else {
                printf("Node not found in the binary search tree. Deletion aborted.\n");
            }
        }
    } while (choice == 'Y' || choice == 'y');

    printf("\nIn-order traversal: ");
    inorderTraversal(root);

    printf("\nPre-order traversal: ");
    preorderTraversal(root);

    printf("\nPost-order traversal: ");
    postorderTraversal(root);

    printf("\nLevel-order traversal: ");
    levelOrderTraversal(root);

    return 0;
}
