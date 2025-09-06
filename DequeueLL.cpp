#include<iostream>
using namespace std;
class Node
{
    public : 
    int data;
    Node *prev,*next;

    Node(int data)
    {
        this->data=data;
        prev=next=NULL;
    }
};
class Deque
{ 
  Node *front,*rear;
  public:
  Deque()
  {
    front=rear=NULL;
  }

  void push_front(int val)
  {
    Node *temp=new Node(val);
    if(front==NULL)
    {
      front=rear=temp;
    }
    else
    {
       temp->next=front;
       front->prev=temp;
       front=temp;
    }
    cout<<"Pushed "<<val<<" in the front\n";
  }
   void push_back(int val)
  {
    Node *temp=new Node(val);
    if(front==NULL) 
    {
      front=rear=temp;
    }
    else
    {
      rear->next=temp;
      temp->prev=rear;
      rear=temp;
    }
    cout<<val<<" added in the Back"<<endl;
  }
  int showFront()
  {
    return front->data;
  }
  int showBack()
  {
    return rear->data;
  }
  void Pop_Back()
  {
    if(front==NULL)
    {
      cout<<"Deque is UnderFLow";
       return ;
     }
   Node *temp=rear;
    rear=rear->prev;
    cout<<"Deleted "<<temp->data <<" from BAck :";
    delete temp;
    if(rear)
    rear->next=NULL;
    else
    front=NULL;
  }
  void pop_front()
  {
    if(front==NULL)
    {
      cout<<"Deque is Underflow";
       return ;
    }
    Node *temp=front;
    front=front->next;
    cout<<"Deleted "<<temp->data <<" from front :";
    delete temp;
    if(front)
    front->prev=NULL;
    else
     rear=NULL;
  }
};
int main()
{
 Deque d;
 d.push_front(5);
 d.push_front(15);
 cout<<d.showFront()<<" in the Front"<<endl;
 cout<<d.showBack()<<" in the back"<<endl;
 d.push_back(2);
 d.push_back(1);
 cout<<d.showBack()<<" in the back"<<endl;
 d.Pop_Back();
  cout<<d.showBack()<<" in the back"<<endl;
  d.pop_front();
  cout<<d.showFront()<<" in the front"<<endl;
}