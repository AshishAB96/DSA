


class node 
{
    public int data;
    public node next;
    public node prev;
}
class Doubly
{
    public node head;
    public int iCount; 
    
    Doubly()
    {
        head = null;
        iCount = 0;
    }
 
    public void InsertFirst(int iNo)
    {
        node newn = null;
        newn = new node();
        newn.data = iNo;
        newn.next = null;
        newn.prev = null;
        
        if(head == null)
        {
            head = newn;
        }
        else
        {
            newn.next = head;
            head.prev = newn;
            head = newn;
            head.prev = null;
        }
        iCount++;   
    }
    public void InsertLast(int iNo)
    {
        
        node newn = null;
        newn = new node();
        newn.data = iNo;
        newn.next = null;
        newn.prev = null;
        
        if(head == null)
        {
            head = newn;
        }
        else
        {   
            node temp = head;
            while(temp.next != null) 
            {
                temp = temp.next;                
            }
            temp.next = newn;
        }
        iCount++;
    }

    public void InsertAtPos(int ino , int iPos)
    {
        node newn = null;
        node temp = null;

        if((iPos < 1) || (iPos > iCount + 1))
        {
            System.out.println("Invalid Position : \n");
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(ino);
        }
        else if(iPos == iCount + 1)
        {
            InsertLast(ino);
        }
        else
        {
            int i = 0; 
            newn  = new node();
            newn.data = ino;
            newn.next = null;
            newn.prev = null;
            temp = head;

            for(i = 1; i <  iPos- 1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;
            iCount++;
        }

    }
    public void Deletefirst()
    {
        if(head == null)
        {
            return ;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else 
        {
            head = head.next;
            head.prev = null;
            System.gc();
        }
        iCount--;
    }

    public void DeleteLast()
    {
        
        if(head == null)
        {
            return ;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else 
        {
            node temp = head;

            while(temp.next.next != null) 
            {
                temp = temp.next;
            }
            temp.next = null;
            System.gc();

        }
        iCount--;

    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;

        if((iPos < 1) || (iPos > iCount + 1))
        {
            System.out.println("Invaid Syntax : ");
            return;
        }
        if(iPos  == 1)
        {
            Deletefirst();
        }  
        else if(iPos == iCount)
        {
            Deletefirst();
        } 
        else 
        {
            int i = 0;
            temp = head;
            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }   
            temp.next = temp.next.next;
            temp.next.prev = temp;
            System.gc(); 
            iCount--;        
        }
    }
    public void Display()
    {
        System.out.println("Number of Elements inside the Linked List are : ");
        node temp = head;
        while(temp != null) 
        {
            System.out.print("|"+temp.data+"|=>");
            temp = temp.next;
        }
        System.out.println("NULL");

    }
    
    public int Count()
    {
        return iCount;
    }
}


class DoublyLL 
{
    public static void main(String a[])
    {
        Doubly dobj = new Doubly();

        dobj.InsertFirst(101);
        
        dobj.InsertFirst(51);
        
        dobj.InsertFirst(11);

        dobj.InsertLast(151);
        dobj.InsertAtPos(75, 3);

        dobj.Display();

        int iRet = dobj.Count();

        System.out.println(" LinkedList contains "+iRet+" Elements");


        dobj.Deletefirst();
        dobj.DeleteLast();
        dobj.DeleteAtPos(3);

        dobj.Display();

        iRet = dobj.Count();

        System.out.println(" LinkedList contains "+iRet+" Elements");

    }
}
