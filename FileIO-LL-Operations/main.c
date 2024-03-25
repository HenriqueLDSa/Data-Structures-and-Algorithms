/*
An alternate method of storing a string is to store each letter of the string in a single node of a linked list, 
with the first node of the list storing the first letter of  the string. Using this method of storage, no null 
character is needed since the next field of the node storing the last letter of the string would simply be a 
null pointer.  
 
In this program, you are going to complete the missing below functions in the attached C-file.  
 
This program reads the input from the attached input.txt file in the following format: 
 
3 
6 
abcdef 
4 
1234 
2 
cm 
 
When the chars “abcdef” are read, your program will construct a linked list as follows: a -> b -> c -> d -> e -> f

You are going to implement the following functions: 
int length(node* head) 
char* toCString(node* head) 
void insertChar(node** pHead, char c) 
void deleteList(node** pHead) 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    node* temp = head;
    int numNodes = 0;

    while (temp!= NULL)
    {
        numNodes++;
        temp = temp->next;
    }
    
    return numNodes;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    node* temp = head;
    int linkedListLength = length(head);
    char* charArray = (char*) malloc(linkedListLength * sizeof(char));

    for(int i = 0; i < linkedListLength; i++){
        charArray[i] = temp->letter;
        temp = temp->next;
    }

    return charArray;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newNode = (node*) malloc(sizeof(node));
    node* temp = *pHead;

    newNode->letter = c;
    newNode->next = NULL;

    if(*pHead == NULL){
        *pHead = newNode;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }      
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* temp = *pHead;

    while(temp->next != NULL){
        temp = *pHead;
        *pHead = temp->next; 
        free(temp); 
    }

    *pHead = NULL; 
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        
        str = toCString(head);
        printf("\nString is : %s\n", str);
        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!\n\n");
            break;
        }
    }

    printf("\n");
}