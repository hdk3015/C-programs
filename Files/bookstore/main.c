#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct books{
    char name[250];
    int ncopies;
    float cost;
    }book;

void insert(FILE *fp);
void display_all(FILE *fp);
void delete(FILE *fp);
void list(FILE *fp);


int main()
{
    int choice;
    FILE *fp;
    fp = fopen("bookData","rb+");
    if(fp == NULL)
    {
        printf("Error in opening file");
        exit(-1);
    }
    while(1)
    {
    printf("\n\n---- BOOK STORE ----\n");
    printf("\n1.Insert a record");
    printf("\n2.Delete a record");
    printf("\n3.List a record");
    printf("\n4.Display all record");
    printf("\n5.Modify a record");
    printf("\n6.Books sold");
    printf("\n7.Exit");
    printf("\n\n");
    printf("Enter your choice --- ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1 : insert(fp); 
                 break;
        case 2 : delete(fp);
                 break;
        case 3 : list(fp);
                 break;
        case 4 : display_all(fp);
                break;
    }
    }
}

void insert(FILE *fp)
{
    fseek(fp, 0, 2);
    printf("\n\nInsert A record");
    printf("\nEnter book name --> ");
    scanf("%s", book.name);
    printf("\nEnter number of copies --> ");
    scanf("%d", &book.ncopies);
    printf("\nEnter book price --> ");
    scanf("%f", &book.cost);
    fwrite(&book, sizeof(book), 1, fp);
    printf("\nRecord Inserted successfully");
    printf("\n\n");
}

void display_all(FILE *fp)
{
    rewind(fp);
    printf("\nName\t\tnCopies\t\tPrice\n");
    while(fread(&book, sizeof(book),1,fp) == 1)
    {
        printf("%s\t\t", book.name);
        printf("%d\t\t", book.ncopies);
        printf("%.2f\n", book.cost);
    }
    printf("\n\n");
}

void delete(FILE *fp)
{
    FILE *ftemp = fopen("temp", "wb+");
    int flag = 0;
    char book_name[250];
    printf("\nEnter book name --> ");
    scanf("%s",&book_name);
    rewind(fp);
    while(fread(&book, sizeof(book),1, fp) == 1)
    {
        if(strcmp(book.name, book_name) != 0)
        {
            fwrite(&book, sizeof(book), 1, ftemp);
        }
        
        else
        {
        flag = 1;
        }
    }
    fclose(fp);
    fclose(ftemp);
    remove("bookData");
    rename("temp", "bookData");
    if(flag == 0)
    {
        printf("\nBook name not found!"); 
    }
    else{
        printf("\nBook Record deleted!");
    }
    printf("\n\n");
}

void list(FILE *fp)
{
    char book_name[250];
    rewind(fp);
    printf("Enter book name --> ");
    scanf("%s", book_name);
    while(fread(&book,sizeof(book),1,fp) == 1)
    {
        if(strcmp(book.name, book_name) == 0)
        {
            printf("\nName\t\tnCopies\t\tPrice\n");
            printf("%s\t\t", book.name);
            printf("%d\t\t", book.ncopies);
            printf("%.2f\n", book.cost);
            printf("\n\n");
            return;
        }
    }
    printf("\nBook not found");
}