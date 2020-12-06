/*this project name is SalGenR
This project for Employees details store in companies Database..
Using this Project we can handle our Employees Details
We can add new employee , we can search Employee, We can Modify Employees Records*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#define _Username_ "Admin" //Define a Default Username for Login
#define _Password_ "Admin" //Define a Default Password for Login

//Declaring a Structure for store employees Details
struct employee
{
    //properties of a Employee
    char name[20];
    int ID;
    int age;
    int phone_number;
    char address[20];
    double salary;
    struct employee *next;
} * head, *tail, *mod; //head pointer for first node , tail pointer for last node, and mod pointer for  modification records

// login section
bool loginCheck(char name[15], char pass[15])
{
    if (strcmp(name, _Username_) == 0) //checking input Username to stored Username
    {
        if (strcmp(pass, _Password_) == 0) //checking input password to stroed Password
        {
            return true; //if Username and Password are matched then it returns a truth value
        }
    }
    else
    {
        return false; //if Username and Password are not matched then it returns a flase value
    }
}

void writeToFile(struct employee *temp_node)
{
    FILE *fp;
    if ((fp = fopen("Database.bin", "ab")) == NULL)
    {
        printf("\nCan't open file\n");
        exit(1);
    }

    fwrite(temp_node, sizeof(*temp_node), 1, fp);
    fclose(fp);
}

void PrintFromFile()
{
    struct employee *temp_node;
    FILE *fp;
    temp_node = (struct employee *)malloc(sizeof(struct employee));
    head = temp_node;
    if ((fp = fopen("Database.bin", "rb")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    fread(temp_node, sizeof(*temp_node), 1, fp);
    printf("\n\n                                     All Employee Details                                     \n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
    printf("----------------------------------------------------------------------------------------------\n");
    do
    {
        printf("| %-19s", temp_node->name);
        printf("| %-9d", temp_node->ID);
        printf("| %-7d", temp_node->age);
        printf("| 0%-13d", temp_node->phone_number);
        printf("| %-19s", temp_node->address);
        printf("| %-13.3lf|\n", temp_node->salary);
        printf("----------------------------------------------------------------------------------------------\n");
        temp_node = temp_node->next;
    } while (temp_node->next != NULL);
    fclose(fp);
}

/*
    Insert section start 
*/

//Creating or adding linklist continiously
void create_linked_list()
{
    //local variables for work
    int n, i = 1;
    char name[20], address[20];
    int age, pnumber, id;
    double salary;
    printf("\nEnter Amount of Employee: ");
    scanf("%d", &n); //scanning size of employee add.

    while (n--)
    {
        //inputting details
        printf("\nEnter Details for Employee %d\n", i);
        printf("Enter Name: ");
        getchar();
        gets(name);
        printf("Enter ID: ");
        scanf("%d", &id);
        printf("Enter Age: ");
        scanf("%d", &age);
        printf("Enter Phone number: ");
        scanf("%d", &pnumber);
        printf("Enter Address: ");
        getchar();
        gets(address);
        printf("Enter Salary: ");
        scanf("%lf", &salary);

        //creating node and fill up value which is inputted avobe
        struct employee *temp_node;
        temp_node = (struct employee *)malloc(sizeof(struct employee)); //dynamiclly allocated
        strcpy(temp_node->name, name);                                  //string copy function .
        temp_node->age = age;
        temp_node->ID = id;
        temp_node->phone_number = pnumber;
        strcpy(temp_node->address, address);
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
        writeToFile(temp_node);
    }
}

//insert Node in linklist at last
void insert_at_last()
{
    char name[20], address[20];
    int age, pnumber, id;
    double salary;
    //scanning all details of employee
    printf("Enter Details for Employee.\n");
    printf("Enter Name: ");
    getchar();
    gets(name);
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Phone number: ");
    scanf("%d", &pnumber);
    printf("Enter Address: ");
    getchar();
    gets(address);
    printf("Enter Salary: ");
    scanf("%lf", &salary);

    //store value in linklist
    struct employee *temp_node;
    temp_node = (struct employee *)malloc(sizeof(struct employee));
    strcpy(temp_node->name, name); //sring copy function
    temp_node->ID = id;
    temp_node->age = age;
    temp_node->phone_number = pnumber;
    strcpy(temp_node->address, address);
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
    writeToFile(temp_node);
}

//insert nodes at first
void insert_at_first()
{
    char name[20], address[20];
    int age, pnumber, id;
    double salary;
    printf("Enter Details for Employee.\n");
    printf("Enter Name: ");
    getchar();
    gets(name);
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Phone number: ");
    scanf("%d", &pnumber);
    printf("Enter Address: ");
    getchar();
    gets(address);
    printf("Enter Salary: ");
    scanf("%lf", &salary);

    //creating node
    struct employee *temp_node = (struct employee *)malloc(sizeof(struct employee));
    strcpy(temp_node->name, name);
    temp_node->ID = id;
    temp_node->age = age;
    temp_node->phone_number = pnumber;
    strcpy(temp_node->address, address);
    temp_node->salary = salary;
    temp_node->next = head;
    head = temp_node;
    writeToFile(temp_node);
}

