#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StrList.h"




int main(){
    int userChoice;
    StrList *StrList1 = StrList_alloc();
    int userSize = 0;
    int maxWord = 45;

    
    do
    {
        scanf("%d", &userChoice);
        switch (userChoice)
        
        {
        case 1:
           
            if(scanf("%d",&userSize)!=1){
                return 0;
            } 
            
            for (int i = 0; i < userSize; i++) {
                char newWord[maxWord];
                scanf("%s", newWord);
                if (newWord != NULL) {
                    StrList_insertLast(StrList1, newWord);
                }
            }
            break;
           
        case 2:
            int getIndex = -1;
            scanf("%d", &getIndex);
            char data[100];
            scanf("%s",data);
            StrList_insertAt(StrList1, data, getIndex);
            break;
        case 3:
            StrList_print(StrList1);

            break;
        case 4:
            int lenString = StrList_size(StrList1);
            printf("%d\n",lenString);
            break;
        case 5:
            int getindex = -1;
            scanf("%d", &getindex);
            StrList_printAt(StrList1, getindex);
            break;
        case 6:
            int numberOfChar = StrList_printLen(StrList1);
            printf("%d\n",numberOfChar);
            break;
        case 7:
            char getString[50];
            scanf("%s",getString);
            int ans = StrList_count(StrList1, getString);
            printf("%d\n",ans);
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
        int i =StrList1->_size-1;
            while(i>0){
                StrList_removeAt(StrList1,0);
                i--;
            }
            StrList1->_head->_data = "";
            break;
        case 12:
            StrList_sort(StrList1);
            break;
        case 13:
            StrList_isSorted(StrList1);
            break;
        case 0:
            StrList_free(StrList1);
            return 0;
            break;
        default:
            break;
        }

    } while (userChoice != 0 && userChoice != EOF); // Continue the loop until the user chooses to exit
    return 0;
}