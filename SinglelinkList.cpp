#include<iostream>
using namespace std;
class Student
{
 public :
 int data;
 Student *next;

 //Construtor  
  Student(int data){
  this->data=data;
  this->next=NULL;
  }
}*start;

class StudentList
{  
  public:
 //Add Student data
  void addStudent()
  {
   int data,ch;
   cout<<"Enter a Student Data :";
   cin>>data;
   Student *ptr=new Student(data);
   //Add in the pereferences
   cout<<"\n1.Add a Student in the Beginning ";
   cout<<"\n2.Add a Student in the Middle :";
   cout<<"\n3.Add a Student in the End";
   cout<<"Select your choice :";
   cin>>ch;
   if(ch==1)
   {
      ptr->next=start;
      start=ptr;
   }
   else if(ch==2)
   {
    int m;
    Student *s,*prev;
    cout<<"\nEnter a Data before you add a new Data :";
    cin>>m;
    for(s=start;(s);s=s->next)
    {
       if(s->data==m)
       {
        ptr->next=s->next;
        s->next=ptr;
       }
       prev=s;      
    }
   }
   else
   {
   if(start==NULL)
    start=ptr;
   else
   {
     Student *p,*prev;
     for(p=start;(p);p=p->next)
      prev=p;
     prev->next=ptr;
     ptr->next=NULL;
   } 
  } 
  }
  void showAllStudent()
  {
     Student *ptr=start;
     while(ptr!=NULL)
     {
      cout<<ptr->data<<endl;
      ptr=ptr->next;
     }
  }
  void deleteStudent()
  {
    Student *ptr,*prev;
    int d;
    cout<<"Enter a student data to delete :";
    cin>>d;
    for(ptr=start;(ptr);ptr=ptr->next)
    {
      if(ptr->data==d)
      {
        if(ptr==start)
         start=start->next;
        else if(ptr->next==NULL)
        prev->next=NULL;
        else
        prev->next=ptr->next;
        free(ptr);
        break;
      }
    prev=ptr;
    }
  }
};
int main()
{
  start=NULL;
  StudentList list;
  int ch;
  do
  {
   cout<<"\n1.Add a New Student :";
   cout<<"\n2.Show All Student :";
   cout<<"\n3.Delete a Student :";
   cout<<"\n4.Exit :";
   cin>>ch;
   if(ch==1)
  list.addStudent();
  else if(ch==2)
   list.showAllStudent();
  else
  list.deleteStudent();
  }while(ch!=4);
}
