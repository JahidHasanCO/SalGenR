/*this project name is SalGenR
This project for Employees details store in companies Database..
Using this Project we can handle our Employees Details
We can add new employee , we can search Employee, We can Modify Employees Records*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
} * head, *tail, *mod;

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

//Creating or adding linklist continiously
void create_linked_list()
{
    int n, i = 1;
    char name[20], address[20];
    int age, pnumber, id;
    double salary;
    printf("\nEnter Amount of Employee: ");
    scanf("%d", &n); //scanning size of employee add.

    while (n--)
    {
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

        struct employee *temp_node;
        temp_node = (struct employee *)malloc(sizeof(struct employee));
        strcpy(temp_node->name, name);
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
    struct employee *temp_node = (struct employee *)malloc(sizeof(struct employee));
    strcpy(temp_node->name, name);
    temp_node->ID = id;
    temp_node->age = age;
    temp_node->phone_number = pnumber;
    strcpy(temp_node->address, address);
    temp_node->salary = salary;
    temp_node->next = head;
    head = temp_node;
}

void insert_after_postiton()
{
    int key;
    struct employee *myNode = head;
    int flag = 0;
    printf("Enter position for insert Employee: ");
    scanf("%d", &key);
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
    while (myNode != NULL)
    {
        if (myNode->ID == key)
        {
            struct employee *newNode = (struct employee *)malloc(sizeof(struct employee));
            strcpy(newNode->name, name);
            newNode->ID = id;
            newNode->age = age;
            newNode->phone_number = pnumber;
            strcpy(newNode->address, address);
            newNode->salary = salary;
            newNode->next = myNode->next;
            myNode->next = newNode;

            printf("New Employee %s is inserted after %d\n", name, key);

            flag = 1;

            break;
        }
        else
            myNode = myNode->next;
    }

    if (flag == 0)
        printf("Key not found!\n");
}

//print all employees details
void print_employee_list()
{
    struct employee *temp = head;
    if (head == NULL)
    {
        printf("\nEmployee list is Empty\n");
    }
    else
    {
        int i = 1;
        while (temp != NULL)
        {
            printf("\n\nDetails for Employee %d\n", i);

            /*  20-10-8-15-20-14 */
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| Name               | ID       | Age    | Phone Number  | Address            | Salary       |\n");
            printf("----------------------------------------------------------------------------------------------\n");
            printf("| %-19s", temp->name);
            printf("| %-9d", temp->ID);
            printf("| %-7d", temp->age);
            printf("| 0%-13d", temp->phone_number);
            printf("| %-19s", temp->address);
            printf("| %-13lf|\n", temp->salary);
            printf("----------------------------------------------------------------------------------------------\n");
            temp = temp->next;
            i++;
        }
    }
}

