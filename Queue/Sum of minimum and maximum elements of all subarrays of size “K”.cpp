#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
	long long sum = 0;
	deque<int> mini;
	deque<int> maxi;
	int i = 0;
	while(i<n){
		// window checking conditions
		if(!maxi.empty() && maxi.front() == i-k){
			maxi.pop_front();
		}
		if(!mini.empty() && mini.front() == i-k){
			mini.pop_front();
		}
		// keeping the only useful elements
		while(!maxi.empty() && nums[maxi.back()]<nums[i]){
			maxi.pop_back();
		}
		while(!mini.empty() && nums[mini.back()]>nums[i]){
			mini.pop_back();
		}
		
		maxi.push_back(i);
		mini.push_back(i);
		// window check
		if(i >= k-1){
			sum += nums[maxi.front()] + nums[mini.front()];
		}
		i++;
	}
	return sum;
}