void insert_after_postiton()
{
    //local variables
    int key;
    struct employee *myNode = head;
    int flag = 0;
    printf("Enter previous ID for insert Employee next: ");
    scanf("%d", &key);
    char name[20], address[20];
    int age, pnumber, id;
    double salary;

    while (myNode != NULL) // if mynode pointer will NULL then this loop will be stop
    {
        if (myNode->ID == key) // ID matching
        {
            //inputting records
            printf("Enter Details for Employee.\n");
            printf("Enter Name: ");
            getchar();
            gets(name);
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Age: ");
            scanf("%d", &age);
            printf("Enter Phone number: ");
            scanf("%d", &pnumber);
            printf("Enter Address: ");
            getchar();
            gets(address);
            printf("Enter Salary: ");
            scanf("%lf", &salary);

            //Dynamiclly allocated
            struct employee *newNode = (struct employee *)malloc(sizeof(struct employee));
            strcpy(newNode->name, name);
            newNode->ID = id;
            newNode->age = age;
            newNode->phone_number = pnumber;
            strcpy(newNode->address, address);
            newNode->salary = salary;
            newNode->next = myNode->next;
            myNode->next = newNode;
            writeToFile(myNode);
            printf("New Employee %s is inserted after %d\n", name, key);

            flag = 1;

            break;
        }
        else
        {
            myNode = myNode->next;
        }
    }

    //if ID not matched or not found then this messege will be show
    if (flag == 0)
    {
        printf("ID not found!\n");
    }
}

/*
    Insert section end 
*/

//print all employees details
// void print_employee_list()
// {
//     struct employee *temp = head; //creating a temporary pointer for traverse
//     //if database is empty then this messege will be show
//     if (head == NULL)
//     {
//         printf("\nEmployee list is Empty\n");
//     }
//     else
//     {

//         /*  20-10-8-15-20-14 */
//         printf("\n\n                                     All Employee Details                                     \n");
//         printf("----------------------------------------------------------------------------------------------\n");
//         printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
//         printf("----------------------------------------------------------------------------------------------\n");

//         while (temp != NULL)
//         {
//             printf("| %-19s", temp->name);
//             printf("| %-9d", temp->ID);
//             printf("| %-7d", temp->age);
//             printf("| 0%-13d", temp->phone_number);
//             printf("| %-19s", temp->address);
//             printf("| %-13.3lf|\n", temp->salary);
//             printf("----------------------------------------------------------------------------------------------\n");
//             temp = temp->next;
//         }
//     }
// }

/*Delete section start 
*/

