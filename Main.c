
#include <stdio.h>
#include "StrList.h"



int main(){
    int userChoice;
    StrList* StrList1 = NULL;


    printf("Enter a number between 0 and 13: ");
    scanf("%d", &userChoice);
    do
    {
        switch (userChoice)
        {
        case 1:
            size_t userSize;
            StrList1 = StrList_alloc();
            if(scanf("%zu",&userSize)!=1){
                return 0;
            }
            else{
                for(size_t i=1;i<=userSize;i++){
                    char* getWord = malloc(sizeof(char)*100);
                    scanf(" %s", getWord);
                    StrList_insertLast(StrList1,getWord);
                }
            }
            break;
        case 2:
            int getIndex = -1;
            scanf("%d", &getIndex);
            char *data = malloc(sizeof(char) * 100);
            scanf("%s",data);
            StrList_insertAt(StrList1, data, getIndex);
            break;
        case 3:
            StrList_print(StrList1);
            break;
        case 4:
            size_t lenString = StrList_size(StrList1);
            printf("%zu",lenString);
            break;
        case 5:
            int getindex = -1;
            scanf("%d", &getindex);
            StrList_printAt(StrList1, getindex);
            break;
        case 6:
            int numberOfChar = StrList_printLen(StrList1);
            printf("%d",numberOfChar);
            break;
        case 7:
            char *getString = malloc(sizeof(char) * 100);
            scanf("%s",getString);
            int ans = StrList_count(StrList1, getString);
            printf("%d",ans);
            break;
        case 8:
            char *getStringToRemove = malloc(sizeof(char) * 100);
            scanf("%s",getStringToRemove);
            StrList_remove( StrList1, getStringToRemove);
            break;
        case 9:
            int getIndexToRemove = -1;
            scanf("%d", &getIndexToRemove);
            StrList_removeAt(StrList1, getIndexToRemove); 
            break;
        case 10:
            StrList_reverse(StrList1);
            break;
        case 11:
            StrList_free(StrList1);
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