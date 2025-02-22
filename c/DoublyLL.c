#include<stdio.h> 
#include<stdlib.h> 

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE , **PPNODE;

void InsertFirst(PPNODE head , int ino)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = ino;
    newn->next = NULL;
    newn->prev = NULL;

    if(*head == NULL)
    {
        *head = newn;        
    }
    else 
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
}

void InsertLast(PPNODE head , int iNo)
{
    
    PNODE newn = NULL;
    PNODE temp = *head;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

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
        newn->prev = temp;
    }
}
void DeleteFirst(PPNODE head)
{
    if(*head == NULL)
    {
        return;
    }

    if((*head)->next == NULL)
    {
        free (*head);
        *head = NULL;
    }
    else 
    {
         *head = (*head)->next;
        free ((*head)->prev);
        (*head)->prev = NULL;
   }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = *head;
    if(*head == NULL)
    {
        return;
    }

    if((*head)->next == NULL)
    {
        free (*head);
        *head = NULL;
    }
    else 
    {
        while(temp->next->next !=  NULL)
        {
            temp = temp->next;
        } 
        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE head)
{
    printf("Number of elements inside the Linked List are : \n");
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

void InsertAtPos(PPNODE head, int ino , int iPos)
{
    PNODE newn = NULL;  
    PNODE temp = *head;
    int i= 0;
    int CountNode = Count(*head);

    if(iPos < 1 || iPos > CountNode + 1)
    {
        printf("Invlaid Position\n");
        return;
    } 

    if(iPos == 1)
    {
        InsertFirst(head, ino);
    }
    else if(iPos == CountNode + 1)
    {
        InsertLast(head, ino);
    }
    else 
    {
        newn  = (PNODE)malloc(sizeof(NODE));
        newn->data = ino;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}
void DeleteAtPos(PPNODE head  , int iPos)
{
    int i = 0;
    int Countnode = Count(*head);   
    PNODE temp = *head;
    PNODE targetnode = NULL;
    if(iPos < 1 || iPos > Countnode )
    {
        printf("Invalid Position \n");
        return ;
    }   
    if(iPos == 1)
    {
        DeleteFirst(head);
    }
    else if(iPos == Countnode)
    {
        DeleteLast(head);
    }
    else 
    {
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        targetnode = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;      
        free (targetnode);
    }
}
int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first,151);
    InsertFirst(&first,111);
    InsertFirst(&first,75);
    InsertFirst(&first,51);

    InsertAtPos(&first,75,3);

    InsertLast(&first,171);
    Display(first);
    iRet = Count(first);

    printf("Number of Nodes Inside the Linekd List are : %d\n",iRet);

    DeleteFirst(&first);
    DeleteLast(&first);

    DeleteAtPos(&first,3);
    Display(first);

    iRet = Count(first);

    printf("Number of Nodes inside the Linked List are : %d\n",iRet);

    return 0;

}