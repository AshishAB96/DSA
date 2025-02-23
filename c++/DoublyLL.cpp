#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node *next;
    struct node *prev;
}NODE , *PNODE;

class DoublyLL
{
    public:
        PNODE head;
        int iCount;
    
        DoublyLL()
        {
            head = NULL;
            iCount = 0;        
        }   
        void InsertFirst(int iNo)
        {
            PNODE newn = new NODE;
            newn->data = iNo;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else 
            {
                newn->next = head;
                head->prev = newn;
                head = newn;
            }
            iCount++;
        }

        void InsertLast(int iNo)
        {
            PNODE newn = new NODE;
            newn->data = iNo; 
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else 
            {
                PNODE temp = head;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
                newn->prev = temp;
            }
            iCount++;
        }

        void InsertAtPos(int iNo , int iPos)
        {
            if(iPos < 1 || iPos > iCount + 1)
            {
                cout<<"Invalid Position\n";
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
                PNODE newn = new NODE;
                newn->data = iNo;
                newn->next = NULL;
                newn->prev = NULL;

                PNODE temp = head;
                for(int i = 1; i <  iPos -1; i++)
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
            if(head == NULL)
            {
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
                delete head->prev;
                head->prev = NULL;
            }
            iCount--;
        }

        void DeleteLast()
        {
            if(head == NULL)
            {
                return;
            }
            else if(head->next == NULL)
            {
                delete head;
                head = NULL;
            }
            else 
            {
                PNODE temp = head;
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
            PNODE target = NULL;
            if(iPos < 1 || iPos > iCount)
            {
                cout << "Invalid Position\n";
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
                PNODE temp = head;

                for(i = 1; i < iPos - 1; i++)
                {
                    temp = temp->next;
                }
                target = temp->next;
                temp->next = temp->next->next;
                temp->next->prev = temp;
                delete target;

                iCount--;
            }
        }

        void Display()
        {
            PNODE temp = head;
            cout<<"Elements inside the Linked list are : \n";

            while(temp != NULL)
            {
                cout<<"|"<<temp->data<<"|<=>";
                temp = temp->next;        
            }
            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyLL dobj;

    dobj.InsertFirst(101);
    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.InsertLast(151);
    dobj.InsertAtPos(91,4);

    dobj.Display();

    dobj.DeleteFirst();
    
    dobj.DeleteAtPos(3);

    dobj.Display();

    return 0;
}
