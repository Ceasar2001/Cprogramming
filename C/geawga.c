#include <stdio.h>
#include <string.h>

struct Emp {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Emp emp;
    int choice;

    FILE *fp;
    fp = fopen("employees.txt", "a+");

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Delete an employee\n");
        printf("2. Add a new employee\n");
        printf("3. Display all employees\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the ID of the employee to delete: ");
                int del_id;
                scanf("%d", &del_id);

                // code to delete an employee from the file

                break;
            case 2:
                printf("Enter the ID of the new employee: ");
                scanf("%d", &emp.id);
                printf("Enter the name of the new employee: ");
                scanf("%s", emp.name);
                printf("Enter the salary of the new employee: ");
                scanf("%f", &emp.salary);

                fprintf(fp, "%d %s %f\n", emp.id, emp.name, emp.salary);

                break;
            case 3:
                // code to display all employees from the file

                break;
            case 0:
                fclose(fp);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}