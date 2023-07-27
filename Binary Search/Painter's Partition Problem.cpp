// Painter's Partition Problem
// Sample Input 1 :
// 2
// 4 2
// 5 5 5 5
// 4 2
// 10 20 30 40
// Sample Output 1 :
// 10
// 60

bool isSolution(vector<int> &boards, int k, int mid)
{
    int painterCount = 1;
    int blockCount = 0;
    for(int i=0;i<boards.size();i++)
    {
        if(blockCount+boards[i] <= mid)
        {
            blockCount += boards[i];
        }
        else{
            painterCount++;
            if(painterCount>k || boards[i]>mid)
            {
                return false;
            }
            blockCount = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    for(int i=0;i<boards.size();i++){
        sum += boards[i];
    }
    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e)
    {
        if(isSolution(boards,k,mid))
        {
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