#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char _data;
    struct _node * _next;
}Node;

struct _StrList{
    Node* _head;
    size_t _size;
}List;



//------------------------------------------------
// Node implementation
//------------------------------------------------

Node* Node_alloc(char data, Node* next){
    Node* p=(Node*)malloc(sizeof(Node));
    p->_data=data;
    p->_next=next;
    return p;

}
void Node_free(Node* node){
    free (node);
}

//------------------------------------------------
// List implementation
//------------------------------------------------

StrList* List_alloc(){
    StrList* p=(StrList*)malloc(sizeof(List));
    p->_head=NULL;
    p->_size=0;
    return p;
}

void StrList_free(StrList* StrList){
    if(StrList==NULL) return ;
    Node* p1 = StrList -> _head;
    Node* p2;
    while (p1){
        p2=p1;
        p1= p1 -> _next;
        Node_free(p2);
    }
    free(StrList);
}


size_t StrList_size(const StrList* StrList){
    return StrList ->_size;
}

void StrList_insertLast(StrList* StrList,const char* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return;
    }
    newNode ->_data = *data;
    newNode ->_next = NULL;

    if(StrList -> _head = *data){
        newNode -> _next = NULL;
    }
    else
    {
        Node* current = StrList -> _head;
        while (current -> _next != NULL ){
            current = current -> _next;
        }

        current -> _next = newNode; 
    }
     StrList ->  _size++;
}


char* StrList_firstData(const StrList* StrList){
    return StrList -> _head -> _data;
}

void StrList_insertAt(StrList* StrList,const char* data , int index){
    if(index < 0 || index > StrList -> _size){
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return;
    }
    newNode -> _data = *data;
    newNode ->_next = NULL;

    if(index == 0){
        newNode -> _next = StrList -> _head;
        StrList -> _head = newNode;
    } 
    else{
        Node* current = StrList-> _head;
        for(int i = 0 ; i< index -1 ; ++i){
            current = current -> _next;  
        }
        newNode -> _next = current -> _next;
        current -> _next = newNode;
    }
    StrList -> _size++;
}










int StrList_isEqual(const StrList* strList1, const StrList* strList2) {
    Node* current1 = strList1->_head;
    Node* current2 = strList2->_head;


    while (current1 != NULL && current2 != NULL) {
        if (strcmp(current1->_data, current2->_data) != 0) {
            return 0; 
        }
        current1 = current1->_next;
        current2 = current2->_next;
    }

   
    if (current1 != NULL || current2 != NULL) {
        return 0;
    }

    return 1;
}




StrList* StrList_clone(const StrList* originalList) {
    // יצירת רשימה חדשה
    StrList* newList = (StrList*)malloc(sizeof(StrList));
    if (newList == NULL) {
        return NULL; // אם נכשלה ההקצאה
    }

    // איתחול הרשימה החדשה
    newList->_head = NULL;
    newList->_size = originalList->_size;

    // עובר על הרשימה המקורית ומעתיק כל תא ומחרוזת
    Node* currentOriginal = originalList->_head;
    Node* tailNew = NULL; // סיימנו כאן את הרשימה החדשה עד כה

    while (currentOriginal != NULL) {
        // יצירת תא חדש
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            // אם נכשלה ההקצאה
            StrList_free(newList); // לשחרור הזיכרון שנוצר עד כה
            return NULL;
        }
        newNode->_data = currentOriginal->_data;
        newNode->_next = NULL;

        // מחבר את התא לרשימה החדשה
        if (newList->_head == NULL) {
            newList->_head = newNode;
        } else {
            tailNew->_next = newNode;
        }
        tailNew = newNode;

        // המשך לתא הבא ברשימה המקורית

        currentOriginal = currentOriginal->_next;
    }

    return newList;
}


void StrList_reverse(StrList* strList) {
    Node* prev = NULL;
    Node* current = strList->_head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }

    strList->_head = prev;
}



void StrList_sort(StrList* list) {
    if (list->_size <= 1){
         return;
    }
    Node* current = list->_head;
    Node* index = NULL;
    char temp;

    while (current != NULL) {
        
        index = current->_next;

        while (index != NULL) {
            if (current->_data > index->_data) {
                temp = current->_data;
                current->_data = index->_data;
                index->_data = temp;
            }
            index = index->_next;
        }
        current = current->_next;
    }
}


int StrList_isSorted(StrList* strList) {
    Node* current = strList->_head;
    
    while (current != NULL && current->_next != NULL) {
        if (strcmp(current->_data, current->_next->_data) > 0) {
            return 0; 
        }
        current = current->_next;
    }
    
    return 1; //if current is null so return 1
}


