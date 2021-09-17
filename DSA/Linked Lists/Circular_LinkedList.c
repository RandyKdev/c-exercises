#include <stdio.h>
#include <stdlib.h>

struct csll{
    int data;
    struct csll *next;
    };
struct csll *first=NULL;
struct csll *rear=NULL;

void insertatbeg(int x){
    struct csll *insatbeg=(struct csll*)malloc(sizeof(struct csll));
    insatbeg->data=x;
    if(first==NULL){
        insatbeg->next=first;
        rear=first;
    }
    else{
        insatbeg->next=first;
        first=insatbeg;
        rear->next=first;
    }
}

void insertatend(int x){
    struct csll *temp=(struct csll*)malloc(sizeof(struct csll));
     temp->data=x;
    if(rear==NULL){
        temp->next=first;
        rear=temp;
    }
   else{
    temp->next=first;
    rear->next=temp;
    rear=temp;
    }
}
void delatbeg(){
    struct csll *temp=first;
    first=first->next;
    rear->next=first;
    free(temp);
}

void delatend(){
    struct csll *cur=first->next;
    struct csll *temp=first;
    while(cur!=NULL){
        temp=cur;
        cur=cur->next;
        }
        temp->next=first;
        free(cur);
    }

void display(){
    struct csll *tempo=first;
        printf("%d ",tempo->data);
        tempo=tempo->next;

    while(tempo!=rear->next && tempo!=NULL){
        printf("%d ",tempo->data);
        tempo=tempo->next;
    }
}




int main(){
int opt,value,loct;
    while(opt!=6){

printf("which operation do you want to perform?\n");
printf("1.Insert at beginning\n");
printf("2.Insert at end\n");
printf("3.Delete from beginning\n");
printf("4.Delete from end\n");
printf("5.Display\n");
printf("6.Exit\n");

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
    case 5:display();
            break;

        }
}
return 0;
}


