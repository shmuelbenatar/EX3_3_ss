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

    if()
     
    
    
    
}
char* StrList_firstData(const StrList* StrList){
    return StrList -> _head -> _data;
}



