#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define _Username_ "Admin"
#define _Password_ "Admin"

struct employee
{
    char name[20];
    double salary;
    struct employee *next;
} * head, *tail;

bool loginCheck(char name[15], char pass[15]);
void print_employee_list();
void create_linked_list();
void insert_at_last(double salary);
void insert_at_first(double salary);

int main()
{
    head = NULL;
    tail = NULL;
    int option, option1;
    char name[15], pass[15], name1[20];
    double salary;
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
                    printf("Choose Option.\n1.Add Employee Continuesly.\n2.Add Employee at First.\n3.Add Employee in position\n4.Add Employee at Last.\n");
                    scanf("%d", option1);
                    switch (option1)
                    {
                    case 1:
                        create_linked_list();
                        break;
                    case 2:
                        break;
                    case 3:

                        break;
                    case 4:
                        break;
                    default:
                        printf("You Need to select valid option\n");
                        break;
                    }
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
            printf("Salary: %lf\n", temp->salary);
            temp = temp->next;
        }
    }
}

void create_linked_list()
{

    int n, i = 1;
    printf("Enter Amount of Em: ");
    scanf("%d", &n);
    double salary;

    while (n--)
    {
        printf("Enter Salary of %d: ", i);
        scanf("%lf", &salary);
        insert_at_last(salary);
        i++;
    }
}

void insert_at_last(double salary)
{
    struct employee *temp_node;
    temp_node = (struct employee *)malloc(sizeof(struct employee));

    temp_node->salary = salary;
    temp_node->next = NULL;

    //For the 1st element
    if (head == NULL)
    {
        head = temp_node;
        tail = temp_node;
    }
    else
    {
        tail->next = temp_node;
        tail = temp_node;
    }
}

void insert_at_first(double salary)
{
    struct employee *temp_node = (struct employee *)malloc(sizeof(struct employee));

    temp_node->salary = salary;
    temp_node->next = head;

    head = temp_node;
}