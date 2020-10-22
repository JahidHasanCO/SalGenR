#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define _Username_ "Admin"
#define _Password_ "Admin"

bool loginCheck(char name[15], char pass[15]);

int main()
{
    int option;
    char name[15], pass[15];
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