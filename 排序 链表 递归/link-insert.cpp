 // ��ʽ�洢�ṹ��ʵ��ֱ�Ӳ������򣨺��ݹ��㷨�Լ��ǵݹ��㷨��


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

   while(p!=0)   //  ˳����Ҳ����
   {
	   if(p->data>x->data) break;   //  �ҵ���������˳�ѭ��
	   { q=p; p=p->next;  }   
   }
  q->next=x; x->next=p;   // ��ɲ��빤��
}

void Insertsort1(linknode *Newhead,linknode *h)// �ݹ��㷨
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

void InsertSort(linknode *Newhead,linknode *h)  // �ǵݹ��㷨
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

   cout<<endl<<"����ǰ�����";
   Print(head);

   cout<<endl<<"�ǵݹ��㷨�����";

   linknode *Newhead=new linknode;
   Newhead->next=0;

   InsertSort(Newhead,head); // ���÷ǵݹ��㷨
   head=Newhead->next;  // ������ͷ���

   Print(head);

   cout<<endl<<"�ݹ��㷨�����";
   Newhead=new linknode;
   Newhead->next=0;

   Insertsort1(Newhead,head);  // ���õݹ��㷨
   head=Newhead->next;  // ������ͷ���

   Print(head);


}