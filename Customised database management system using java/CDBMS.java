class CDBMS
{
    public static void main(String[] args)
    {
        DBMS obj = new DBMS();

        obj.InsertIntoTable("Aparna","Pune",99);
        obj.InsertIntoTable("Atul","Pune",89);
        obj.InsertIntoTable("Anushree","Nashik",72);
        obj.InsertIntoTable("Akaay","Dhule",65);

        obj.SelectStarFrom();
        obj.SelectStarFromWhereCity("Nashik");
        obj.SelectStarFromWhereName("Akaay");
        obj.SelectCount();
        obj.SumMarks();
        obj.AverageMarks();
        obj.MinMarks();
        obj.MaxMarks();
        obj.UpdateCity("Satara",4);
         obj.SelectStarFrom();
         obj.DeletefromTablewhere(3);
         obj.SelectStarFrom();
    }
}


class node
{
    private static int counter = 1;
    
    public int Rno;
    public String Name;
    public String City;
    public int Marks;

    public node next;

    public node(String A, String B, int C)
    {
        Rno = counter;
        counter++;
        Name = A;
        City = B;
        Marks = C;

        next = null;
    }
}

class DBMS
{
    private node first;

    public DBMS()
    {
        first = null;
        System.out.println("DBMS Initialized successfully!!");
        System.out.println("Student table gets created successfully!!");
    }

    public void InsertIntoTable(String Name, String City, int Marks)
    {
        node newn = new node(Name,City,Marks);
        node temp = first;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            while(temp.next != null)
            {
                temp = temp.next;
            }
                temp.next = newn;
            
        }
        System.out.println("One record gets inserted successfully..!!");
    }

     public void SelectStarFrom()
    {
        System.out.println("Data from the student table is : ");

        node temp = first;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            System.out.println(temp.Rno+"\t"+temp.Name+"\t"+temp.City+"\t"+temp.Marks);
            temp = temp.next;
        }
        System.out.println("--------------------------------------------------------------");
    }

    public void SelectStarFromWhereCity(String city)
    {
        System.out.println("Data from the student table where city is : "+city);

        node temp = first;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            if(city.equals(temp.City))
            System.out.println(temp.Rno+"\t"+temp.Name+"\t"+temp.City+"\t"+temp.Marks);
            temp = temp.next;
        }
        System.out.println("--------------------------------------------------------------");
    }

    public void SelectStarFromWhereName(String name)
    {
        System.out.println("Data from the student table where Name is : "+name);

        node temp = first;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            if(name.equals(temp.Name))
            System.out.println(temp.Rno+"\t"+temp.Name+"\t"+temp.City+"\t"+temp.Marks);
            temp = temp.next;
        }
        System.out.println("--------------------------------------------------------------");
    }

public void SelectCount()
    {
        node temp = first;
        int iCnt = 0;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            iCnt++;
            temp = temp.next;
            
        }
        System.out.println("Number of records in student table are : "+iCnt);
        System.out.println("--------------------------------------------------------------");
    }

    public void SumMarks()
    {
        node temp = first;
        int sum = 0;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            sum = sum + temp.Marks;
            temp = temp.next;
        }
        System.out.println("Summation of marks from student table is : "+sum);
        System.out.println("--------------------------------------------------------------");
    }

    public void AverageMarks()
    {
        node temp = first;
        int sum = 0;
        int iCnt = 0;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            sum = sum + temp.Marks;
            temp = temp.next;
            iCnt++;
        }
        System.out.println("Average of marks from student table is : "+(((float)sum/iCnt)));
        System.out.println("--------------------------------------------------------------");
    }
     public void MinMarks()
    {
        node temp = first;
        int Min = temp.Marks;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
           if(temp.Marks < Min)
            
             Min = temp.Marks;

            temp = temp.next;
        }
        System.out.println("Minimum marks from student table is : "+Min);
        System.out.println("--------------------------------------------------------------");
    }

     public void MaxMarks()
    {
        node temp = first;
        int Max = temp.Marks;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
           if(temp.Marks > Max)
            
             Max = temp.Marks;

            temp = temp.next;
        }
        System.out.println("Maximum marks from student table is : "+Max);
        System.out.println("--------------------------------------------------------------");
    }
    
    public void UpdateCity(String name, int rno)
    {

        node temp = first;

        System.out.println("--------------------------------------------------------------");
        while(temp != null)
        {
            if(rno==temp.Rno)
            {
                temp.City = name;
            }
            temp = temp.next;
        }
        System.out.println("Record updated successfully!");
        System.out.println("--------------------------------------------------------------");
    }

    public void DeletefromTablewhere(int rno)
    {
        node temp = first;

        if(temp == null)
        {
            return;
        }

        else if(temp.Rno == rno)
        {
            first = first.next;
            return;
        }
        else
        {
            while(temp.next != null)
            {
                if(temp.next.Rno == rno)
                {
                    temp.next = temp.next.next;
                    break;
                }
                temp = temp.next;
            }
        }
        System.out.println("Record get deleted successfully.!");
    }
}