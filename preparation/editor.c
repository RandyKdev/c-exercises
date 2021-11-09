#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct string {
    char *s;
    struct string *prev;
};

struct string *append(struct string *head)
{
    char str[1000000];
    int len;
    struct string *new_node = NULL;
    
    scanf("%s", str);
    len = strlen(str);
    new_node = (struct string*) calloc(1, sizeof(struct string));
    if (head == NULL) {
        new_node->s = (char*)calloc(len + 1, sizeof(char));
        strcpy(new_node->s, str);
    }
    else {
        int leny = strlen (head->s);
        new_node->s = (char *) calloc((len + leny) + 1, sizeof(char));
        strcpy(new_node->s, head->s);
        strcat(new_node->s, str);
    }
    
    new_node->prev = head;
    // printf("%s\n", new_node->s);
    return new_node;
}


struct string *delete_str(struct string *head)
{
    int num;
    scanf("%d", &num);
    int len = strlen(head->s);
    struct string *new_node = (struct string*)malloc(sizeof(struct string));
    new_node->s = (char*)malloc(sizeof(char)*(len- num + 1));
    if (len - num == 0) {
        new_node->s[0] = '\0';
    } else {
        strncpy(new_node->s, head->s, len-num);
    }
    printf("%s\n", new_node->s);
    new_node->prev = head;
    
    
    return new_node;
}

void print(struct string *head)
{
    int ind;
    scanf("%d", &ind);
    
    printf("%c\n", head->s[ind-1]);
}

struct string *undo(struct string *head)
{
    struct string *tm = head -> prev;
    
    free(head->s);
    free(head);
    return tm;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
       
    struct string *head = NULL;
    int num_ops = 0, i = 0, option;
    
    scanf("%d", &num_ops);
    
    while (i < num_ops)
    {
        scanf("%d ", &option);
        switch (option)
        {
            case 1:
                head = append(head);
                break;
            case 2:
                head = delete_str(head);
                break;
            case 3:
                print(head);
                break;
            case 4:
                head = undo(head);
                break;
            default:
                continue;
        }
        i++;
    }
    
    return 0;
}
