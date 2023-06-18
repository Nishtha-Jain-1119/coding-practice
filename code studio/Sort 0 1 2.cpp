// Sort 0 1 2
// Sample Input 1 :
// 2
// 6
// 0 1 2 2 1 0
// 7
// 0 1 2 1 2 1 2
// Sample Output 1 :
// 0 0 1 1 2 2
// 0 1 1 1 2 2 2

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int count0 = 0;
   int count1 = 0;
   int count2 = 0;
   for(int i=0;i<n;i++)
   {
      if(arr[i] == 0)
         count0++;
      else if (arr[i] == 1)
         count1++;
      else
         count2++;
   }
   int j = 0;
   for(int i=0;i<count0;i++)
   {
      arr[j] = 0;
      j++;
   }
   for(int i=0;i<count1;i++)
   {
      arr[j] = 1;
      j++;
   }
   for(int i=0;i<count2;i++)
   {
      arr[j] = 2;
      j++;
   }
}