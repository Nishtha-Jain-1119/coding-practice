// 3Sum
// Sample Input 1:
// 1
// 5
// 10 5 5 5 2
// 12
// Sample Output 1:
// 5 5 2

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	for(int i = 0;i<n;i++)
	{
		int target = K - arr[i];
		int front = i+1;
		int end = n-1;
		while(front<end)
		{
			if(arr[front]+arr[end] > target)
				end--;
			else if(arr[front]+arr[end] < target)
				front++;
			else
			{
				int x = arr[front];
				int y = arr[end];
				ans.push_back({arr[i],x,y});
				while(front<end && arr[front]==x) //skipping the same no.
					front++;
				while(front<end && arr[end]==y)
					end--;
			}
		}
		while(i+1<n && arr[i]==arr[i+1]) // skipping the same no. ---> removing the duplicacy.
			i++;
	}
	return ans;
}