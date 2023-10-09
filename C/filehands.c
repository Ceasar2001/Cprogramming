#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Client {
    char name[MAX_NAME_LENGTH];
    struct Client *next;
} Client;

typedef struct CustomerQueue {
    Client *front;
    Client *rear;
} CustomerQueue;

typedef struct CustomerStack {
    Client *top;
} CustomerStack;

CustomerQueue regularQueue;
CustomerStack vipStack;

void enqueueClient(Client *newClient, CustomerQueue *queue) {
    if (queue->rear == NULL) {
        queue->front = newClient;
        queue->rear = newClient;
    } else {
        queue->rear->next = newClient;
        queue->rear = newClient;
    }
}

Client *dequeueClient(CustomerQueue *queue) {
    if (queue->front == NULL) {
        return NULL;
    }

    Client *client = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return client;
}

void pushClient(Client *newClient, CustomerStack *stack) {
    newClient->next = stack->top;
    stack->top = newClient;
}

Client *popClient(CustomerStack *stack) {
    if (stack->top == NULL) {
        return NULL;
    }

    Client *client = stack->top;
    stack->top = stack->top->next;

    return client;
}

void readInputFile() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: unable to open input file\n");
        exit(1);
    }

    char line[100];
    char name[MAX_NAME_LENGTH];
    char customerType[10];

    while (fgets(line, sizeof(line), inputFile)) {
        sscanf(line, "%*[^,],%[^,],%s", name, customerType);

        Client *newClient = (Client*) malloc(sizeof(Client));
        strcpy(newClient->name, name);
        newClient->next = NULL;

        if (strcmp(customerType, "regular") == 0) {
            enqueueClient(newClient, &regularQueue);
            printf("Regular client %s lines up at RegularQueue\n", name);
        } else if (strcmp(customerType, "VIP") == 0) {
            pushClient(newClient, &vipStack);
            printf("VIP client %s lines up at VIPStack\n", name);
        } else {
            printf("Error: invalid customer type '%s'\n", customerType);
            exit(1);
        }
    }

    fclose(inputFile);
}

void printCustomerQueue(CustomerQueue *queue) {
    Client *currentClient = queue->front;
    while (currentClient != NULL) {
        printf("%s\n", currentClient->name);
        currentClient = currentClient->next;
    }
}

void printCustomerStack(CustomerStack *stack) {
    Client *currentClient = stack->top;
    while (currentClient != NULL) {
        printf("%s\n", currentClient->name);
        currentClient = currentClient->next;
    }
}

int main() {
    regularQueue.front = NULL;
    regularQueue.rear = NULL;
    vipStack.top = NULL;

    readInputFile();


    return 0;
}
