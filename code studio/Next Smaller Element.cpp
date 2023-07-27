// Next Smaller Element
// Sample Input 1:
// 2
// 4
// 2 1 4 3
// 3
// 1 3 2
// Sample Output 1:
// 1 -1 3 -1
// -1 2 -1

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    int curr;
    for(int i=n-1; i>=0; i--){
        curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        // ans is top of stack
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}
