#include <iostream>
#include "Algs.h"
#include <stdlib.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <fstream>

using namespace std;


int main()
{
ofstream myfile;
LARGE_INTEGER li;
QueryPerformanceFrequency(&li);
double PCFreq = li.QuadPart/1000.0;
int64_t startt;
int64_t endd;

int times = 100;

int k=10;
//for  (size_t siz : {100,200,300,400,500, 1000,2000,3000,4000,5000, 10000,20000,30000,40000,50000,100000,200000,300000,400000,500000,1000000})
for (size_t siz = 10; siz<=10000000; )
{
//  size_t siz = 100000;
double merging =0 ;
double quick =0;
double heap =0;


    int *arr = new int [siz];
    int *b = new int [siz];
    int *c = new int [siz];


for (int k=0; k<times; k++)
    {

    creArray(arr,  siz);
  //  printArray(arr, siz);
    copy(arr, arr+siz, b);
    copy(arr, arr+siz, c);


QueryPerformanceCounter(&li);
startt = li.QuadPart;
meSort(arr, siz);
QueryPerformanceCounter(&li);
endd = li.QuadPart;
merging = endd - startt + merging;

//cout << " 1 ";
//cout << endl<< endl<< endl<< endl;

QueryPerformanceCounter(&li);
startt = li.QuadPart;
   quicksort(b, 0, siz-1);
QueryPerformanceCounter(&li);
endd = li.QuadPart;

  //cout << " 2 ";
quick = endd- startt + quick;

equaly(arr, b ,siz);
 // pivot 0
//  cout << endl<< endl<< endl<< endl;


QueryPerformanceCounter(&li);
startt = li.QuadPart;
  Heaping(c, siz);
QueryPerformanceCounter(&li);
endd = li.QuadPart;

// cout << " 3 \n";
// equaly(arr,  c, siz);
heap = endd - startt + heap;

// cout << endl<< endl<< endl<< endl;




    }
 //    myfile.open ("algorithms.txt" , ios::app );
cout  <<  setw(8) << fixed <<"For " << siz <<" elements: \n time wasted on merging (dynamic): " << merging/PCFreq/times << endl
  << " time wasted on quick : " << quick/PCFreq/times << endl << " time wasted on heap : " << heap/PCFreq/times << endl;
//  myfile.close();

        siz=siz+k;
        if(siz==k*6)
        {
        k=k*10;
        siz=1*k;
        }

// equaly(arr,  c, siz);
}



    return 0;

}
