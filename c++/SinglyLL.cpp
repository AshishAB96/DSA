#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node 
{
    int data;
    struct node  *next;
}NODE , *PNODE;

class SinglyLL
{
    public: 
        PNODE head;     
        int iCount;
    SinglyLL()
    {
        head = NULL;
        iCount = 0;
    }
    void InsertFirst(int iNo)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = iNo;
        newn->next = NULL;
    
        if(head == NULL)
        {
            head = newn;
        }
        else
        {
            newn->next = head;
            head = newn;
        }  
        iCount++;      
    }
    void InsertLast(int iNo)
    {
        PNODE newn = NULL;
        PNODE temp = head;
        newn = new NODE;
        newn->data = iNo;
        newn->next = NULL;

        if(head == NULL)
        {
            head = newn;
        }
        else
        {
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next  = newn;         
        }  
        iCount++;    
    }   
    void InserAtPos(int iNo, int iPos)
    {
        PNODE newn = NULL;
        int i = 0;
        PNODE temp = head;

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
            for(i = 1; i< iPos -1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            iCount++;          
        }
    }
    void DeleteFirst()
    {
        PNODE temp = head;
        if(head == NULL)
        {
            cout<<"Linked List is Empty \n";
            return;
        }
        else if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else 
        {
            head = head->next;
            delete temp;
        }
        iCount--;
    }
    void DeleteLast()
    {
        
        PNODE temp = head;
        if(head == NULL)
        {
            cout<<"Linked List is Empty \n";
            return;
        }
        else if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else 
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        iCount--;
    }
    void DeleteAtPos(int iPos)
    {
        int i = 0;
        PNODE temp = head;
        PNODE target = NULL;

        if(iPos < 1 || iPos > iCount )
        {
            cout<<"Invalid Sysntax :\n";
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
        cout<<"Elements Inside the Linekd List are : \n";
        PNODE temp = head;
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|=>";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    int Count()
    {
        return iCount;
    }
};

int main()
{
    SinglyLL sobj;

    sobj.InsertFirst(101);
    sobj.InsertFirst(75);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(151);

    sobj.InserAtPos(95,4);

    sobj.Display();

    sobj.DeleteFirst();
    sobj.DeleteLast();
    sobj.DeleteAtPos(3);
    sobj.Display();

    return 0;
}