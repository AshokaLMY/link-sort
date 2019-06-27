 // 链式存储结构下实现直接插入排序（含递归算法以及非递归算法）


#include<iostream>

using namespace std;

struct linknode 
{
  int data;
  linknode *next;
};

linknode *Create()
{
   linknode *p;
   int x;

   cin>>x;
   if (x==-1) return 0;
   p=new linknode;
   p->data=x;
   p->next=Create();
   return p;
}


void InsertByOrder(linknode *Nh,linknode *x)
{
   linknode *q,*p;
   
   q=Nh;
   p=Nh->next;

   while(p!=0)   //  顺序查找插入点
   {
	   if(p->data>x->data) break;   //  找到插入点则退出循环
	   { q=p; p=p->next;  }   
   }
  q->next=x; x->next=p;   // 完成插入工作
}

void Insertsort1(linknode *Newhead,linknode *h)// 递归算法
{
    linknode *pp;

	 if(h==0) return ;
	 else
	 {
		 pp=h;  h=h->next;
		 InsertByOrder(Newhead,pp);
         Insertsort1(Newhead,h);
	 }
} 

void InsertSort(linknode *Newhead,linknode *h)  // 非递归算法
{
   linknode *pp;

   while(h!=0)
   {
     pp=h;  h=h->next;
     InsertByOrder(Newhead,pp);
   }
} 

void Print(linknode *h)
{
  if(h==0) return ;
  cout<<h->data<<"  ";
  Print(h->next);
}

void main()
{
   linknode *head;

   head=Create();

   cout<<endl<<"排序前结果：";
   Print(head);

   cout<<endl<<"非递归算法结果：";

   linknode *Newhead=new linknode;
   Newhead->next=0;

   InsertSort(Newhead,head); // 调用非递归算法
   head=Newhead->next;  // 跳过表头结点

   Print(head);

   cout<<endl<<"递归算法结果：";
   Newhead=new linknode;
   Newhead->next=0;

   Insertsort1(Newhead,head);  // 调用递归算法
   head=Newhead->next;  // 跳过表头结点

   Print(head);


}