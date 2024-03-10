#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCL
{
    private:
        int count;
        struct node<T> * first;
        struct node<T> * last;

    public:

        DoublyCL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no,int ipos);
    void DeleteAtPos(int ipos);
    void DeleteFirst();
    void DeleteLast();
    int Count();
    void Display();
};

template<class T>
DoublyCL<T> :: DoublyCL()
{
    count = 0;
    first = NULL;
    last = NULL;
}

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct node <T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else 
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    first->prev = last;
    last->next = first;
    count++;
}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{   
    struct node <T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else 
    {
        //newn->next = first;
       // first->prev = newn;
        last->next = newn;
        newn->prev = last;
        last = newn;

    }
    first->prev = last;
    last->next = first;
    count++;

}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
  if((first == NULL)&&(last == NULL))
  {
    return;
  }  
  else if(first == last)
  {
    delete first;
    first = NULL;
    last = NULL;
  }
  else
  {
    first = first->next;
    delete first->prev;
   
  }
   first->prev = last;
    last->next = first;
  count--;
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
    if((first == NULL)&&(last == NULL))
  {
    return;
  }  
  else if(first == last)
  {
    delete last;
    first = NULL;
    last = NULL;
  }
  else
  {
    last = last->prev;
    delete first->prev;
      first->prev = last;
    last->next = first;
  }
 
  count--;
}

template<class T>
void DoublyCL<T>::Display()
{
    cout<<"Contents of the linked list are : \n";

    if((first != NULL)&&(last != NULL))
    {
    do
    {
        cout<<"<=> | "<<first->data<<" | ";
        first = first->next;

    }while(first != last -> next);

    cout<<"<=>\n";
    }
}

template<class T>
int DoublyCL<T> :: Count()
{
    return count;
}


template<class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    struct node <T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    int i = 0;
    struct node <T> * temp = first;

    if((ipos < 1) || (ipos > count+1))
    {
        cout<<"Invalid position\n";
        return;
    }
    else if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == count+1)
    {
        InsertLast(no);
    }
    else
    {
        for(i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;

            count++;
    }
    
}

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    int i = 0;
    struct node <T> * temp = first;

    if((ipos < 1) || (ipos > count))
    {
        cout<<"Invalid position\n";
        return;
    }
    else if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == count)
    {
        DeleteLast();
    }
    else
    {
        for(i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        count--;
    }
    
}

int main()
{
    cout<<"------------------------------------------------------------------------------\n\n";
    cout<<"----------------------------INTEGER LINKEDLIST----------------------------------\n";
    DoublyCL<int> cobj;
    int iRet = 0;

    cobj.InsertFirst(151);
    cobj.InsertFirst(101);
    cobj.InsertFirst(51);
    cobj.InsertFirst(21);
    cobj.InsertFirst(11);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.Count()<<endl;

    cobj.InsertLast(201);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.Count()<<endl;

    cobj.InsertAtPos(251,7);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.Count()<<endl;

    cobj.DeleteAtPos(3);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.Count()<<endl;

    cobj.DeleteFirst();
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.Count()<<endl;

    cobj.DeleteLast();
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.Count()<<endl;



cout<<"------------------------------------------------------------------------------\n\n";
cout<<"----------------------------FLOAT LINKEDLIST----------------------------------\n";

    DoublyCL<float> fobj;
   // float iRet = 0.0f;

    fobj.InsertFirst(151.51f);
    fobj.InsertFirst(101.101f);
    fobj.InsertFirst(51.51f);
    fobj.InsertFirst(21.21f);
    fobj.InsertFirst(11.11f);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.Count()<<endl;

    fobj.InsertLast(201.201f);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.Count()<<endl;

    fobj.InsertAtPos(251.51f,7);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.Count()<<endl;

    fobj.DeleteAtPos(3);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.Count()<<endl;

    fobj.DeleteFirst();
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.Count()<<endl;

    fobj.DeleteLast();
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.Count()<<endl;


cout<<"------------------------------------------------------------------------------\n\n";
cout<<"----------------------------DOUBLE LINKEDLIST----------------------------------\n";

    DoublyCL<double> dobj;
  
    dobj.InsertFirst(151.5112);
    dobj.InsertFirst(101.10121);
    dobj.InsertFirst(51.5111);
    dobj.InsertFirst(21.2112);
    dobj.InsertFirst(11.1100);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    dobj.InsertLast(201.20189);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    dobj.InsertAtPos(251.5178,7);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    dobj.DeleteAtPos(3);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    dobj.DeleteFirst();
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<endl;

    dobj.DeleteLast();
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<endl;


    cout<<"------------------------------------------------------------------------------\n\n";
    cout<<"----------------------------CHARACTER LINKEDLIST----------------------------------\n";

    DoublyCL<char> obj;
  
    obj.InsertFirst('D');
    obj.InsertFirst('C');
    obj.InsertFirst('B');
    obj.InsertFirst('A');
    obj.InsertFirst('E');
    obj.Display();
    cout<<"Number of nodes are : "<<obj.Count()<<endl;

    obj.InsertLast('F');
    obj.Display();
    cout<<"Number of nodes are : "<<obj.Count()<<endl;

    obj.InsertAtPos('G',7);
    obj.Display();
    cout<<"Number of nodes are : "<<obj.Count()<<endl;

    obj.DeleteAtPos(3);
    obj.Display();
    cout<<"Number of nodes are : "<<obj.Count()<<endl;

    obj.DeleteFirst();
    obj.Display();
    cout<<"Number of nodes are : "<<obj.Count()<<endl;

    obj.DeleteLast();
    obj.Display();
    cout<<"Number of nodes are : "<<obj.Count()<<endl;
    return 0;
}