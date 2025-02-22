#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;

void InsertFirst(PPNODE head , int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else 
    {
        newn->next = *head;
        *head = newn;
    }
}

void InsertLast(PPNODE head , int iNo)
{   
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;
    PNODE temp = *head;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;    
    }
}

void DeleteFirst(PPNODE head)
{
    PNODE temp = *head;
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free (*head);
        *head == NULL;
    }
    else 
    {
        *head = (*head)->next;
        free (temp);        
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = *head;
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free (*head);
        *head = NULL;
    }
    else 
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;   
    }
}
void Display(PNODE head)
{
    printf("Number of Elements inside the Linked List are : \n");

    while(head != NULL)
    {
        printf("|%d|=>",head->data);
        head = head->next;    
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCount = 0; 

    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;
}

void InsertAtPos(PPNODE head , int iNo , int iPos)
{
    PNODE newn = NULL;
    int i = 0 , iCountnode = Count(*head);
    PNODE temp = *head;

    if(iPos < 1 || iPos > iCountnode + 1)
    {
        printf("Invalid Postion : \n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(head , iNo);
    }
    else if(iPos == iCountnode + 1)
    {
        InsertLast(head , iNo);
    }
    else 
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = iNo;
        newn->next = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }  
        newn->next = temp->next;
        temp->next = newn;       
    }
}



void DeleteAtPos(PPNODE head , int iPos)
{
    PNODE temp = *head;
    PNODE target = NULL;
    int i = 0 , CountNode = Count(*head);

    if(iPos < 1 || iPos > CountNode)
    {
        printf("Invalid Syntax : \n");
        return;
    }   
    if(iPos == 1)
    {
        DeleteFirst(head);
    }
    else if(iPos == CountNode)
    {
        DeleteLast(head);
    }
    else 
    {
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = temp->next->next;
        free (target);
    }
}
int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first,151);
    InsertFirst(&first,101);
    InsertFirst(&first,75);
    InsertFirst(&first,50);
    InsertLast(&first,171);

    InsertAtPos(&first,100,3);
    
    Display(first);
    iRet = Count(first);

    printf("Number of node inside the Linked List are : %d\n",iRet);

    DeleteFirst(&first);
    DeleteLast(&first);
    DeleteAtPos(&first,3);

    Display(first);
    iRet = Count(first);
    printf("Number of node inside the Linked List are : %d\n",iRet);

    return 0;
}

