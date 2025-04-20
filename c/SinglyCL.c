#include<stdio.h> 
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}NODE , *PNODE , **PPNODE;

void InsertFirst(PPNODE head, PPNODE tail , int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if((*head == NULL) && (*tail == NULL))
    {
        *head = newn;
        *tail = newn;
    }   
    else 
    {
        newn->next = *head;
        *head = newn;
    }
    (*tail)->next = *head;
}
void InsertLast(PPNODE head , PPNODE tail , int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;  

    if(*head == NULL)
    {
        *head = newn;
        *tail = newn;
    }
    else 
    {
        (*tail)->next = newn;
        *tail = newn;
    }
    (*tail)->next = *head;
}

void DeleteFirst(PPNODE head , PPNODE tail )
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
        free ((*tail)->next);
    }      
    (*tail)->next = *head;
}
void DeleteLast(PPNODE head , PPNODE tail)
{
    PNODE temp = *head;
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
        while(temp->next != *tail)
        {
            temp = temp->next;
        }
        free(temp->next);
        *tail = temp;  
        temp->next = *head;       
    }
}
void Display(PNODE head , PNODE tail)
{
    printf("Number of Elements inside the Linked List are : \n");

    if(head == NULL && tail == NULL)
    {
        printf("Linked List is empty :\n");
        return;
    }
    
        do 
        {
            printf("|%d|=>",head->data);
            head = head->next;
        }while(head != tail->next);
        printf("\n");
    
}
int Count(PNODE head , PNODE tail)
{
    int iCount = 0;

    if((head != NULL) &&  (tail != NULL))
    {
    do 
    {
        iCount++;
        head = head->next;
    }while(head != tail->next);

    }
    return iCount;
}

void InsertAtPos(PPNODE head, PPNODE tail , int ino , int iPos)
{
    PNODE newn = NULL;
    PNODE temp = *head;
    int i = 0;
    int Countnode = Count(*head, *tail);

    if(iPos < 1 || iPos > Countnode + 1)
    {
        printf("Invalid Position \n");

        return;
    }   
    if(iPos == 1)
    {
        InsertFirst(head, tail,ino);
    }
    else if(iPos == Countnode + 1)
    {
        InsertLast(head , tail, ino);
    }
    else 
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = ino;
        newn->next = NULL;
        for(i = 1; i< iPos -1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next= newn;
    }
} 
void DeleteAtPos(PPNODE head , PPNODE tail, int iPos)
{
    PNODE temp = *head;
    int i = 0; 
    PNODE targetnode = NULL;
    int Countnode = Count(*head , *tail);

    if(iPos < 1 || iPos > Countnode)
    {
        printf("Invalid Position \n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(head , tail);
    }
    else if(iPos == Countnode) 
    {
        DeleteLast(head , tail);
    }
    else 
    {
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        targetnode = temp->next;
        temp->next = temp->next->next;
        free (targetnode);
    }
}
int main()
{
    PNODE first = NULL;
    PNODE last = NULL;
    InsertFirst(&first,&last,101);
    InsertFirst(&first,&last,51);
    InsertFirst(&first,&last,11);
    InsertLast(&first, &last,151);

    InsertAtPos(&first, &last, 75, 2);
    Display(first , last);
    int iRet = Count(first,last);

    printf("Number of Elements inside the Linked List are : %d\n",iRet);


    DeleteFirst(&first, &last);
    
    DeleteLast(&first, &last);

    DeleteAtPos(&first, &last , 2);

    Display(first, last);
    iRet = Count(first,last);

    printf("Number of Elements inside the Linked List are : %d\n",iRet);

    return 0;
}
