#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    char date_published[100];
};

typedef struct emps{
    int idnumber;
    char firstname[100];
    char lastname[100];
    float salary;
}emp;

int main() {

   // emp em = {
    //    .idnumber = 21100557,
    //    .firstname = "ceasar",
    //    .lastname = "ecleo",
    //    .salary = 1500.45
   // };



    emp em_arr[5];
    int arr[100];



    em_arr[0].idnumber = 103;
    strcpy(em_arr[0].firstname,"ceasar");
    strcpy(em_arr[0].lastname,"ecleo");
    em_arr[0].salary = 1500.5;

    printf("\nidnumber: %d\n", em_arr[0].idnumber);
    printf("\nfirstname: %s\n", em_arr[0].firstname);
    printf("\nlastname: %s\n", em_arr[0].lastname);
    printf("\nsalary: %f\n", em_arr[0].salary);


   emp em_arr[1] = {105, "ceasaria", "idol", 1500.4};

    return 0;
}

/*
    struct Book bb = {1, "programming", "ceasar", "jan. 19, 2060"};

    printf("ID: %d\n", bb.id);
    printf("title: %s\n", bb.title);
    printf("author: %s\n", bb.author);
    printf("published on: %s", bb.date_published);

*/ 

/*
#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int pages;
};

int main() {
    struct Book myBook;
    strcpy(myBook.title, "The Great Gatsby");
    strcpy(myBook.author, "F. Scott Fitzgerald");
    myBook.pages = 180;

    printf("Title: %s\n", myBook.title);
    printf("Author: %s\n", myBook.author);
    printf("Pages: %d\n", myBook.pages);

    return 0;
}
*/ 