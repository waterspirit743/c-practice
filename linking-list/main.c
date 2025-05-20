#include <stdio.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *new_linked_list()
{
    return NULL;
}

void append_linked_list(Node **list, int val)
{
    Node *node = *list;
    Node *prenode = NULL;
    while (node != NULL)
    {
        prenode = node;
        node = node->next;
    }
    Node *new_node = malloc(sizeof(Node));
    new_node->data = val;
    if (prenode != NULL)
    {
        prenode->next = new_node;
    }
    else
    {
        *list = new_node;
    }
}
void print_linked_list(Node *list)
{
    if (list == NULL)
    {
        printf("empty\n");
        return;
    }
    Node *node = list;
    while (node != NULL)
    {
        printf("%d", node->data);
        if (node->next != NULL)
        {
            printf(",");
        }
        node = node->next;
    }
    printf("\n");
}
void free_linked_list(Node *node)
{

    while (node != NULL)
    {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
}
int main()
{
    Node *list = new_linked_list();
    append_linked_list(&list, 1);
    append_linked_list(&list, 2);
    append_linked_list(&list, 3);
    print_linked_list(list);
    free_linked_list(list);
    return 0;
}