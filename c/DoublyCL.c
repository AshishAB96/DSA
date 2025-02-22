#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
    struct node *prev;
}NODE , *PNODE , **PPNODE;

void InsertFirst(PPNODE head , PPNODE tail , int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((*head == NULL ) && (*tail == NULL))
    {
        *head = newn;
        *tail = newn;
    }
    else 
    {
        newn->next = *head;
        *head = newn;
    }
    (*head)->prev = *tail;
    (*tail)->next = *head;
}

void InsertLast(PPNODE head , PPNODE tail , int iNo)
{
    
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((*head == NULL ) && (*tail == NULL))
    {
        *head = newn;
        *tail = newn;
    }
    else 
    {
        (*tail)->next = newn;
        newn->prev = *tail;    
        *tail = newn;
    }
    (*head)->prev = *tail;
    (*tail)->next = *head;
}


void DeleteFirst(PPNODE head , PPNODE tail)
{
    if((*head == NULL) && (*tail == NULL))
    {
        return;
    }
    else if(*head == *tail)
    {
        free (*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        free((*tail)->next);
    }
    (*head)->prev = *tail;
    (*tail)->next = *head;
}

void DeleteLast(PPNODE head , PPNODE tail)
{
    if((*head == NULL) && (*tail == NULL))
    {
        return;
    }
    else if(*head == *tail)
    {
        free (*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *tail = (*tail)->prev;
        free ((*head)->prev);
    }
    (*head)->prev = *tail;
    (*tail)->next = *head;
}

void Display(PNODE head , PNODE tail)
{
    printf("Number of Elements Inside the Linked List are : \n");

    if((head) == NULL && (tail) == NULL)
    {
        printf("Linked List is Empty : \n");
        return;
    }  
    do 
    {
        printf("|%d|<=>",head->data);
        head = head->next;

    }while(head != tail->next);
    printf("\n");
}

int  Count(PNODE head, PNODE tail)
{
    int iCount = 0;

    if((head) == NULL && (tail) == NULL)
    {
        printf("Linked List is Empty : \n");
        return -1;
    }  
    do 
    {
        iCount++;
        head = head->next;

    }while(head != tail->next);

    return iCount;
}
void InsertAtPos(PPNODE head , PPNODE tail , int iNo , int iPos)
{
    PNODE newn = NULL;
    int i = 0 , CountNode = Count(*head , *tail);
    PNODE temp = *head;
    
    if(iPos < 1 || iPos > CountNode + 1)
    {
        printf("Invalid Synstax :\n");
        return;
    }   
    if(iPos == 1)
    {
        InsertFirst(head , tail , iNo);
    }
    else if(iPos == CountNode + 1)
    {
        InsertLast(head , tail , iNo);
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
        temp->next->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE head , PPNODE tail , int iPos)
{
    PNODE temp = *head;
    int i = 0, CountNode = Count(*head, *tail);
    PNODE target = NULL;
    
    if(iPos < 1 || iPos > CountNode )
    {
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst(head , tail);
    }
    else if(iPos == CountNode + 1)
    {
        DeleteLast(head , tail);
    }
    else
    {
        for(i = 1; i< iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        free (target);
    }
}
int main()
{
    PNODE first = NULL;
    PNODE last = NULL;
    int iRet = 0;

    InsertFirst(&first,&last,151);
    
    InsertFirst(&first,&last,91);
    
    InsertFirst(&first,&last,51);

    InsertFirst(&first,&last,21);
    InsertFirst(&first,&last,11);

    InsertLast(&first,&last,171);
    InsertAtPos(&first, &last,115, 4);

    Display(first, last);

    iRet = Count(first, last);

    printf("Number of Nodes  inside the Linked List are : %d\n",iRet);

    DeleteFirst(&first, &last);
    DeleteLast(&first, &last);
    DeleteAtPos(&first, &last,3);
    Display(first, last);

    iRet = Count(first, last);

    printf("Number of Nodes  inside the Linked List are : %d\n",iRet);

    
    return 0;
}