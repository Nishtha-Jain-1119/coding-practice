// Allocate Books
// Sample Input 1:
// 1
// 3 5
// 1 2 2 3 1
// Sample Output 1:
// 4
// Explanation Of Sample Input 1:
// The ayush will read the chapter as follows,
// Day 1 : 1 , 2         Time required : 3
// Day 2 : 3             Time required : 2
// Day 3 : 4 , 5         Time required : 4
// So the maximum time in a day is 4.

#include <bits/stdc++.h> 
bool isSolution(int n, int m, vector<int> time, long long mid)
{
	int dayCount = 1;
	long long totalTime = 0;
	for(int i=0;i<m;i++){
		if(totalTime + time[i] <= mid){
			totalTime += time[i];
		}
		else{
			dayCount++;
			if(dayCount>n || mid<time[i]){
				return false;
			}
			totalTime = time[i];
		}
	}
	return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long s = 0;
	long long sum = 0;
	for(int i=0;i<m;i++)
	{
		sum += time[i];
	}
	long long e = sum;
	long long mid = s + (e-s)/2;
	long long ans = -1;
	while(s<=e){
		if(isSolution(n,m,time,mid)){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
		mid = s + (e-s)/2;
	}
	return ans;
}