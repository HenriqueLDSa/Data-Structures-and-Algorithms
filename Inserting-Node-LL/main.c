/*Write a function insertAfterN, that takes the head of a linked list, and two integers M and N (M ≠ N) 
and inserts M after all the nodes containing N. For example, if M = 200 and N = 6, the linked list 3, 6, 
4, 6, 6, 5 will be changed to 3, 6, 200, 4, 6, 200, 6, 200, 5.  */

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{  
    int data;  
    struct node* next;  
} node;  
 
void insertAfterN(node* head, int M, int N)
{
    node *temp = head;

    if (head == NULL)
        printf("Linked list is empty!\n");
    else if (M == N)
    {
        printf("Make sure both numbers are not equal!\n");
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == N)
            {
                node *newNode = (node*) malloc(sizeof(node));

                newNode->data = M;
                newNode->next = temp->next;
                temp->next = newNode;

                temp->next->data = M;
            }

            temp = temp->next;
        }
    }

}