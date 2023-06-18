// Pair Sum
// Sample Input 1:
// 5 5
// 1 2 3 4 5
// Sample Output 1:
// 1 4
// 2 3

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
   sort(arr.begin(), arr.end());
   for(int i=0;i<arr.size();i++)
   {
      int j = i+1;
      while(j<arr.size())
      {
         if(arr[i]+arr[j] > s){
            break;
         }
         else if(arr[i]+arr[j] == s){
            ans.push_back({arr[i], arr[j]});
            j++;
         }
         else{
            j++;
         }
      }

   }
   return ans;
}