//Delete Employees Record By name
void delete_Employee_Record_by_name()
{
    char value[20];
    int key;
    struct employee *myNode = head, *previous = NULL;
    int flag = 0;
    printf("Enter Name: ");
    getchar();
    gets(value);
    while (myNode != NULL)
    {

        if (strcmp(strlwr(myNode->name), strlwr(value)) == 0)
        {

            printf("\nDo you Really delete this Employee Record\n");
            //after entry Name match then this will be  print
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", myNode->name);
            printf("| %-9d", myNode->ID);
            printf("| %-7d", myNode->age);
            printf("| 0%-13d", myNode->phone_number);
            printf("| %-19s", myNode->address);
            printf("| %-13.3lf|\n", myNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\n\nFor Delete this record (type 1): ");
            scanf("%d", &key);
            //if user input = 1 then delete function will be work
            if (key == 1)
            {

                if (previous == NULL)
                {
                    head = myNode->next;
                }
                else
                {
                    previous->next = myNode->next;
                }
                //after delete records this messsege will be print
                printf("\n%s Name records is deleted from Database\n", value);

                flag = 1;
                free(myNode); //need to free up the memory to prevent memory leak
                break;
            }
            else
            {
                break;
            }
        }
        previous = myNode;
        myNode = myNode->next;
    }

    if (flag == 0) // if user input not match with database this messege will be show
        printf("\nThis Name not found!\n");
}

//Delete Employees Record By ID
void delete_Employee_Record_by_ID()
{
    int value, key;
    struct employee *myNode = head, *previous = NULL;
    int flag = 0;
    printf("Enter ID: ");
    scanf("%d", &value);
    while (myNode != NULL)
    {

        if (myNode->ID == value)
        {

            printf("\nDo you Really delete this Employee Record\n");
            //after entry ID match then this will be  print
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", myNode->name);
            printf("| %-9d", myNode->ID);
            printf("| %-7d", myNode->age);
            printf("| 0%-13d", myNode->phone_number);
            printf("| %-19s", myNode->address);
            printf("| %-13.3lf|\n", myNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\n\nFor Delete this record (type 1): ");
            scanf("%d", &key);
            //if user input = 1 then delete function will be work
            if (key == 1)
            {

                if (previous == NULL)
                {
                    head = myNode->next;
                }
                else
                {
                    previous->next = myNode->next;
                }
                //after delete records this messsege will be print
                printf("\n%d ID records is deleted from Database\n", value);

                flag = 1;
                free(myNode); //need to free up the memory to prevent memory leak
                break;
            }
            else
            {
                break;
            }
        }
        previous = myNode;
        myNode = myNode->next;
    }

    if (flag == 0) // if user input not match with database this messege will be show
        printf("\nThis ID not found!\n");
}

//Delete Employees Record By age
void delete_Employee_Record_by_age()
{
    int value, key;
    struct employee *myNode = head, *previous = NULL;
    int flag = 0;
    printf("Enter Age: ");
    scanf("%d", &value);
    while (myNode != NULL)
    {

        if (myNode->age == value)
        {

            printf("\nDo you Really delete this Employee Record\n");
            //after entry ID match then this will be  print
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", myNode->name);
            printf("| %-9d", myNode->ID);
            printf("| %-7d", myNode->age);
            printf("| 0%-13d", myNode->phone_number);
            printf("| %-19s", myNode->address);
            printf("| %-13.3lf|\n", myNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\n\nFor Delete this record (type 1): ");
            scanf("%d", &key);
            //if user input = 1 then delete function will be work
            if (key == 1)
            {

                if (previous == NULL)
                {
                    head = myNode->next;
                }
                else
                {
                    previous->next = myNode->next;
                }
                //after delete records this messsege will be print
                printf("\n%d age records is deleted from Database\n", value);

                flag = 1;
                free(myNode); //need to free up the memory to prevent memory leak
                break;
            }
            else
            {
                break;
            }
        }
        previous = myNode;
        myNode = myNode->next;
    }

    if (flag == 0) // if user input not match with database this messege will be show
        printf("\nThis age not found!\n");
}

//Delete Employees Record By Phone Number
void delete_Employee_Record_by_Phone_Number()
{
    int value, key;
    struct employee *myNode = head, *previous = NULL;
    int flag = 0;
    printf("Enter Phone Number: ");
    scanf("%d", &value);
    while (myNode != NULL)
    {

        if (myNode->phone_number == value)
        {

            printf("\nDo you Really delete this Employee Record\n");
            //after entry ID match then this will be  print
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", myNode->name);
            printf("| %-9d", myNode->ID);
            printf("| %-7d", myNode->age);
            printf("| 0%-13d", myNode->phone_number);
            printf("| %-19s", myNode->address);
            printf("| %-13.3lf|\n", myNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\n\nFor Delete this record (type 1): ");
            scanf("%d", &key);
            //if user input = 1 then delete function will be work
            if (key == 1)
            {

                if (previous == NULL)
                {
                    head = myNode->next;
                }
                else
                {
                    previous->next = myNode->next;
                }
                //after delete records this messsege will be print
                printf("\n%d phone Number records is deleted from Database\n", value);

                flag = 1;
                free(myNode); //need to free up the memory to prevent memory leak
                break;
            }
            else
            {
                break;
            }
        }
        previous = myNode;
        myNode = myNode->next;
    }

    if (flag == 0) // if user input not match with database this messege will be show
        printf("\nThis Phone Number not found!\n");
}

//Delete Employees Record By Salary
void delete_Employee_Record_by_Salary()
{
    double value;
    int key;
    struct employee *myNode = head, *previous = NULL;
    int flag = 0;
    printf("Enter Salary: ");
    scanf("%lf", &value);
    while (myNode != NULL)
    {

        if (myNode->salary == value)
        {

            printf("\nDo you Really delete this Employee Record\n");
            //after entry ID match then this will be  print
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", myNode->name);
            printf("| %-9d", myNode->ID);
            printf("| %-7d", myNode->age);
            printf("| 0%-13d", myNode->phone_number);
            printf("| %-19s", myNode->address);
            printf("| %-13.3lf|\n", myNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\n\nFor Delete this record (type 1): ");
            scanf("%d", &key);
            //if user input = 1 then delete function will be work
            if (key == 1)
            {

                if (previous == NULL)
                {
                    head = myNode->next;
                }
                else
                {
                    previous->next = myNode->next;
                }
                //after delete records this messsege will be print
                printf("\n%lf salary records is deleted from Database\n", value);

                flag = 1;
                free(myNode); //need to free up the memory to prevent memory leak
                break;
            }
            else
            {
                break;
            }
        }
        previous = myNode;
        myNode = myNode->next;
    }

    if (flag == 0) // if user input not match with database this messege will be show
        printf("\nThis Salary not found!\n");
}

//Delete Employees Record By Place
void delete_Employee_Record_by_Place()
{
    char value[20];
    int key;
    struct employee *myNode = head, *previous = NULL;
    int flag = 0;
    printf("Enter Address: ");
    getchar();
    gets(value);
    while (myNode != NULL)
    {

        if (strcmp(strlwr(myNode->address), strlwr(value)) == 0)
        {

            printf("\nDo you Really delete this Employee Record\n");
            //after entry ID match then this will be  print
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", myNode->name);
            printf("| %-9d", myNode->ID);
            printf("| %-7d", myNode->age);
            printf("| 0%-13d", myNode->phone_number);
            printf("| %-19s", myNode->address);
            printf("| %-13.3lf|\n", myNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\n\nFor Delete this record (type 1): ");
            scanf("%d", &key);
            //if user input = 1 then delete function will be work
            if (key == 1)
            {

                if (previous == NULL)
                {
                    head = myNode->next;
                }
                else
                {
                    previous->next = myNode->next;
                }
                //after delete records this messsege will be print
                printf("\n%s Address records is deleted from Database\n", value);

                flag = 1;
                free(myNode); //need to free up the memory to prevent memory leak
                break;
            }
            else
            {
                break;
            }
        }
        previous = myNode;
        myNode = myNode->next;
    }

    if (flag == 0) // if user input not match with database this messege will be show
        printf("\nThis Address not found!\n");
}

/*
    Delete section End
*/

/*
    Search section start 
*/

//Search Employees Details by Name
void search_Employee_By_Name()
{
    char value[20];
    struct employee *searchNode = head;
    int flag = 0; //this variable check for search result validity
    printf("\nEnter name for search.\n");
    printf("----------------------\n");
    printf("\nSearch>> ");
    getchar();
    gets(value);
    printf("\n\nSearch Result.\n");
    while (searchNode != NULL)
    {
        if (strcmp(strlwr(searchNode->name), strlwr(value)) == 0)
        {
            //print data after search
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", searchNode->name);
            printf("| %-9d", searchNode->ID);
            printf("| %-7d", searchNode->age);
            printf("| 0%-13d", searchNode->phone_number);
            printf("| %-19s", searchNode->address);
            printf("| %-13.3lf|\n", searchNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            flag = 1;
            searchNode = searchNode->next;
        }
        else
        {
            //if user given name and stored name not matched then searchnode traverse the next node
            searchNode = searchNode->next;
        }
    }

    if (flag == 0)
    {
        //if name not matched or ont found then this messges will be print
        printf("\nEmployee not found for this (%s) name\n", value);
    }
}

//Search Employees Details by ID
void search_Employee_By_ID()
{
    int value;
    struct employee *searchNode = head;
    int flag = 0; //this variable check for search result validity
    printf("\nEnter ID for search.\n");
    printf("----------------------\n");
    printf("\nSearch>> ");
    scanf("%d", &value);
    printf("\n\nSearch Result.\n");
    while (searchNode != NULL)
    {
        if (searchNode->ID == value)
        {
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", searchNode->name);
            printf("| %-9d", searchNode->ID);
            printf("| %-7d", searchNode->age);
            printf("| 0%-13d", searchNode->phone_number);
            printf("| %-19s", searchNode->address);
            printf("| %-13.3lf|\n", searchNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            //if user given id and stored id not matched then searchnode traverse the next node
            searchNode = searchNode->next;
    }

    if (flag == 0)
    {
        //if id not matched or ont found then this messges will be print
        printf("\nEmployee not found for this (%d) ID\n", value);
    }
}

//Search Employees Details by Age
void search_Employee_By_Age()
{
    int value;
    struct employee *searchNode = head;
    int flag = 0; //this variable check for search result validity
    printf("\nEnter age for search.\n");
    printf("-----------------------\n");
    printf("\nSearch>> ");
    scanf("%d", &value);
    printf("\n\nSearch Result.\n");
    while (searchNode != NULL)
    {
        if (searchNode->age == value)
        {
            //print data
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", searchNode->name);
            printf("| %-9d", searchNode->ID);
            printf("| %-7d", searchNode->age);
            printf("| 0%-13d", searchNode->phone_number);
            printf("| %-19s", searchNode->address);
            printf("| %-13.3lf|\n", searchNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            //if user given age and stored age not matched then searchnode traverse the next node
            searchNode = searchNode->next;
    }

    if (flag == 0)
    {
        //if user given age and stored age not matched then this messege will be print
        printf("\nEmployee not found for this (%d) Age\n", value);
    }
}

//Search Employees Details by Phone Number
void search_Employee_By_phone()
{
    int value;
    struct employee *searchNode = head;
    int flag = 0; //this variable check for search result validity
    printf("\nEnter phone number for search.\n");
    printf("------------------------------\n");
    printf("\nSearch>> ");
    scanf("%d", &value);
    printf("\n\nSearch Result.\n");
    while (searchNode != NULL)
    {
        if (searchNode->phone_number == value)
        {
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", searchNode->name);
            printf("| %-9d", searchNode->ID);
            printf("| %-7d", searchNode->age);
            printf("| 0%-13d", searchNode->phone_number);
            printf("| %-19s", searchNode->address);
            printf("| %-13.3lf|\n", searchNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            //if user given phone number and stored phone number not matched then searchnode traverse the next node
            searchNode = searchNode->next;
    }

    if (flag == 0)
    {
        //if user given phone number and stored phone number not matched then this messege will be print
        printf("\nEmployee not found for this (0%d) Phone number\n", value);
    }
}

//Search Employees Details by Salary
void search_Employee_By_Salary()
{
    double value;
    struct employee *searchNode = head;
    int flag = 0; //this variable check for search result validity
    printf("\nEnter salary for search.\n");
    printf("------------------------\n");
    printf("\nSearch>> ");
    scanf("%ld", &value);
    printf("\n\nSearch Result.\n");
    while (searchNode != NULL)
    {
        //if user input salary and stored salary are match then this condition will be true
        if (searchNode->salary == value)
        {
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", searchNode->name);
            printf("| %-9d", searchNode->ID);
            printf("| %-7d", searchNode->age);
            printf("| 0%-13d", searchNode->phone_number);
            printf("| %-19s", searchNode->address);
            printf("| %-13.3lf|\n", searchNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            //if user given salary and stored salary not matched then searchnode traverse the next node
            searchNode = searchNode->next;
    }

    if (flag == 0)
    {
        printf("\nEmployee not found for this (%ld) salary\n", value);
    }
}

//Search Employees Details by Place
void search_Employee_By_Place()
{
    char value[20]; //input address in this
    struct employee *searchNode = head;
    int flag = 0; //this variable check for search result validity
    printf("\nEnter address for search.\n");
    printf("----------------------\n");
    printf("\nSearch>> ");
    getchar();
    gets(value);
    printf("\n\nSearch Result.\n");
    while (searchNode != NULL)
    {
        if (strcmp(strlwr(searchNode->address), strlwr(value)) == 0)
        {
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", searchNode->name);
            printf("| %-9d", searchNode->ID);
            printf("| %-7d", searchNode->age);
            printf("| 0%-13d", searchNode->phone_number);
            printf("| %-19s", searchNode->address);
            printf("| %-13.3lf|\n", searchNode->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            //if user given address and stored address not matched then searchnode traverse the next node
            searchNode = searchNode->next;
    }

    if (flag == 0)
    {
        printf("\nEmployee not found for this (%s) Place\n", value);
    }
}

/*
    Search section End 
*/

/*
    modifie section start 
*/

bool modify_Employee_Name()
{
    char old[20];
    int pos = 0, key;
    if (head == NULL)
    {
        printf("\nDatabase not Found!\n");
        return false;
    }
    printf("\nEnter name for modifie: ");
    getchar();
    gets(old);
    struct employee *current = head;
    while (current->next != NULL)
    {
        if (strcmp(current->name, old) == 0)
        {
            printf("\n%s this name found employee.", old);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", current->name);
            printf("| %-9d", current->ID);
            printf("| %-7d", current->age);
            printf("| 0%-13d", current->phone_number);
            printf("| %-19s", current->address);
            printf("| %-13.3lf|\n", current->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\nDo You want to Modifie this Records?(1 = Yes, 2 = No)\n");
            printf("--------------------------------------------------------\n");
            scanf("%d ", &key);
            if (key == 1)
            {
                mod = current;
                // printf("\n%s found at position %d, and replaced\n", old, pos);
                return true;
            }
        }
        else
        {
            //if user given name and stored name not matched then searchnode traverse the next node
            current = current->next;
        }
        pos++;
    }

    printf("\n%s name not exist in the Database.\n", old);
}

//modify function using by ID
bool modify_Employee_ID()
{
    int old;          //old value
    int pos = 0, key; //position and option change value variable
    if (head == NULL) // check database impty or not
    {
        printf("\nDatabase not Found!\n");
        return false;
    }
    printf("\nEnter ID for modifie: ");
    scanf("%d", &old);
    struct employee *current = head;

    /* this codindition for first node or last node....
    I mean database has only one node then this condition will be run
    or database has last node to check then this condition will be run
    */

    if (current->next == NULL)
    {
        if (current->ID == old)
        {
            printf("\n%d this ID found employee.\n", old);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", current->name);
            printf("| %-9d", current->ID);
            printf("| %-7d", current->age);
            printf("| 0%-13d", current->phone_number);
            printf("| %-19s", current->address);
            printf("| %-13.3lf|\n", current->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\nDo You want to Modifie this Records?(1 = Yes, 2 = No)\n");
            printf("--------------------------------------------------------\n");
            scanf("%d ", &key);
            if (key == 1)
            {
                mod = current;
                // printf("\n%s found at position %d, and replaced\n", old, pos);
                return true;
            }
        }
    }
    while (current->next != NULL)
    {
        if (current->ID == old)
        {
            printf("\n%d this ID found employee.", old);
            printf("-----------------------------------\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", current->name);
            printf("| %-9d", current->ID);
            printf("| %-7d", current->age);
            printf("| 0%-13d", current->phone_number);
            printf("| %-19s", current->address);
            printf("| %-13.3lf|\n", current->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\nDo You want to Modifie this Records?(1 = Yes, 2 = No)\n");
            printf("--------------------------------------------------------\n");
            scanf("%d ", &key);
            if (key == 1)
            {
                mod = current;
                // printf("\n%s found at position %d, and replaced\n", old, pos);
                return true;
            }
        }
        else
        {
            //if user given id and stored id not matched then searchnode traverse the next node
            current = current->next;
        }
        pos++;
    }

    printf("\n%d ID not exist in the Database.\n", old);
}

//modify function using by Age
bool modify_Employee_Age()
{
    int old;          //old value
    int pos = 0, key; //position and option change value variable
    if (head == NULL) // check database impty or not
    {
        printf("\nDatabase not Found!\n");
        return false;
    }
    printf("\nEnter Age for modifie: ");
    scanf("%d", &old);
    struct employee *current = head;

    /* this codindition for first node or last node....
    I mean database has only one node then this condition will be run
    or database has last node to check then this condition will be run
    */

    if (current->next == NULL)
    {
        if (current->age == old)
        {
            printf("\n%d this age found employee.\n", old);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", current->name);
            printf("| %-9d", current->ID);
            printf("| %-7d", current->age);
            printf("| 0%-13d", current->phone_number);
            printf("| %-19s", current->address);
            printf("| %-13.3lf|\n", current->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\nDo You want to Modifie this Records?(1 = Yes, 2 = No)\n");
            printf("--------------------------------------------------------\n");
            scanf("%d ", &key);
            if (key == 1)
            {
                mod = current;
                // printf("\n%s found at position %d, and replaced\n", old, pos);
                return true;
            }
        }
    }
    while (current->next != NULL)
    {
        if (current->age == old)
        {
            printf("\n%d this age found employee.", old);
            printf("-----------------------------------\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", current->name);
            printf("| %-9d", current->ID);
            printf("| %-7d", current->age);
            printf("| 0%-13d", current->phone_number);
            printf("| %-19s", current->address);
            printf("| %-13.3lf|\n", current->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\nDo You want to Modifie this Records?(1 = Yes, 2 = No)\n");
            printf("--------------------------------------------------------\n");
            scanf("%d ", &key);
            if (key == 1)
            {
                mod = current;
                // printf("\n%s found at position %d, and replaced\n", old, pos);
                return true;
            }
        }
        else
        {
            //if user given id and stored id not matched then searchnode traverse the next node
            current = current->next;
        }
        pos++;
    }

    printf("\n%d age not exist in the Database.\n", old);
}

//modify function using by Phone Number
bool modify_Employee_pnumber()
{
    int old;          //old value
    int pos = 0, key; //position and option change value variable
    if (head == NULL) // check database impty or not
    {
        printf("\nDatabase not Found!\n");
        return false;
    }
    printf("\nEnter Phone Number for modifie: ");
    scanf("%d", &old);
    struct employee *current = head;

    /* this codindition for first node or last node....
    I mean database has only one node then this condition will be run
    or database has last node to check then this condition will be run
    */

    if (current->next == NULL)
    {
        if (current->phone_number == old)
        {
            printf("\n%d this Phone Number found employee.\n", old);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", current->name);
            printf("| %-9d", current->ID);
            printf("| %-7d", current->age);
            printf("| 0%-13d", current->phone_number);
            printf("| %-19s", current->address);
            printf("| %-13.3lf|\n", current->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\nDo You want to Modifie this Records?(1 = Yes, 2 = No)\n");
            printf("--------------------------------------------------------\n");
            scanf("%d ", &key);
            if (key == 1)
            {
                mod = current;
                // printf("\n%s found at position %d, and replaced\n", old, pos);
                return true;
            }
        }
    }
    while (current->next != NULL)
    {
        if (current->phone_number == old)
        {
            printf("\n%d this age found employee.", old);
            printf("-----------------------------------\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", current->name);
            printf("| %-9d", current->ID);
            printf("| %-7d", current->age);
            printf("| 0%-13d", current->phone_number);
            printf("| %-19s", current->address);
            printf("| %-13.3lf|\n", current->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            printf("\nDo You want to Modifie this Records?(1 = Yes, 2 = No)\n");
            printf("--------------------------------------------------------\n");
            scanf("%d ", &key);
            if (key == 1)
            {
                mod = current;
                // printf("\n%s found at position %d, and replaced\n", old, pos);
                return true;
            }
        }
        else
        {
            //if user given id and stored id not matched then searchnode traverse the next node
            current = current->next;
        }
        pos++;
    }

    printf("\n%d Phone Number not exist in the Database.\n", old);
}

//this function change record if we need to modifie
void change_Records(struct employee *current)
{

    char name[20];
    int age, pnumber, id, option;
    double salary;
    while (1)
    {
        printf("\nChoose option for modifie\n");
        printf("--------------------------\n");
        printf("1. Name change.\n");
        printf("2. ID change\n");
        printf("3. Age change\n");
        printf("4. Phone Number change\n");
        printf("5. Salary change\n");
        printf("6. Exit\n");
        printf("\nChange>> ");
        scanf("%d", &option);
        if (option == 6)
        {
            break;
        }

        switch (option)
        {
        case 1:
            printf("Enter new Name: ");
            getchar();
            gets(name);
            strcpy(current->name, name);
            break;
        case 2:
            printf("Enter new ID: ");
            scanf("%d", &id);
            current->ID = id;
            break;
        case 3:
            printf("Enter new Age: ");
            scanf("%d", &age);
            current->age = age;
            break;
        case 4:
            printf("Enter new Phone number: ");
            scanf("%d", &pnumber);
            current->phone_number = pnumber;
            break;
        case 5:
            printf("Enter new Salary: ");
            scanf("%lf", &salary);
            current->salary = salary;
            break;
        default:
            printf("\nYou have to choose right option\n");
            break;
        }
    }
    mod = NULL;
}

/*
    modifie section end 
*/

// logo function
void printLogo()
{
    //logo using ascii codes
    printf("        _____       _  _____            _____        \n");
    printf("       / ____|     | |/ ____|          |  __ \\       \n");
    printf("      | (___   __ _| | |  __  ___ _ __ | |__) |      \n");
    printf("       \\___ \\ / _` | | | |_ |/ _ \\ '_ \\|  _  /       \n");
    printf("       ____) | (_| | | |__| |  __/ | | | | \\ \\       \n");
    printf("      |_____/ \\__,_|_|\\_____|\\___|_| |_|_|  \\_\\      \n");
    printf("-----------------------SaLGenR--------------------------\n");
    printf("         a powerfull employee management tool           \n");
    printf("                  @jibbleeinuxcode                      \n");
    printf("\n\n");
}

//main Function
int main()
{
    head = NULL; //declareing head to Null
    tail = NULL; //Declaring tail to Null
    mod = NULL;
    int option, option1, option2, option3, option4; //option for Main manu. Option1 for Add New section. Option2 for Search Section.
    char name[15], pass[15], name1[20];
    double salary;
    printLogo(); //call printlogo function.
    while (1)
    {
        //this is main loop.
        printf("You need to login first.\n");
        printf("Username: ");
        gets(name); //input username for login
        printf("Password: ");
        gets(pass);                 //input password for login
        if (loginCheck(name, pass)) /*calling login check function for check input username and password validity*/
        {
            /*This is dashboard section after successfull login*/
            while (1)
            {

                printf("\nSelect Your Option From Menu.\n");
                printf("------------------------------\n");
                //Options for main Menu.
                printf("1.Add New\n2.List\n3.Exit\n4.Modify\n5.Search\n6.Delete\n");
                printf("\nSalGenR>> ");
                scanf("%d", &option); //seacning key for main menu
                switch (option)
                {
                case 1:
                    system("cls");
                    //this is adding section. Here we can adding Employees Details various option
                    printf("\nChoose Option.\n");
                    printf("--------------\n");
                    printf("1.Add Employee Continuesly.\n");
                    printf("2.Add Employee at First.\n");
                    printf("3.Add Employee in position\n");
                    printf("4.Add Employee at Last.\n");
                    printf("5.Back\n");
                    printf("\nAdd New>> ");
                    scanf("%d", &option1); //options for add new section
                    switch (option1)
                    {
                    case 1:
                        //this case for store Employees details continiously
                        create_linked_list();
                        break;
                    case 2:
                        //this case for store Employees details from first Node
                        insert_at_first();
                        break;
                    case 3:
                        insert_after_postiton();
                        break;
                    case 4:
                        //this case for store Employees details from Last Node
                        insert_at_last();
                        break;
                    case 5:
                        //this section for back previous menu
                        break;
                    default:
                        //if user input a unvalid option which is not match on above.
                        printf("You Need to select valid option\n");
                        break;
                    }
                    break;
                case 2:
                    system("cls");
                    //this section for printing Employees records
                    PrintFromFile();
                    break;
                case 3:
                    //this exit function will exit this program
                    exit(0);
                    break;
                case 4:
                    system("cls");
                    //Modifie section start
                    printf("\nChoose Option.\n");
                    printf("--------------\n");
                    printf("1.Modifie by Name.\n");
                    printf("2.Modifie by ID.\n");
                    printf("3.Modifie by Age.\n");
                    printf("4.Modifie by Phone Number.\n");
                    printf("5.Modifie by Salary\n");
                    printf("6.Modifie by Address\n");
                    printf("7.Back\n");
                    printf("\nModifie>> ");
                    scanf("%d", &option3);

                    /*
                    if user are not want to modifie and leave these menu 
                    then they can get back previous menu by using this section
                    */
                    if (option3 == 7)
                    {
                        break;
                    }

                    switch (option3)
                    {
                    case 1:
                        //if user want to modifie employee by name then this condition will be true
                        if (modify_Employee_Name() == true) /*if modify function returns a true value then this condition will be true */
                        {
                            change_Records(mod);
                        }
                        break;
                    case 2:
                        //if user want to modifie employee by ID then this condition will be true
                        if (modify_Employee_ID() == true) /*if modify function returns a true value then this condition will be true */
                        {
                            change_Records(mod);
                        }
                        break;
                    case 3:
                        //if user want to modifie employee by age then this condition will be true
                        if (modify_Employee_Age() == true) /*if modify function returns a true value then this condition will be true */
                        {
                            change_Records(mod);
                        }
                        break;
                    case 4:
                        //if user want to modifie employee by phone Number then this condition will be true
                        if (modify_Employee_pnumber() == true) /*if modify function returns a true value then this condition will be true */
                        {
                            change_Records(mod);
                        }
                        break;
                    default:
                        //if user not input a valid option then this messege will be print
                        printf("\nYou need to choose currect option.\n");
                        break;
                    }

                    break;
                    //Modifie section end
                case 5:
                    system("cls");
                    //case 5 ----Search section start

                    printf("\nChoose your Searching Option.\n");
                    printf("-------------------------------\n");
                    printf("1.Search by Name\n");
                    printf("2.Search by ID\n");
                    printf("3.Search by Age\n");
                    printf("4.Search by Phone Number\n");
                    printf("5.Search by Salary\n");
                    printf("6.Search by Place\n");
                    printf("7.Back\n");
                    printf("\nSearch>> ");
                    scanf("%d", &option2);
                    switch (option2) //search option
                    {
                    case 1:
                        //Search Employee details using by Name
                        search_Employee_By_Name();
                        break;
                    case 2:
                        //Search Employee details using by ID
                        search_Employee_By_ID();
                        break;
                    case 3:
                        //Search Employee details using by Age
                        search_Employee_By_Age();
                        break;
                    case 4:
                        //Search Employee details using by Phone Number
                        search_Employee_By_phone();
                        break;
                    case 5:
                        //Search Employee details using by Salary
                        search_Employee_By_Salary();
                        break;
                    case 6:
                        //Search Employee details using by Area
                        search_Employee_By_Place();
                        break;
                    case 7:
                        //this section for back main menu
                        break;
                    default:
                        //if user input not vaild
                        printf("You have to choose right option\n");
                        break;
                    }

                    //case 5 ----search section End
                    break;
                case 6:
                    system("cls");
                    //delete section start
                    printf("\nChoose your Delete Option.\n");
                    printf("-------------------------------\n");
                    printf("1.Delete by Name\n");
                    printf("2.Delete by ID\n");
                    printf("3.Delete by Age\n");
                    printf("4.Delete by Phone Number\n");
                    printf("5.Delete by Salary\n");
                    printf("6.Delete by Place\n");
                    printf("7.Back\n");
                    printf("\nDelete>> ");
                    scanf("%d", &option4);

                    //switch section start
                    switch (option4)
                    {
                    case 1:
                        //if user want to delete record using by name
                        delete_Employee_Record_by_name();

                        break;
                    case 2:
                        //if user want to delete record using by ID
                        delete_Employee_Record_by_ID();
                        break;

                    case 3:
                        //if user want to delete record using by age
                        delete_Employee_Record_by_age();
                        break;
                    case 4:
                        //if user want to delete record using by Phone Number
                        delete_Employee_Record_by_Phone_Number();
                        break;
                    case 5:
                        //if user want to delete record using by Salary
                        delete_Employee_Record_by_Salary();
                        break;
                    case 6:
                        //if user want to delete record using by Address
                        delete_Employee_Record_by_Place();
                        break;
                    case 7:
                        break;
                    default:
                        //if user input not vaild
                        printf("You have to choose right option\n");
                        break;
                    }
                    //switch section end

                    break;
                    //delete section End
                default:
                    //if user not input bettween 1-6 then this messege will be print
                    printf("You Need to choose option into 1-6\n");
                    break;
                }
            }

            break;
        }
    }

    return 0;
}
