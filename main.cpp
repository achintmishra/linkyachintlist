#include <iostream>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
class node
{
  public:
  int data;
  node *next ;
  node(int data)
  {
    this->data=data;
    next = NULL;
  }
};
node *takeinput()
{
  int data;
  cin>>data;
  node *head=NULL;
  node *tail=NULL;
  while(data!=-1)
  {
    node *newnode = new node(data);
    if(head==NULL)
    {
      head=newnode;
      tail=newnode;
    }
    else
    {
      tail->next = newnode;
      tail = tail->next;
    }
    cin>>data;
  }
  return head;
}
void print(node *head)
{
  while(head!=NULL)
  {
    cout<<head->data<<" ";
    head= head->next;
  }
}
node* insert(node* head,int i,int data)
{
  node*temp=head;
  node *newnode= new node(data);
  int count=0;
  while(count<i-1 && temp!=NULL)
  {
    temp=temp->next;
    count++;
  }
  if(temp!=NULL)
  {
    node*a =temp->next;
    temp->next=newnode;
    newnode->next= a;
  }
  return head;
}
bool find(node* head,int x)
{
  while(head!=NULL)
  {
    if(head->data==x)
    {
      return true ;
    }
    head=head->next;
  }
  return false;
}
node*appendnode(node*head,int n,int i)
{
  node*temp1=head;
  node*temp2=head;
  node*temp3=head;
  int count =0; 
  while(count<n-i-1)
  {
    temp1=temp1->next;
    temp2=temp2->next;
    count++;
  }
  if (head!=NULL &&temp1!=NULL &&temp2!=NULL)
  {
    temp2=temp2->next;
    temp1->next=NULL;
    head=temp2;
  }
  count=0;
  while(count<i-1)
  {
    temp2=temp2->next;
    count++;
  }
  temp2->next=temp3;
  return head;
}
node*reverse(node*head)
{
  node*curr=head;
  node*prev=NULL;
  node*nexter=NULL;
  while(curr!=NULL)
  {
    nexter=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nexter;
  }
  return prev;
}
bool isPalindrome(node* head) {
  stack<int> s;
  node* slow = head;
  while(slow!=NULL)
  {
    s.push(slow->data);
    slow=slow->next;
  }
  while(head!=NULL)
  {
    int i=s.top();
    s.pop();
    if(head->data!=i)
    {
      return false;
    }
    head=head->next;
  }
  return true;
}
node*midpoint(node*head)
{
  node*slow=head;
  node*fast=head;
  while(fast!=NULL&&fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
}
node*merge(node*head1,node*head2)
{
  if(head1==NULL)
  {
    return head2;
  }
  if(head2==NULL)
  {
    return head1;
  }
  node*head=NULL;
  node*tail=NULL;
  if(head1->data<head2->data)
  {
    head=head1;
    tail=head1;
    head1=head1->next;
  }
  else
  {
    head=head2;
    tail=head2;
    head2=head2->next;
  }
  while(head1!=NULL && head2!=NULL)
  {
    if(head1->data<head2->data)
    {
      tail->next=head1;
      tail=head1;
      head1=head1->next;
    }
    else
    {
      tail->next=head2;
      tail=head2;
      head2=head2->next;
    }
  }
  if(head1!=NULL)
  {
    tail->next=head1;
  }
  if(head2!=NULL)
  {
    tail->next=head2;
  }
  return head;
}
node *evenafterodd(node *head)
{
  if(head==NULL)
  {
    return head;
  }
    node *evenhead=NULL;
    node *eventail=NULL;
    node *oddhead=NULL;
    node *oddtail=NULL;
  while(head!=NULL)
  {
    if(head->data%2==0)
    {
      if(evenhead==NULL)
      {
        evenhead=head;
        eventail=head;
      }
      else
      {
        eventail->next=head;
        eventail=eventail->next;
      }
    }
    else
    {
      if(oddhead==NULL)
      {
        oddhead=head;
        oddtail=head;
      }
      else
      {
        oddtail->next=head;
        oddtail=oddtail->next;
      }
    }
    head=head->next;
  }
  if(oddhead==NULL)
  {
    return evenhead;
  }
  else
  {
    oddtail->next=evenhead;
  }
  if(evenhead!=NULL)
  {
    eventail->next=NULL;
  }
  return oddhead;
}
node*deleteNnodes(node*head,int m,int n)
{
  if(head==NULL||m==0)
  {
    return NULL;
  }
  node* temp1=head;
  node*temp2=NULL;
  int count;
  while(temp1!=NULL)
  {
    for(count=1;count<m && temp1!=NULL;count++)
    {
      temp1=temp1->next;
    }
    if(temp1==NULL)
    {
      return head;
    }
    temp2=temp1->next;
    for(count=0;count<n &&temp2!=NULL;count++)
    {
      node*t=temp2;
      temp2=temp2->next;
      delete(t);
    }
    temp1->next=temp2;
    temp1=temp2;
  }
  return head;
}
node *kreverse(node*head,int k)
{
  if(k==0||k==1)
  {
    return head;
  }
  node*current=head;
  node*prev=NULL;
  node*nexter=NULL;
  int count=0;
  while(count<k && current!=NULL)
  {
    nexter=current->next;
    current->next=prev;
    prev=current;
    current=nexter;
    count++;
  }
  if(nexter!=NULL)
  {
    head->next=kreverse(nexter,k);
  }
  return prev;
}
node*deleteDuplicates(node* head) {
    if(head==NULL)
    {
        return NULL;
    }
    node*temp=head;
    node*temp2=head->next;
    while(temp2!=NULL)
    {
        if(temp->data==temp2->data)
        {
            temp2=temp2->next;
        }
        else
        {
            temp->next=temp2;
            temp=temp2;
        }
    }
    temp->next=NULL;
    return head;
}
int size(node*head)
{
  int count=0;
  while(head!=NULL)
  {
    head=head->next;
    count++;
  }
  return count;
}
node *removeNthFromEnd(node* head, int n) {
    node*temp2=head;
    int count=size(head);
    if(n>=count)
    {
        return head->next;
    }
    int deletion=(count-n);
    int i=1;
    while(i<deletion)
    {
        temp2=temp2->next;
        i++;
    }
    temp2->next=temp2->next->next;
    return head;
}

int main()
{
  node* head=takeinput();
  print(head);
  cout<<endl;
  head=removeNthFromEnd(head,2);
  print(head);
}
