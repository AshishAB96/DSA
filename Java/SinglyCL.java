
class node 
{
    public int data;
    public node next;
}
class Singly
{
    public node head;
    public node tail;
    public int iCount;

    Singly()
    {
        head = null;
        tail = null;
        iCount = 0;
    }  
    void Insertfirst(int ino)
    {
        node newn = null;
        newn = new node();
        newn.data = ino;
        newn.next = null;

        if((head == null) && (tail == null))
        {   
            head = newn;
            tail = newn;
        }
        else 
        {
            newn.next = head;
            head = newn;
        }
        tail.next = head;
        iCount++;
    }
    void InsertLast(int ino)
    {
        node newn = null;
        newn = new node();
        newn.data = ino;
        newn.next = null;

        if((head == null) && (tail == null))
        {   
            head = newn;
            tail = newn;
        }
        else 
        {
            node temp = head;

            while(temp.next != head) 
            {
                temp = temp.next;             
            }
            temp.next = newn;
            tail = newn;
        }
        tail.next = head;
        iCount++;              
    }

    void InsertAtPos(int ino , int iPos)
    {
      node newn = null;
      node temp = null;

      if((iPos < 1 ) || (iPos > iCount + 1))
      {
        System.out.println("Invalid Position :\n");
        return;
      }
      if(iPos == 1)
      {
        Insertfirst(ino);
      }
      else if(iPos == iCount + 1)
      {
        InsertLast(ino);
      } 
      else 
      {
        int i = 0 ; 
        temp = head;
        newn = new node();
        newn.data = ino;
        newn.next = null;
        for(i = 1; i < iPos -1; i++)
        {
            temp = temp.next;
        }
        newn.next = temp.next;
        temp.next = newn;
        iCount++;
      }       
    }

    void Deletefirst()
    {
        if((head == null) && (tail == null))
        {
            System.out.println("Invalid Syntax");
            return;
        }
        else if(head == tail)
        {
            head = null;
            tail = null;
            System.gc();
        }
        else 
        {
            head = head.next;
            System.gc();
        }
        tail.next = head;
        iCount--;
    }
    void Deletelast()
    {
        
        if((head == null) && (tail == null))
        {
            System.out.println("Invalid Syntax");
            return;
        }
        else if(head == tail)
        {
            head = null;
            tail = null;
            System.gc();
        }
        else 
        {
            node temp = head;
            while(temp.next.next != head)
            {
                temp = temp.next;
            }
            tail.next = null;
            System.gc();     
        }
        tail.next = head;
        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        node temp = null;
        
        if((iPos < 1 ) || (iPos >  iCount))
        {
            System.out.println("invalid Syntax :");
            return;
        }

        if(iPos == 1)
        {
            Deletefirst();
        }
        else if(iPos == iCount + 1)
        {
            Deletelast();
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
            System.gc();
            iCount--;
        }
    }

    public void Display()
    {
        System.out.println("Elements inside the Linked List are : ");
        node temp = head;
        do 
        {
            System.out.print("|"+temp.data+"|=>");
            temp = temp.next;
        }while(temp != tail.next);

        System.out.println("NULL");

    }

    public int Count()
    {
        return iCount;
    }
}
class SinglyCL
{
    public static void main(String a[])
    {
        Singly sobj = new Singly();     
        sobj.Insertfirst(101);
        sobj.Insertfirst(51);
        sobj.Insertfirst(21);
        sobj.Insertfirst(11);

        sobj.InsertLast(151);
        sobj.InsertAtPos(75,4);

        sobj.Display();

        int iRet = sobj.Count();

        System.out.println("number of Eelements inside the Linked List are : "+iRet);

        sobj.Deletefirst();

        sobj.Deletelast();
        sobj.DeleteAtPos(3);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("number of Eelements inside the Linked List are : "+iRet);

    }
}   