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

int bbl(){
struct sll *cur=start->next;
struct sll *temp=start;
while(cur->next->next!=NULL){
    temp=cur;
    cur=cur->next;
}
return(temp->data);
}



int main(){
int opt,value,loct;
    while(opt!=8){

printf("which operation do you want to perform?\n");
printf("1.Insert at beginning\n");


scanf("%d",&opt);

        switch(opt){
    case 1:printf("enter the value\n");
            scanf("%d",&value);
            insertatbeg(value);
            break;


        }

}
loct=bbl();
printf("%d ",loct);
return 0;
}

