
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
///////////////////////////////////////////////////////////
struct node *createnode()  // function to create node
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    return (t);
}
////////////////////////////////////////////////////////
struct node* insert(struct node* start, int item)  // function to insert at first location
{
    struct node *p;
    p = createnode();
    p->link = NULL;
    p->info = item;
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        p->link = start;
        start = p;
    }

    return start;
}

struct node* search(struct node* list, int item) {


    for(; list != NULL && list->info != item; list = list->link);
    return list;
    // if(list == NULL) return NULL;

    // if(list->info == item) return list;

    // search(list->link, item);
}



int main(void) {
    struct node* head = createnode();
    for(int i = 0; i < 5; i++) {
        head = insert(head, i);
    }

    
    struct node* s = search(head, 51);
    if(s == NULL) {
        printf("NULL\n");    
    } else
    printf("%d\n", s->info);
    return 0;
}