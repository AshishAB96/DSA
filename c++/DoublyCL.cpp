#include<iostream>
#include<stdlib.h>
using namespace std;


typedef struct node 
{
    int data;
    struct node *next;
    struct node *prev;
}NODE , *PNODE , *PPNODE;

class DoublyCL
{
    public:
        PNODE head;
        PNODE tail;
        int iCount;
        
    DoublyCL()
    {
        head = NULL;
        tail = NULL;
        iCount = 0;
    }
    void InsertFirst(int iNo)
    {
        PNODE newn = NULL;
        newn = new (NODE);
        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        if((head == NULL) && (tail == NULL))
        {
            head = newn;
            tail = newn;
        }
        else
        {
            newn->next = head;
            head = newn;
        }
        head->prev = tail;
        tail->next = head;
        iCount++;
    }
    void InsertLast(int iNo)
    {
        
        PNODE newn = NULL;
        newn = new (NODE);
        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        if((head == NULL) && (tail == NULL))
        {
            head = newn;
            tail = newn;
        }
        else
        {   
            tail->next = newn;
            newn->prev = tail;
            tail = newn;

        }
        head->prev = tail;
        tail->next = head;
        iCount++;
    }

    void InsertAtPos(int iNo , int iPos)
    {
        PNODE newn = NULL;
        PNODE temp = head;
        int i =0;

        if(iPos < 1 || iPos > iCount + 1)
        {
            cout<<"Invlaid Position :\n";
            return;
        }
        if(iPos == 1)
        {
            InsertFirst(iNo);

        }
        else if(iPos == iCount + 1)
        {
            InsertLast(iNo);
        }
        else 
        {
            newn = new (NODE);
            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;
            
            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;

            iCount++;
        }
    }
    void DeleteFirst()
    {
        if((head == NULL ) && (tail  == NULL))
        {

            return;
        }
        else if(head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else 
        {
            head = head->next;
            delete tail->next;
        } 
        head->prev = tail;
        tail->next = head;
        iCount--;
    }

    void DeleteLast()
    {
        
        if((head == NULL ) && (tail  == NULL))
        {

            return;
        }
        else if(head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else 
        {
            tail = tail->prev;
            delete head->prev;

        }
        head->prev = tail;
        tail->next = head;
        iCount--;
    }

    void DeleteAtPos(int iPos)
    {
        int i = 0; 
        PNODE temp = head;
        PNODE target = NULL;

        if(iPos < 1 || iPos >  iCount)
        {
            cout<<"Invalid Position :\n";
            return;
        }
        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount )
        {
            DeleteLast();
        }
        else 
        {
            for(i = 1; i < iPos-1; i++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete target;            
        }        
    }
    void Display()
    {
        cout<<"Number  of Elements inside the Linked List are : \n";

        if((head == NULL) &&  (tail == NULL))
        {
            cout<<"Linked List is Empty : \n";
            return;
        }
        do 
        {
            cout<<"|"<<head->data<<"|<=>";
            head = head->next;
        }while(head != tail->next);
        cout<<"NULL\n";
    }

    int Count()
    {
        return iCount;
    }
};

int main()
{

    DoublyCL dobj;

    dobj.InsertFirst(101);
    
    dobj.InsertFirst(51);
    
    dobj.InsertFirst(21);

    dobj.InsertFirst(11);

    dobj.InsertLast(151);

    dobj.InsertAtPos(75,4);
    dobj.Display();

    dobj.DeleteFirst();
    dobj.DeleteLast();
    dobj.DeleteAtPos(2);

    dobj.Display();

    return 0;
}