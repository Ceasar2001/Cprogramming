#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

struct Person {
    int id;
    char name[MAX_LEN];
    float salary;
};

int main() {
    int choice;
    struct Person p;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add a person\n");
        printf("2. Delete a person\n");
        printf("3. Search for a person\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter ID: ");
            scanf("%d", &p.id);

            printf("Enter Name: ");
            scanf("%s", p.name);

            printf("Enter Salary: ");
            scanf("%f", &p.salary);

            FILE *fp;
            fp = fopen("person.txt", "a");
            fprintf(fp, "%d %s %f\n", p.id, p.name, p.salary);
            fclose(fp);
        } else if (choice == 2) {
            int idToDelete;
            printf("Enter ID to delete: ");
            scanf("%d", &idToDelete);

            FILE *fp;
            fp = fopen("person.txt", "r");
            FILE *temp;
            temp = fopen("temp.txt", "w");

            while (fscanf(fp, "%d %s %f\n", &p.id, p.name, &p.salary) != EOF) {
                if (p.id != idToDelete) {
                    fprintf(temp, "%d %s %f\n", p.id, p.name, p.salary);
                }
            }

            fclose(fp);
            fclose(temp);

            remove("person.txt");
            rename("temp.txt", "person.txt");
        } else if (choice == 3) {
            int idToSearch;
            printf("Enter ID to search: ");
            scanf("%d", &idToSearch);

            int found = 0;
            FILE *fp;
            fp = fopen("person.txt", "r");

            while (fscanf(fp, "%d %s %f\n", &p.id, p.name, &p.salary) != EOF) {
                if (p.id == idToSearch) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                printf("Person Found:\n");
                printf("ID: %d\n", p.id);
                printf("Name: %s\n", p.name);
                printf("Salary: %f\n", p.salary);
            } else {
                printf("Person Not Found\n");
            }

            fclose(fp);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}