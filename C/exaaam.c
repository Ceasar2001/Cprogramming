#include <stdio.h>
#include <stdlib.h>

struct Emp {
    int id;
    char name[50];
    float Salary;
};

void add(struct Emp *e, int *c) {

    printf("Enter ID: ");
    scanf("%d", &e[*c].id);
    printf("Enter name: ");
    scanf("%s", e[*c].name);
    printf("Enter salary: ");
    scanf("%f", &e[*c].Salary);
    (*c)++;

}

void delete(struct Emp *e, int *c) {
    int id, i, j;
    printf("Enter ID to be deleted: ");
    scanf("%d", &id);
    for (i = 0; i < *c; i++) {
        if (e[i].id == id) {
            for (j = i; j < *c - 1; j++) {
                e[j] = e[j + 1];
            }
            (*c)--;
            printf("ID %d has been deleted\n", id);
            break;
        }
    }
    if (i == *c) {
        printf("ID %d is not found\n", id);
    }
}

void writeToFile(struct Emp *e, int c){
    
    FILE *fp;


    fp = fopen("files.txt", "w");


    for (int i = 0; i < c; i++){
        fprintf(fp, "%d %s %f\n", e[i].id, e[i].name, e[i].Salary);
    }

    fclose(fp);

    printf("Data written to file\n");
}

void display(struct Emp *e, int c) {
    printf("ID\tName\tSalary\n");

    for (int i = 0; i < c; i++) {
        printf("%d\t%s\t%.2f\n", e[i].id, e[i].name, e[i].Salary);
    }

}

int main() {
    int choice = 1, c = 0;
    struct Emp emp[100];

    while (choice != 0) {
        printf("\nEnter 1 to add\n");
        printf("Enter 2 to delete\n");
        printf("Enter 3 to display\n");
        printf("Enter 0 to exit\n");

        printf("\nEnter number: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add(emp, &c);
                break;
            case 2:
                delete(emp, &c);
                break;
            case 3:
                display(emp, c);
                break;
            case 0:
                writeToFile(emp, c);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}