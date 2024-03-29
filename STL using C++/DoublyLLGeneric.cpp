// Doubly Linear
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
class DoublyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    Count = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
     struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {

        struct node<T> * temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}


template<class T>
void DoublyLL<T>::Display()
{
    struct node<T> * temp = first;

    cout<<"Elements of the linked list are : "<<endl;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if((first->next == NULL) && (first->prev == NULL))
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        free(first->prev);
        first->prev = NULL;  
    }
    Count--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL && first->prev == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {

        struct node<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
       
    }
    Count--;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T no,int ipos)
{
        if((ipos < 1 )|| (ipos > Count+1 ))
        {
            cout<<"Invalid position\n";
            return;
        }
        if(ipos == 1)
        {
            InsertFirst(no);
        }
       else if(ipos == Count+1)
        {
            InsertLast(no);
        }
        else
        { 
            struct node<T> * newn = new struct node<T>; 
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

        struct node<T> * temp = first;

            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            newn->prev = temp; 
            temp->next->prev = newn; 

            Count++;             
            }
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    struct node<T> * temp = first;
    int i = 0;
    if((ipos < 1 )|| (ipos > Count ))
        {
            cout<<"Invalid position\n";
            return;
        }
        if(ipos == 1)
        {
            DeleteFirst();
        }
       else if(ipos == Count)
        {
            DeleteLast();
        }
        else
        {         
            for( i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;

            Count--;
        }
}

int main()
{
    cout<<"------------------------------------------------------------------------------\n\n";
    cout<<"----------------------------INTEGER LINKEDLIST----------------------------------\n";
    DoublyLL<int> cobj;
    int iRet = 0;

    cobj.InsertFirst(151);
    cobj.InsertFirst(101);
    cobj.InsertFirst(51);
    cobj.InsertFirst(21);
    cobj.InsertFirst(11);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;

    cobj.InsertLast(201);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;

    cobj.InsertAtPos(251,7);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;

    cobj.DeleteAtPos(3);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;

    cobj.DeleteFirst();
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;

    cobj.DeleteLast();
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;



cout<<"------------------------------------------------------------------------------\n\n";
cout<<"----------------------------FLOAT LINKEDLIST----------------------------------\n";

    DoublyLL<float> fobj;
   // float iRet = 0.0f;

    fobj.InsertFirst(151.51f);
    fobj.InsertFirst(101.101f);
    fobj.InsertFirst(51.51f);
    fobj.InsertFirst(21.21f);
    fobj.InsertFirst(11.11f);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;

    fobj.InsertLast(201.201f);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;

    fobj.InsertAtPos(251.51f,7);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;

    fobj.DeleteAtPos(3);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;

    fobj.DeleteFirst();
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;

    fobj.DeleteLast();
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;


cout<<"------------------------------------------------------------------------------\n\n";
cout<<"----------------------------DOUBLE LINKEDLIST----------------------------------\n";

    DoublyLL<double> dobj;
  
    dobj.InsertFirst(151.5112);
    dobj.InsertFirst(101.10121);
    dobj.InsertFirst(51.5111);
    dobj.InsertFirst(21.2112);
    dobj.InsertFirst(11.1100);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;

    dobj.InsertLast(201.20189);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;

    dobj.InsertAtPos(251.5178,7);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;

    dobj.DeleteAtPos(3);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;

    dobj.DeleteFirst();
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;

    dobj.DeleteLast();
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;


    cout<<"------------------------------------------------------------------------------\n\n";
    cout<<"----------------------------CHARACTER LINKEDLIST----------------------------------\n";

    DoublyLL<char> obj;
  
    obj.InsertFirst('D');
    obj.InsertFirst('C');
    obj.InsertFirst('B');
    obj.InsertFirst('A');
    obj.InsertFirst('E');
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;

    obj.InsertLast('F');
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;

    obj.InsertAtPos('G',7);
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;

    obj.DeleteAtPos(3);
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;

    obj.DeleteFirst();
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;

    obj.DeleteLast();
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;
    return 0;
}