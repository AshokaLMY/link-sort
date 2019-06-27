// Ã°ÅÝÅÅÐòµÄµÝ¹éËã·¨(Ë³Ðò´æ´¢½á¹¹)

#include<iostream>
 
using namespace std;

int R[100];




void bubblesort(int n)
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

 
  bubblesort(n);
  

   for(i=1;i<=n;i++)
      cout<<R[i]<<" ";

  cin>>n;
  
  return 1;
}
