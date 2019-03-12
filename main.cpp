#include <iostream>
#include<fstream>
using namespace std;
ifstream f("Date.txt");

void citire_vector(int *&A, int &n)
{
    int i;
    if(f!=NULL)
    {
      f>>n;
      A= new int[n];

      for(i=0;i<n;i++)
       f>>A[i];
    }
    else
     {cout<<"File not found"; return;}
}

void insertieDirecta(int *&A, int left, int right)
{
    int i,x,j;

    for(i=left+1;i<right;i++)
    {   x=A[i];
        j=i-1;

        while(j>=left&&x<A[j])
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }

}

void partitionare(int *&A, int left, int right, int &q)
{
    int i=left, j=right;
    q=(i+j)/2;
    while(i<j)
    {
        while(A[i]<q)
            i++;


        while(A[j]>q)
            j--;

        if(i<=j)
         {
            swap(A[i],A[j]);
            i++;
            j--;
         }

    }


}


void QS (int *&A, int left, int right)
{
    if(left==right)
        return;
    else
     if(right-left+1<11)
       insertieDirecta(A,left,right);
       else
      {
        int q;
        partitionare(A, left, right,q);

        QS(A,left,q);
        QS(A,q+1,right);

      }

}

void afisare(int *A, int n)
{
   int i;
   for(i=0;i<n;i++)
     cout<<A[i]<<" ";
   cout<<"\n";

}

int main()
{
    int n, *A;
    citire_vector(A,n);
    QS(A,0,n-1);

    afisare(A,n);
    cout<<"Final\n";
    return 0;
}