//Delete Employees Record
void delete_Employee_Record()
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
            printf("-----------------------------------------\n");
            printf("Name: ");
            puts(myNode->name);
            printf("Employee ID: %d\n", myNode->ID);
            printf("Age: %d\n", myNode->age);
            printf("Phone Number: 0%d\n", myNode->phone_number);
            printf("Salary: %.2lf\n", myNode->salary);
            printf("\n\nFor Delete this record (type 1): ");
            scanf("%d", &key);
            if (key == 1)
            {

                if (previous == NULL)
                    head = myNode->next;
                else
                    previous->next = myNode->next;

                printf("%d is deleted from list\n", value);

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

    if (flag == 0)
        printf("\nThis ID not found!\n");
}

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
    while (searchNode != NULL)
    {
        if (strlwr(searchNode->name) == strlwr(value))
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%s Name employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Employee ID: %d\n", searchNode->ID);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("\nEmployee not found for this (%s) name\n", value);
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
    while (searchNode != NULL)
    {
        if (searchNode->ID == value)
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%d ID employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Employee ID: %d\n", searchNode->ID);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("\nEmployee not found for this (%d) ID\n", value);
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
    while (searchNode != NULL)
    {
        if (searchNode->age == value)
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%d Age employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Employee ID: %d\n", searchNode->ID);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("\nEmployee not found for this (%d) Age\n", value);
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
    while (searchNode != NULL)
    {
        if (searchNode->phone_number == value)
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%d Phone Number employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Employee ID: %d\n", searchNode->ID);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("\nEmployee not found for this (0%d) Phone number\n", value);
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
    while (searchNode != NULL)
    {
        if (searchNode->salary == value)
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%ld Salary employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Employee ID: %d\n", searchNode->ID);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("\nEmployee not found for this (%ld) salary\n", value);
}

//Search Employees Details by Place
void search_Employee_By_Place()
{
    char value[20];
    struct employee *searchNode = head;
    int flag = 0; //this variable check for search result validity
    printf("\nEnter area for search.\n");
    printf("----------------------\n");
    printf("\nSearch>> ");
    getchar();
    gets(value);
    while (searchNode != NULL)
    {
        if (strlwr(searchNode->name) == strlwr(value))
        {
            printf("\n\nSearch Result.\n");
            printf("-----------------\n");
            printf("%s area employee present in this database.\n", value);
            printf("Name: ");
            puts(searchNode->name);
            printf("Employee ID: %d\n", searchNode->ID);
            printf("Age: %d\n", searchNode->age);
            printf("Phone Number: 0%d\n", searchNode->phone_number);
            printf("Salary: %.2lf\n", searchNode->salary);
            flag = 1;
            searchNode = searchNode->next;
        }
        else
            searchNode = searchNode->next;
    }

    if (flag == 0)
        printf("\nEmployee not found for this (%s) Place\n", value);
}

//modifie section
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
            printf("-----------------------------------\n");
            printf("Name: ");
            puts(current->name);
            printf("Employee ID: %d\n", current->ID);
            printf("Age: %d\n", current->age);
            printf("Phone Number: 0%d\n", current->phone_number);
            printf("Salary: %.2lf\n", current->salary);
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
            current = current->next;
        }
        pos++;
    }

    printf("%s does not exist in the list\n", old);
}

bool modify_Employee_ID()
{
    int old;
    int pos = 0, key;
    if (head == NULL)
    {
        printf("\nDatabase not Found!\n");
        return false;
    }
    printf("\nEnter ID for modifie: ");
    scanf("%d", &old);
    struct employee *current = head;
    if (current->next == NULL)
    {
        if (current->ID == old)
        {
            printf("\n%d this ID found employee.\n", old);
            printf("-----------------------------------\n");
            printf("Name: ");
            puts(current->name);
            printf("Employee ID: %d\n", current->ID);
            printf("Age: %d\n", current->age);
            printf("Phone Number: 0%d\n", current->phone_number);
            printf("Salary: %.2lf\n", current->salary);
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
            printf("Name: ");
            puts(current->name);
            printf("Employee ID: %d\n", current->ID);
            printf("Age: %d\n", current->age);
            printf("Phone Number: 0%d\n", current->phone_number);
            printf("Salary: %.2lf\n", current->salary);
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
            current = current->next;
        }
        pos++;
    }

    printf("%s does not exist in the list\n", old);
}

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

// logo function
void printLogo()
{
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
    int option, option1, option2; //option for Main manu. Option1 for Add New section. Option2 for Search Section.
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
                    //this is adding section. Here we can adding Employees Details various option
                    printf("\nChoose Option.\n");
                    printf("--------------\n");
                    printf("1.Add Employee Continuesly.\n");
                    printf("2.Add Employee at First.\n");
                    printf("3.Add Employee in position\n");
                    printf("4.Add Employee at Last.\n");
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
                    default:
                        //if user input a unvalid option which is not match on above.
                        printf("You Need to select valid option\n");
                        break;
                    }
                    break;
                case 2:
                    //this section for printing Employees records
                    print_employee_list();
                    break;
                case 3:
                    exit(0);
                    break;
                case 4:
                    //Modifie function
                    if (modify_Employee_ID() == true)
                    {
                        change_Records(mod);
                    }
                    break;
                case 5:

                    //case 5 ----Search section start

                    printf("\nChoose your Searching Option.\n");
                    printf("-------------------------------\n");
                    printf("1.Search by Name\n");
                    printf("2.Search by ID\n");
                    printf("3.Search by Age\n");
                    printf("4.Search by Phone Number\n");
                    printf("5.Search by Salary\n");
                    printf("6.Search by Place\n");
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
                    default:
                        //if user input not vaild
                        printf("You have to choose right option\n");
                        break;
                    }

                    //case 5 ----search section End
                    break;
                case 6:
                    //Delete Employees record
                    delete_Employee_Record();
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
