#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    *newNode = (struct Node){value, NULL, NULL};
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value <= root->data) root->left = insertNode(root->left, value);
    else root->right = insertNode(root->right, value);
    return root;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;
    if (value < root->data) root->left = deleteNode(root->left, value);
    else if (value > root->data) root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        struct Node* temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node* searchNode(struct Node* root, int value) {
    if (root == NULL || root->data == value) return root;
    if (value < root->data) return searchNode(root->left, value);
    return searchNode(root->right, value);
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    int numRootNodes;
    printf("Enter the number of root nodes: ");
    scanf("%d", &numRootNodes);

    for (int i = 0; i < numRootNodes; i++) {
        int value;
        printf("Enter value for root node %d: ", i + 1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    int value;
    printf("Enter a value to search: ");
    scanf("%d", &value);
    struct Node* searchResult = searchNode(root, value);
    if (searchResult != NULL) {
        printf("%d found in the tree.\n", searchResult->data);
    } else {
        printf("%d not found in the tree.\n", value);
    }

    printf("Enter a value to delete: ");
    scanf("%d", &value);
    root = deleteNode(root, value);

    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
