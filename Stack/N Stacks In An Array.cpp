// N Stacks In An Array

#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    int *top;
    int *next;
    int s, n, freeSpot;
    NStack(int N, int S)
    {
        this->s = S;
        this->n = N;
        arr = new int[s];
        next = new int[s];
        // if(arr[i] = stores an element)
        // ---point to next (prev) element after stack top element
        // if(arr[i] = stores nothing)
        // ---point to next free space in the array 
        top = new int[n];
        // ---top represent index of top element of each stack

        // initialise top[]
        // --using memset
        // memset(top, -1, sizeof(top));

        for(int i=0;i<n;i++){
            top[i] = -1;
        }

        // initialise next[]
        for(int i=0; i<(s-1); i++){
            next[i] = i+1;
        }
        next[s-1] = -1;

        // initiailise freeSpot
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check overflow
        if(freeSpot == -1){
            return false;
        }

        // step-1 find index
        int index = freeSpot;

        // step-2 update freeSpot
        freeSpot = next[index];

        // step-3 put value to arr
        arr[index] = x;

        // step-4 update next
        next[index] = top[m-1];

        // step-5 update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check if stack is empty
        if(top[m-1] == -1){
            return -1;
        }
        // find index
        int index = top[m-1];

        // update top
        top[m-1] = next[index];

        // update next
        next[index] = freeSpot;

        // update freeSpot
        freeSpot = index;

        return arr[index];
    }
};
