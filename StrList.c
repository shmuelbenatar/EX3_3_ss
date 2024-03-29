
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"





//------------------------------------------------
// Node implementation
//------------------------------------------------

Node* Node_alloc(char* data, Node* next){
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

StrList* StrList_alloc(){
    StrList* p=(StrList*)malloc(sizeof(StrList));
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
    size_t totalChars = 0;
    Node* current = StrList->_head;
    while (current != NULL) {
        totalChars++; 
        current = current->_next;
    }
    return totalChars;
    
}

void StrList_insertLast(StrList* StrList,const char* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return;
    }
    newNode ->_data = strdup(data);
    newNode ->_next = NULL;

    if (StrList->_head == NULL) {
        StrList->_head = newNode; 
    } else {
        Node* current = StrList->_head;
        while (current->_next != NULL) {
            current = current->_next;
        }
        current->_next = newNode; 
    
    }
     StrList -> _size++;
}



void StrList_insertAt(StrList* StrList,const char* data , int index){
    if(index < 0 || index > StrList -> _size){
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return;
    }
    newNode -> _data = strdup(data);
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

char* StrList_firstData(const StrList* StrList){
    if(StrList -> _head == NULL){
        return NULL;
    }
    return (char*)StrList -> _head -> _data;
}

void StrList_print(const StrList* StrList){
    Node* current = StrList -> _head;
    
    while (current->_next != NULL){
        printf("%s ",current -> _data);
        current = current -> _next;
    }
    if(current != NULL){
        printf("%s",current ->_data);
    } 
    printf("\n");
}


void StrList_printAt(const StrList* StrList, int index) {
    if (index < 0 || index >= StrList->_size) {
        return;
    }
    Node* current = StrList->_head;
    for (int i = 0; i < index; ++i) {
        current = current->_next;
    }
    printf("%s\n", current->_data);
}


int StrList_printLen(const StrList* StrList) {
    int totalChars = 0;
    Node* current = StrList->_head;
    while (current != NULL) {
        totalChars += (int)strlen(current->_data);
        current = current->_next;
    }
    return totalChars;
}


int StrList_count(StrList* StrList, const char* data){
    int count = 0;
        Node* current = StrList->_head;
        while (current) {
            if (strcmp(current->_data,data) == 0) {
                count++;
            }
            current = current->_next;
        }
    return count;
}



void StrList_remove(StrList* strList, const char* data) {
    Node* current = strList->_head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL) {
        if (strcmp(current->_data, data) == 0) {
            next = current->_next;

            if (prev != NULL) {
                prev->_next = next;
            } 
            else {
                strList->_head = next;
            }
            free(current); 
            strList->_size--; 
            current = next;
        } 
        else {
            prev = current;
            current = current->_next;
        }
    }
}

void StrList_removeAt(StrList* strList, int index) {
    if (index < 0 || index >= strList->_size) {
        return; 
    }
    Node* current = strList->_head;
    Node* prev = NULL;
    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->_next;
    }
    if (prev == NULL) {
        strList->_head = current->_next;
    } 
    else {
        prev->_next = current->_next;
    }
    free(current); 
    strList->_size--; 
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



StrList* StrList_clone(const StrList* StrList) {
    struct _StrList* newList = StrList_alloc();
    if (newList == NULL) {
        return NULL; 
    }
    newList->_size = StrList->_size;

    Node* currentOriginal = StrList->_head;
    Node* tailNew = NULL; 

    while (currentOriginal != NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            StrList_free(newList); 
            return NULL;
        }
        newNode->_data = currentOriginal->_data;
        newNode->_next = NULL;

        if (newList->_head == NULL) {
            newList->_head = newNode;
        } 
        else {
            tailNew->_next = newNode;
        }
        tailNew = newNode;

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
    if (list == NULL && list->_size <= 1) {
        return;
    }
    int size = (int)list->_size;

    int i,j;
    Node* node;
    Node* nextNode;

    for(i = 0;i < size - 1;i++){
        node = list->_head;
        nextNode = node->_next;
        for(j=0; j < size - 1 - i;j++){
            if(0 < strcmp(node->_data,nextNode->_data)) {
                char* temp = nextNode->_data;
                nextNode->_data = node->_data;
                node->_data = temp;
            }
            node = node->_next;
            nextNode = nextNode->_next;
        }
    }
}


int StrList_isSorted(StrList* strList) {
    Node* current = strList->_head;
    
    while (current->_next != NULL) {
        if (strcmp(current->_data, current->_next->_data) > 0) {
            printf("false\n");
            return 0; 
        }
        current = current->_next;
    }
    printf("true\n");
    return 1; //if current is null so return 1
}


