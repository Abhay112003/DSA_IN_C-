#include<iostream>
using namespace std;
class Employee
{
    public :
    int id;
    string name;
    Employee *next;
    Employee *prev;  
    Employee(int id,string name)
    {
      this->id=id;
      this->name=name;
      this->next=NULL;
      this->prev=NULL;
    }
}*start;
Employee *endd;
void AddEmployee()
{
    int id,c;
    string name;
    cout<<"Enter a Employee ID";
    cin>>id;
    cout<<"Enter a Employee Name";
    cin>>name;
    Employee *ptr=new Employee(id,name);
    //Enter Data in Start Middle Or End 
    cout<<"\n1.Add Employee in The Begninning";
    cout<<"\n2.Add Employee in The Middle";
    cout<<"\n3.Add Employee in The End";
    cin>>c;
     if(c==1)
     {
       ptr->next=start;
       start->prev=ptr;
       start=ptr; 
     }
    else if(c==2)
    {
       int m;
       Employee *p;
       cout<<"Enter a Employee Id before you add a new Employee :";
       cin>>m;
       for(p=start;(p);p=p->next)
       {
         if(p->id==m)
         {
            p->next->prev=ptr;
            ptr->next=p->next;
            p->next=ptr;
         }
       }
    }
    else
    {
        if(start==NULL)
        {
       start=ptr;
       endd=ptr;
       start->prev=NULL;
       start->next=NULL;
        }
        else
       {
        endd->next=ptr;
        ptr->prev=endd;
        endd=ptr;
        endd->next=NULL;
      }
    }
}
void ShowAllEmployee()
{
    Employee *ptr;
    if(start==NULL)
    cout<<"\nNo Employee Exists";
   for(ptr=start;(ptr);ptr=ptr->next)
   {
    cout<<"Employee Id is = "<<ptr->id<<endl;
    cout<<"Employee Id is = "<<ptr->name<<endl;
    cout<<endl;
   }
}
void ShowAllReverse()
{
  Employee *ptr;
  for(ptr=endd;(ptr);ptr=ptr->prev)
  {
    cout<<"Employee Id is = "<<ptr->id<<endl;
    cout<<"Employee Id is = "<<ptr->name<<endl;
    cout<<endl;
  }
}
void DeleteEmployee()
{
   int d;
   Employee *p;
   cout<<"Enter a Employee Id to Delete :";
   cin>>d;
   for(p=start;(p);p=p->next)
   {
     if(p->id==d)
     {
        if(p==start)
        {
            if(p->next==NULL)
            {
             start=NULL; 
             return;
            }
             start=start->next;
            start->prev=NULL;
        }
        else if(p->next==NULL)
        {
            endd=endd->prev;
            endd->next=NULL;
        }
        else
        {
            p->prev->next=p->next;
            p->next->prev=p->prev;
        }
        free(p);
        break;
     }
    
   }
}
int main()
{
    start=endd=NULL;
    int ch;
    do
    {
      cout<<"Add a Employee :";
      cout<<"\n2.Show All Employee Data :";
      cout<<"\n3.Show All Employee Data in reverse";
      cout<<"\n4.Delete a Employee :";
      cout<<"\n5.Exit";
      cout<<"Select Your Choice :";
      cin>>ch;
      if(ch==1)
       AddEmployee();
      else if(ch==2)
       ShowAllEmployee();
      else if(ch==3)
        ShowAllReverse();
       else if(ch==4)
       DeleteEmployee(); 
    }while(ch!=5);
} 