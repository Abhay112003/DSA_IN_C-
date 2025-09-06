#include<iostream>
using namespace std;
class Dequeue
{
    int *arr;
    int size,front,rear;
   public:
    Dequeue(int s)
    {
      arr=new int[s];
      size=s;
      front=rear=-1;
    }
    //Check Dequeqe is EMPTY OR NOT
    bool isEmpty()
    {
        return front==-1;
    }
    //Check Dequeqe is FULL OR NOT
    bool isFull()
    {
       return (rear+1)%size==front;
    }

    //PUSH IN THE FRONT
    void push_front(int val){
   
      if(isEmpty())
      {
        front++;
        rear++;
        arr[front]=val;
      }
      else if(isFull())
      {
        cout<<"Dequeue is OverFlow :"<<endl;
        return;
      }
      else
      {
        front=(front-1+size)% size;
        cout<<front<<"index";
        arr[front]=val;
      }
      cout<<arr[front]<<"Added In the Front"<<endl;
    }
    //PUSH IN THE END
    void Push_back(int val)
    {
       
       if(isEmpty())
       {
        front++;
        rear++;
        arr[front]=val;
       }
       else if(isFull())
       {
        cout<<"Dequeue is OverFlow";
        return;
       }
       else
       {
          rear=(rear+1)%size;
          arr[rear]=val;
       }
       cout<<arr[rear]<<"Added in the Back:"<<endl;
    }
    //SHOW FRONT ELEMENT
    int Show_front()
    {
        if(isEmpty())
            return -1;
        else
         return arr[front];
    }
    //SHOW LAST ELEMENT
    int Show_Back()
    {
        if(isEmpty())
            return -1;
        else
        return arr[rear];
    }
    // REMOVE ELEMENT FROM FRONT
    void pop_front()
    {
      if(isEmpty())
      {
        cout<<"Dequeue is Empty :"<<endl;
        return;
      }
      else
      {
        if(front==rear)
         front=rear=-1;
        else
        {
        cout<<arr[front]<<" Pooped in the front:";
        front=(front+1)%size;
        }
      }
    }
    //REMOVE ELEMENT FROM BACK
    void pop_back()
    {
     if(isEmpty())
      {
        cout<<"Dequeue is Empty :"<<endl;
        return;
      }
      else
      { 
        if(front==rear)
        front=rear=-1;
      else
      {
        cout<<arr[rear]<<" Popped in the back";
        rear=(rear-1)%size;
    }
      }
    }
};

int main()
{
   Dequeue d(5);
   d.push_front(4);
   d.push_front(5);
   d.Push_back(6);
   d.Push_back(7);
   cout<<d.Show_Back()<<" is in the back"<<endl;
   cout<<d.Show_front()<<" is in the front"<<endl;
   d.pop_front();
    cout<<d.Show_front()<<" is in the front"<<endl;
    d.pop_back();
    
   cout<<d.Show_Back()<<" is in the back"<<endl;
   
}