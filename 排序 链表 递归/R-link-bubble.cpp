// Ã°ÅİÅÅĞòµÄµİ¹éËã·¨(Á´Ê½´æ´¢½á¹¹)

#include<iostream.h>

struct link
{
   int data;
   link *next;
};

link *create()
{
   link *h=0,*p;
   int x;

   cin>>x;
   while(x!=-1)
   {
      p=new link;
	  p->data=x;
	  p->next=h;
	  h=p;
      cin>>x;
   }
  return h;
}

void print(link *h)
{
   while(h!=0)   
   {  cout<<h->data<<"  "; h=h->next;   }
   cout<<endl;

}

void bubble_pass(link *head,link *&tail)
{
  link *q; 
  int x;

  if(head->next==tail){tail=head;return;}
  q=head->next; 
  if(head->data>q->data)
  {
     x=head->data; 
     head->data=q->data;
     q->data=x;
  }
  bubble_pass(head->next,tail);
  return ; 
}


void bubble(link *head,link *&tail)
{

   if ( head->next==tail )  return ;
   
   bubble_pass(head,tail);
 
   bubble(head,tail);

}




main()
{
   link *head,*tail=0;

   head=create();

   print(head);

 
   bubble(head,tail);
   
   print(head);


}