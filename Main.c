
#include <stdio.h>
#include "StrList.h"



int main()
{
    int userChoice;
    StrList* StrList1 = NULL;

    printf("Enter a number between 0 and 13: ");
    scanf("%d", &userChoice);
    do
    {
        switch (userChoice)
        {
        case 1:
            StrList* stringList = StrList_alloc();
            
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
            int getindex ;
            scanf("%d", &getindex);
            StrList_removeAt(StrList1, getindex); 
            break;
        case 10:
            StrList_reverse(StrList1);
            break;
        case 11:
            printf("You chose option 11\n");
            break;
        case 12:
            StrList_sort(StrList1);
            break;
        case 13:
            if(StrList_isSorted(StrList1)){
                printf("false");
            }
            else{
                printf("true");
            }
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
