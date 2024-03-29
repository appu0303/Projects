#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class QueueGeneric
{
    private:
        int count;
        struct node<T> * first;
    
    public:
        QueueGeneric();
        void Enqueue(T no);
        void Display();
        int CountNode();
        void Dequeue();  
};

template<class T>
QueueGeneric<T>::QueueGeneric()
{
    count = 0;
    first = NULL;
}

template<class T>
void QueueGeneric<T>::Enqueue(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
       struct node<T> * temp = first;

       while(temp -> next != NULL)
       {
        temp = temp -> next;
       }
       temp->next = newn;
    }

    count++;
}

template<class T>
void QueueGeneric<T>::Dequeue()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    } 
    
    else
    {
        struct node<T> * temp = first;
        first = first->next;
        delete temp;
    }
    count--;
}

template<class T>
void QueueGeneric<T>::Display()
{
    struct node<T> * temp = first;

    cout<<"Elements of the stack are :"<<endl;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"___"<<endl;
}

template<class T>
int QueueGeneric<T>::CountNode()
{
    return count;
}

int main()
{
    cout<<"-----------------------\n\n";
    cout<<"----INTEGER QUEUE-------\n";
    QueueGeneric<int> cobj;

    cobj.Enqueue(151);
    cobj.Enqueue(101);
    cobj.Enqueue(51);
    cobj.Enqueue(21);
    cobj.Enqueue(11);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;

    cobj.Dequeue();
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;

cout<<"-----------------------\n\n";
cout<<"----FLOAT QUEUE-------\n";

    QueueGeneric<float> fobj;
   // float iRet = 0.0f;

    fobj.Enqueue(151.51f);
    fobj.Enqueue(101.101f);
    fobj.Enqueue(51.51f);
    fobj.Enqueue(21.21f);
    fobj.Enqueue(11.11f);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;

    fobj.Dequeue();
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;


cout<<"-----------------------\n\n";
cout<<"----DOUBLE QUEUE-------\n";

    QueueGeneric<double> dobj;
  
    dobj.Enqueue(151.5112);
    dobj.Enqueue(101.10121);
    dobj.Enqueue(51.5111);
    dobj.Enqueue(21.2112);
    dobj.Enqueue(11.1100);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;

    dobj.Dequeue();
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;


   cout<<"-----------------------\n\n";
    cout<<"----CHARACTER QUEUE-------\n";

    QueueGeneric<char> obj;
  
    obj.Enqueue('D');
    obj.Enqueue('C');
    obj.Enqueue('B');
    obj.Enqueue('A');
    obj.Enqueue('E');
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;

    obj.Dequeue();
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;
    return 0;
}