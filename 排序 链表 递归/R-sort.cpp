//˳��洢�ṹ��ʵ��ֱ��ѡ������ֱ�Ӳ�������ð������ĵݹ��㷨

#include<iostream>
 
using namespace std;

int R[100];



void selectsort(int n)// ��β��ͷ����ֱ��ѡ������ĵݹ��㷨
{
  int i,max;

  if (n==1) return ;
  else 
  { 
     max=n;
	 for(i=n-1;i>0;i--)
	   if(R[max]<R[i])
	       max=i;
	 R[0]=R[max]; R[max]=R[n]; R[n]=R[0];
	 selectsort(n-1);
	 return ;
  }    


}


void selectsort1(int i,int n)// ��ͷ��βΪ����ֱ��ѡ������ĵݹ��㷨
{
  int j,min;

  if (i==n) return ;
  else 
  { 
     min=i;
	 for(j=i+1;j<=n;j++)
	   if(R[min]>R[j])
	       min=j;
	 R[0]=R[min]; R[min]=R[i]; R[i]=R[0];
	 selectsort1(i+1,n);
	 return ;
  }    


}


void insertsort(int i, int n) // ��β��ͷ����ֱ�Ӳ�������ĵݹ��㷨
{
  int j;

  if(i==0) return ;
  else 
  {  R[0]=R[i];
     for(j=i+1;j<=n;j++)
	   if(R[j]<R[0])
	       R[j-1]=R[j];
	   else break;
	 R[j-1]=R[0];
	 insertsort(i-1,n);
     return;
  }
}



void bubblesort(int n)// ��β��ͷ����ð������ĵݹ��㷨
{
   int swapped,i;

   if(n==1) return ;
   else 
   {
      swapped=0;
	  for(i=1;i<n;i++)
	    if (R[i]>R[i+1])
		 { swapped=1;
		    R[0]=R[i]; R[i]=R[i+1]; R[i+1]=R[0]; 
		 }
		 if (swapped=0) return ;
		 else bubblesort(n-1);
         return ;
	}
}


int main( )
{
   int i,n;
   cin>>n;
   
   for(i=1;i<=n;i++)
      cin>>R[i];

   // insertsort(n-1,n);  	   
  
   //bubblesort(n);  
  
   // selectsort(n);

   selectsort1(1,n);
  
   for(i=1;i<=n;i++)
      cout<<R[i]<<" ";

  cin>>n;
  
  return 1;
}
