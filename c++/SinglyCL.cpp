#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct  node 
{
    int data;
    struct node *next;   
}NODE , *PNODE;

class SinglyCL
{
    public:
        PNODE head;
        PNODE tail;
        int iCount;

        SinglyCL()
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

        if(head == NULL &&  tail == NULL)
        {   
            head = newn;
            tail = newn;
        }
        else
        {
            newn->next = head;
            head = newn;
            tail->next = head;
        }
        iCount++;
    }
    void InsertLast(int iNo)
    {
        PNODE newn = NULL;
        newn = new (NODE);
        newn->data = iNo;
        newn->next = NULL;

        if(head == NULL &&  tail == NULL)
        {   
            head = newn;
            tail = newn;
        }
        else
        {   
            
            tail->next = newn;
            tail = newn;
            tail->next = head;   
        }
        iCount++;
    }   
    void DeleteFirst()
    {
        if(head == NULL &&  tail == NULL)
        {
            cout<<"Linked List is Empty\n";
            return;
        }
        if(head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            delete (tail->next);    
        }
        tail->next = head;
        iCount--;
    }
    void DeleteLast()
    {
        PNODE temp = head;
        if(head == NULL &&  tail == NULL)
        {
            cout<<"Linked List is Empty\n";
            return;
        }
        if(head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else 
        {
            while(temp->next->next != head)
            {
                temp = temp->next;
            }
            tail = temp;
            delete temp->next;
           
        }
        temp->next = head;
        iCount--;
    }
 
    void InsertAtPos(int iNo , int iPos)
    {
        PNODE newn = NULL;
        int i = 0;
        PNODE temp = head;

        if(iPos < 1 || iPos > iCount + 1)
        {
            cout<<"Linked List is Empty :\n";
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

            for(i = 1; i< iPos -1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;

            iCount++;
        }
   }
      void DeleteAtPos(int iPos)
    {
        int i = 0;
        PNODE temp = head;   
        PNODE target = NULL;       
        if(iPos < 1 || iPos > iCount)
        {
            cout<<"Linked List is Empty :\n";
            return;
        }
        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else 
        {
            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = temp->next->next;
            delete target;
            
            iCount--;
        }
    }
    void Display()
    {
        cout<<"Number of elements iside the Linekd List are : \n";

        if(head == NULL && tail == NULL)
        {
            cout<<"Linked List is Empty :\n";
            return;
        }
        
        do
        {
            cout<<"|"<<head->data<<"|=>";
            head = head->next;
        } while(head != tail->next);
        cout<<"NULL \n";       
    }

    int Count()
    {
        return iCount;
    }
};

int main()
{
    SinglyCL sobj;

    sobj.InsertFirst(101);

    
    sobj.InsertFirst(75);
    
    sobj.InsertFirst(55);
    
    sobj.InsertFirst(11);

    sobj.InsertLast(151);

    sobj.InsertAtPos(91,4);

    sobj.Display();
    
    sobj.DeleteFirst();

    sobj.DeleteLast();

    sobj.DeleteAtPos(4);

    sobj.Display();
    return 0;
}