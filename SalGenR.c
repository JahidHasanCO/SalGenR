#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define _Username_ "Admin"
#define _Password_ "Admin"

struct employee
{
    char name[20];
    struct employee *next;
} * head;

bool loginCheck(char name[15], char pass[15]);
void add_employee_list(char name1);
void print_employee_list();

int main()
{
    int option;
    char name[15], pass[15], name1[20];
    while (1)
    {
        printf("You need to login first.\n");
        printf("Username: ");
        gets(name);
        printf("Password: ");
        gets(pass);
        if (loginCheck(name, pass))
        {
            while (1)
            {
                printf("Select Your Option From Menu.\n");
                printf("Menu\n1.Add New\n2.List\n3.Exit\n4.Modify\n5.Search\n6.Delete\n");
                printf("SalGenR>> ");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                    printf("Enter name: ");
                    puts(name1);
                    add_employee_list(name1);
                    break;
                case 2:
                    print_employee_list();
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                default:
                    printf("You Need to choose option into 1-6\n");
                    break;
                }
            }

            break;
        }
    }

    return 0;
}

// login section

bool loginCheck(char name[15], char pass[15])
{
    if (strcmp(name, _Username_) == 0)
    {
        if (strcmp(pass, _Password_) == 0)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

void add_employee_list(char name1)
{
    struct employee *newNode, *temp;

    newNode = (struct employeee *)malloc(sizeof(struct employee));

    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        strcpy(newNode->name, name1);
        newNode->next = NULL;
        temp = head;

        // Traverse to the last node
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; // Link address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void print_employee_list()
{
    struct employee *temp = head;
    if (head == NULL)
    {
        printf("Employee list is Empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("Name: ");
            puts(temp->name);
            temp = temp->next;
        }
    }
}