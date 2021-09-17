#include <stdio.h>
#include <stdlib.h>

struct sll{
    int data;
    struct sll *next;
    };
struct sll *start=NULL;

void insertatbeg(int x){
struct sll *insatbeg=(struct sll*)malloc(sizeof(struct sll));
    insatbeg->data=x;
    insatbeg->next=start;
    start=insatbeg;

}

void insertatend(int x){
    struct sll *insatend=(struct sll*)malloc(sizeof(struct sll));
    struct sll *temp=start;
    insatend->data=x;
    insatend->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=insatend;

}

void insertatloc(int x,int loc){
    int i,k;
    struct sll *ptr=(struct sll*)malloc(sizeof(struct sll));
    struct sll *temp=start;
    ptr->data=x;
    for(i=0;i<loc;i++){
        temp=temp->next;
        if(temp==NULL)
            printf("node less than one");

    }
    ptr->next=temp->next;
    temp->next=ptr;
}


void delatbeg(){
    if(start==NULL){
        printf("linkedlist already empty");
    }
    else{
    struct sll *del=(struct sll*)malloc(sizeof(struct sll));
    del=start;
    start=start->next;
    free(del);
    }
}

void delatend(){
     struct sll *del=(struct sll*)malloc(sizeof(struct sll));
     struct sll *pntr=(struct sll*)malloc(sizeof(struct sll));
    if(start==NULL){
        printf("linkedlist already empty");
    }
    else if(start->next==NULL){
        del=start;
        start=NULL;
        free(del);
        }
    else{
        del=start;
        pntr=start->next;
        while(pntr->next!=NULL){
            del=pntr;
            pntr=pntr->next;
        }
        del->next=NULL;
        free(pntr);
    }
}


int delatpos(int val){
    struct sll *temp=start;
    struct sll *loc=start;

    if(start==NULL){
        printf("linkedlist already empty");
    }
    else{
    while(temp!=NULL){
        if(temp->data==val){
            loc->next=temp->next;
            free(temp);
            return 0;
        }
        loc=temp;
        temp=temp->next;
      }
    }
    return 0;
    }

 void display(){
      struct sll *temp=start;
      while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
      }
      printf("%d \n",temp->data);
 }

int main(){
int opt,value,loct;
    while(opt!=8){

printf("which operation do you want to perform?\n");
printf("1.Insert at beginning\n");
printf("2.Insert at end\n");
printf("3.Insert at specific position\n");
printf("4.Delete from beginning\n");
printf("5.Delete from end\n");
printf("6.Delete specific value\n");
printf("7.Display\n");
printf("8.Exit\n");

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
    case 3:printf("enter the value\n");
            scanf("%d",&value);
            printf("enter location of node");
            scanf("%d",&loct);
            insertatloc(value,loct);
            break;
    case 4: delatbeg();
            break;
    case 5: delatend();
            break;
    case 6:printf("enter the value to be deleted in linked list\n");
            scanf("%d",&value);
            delatpos(value);
            break;
    case 7: display();
            break;

        }
}
return 0;
}
