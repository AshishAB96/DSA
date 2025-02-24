
class node
{
    public int data;
    public node next;
    public node prev;
}

class Doubly
{
    public node head;
    public node tail;
    public int iCount;

    public Doubly()
    {
        head = null;
        tail = null;
        iCount = 0;
    }
    public void Insertfirst(int ino)
    {   
        node newn = null;
        newn = new node();
        newn.data = ino;
        newn.next = null;
        newn.prev = null;
        if((head == null) && (tail == null))
        {
            head = newn;
            tail = newn;
        }
        else 
        {
            newn.next = head;
            head.prev = newn;
            head = newn;
        }
        head.prev = tail;
        tail.next = head;
        iCount++;
    }
    public void Insertlast(int iNo)
    {
        node newn = null;
        newn = new node();
        newn.data = iNo;
        newn.next = null;
        newn.prev = null;

        if((head == null) && (tail == null))
        {
            head = newn;
            tail = newn;
        }
        else 
        {
            tail.next = newn;
            newn.prev = tail;
            tail = newn;
        }
        head.prev = tail;
        tail.next = head;
        iCount++;          
    }
    public void InsertAtPos(int ino , int ipos)
    {
        node newn = null;
        node temp = null;

        if((ipos <  1)  || (ipos > iCount + 1))
        {
            System.out.println("Invalid Sysntax : ");
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
            int i = 0; 
            temp = head;
            newn = new node();
            newn.data = ino;
            newn.next = null;
            newn.prev = null;

            for(i = 1; i < ipos - 1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next.prev = newn;
            newn.prev = temp;
            temp.next = newn;
            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if((head == null ) &&  (tail == null))
        {
            System.out.println("Linked List is Empty ");
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
            tail.next = null;
            System.gc();
        }
        head.prev = tail;
        tail.next = head;
        iCount--;
    }

    public void DeleteLast()
    {
        if((head == null ) &&  (tail == null))
        {
            System.out.println("Linked List is Empty ");
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
            tail = tail.prev;
            tail.next = null;
            System.gc();
        }
        head.prev = tail;
        tail.next = head;   
        iCount--;
    }
    public void DeleteAtPos(int ipos)
    {
        node temp  = null;

        if((ipos < 1 ) || (ipos > iCount))
        {
            return;
        }
        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == iCount) 
        {
            DeleteLast();
        }
        else 
        {
            temp = head;
            int i = 0;
            for(i = 1; i < ipos - 1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev =temp;
            System.gc();
            iCount--;
        }
    }

    public void Display()
    {
        System.out.println("Number of Elements inside the Linked List are : ");
        node temp = head;

        do 
        {

            System.out.print("|"+temp.data+"|<=>");
            temp = temp.next;
        }while(temp != tail.next);  
        System.out.println("NULL");

    }

    public int Count()
    {
        return iCount; 
    }

}
class DoublyCL 
{
    public static void main(String a[])
    {
        Doubly dobj = new Doubly();

        dobj.Insertfirst(101);
        dobj.Insertfirst(51);
        dobj.Insertfirst(21);
        dobj.Insertfirst(11);
        dobj.Insertfirst(1);

        dobj.Insertlast(151);

        dobj.InsertAtPos(75, 5);
        
        dobj.Display();
        int iRet = dobj.Count();
        System.out.println("Number of Elements inside the Lineked list are : "+iRet);   
        
        dobj.DeleteFirst();
        dobj.DeleteLast();
        dobj.DeleteAtPos(3);
        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of Elements inside the Lineked list are : "+iRet);   

    }
}