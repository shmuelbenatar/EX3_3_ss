
#include <stdio.h>
#include "StrList.h"


int main()
{
    int userChoice;

    printf("Enter a number between 0 and 12: ");
    scanf("%d", &userChoice);
    do
    {

        switch (userChoice)
        {
        case 1:
            StrList* stringList =StrList_alloc();
            
            break;
        case 2:
            printf("You chose option 2\n");
            break;
        case 3:
            printf("You chose option 3\n");
            break;
        case 4:
            printf("You chose option 4\n");
            break;
        case 5:
            printf("You chose option 5\n");
            break;
        case 6:
            printf("You chose option 6\n");
            break;
        case 7:
            printf("You chose option 7\n");
            break;
        case 8:
            printf("You chose option 8\n");
            break;
        case 9:
            printf("You chose option 9\n");
            break;
        case 10:
            printf("You chose option 10\n");
            break;
        case 11:
            printf("You chose option 11\n");
            break;
        case 12:
            printf("You chose option 12\n");
            break;
        case 13:
            printf("You chose option 13\n");
            break;
        case 0:
            printf("You chose option 13\n");
            break;
        default:
            break;
        }

    } while (userChoice != 0 && userChoice != EOF); // Continue the loop until the user chooses to exit
    return 0;
}
