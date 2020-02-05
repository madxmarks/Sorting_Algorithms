#include "Algs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <windows.h>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <stdexcept>

using namespace std;

void printArray(int* A, int siz)
{
    for (int i=0; i < siz; i++)
        cout << A[i] << " ";
        cout << "\n";
}

void creArray(int* arr, int siz)
{
    LARGE_INTEGER seed;
    QueryPerformanceCounter(&seed);
    std::mt19937 gen(seed.QuadPart);

    std::uniform_int_distribution<> dis(-2*siz, 2*siz);

    for (int i=0; i < siz; i++)
        arr[i]=dis(gen);
}

void equaly (int *arr, int *arr2, int n)
{
    int eq = 0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]!=arr2[i])
            eq++;
    }
        if (eq != 0)
        {
            throw logic_error (" OOOOPS they are not!! ");
        }

}

//-----------------------------------------------------------------------

void merg ( int *arr, int *Le, int *Rt, int l, int m, int r)
{

    int i,j,k=l;
    int n1=m-l+1;
    int n2=r-m;

    for (i=0; i<n1; i++)
    {
        Le[i]=arr[i+l];
    }
  //  printArray(Le,n1);
    for (j=0; j<n2; j++)
    {
        Rt[j]=arr[m+1+j];
    }
 //   printArray(Rt,n2);
    i=0; j=0;
    while (i<n1 && j<n2)
    {
        if(Le[i]<=Rt[j])
        {
            arr[k]=Le[i];
            i++;
        }
         else
        {
            arr[k]=Rt[j];
            j++;
        }
        k++;
    }

    while (i<n1)
    {
        arr[k]=Le[i];
        i++;
        k++;
    }
     while (j<n2)
    {
        arr[k]=Rt[j];
        j++;
        k++;
    }

// cout << "Printing new-old arr " << r << " \n";
//    printArray(arr,r);

}

void mergeSort (int *arr, int *Le, int *Rt, int l, int r)
{
    if (l<r)
    {
    int m=l+(r-l)/2;
 //   cout << "Dividing from L to M " << l << " " << m << " " << r << " \n";
    if (l<m)
    mergeSort(arr, Le, Rt, l, m);
  //  cout << "Dividing  From M to R " << r << " \n";
    if (m+1<r)
    mergeSort(arr, Le, Rt ,m+1, r);
 //   cout << "merging  " << arr[r] << " \n";
    merg(arr, Le, Rt, l,m,r);
    }
    else
        return;

}

void meSort (int *arr, int r)
{
int l = 0;
int m=l+(r-1-l)/2;
int *Le= new int[m-l+1];
int *Rt = new int [r-1-m];
mergeSort(arr, Le, Rt, l, r-1);
   delete [] Le;
   delete [] Rt;
}



//---------------------------------------------------



void swape(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort (int *arr, int a, int b)
{
    int pivot = a;
    int left= a+1;
    int right= b;
 //   cout << arr[pivot]<< endl;
//  printarr (arr, b+1);
 //   cout << endl << endl;
    while (left <= right)
    {
    //    cout <<  " start 1 loop ";
        while (left <= right && arr[left]<=arr[pivot])
        {
     //       cout <<  "\n start 2 loop " << arr[left];
            left++;
        }
        while (left <= right && arr[right]>arr[pivot])
        {
       //     cout <<  "\n start 3 loop " << arr[right] <<endl;
            right--;
        }
        if (left <=  right && arr[left]>arr[right])
        {
      //      cout <<  "\n swape 1 " << arr[left] << " and " << arr[right] << endl;
            swape (&arr[left], &arr[right]);
            left++; right --;
 //            cout <<  "\n Result of swape 1 is " ; printarr (arr, b+1); cout << endl;
        }
    }
    if (left-1<=b && left-1!=pivot)
    {

 //       cout <<  "\n swape 2 " << arr[pivot] << " and " << arr[left-1] << endl;
        swape (&arr[pivot], &arr[left-1]);
//        cout << endl << endl;
//        printarr (arr, b+1);
    }
    if (right > a )
    {
        quicksort(arr, a, right-1);
    }
    if (left <  b)
        quicksort(arr, left, b);
}


//------------------------------------------------




void sink (int *arr, int i, int n)
{
    // A question here...
    //if we first check (arr[i*2+1]<arr[i*2+2]) && (arr[i*2+2]>arr[i]) and then i*2+2 < n program crashes on some changes of size, why?
            if (i*2+2 < n &&(arr[i*2+1]<arr[i*2+2]) && (arr[i*2+2]>arr[i]) )
            {
             swape(&arr[i*2+2], &arr[i]);
                // cout << " sink +2 ";
             sink(arr, i*2+2, n);
            }
            else {
             if (i*2+1 < n && (arr[i*2+1]>arr[i]) )
             {
                    swape(&arr[i*2+1], &arr[i]);
                   //  cout << " sink +1 ";
                        sink(arr, i*2+1, n);
             }
            }

}

void HeSort(int *arr, int n)
{

    for (int i=(n/2)-1; i>=0; i--)
    {
          sink(arr, i, n);
/*
        if (arr[i]<arr[(i*2)+1] && (i*2)+1<n)
        {
            sink(arr, (i*2)+1, n);
        }
        if (arr[i]<arr[(i*2)+2] && (i*2)+2<n)
        {
            sink(arr, (i*2)+2, n);
        }
*/
    }
}


void Heaping (int *arr, int n)
{
   HeSort(arr, n);
//    printArray(arr,n);
//    cout << endl<< endl<< endl<< endl;

    for (int i=n-1; i>0; i--)
    {

        swape (&arr[i], &arr[0]);
        sink(arr, 0, i);
    }

}



