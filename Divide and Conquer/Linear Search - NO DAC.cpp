// Linear Search
// Not based on Divide and Conquer approach, but necessary to understand binary search 

// Input : integer 'k' to be found in array , array of n elements
// Output : position of 'k' in array

// We will use 'Recursion'

// Recurrence relation 
// find(arr,k,low,high) = low  if low==high and arr[low]==k
//                      = find(arr,k,low+1,high)  if low!=high
//                      = -1 otherwise                    

vector<int> find(vector<int> arr, int k, int low, int high)
{
    // Index of 'k' in arr
    int result;

    // Smallest sub-problem defines the base-case / termination case [O(1)]
    if(low == high)
    {
        if(arr[low] == k)
        {
            result = low;
        }
        else
        {
            result = -1;
        }
    }
    else
    {
        // More than 2 elements 

        low = low + 1;
        
        result = find(arr, k, low + 1, high);

    }

    return result;
}

// Time Complexity = T(n)
// T(n) = T(n-1) + O(1)
// T(n) = O(n) for worst case , O(1) for best case, O(n) for average case

// Space Complexity = O(n) for stack + O(n) for input 
