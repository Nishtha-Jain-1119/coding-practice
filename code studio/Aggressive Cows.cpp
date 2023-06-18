// Aggressive CowsSample Input 1 :
// 6 4
// 0 3 4 7 10 9
// Sample Output 1 :
// 3
// Explanation To Sample Input 1 :
// The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.

bool isSolution(vector<int> &stalls, int k, int mid){
    int cowCnt = 1;
	int lasPos = stalls[0];
	for(int i=0;i<stalls.size();i++)
	{
		if(stalls[i] - lasPos>= mid){
			cowCnt++;
			lasPos = stalls[i];
			if(cowCnt == k){
				return true;
			}
		}
	}
	return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
	sort(stalls.begin(), stalls.end());
    int s = 0;
	int e = *max_element(stalls.begin(),stalls.end());
	int mid = s + (e-s)/2;
	int ans = -1;
	while(s<=e){
		if(isSolution(stalls, k,mid)){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
		mid = s + (e-s)/2;
	}
	return ans;
}