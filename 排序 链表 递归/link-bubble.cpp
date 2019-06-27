 // 链式存储结构下实现冒泡排序（含递归算法以及非递归算法）


#include<iostream.h>

struct node 
{
  int data;
  node *next;
};

node *Create()
{
   node *p;
   int x;

   cin>>x;
   if (x==-1) return 0;
   p=new node;
   p->data=x;
   p->next=Create();
   return p;
}

void bubble1(node *h,node *end)// 递归算法
{
    node *p,*q;
    int x;

    if (h->next==end) return ;
   
     p=h; 
     while(p->next!=end)
     {
        q=p->next;
        if (p->data>q->data)
	    {
           x=p->data; p->data=q->data; q->data=x;  
	    }
		p=p->next;
     }
     bubble1(h,p);
} 

void bubble(node *h)  // 非递归算法
{
   node *p,*q,*end;
   int x;

   end=0;   // 第一趟到最后一个结点

   while(h->next!=end)
   {
     p=h; 
     while(p->next!=end)
     {
        q=p->next;
        if (p->data>q->data)
	    {
           x=p->data; p->data=q->data; q->data=x;  
	    }
		p=p->next;
     }
     end=p;
   }
} 

void Print(node *h)
{
  if(h==0) return ;
  cout<<h->data<<"  ";
  Print(h->next);
}

void main()
{
   node *head;

   head=Create();

   Print(head);

   cout<<endl;

   //bubble(head); // 调用非递归算法

   bubble1(head,0);  // 调用递归算法

   Print(head);


}