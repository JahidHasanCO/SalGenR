#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define _Username_ "Admin"
#define _Password_ "Admin"

struct employee
{
    char name[20];
    int age;
    int phone_number;
    double salary;
    struct employee *next;
} * head, *tail;

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

void create_linked_list()
{
    int n, i = 1;
    char name[20];
    int age, pnumber;
    double salary;
    printf("Enter Amount of Employee: ");
    scanf("%d", &n);

    while (n--)
    {
        printf("Enter Details for Employee %d\n", i);
        printf("Enter Name: ");
        getchar();
        gets(name);
        printf("Enter Age: ");
        scanf("%d", &age);
        printf("Enter Phone number: ");
        scanf("%d", &pnumber);
        printf("Enter Salary: ");
        scanf("%lf", &salary);

        struct employee *temp_node;
        temp_node = (struct employee *)malloc(sizeof(struct employee));
        strcpy(temp_node->name, name);
        temp_node->age = age;
        temp_node->phone_number = pnumber;
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
        i++;
    }
}

void insert_at_last(char name[20], int age, int pnumber, double salary)
{
    struct employee *temp_node;
    temp_node = (struct employee *)malloc(sizeof(struct employee));
    strcpy(temp_node->name, name);
    temp_node->age = age;
    temp_node->phone_number = pnumber;
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
void print_employee_list()
{
    struct employee *temp = head;
    if (head == NULL)
    {
        printf("Employee list is Empty\n");
    }
    else
    {
        int i = 1;
        while (temp != NULL)
        {
            printf("\n\nDetails for Employee %d\n", i);
            printf("Name: ");
            puts(temp->name);
            printf("Age: %d\n", temp->age);
            printf("Phone Number: 0%d\n", temp->phone_number);
            printf("Salary: %lf\n", temp->salary);
            temp = temp->next;
            i++;
        }
    }
}

void printLogo()
{

    printf("███████╗ █████╗ ██╗      ██████╗ ███████╗███╗   ██╗██████╗ \n");
    printf("██╔════╝██╔══██╗██║     ██╔════╝ ██╔════╝████╗  ██║██╔══██╗\n");
    printf("███████╗███████║██║     ██║  ███╗█████╗  ██╔██╗ ██║██████╔╝\n");
    printf("╚════██║██╔══██║██║     ██║   ██║██╔══╝  ██║╚██╗██║██╔══██╗\n");
    printf("███████║██║  ██║███████╗╚██████╔╝███████╗██║ ╚████║██║  ██║\n");
    printf("╚══════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝\n");
    printf("-------------------------SaLGenR---------------------------\n");
}

int main()
{
    head = NULL;
    tail = NULL;
    int option, option1;
    char name[15], pass[15], name1[20];
    double salary;
    // printLogo();
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
                printf("\nSelect Your Option From Menu.\n");
                printf("------------------------------\n");
                printf("1.Add New\n2.List\n3.Exit\n4.Modify\n5.Search\n6.Delete\n");
                printf("\nSalGenR>> ");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                    printf("\nChoose Option.\n--------------\n1.Add Employee Continuesly.\n2.Add Employee at First.\n3.Add Employee in position\n4.Add Employee at Last.\n");
                    printf("\nAdd New>> ");
                    scanf("%d", &option1);
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
                    // create_linked_list();
                    break;
                case 2:
                    print_employee_list();
                    break;
                case 3:
                    exit(0);
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
