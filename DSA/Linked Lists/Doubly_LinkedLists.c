#include <stdio.h>
#include <stdlib.h>

struct dll{
    int data;
    struct dll *next;
    struct dll *prev;
    };

struct dll *head=NULL;
struct dll *tail=NULL;

void insertatbeg(int x){
struct dll *ptr=(struct dll*)malloc(sizeof(struct dll));
ptr->data=x;
if(head==NULL){
    ptr->next=NULL;
    ptr->prev=NULL;
    head=tail=ptr;
}
else{
    ptr->prev=NULL;
    ptr->next=head;
    head->prev=ptr;
    head=ptr;
}
}

insertatend(int x){
struct dll *temp=(struct dll*)malloc(sizeof(struct dll));
temp->data=x;
if(tail==NULL){
    temp->next=NULL;
    temp->prev=NULL;
    head=tail=temp;
}
else{
    temp->next=NULL;
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
}

void delatbeg(){
    struct dll *temp=(struct dll*)malloc(sizeof(struct dll));
    if(head==NULL){
        printf("list already empty\n");
    }
    else if(head->next==NULL){
        temp=head;
        head=tail=NULL;
    }
   else{
        temp=head;
        head=head->next;
        head->prev=NULL;
    }
    free(temp);
}

void delatend(){
struct dll *temp=(struct dll*)malloc(sizeof(struct dll));
if(tail==NULL){
    printf("list already empty\n");
}
else if(tail->prev==NULL){
    temp=tail;
    head=tail=NULL;
}
else{
    temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    }
    free(temp);
}

void forwardtraverse(){
struct dll *temp=head;
while(temp->next!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("%d ",temp->data);
}

void reversetraverse(){
struct dll *temp=tail;
while(temp->prev!=NULL){
    printf("%d ",temp->data);
    temp=temp->prev;
}
printf("%d ",temp->data);
}

int main(){
int opt,value,loct;
    while(opt!=7){

printf("which operation do you want to perform?\n");
printf("1.Insert at beginning\n");
printf("2.Insert at end\n");
printf("3.Delete from beginning\n");
printf("4.Delete from end\n");
printf("5.Forward traverse\n");
printf("6.reverse Traverse\n");
printf("7.Exit\n");

scanf("%d",&opt);

        switch(opt){
    case 1:printf("enter the value\n");
            scanf("%d",&value);
            insertatbeg(value);
            break;
    case 2:printf("enter the value\n");
            scanf("%d",&value);
            insertatend(value);
            break;
    case 3: delatbeg();
            break;
    case 4: delatend();
            break;
    case 5:forwardtraverse();
            break;
    case 6: reversetraverse();
            break;

        }
}
return 0;
}

