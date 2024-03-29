#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class StackGeneric
{
    private:
        int count;
        struct node<T> * first;
    
    public:
        StackGeneric();
        void push(T no);
        void Display();
        int CountNode();
        void pop();  
};

template<class T>
StackGeneric<T>::StackGeneric()
{
    count = 0;
    first = NULL;
}

template<class T>
void StackGeneric<T>::push(T no)
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
        newn->next = first;
        first = newn;
    }

    count++;
}

template<class T>
void StackGeneric<T>::pop()
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
void StackGeneric<T>::Display()
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
int StackGeneric<T>::CountNode()
{
    return count;
}

int main()
{
    cout<<"-----------------------\n\n";
    cout<<"----INTEGER STACK-------\n";
    StackGeneric<int> cobj;

    cobj.push(151);
    cobj.push(101);
    cobj.push(51);
    cobj.push(21);
    cobj.push(11);
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;

    cobj.pop();
    cobj.Display();
    cout<<"Number of nodes are : "<<cobj.CountNode()<<endl;

cout<<"-----------------------\n\n";
cout<<"----FLOAT STACK-------\n";

    StackGeneric<float> fobj;
   // float iRet = 0.0f;

    fobj.push(151.51f);
    fobj.push(101.101f);
    fobj.push(51.51f);
    fobj.push(21.21f);
    fobj.push(11.11f);
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;

    fobj.pop();
    fobj.Display();
    cout<<"Number of nodes are : "<<fobj.CountNode()<<endl;


cout<<"-----------------------\n\n";
cout<<"----DOUBLE STACK-------\n";

    StackGeneric<double> dobj;
  
    dobj.push(151.5112);
    dobj.push(101.10121);
    dobj.push(51.5111);
    dobj.push(21.2112);
    dobj.push(11.1100);
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;

    dobj.pop();
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.CountNode()<<endl;


   cout<<"-----------------------\n\n";
    cout<<"----CHARACTER STACK-------\n";

    StackGeneric<char> obj;
  
    obj.push('D');
    obj.push('C');
    obj.push('B');
    obj.push('A');
    obj.push('E');
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;

    obj.pop();
    obj.Display();
    cout<<"Number of nodes are : "<<obj.CountNode()<<endl;
    return 0;
}