class node 
{
    public int data;
    public node next;
}
class Singly
{
    public node head;
    public int iCount;

    Singly()
    {
        head = null;
        iCount = 0;
    }

    public void Insertfirst(int no)
    {
        node newn = null;        

        newn = new node();
        newn.data = no;
        newn.next = null;

        if(head == null)
        {
            head = newn;
        }
        else
        {
            newn.next = head;
            head = newn;
        }
        iCount++;
    }

    public void Insertlast(int no)
    {
        node newn = null;        
        node temp = head;
        newn = new node();
        newn.data = no;
        newn.next = null;

        if(head == null)
        {
            head = newn;
        }
        else
        {
            while(temp.next != null) 
            {
                temp = temp.next;                
            }
            temp.next = newn;
        }
        iCount++;
    }

    public void InsertAtPos(int ino , int ipos)
    {
        node newn = null;
        int i = 0; 
        node temp = head;

        if(ipos < 1 || ipos > iCount  + 1)
        {
            System.out.println("Invalid Sysntax : \n");
            return;
        }

        if(ipos == 1)
        {
            Insertfirst(ino);
        }
        else if(ipos == iCount + 1)
        {
            Insertlast(ino);
        }
        else 
        {
            newn = new node();
            newn.data = ino;
            newn.next = null;

            for(i = 1; i < ipos - 1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }       
    }
    public void Deletefirst()
    {
        if(head == null)
        {
            return;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else 
        {
            head = head.next;
            System.gc();
        }
        iCount--;
    }
    public void Deletelast()
    {
        node temp = head;
        if(head == null)
        {
            return;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else 
        {
            while(temp.next.next != null) 
            {
                temp = temp.next;                
            }
            temp.next = null;
            System.gc();
        }
        iCount--;
    }

    public void DeleteAtPos(int ipos)
    {
        if((ipos < 1) || (ipos > iCount))
        {
            System.out.println("Invalid position");
            return;
        }

        if(ipos == 1)
        {
            Deletefirst();
        }
        else if(ipos == iCount)
        {
            Deletelast();
        }
        else
        {   
            node temp = head;
            int i = 0;

            for(i = 1; i < ipos-1; i++)
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

        node temp  = head;
        while(temp != null) 
        {
            System.out.print("|"+temp.data+"|->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }
    public int Count()
    {
        return iCount;
    }
}

class SinglyLL
{
    public static void main(String a[])
    {
        Singly sobj = new Singly();     
        int iRet = 0;

        sobj.Insertfirst(101);
        sobj.Insertfirst(51);
        sobj.Insertfirst(21);
        sobj.Insertfirst(11);

        sobj.Insertlast(111);
        sobj.Insertlast(121);

        sobj.InsertAtPos(75, 4);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Elements inside the Linked List are : "+iRet);

        sobj.Deletefirst();
         sobj.Deletelast();
        sobj.DeleteAtPos(4);

        
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Elements inside the Linked List are : "+iRet);


    }
}

