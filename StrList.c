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

void List_free(StrList* list){
    if(list==NULL) return ;
    Node* p1 = list -> _head;
}


