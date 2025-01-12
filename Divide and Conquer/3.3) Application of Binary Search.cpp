// Divide and Conquer
// Based on 'Search'

/*********************************************************************************************************
    Input : array of 'n' distinct elements 
    Output : index i such that arr[i]==i
**********************************************************************************************************/

// We will use 'Recursion'

// arr[low..high] being considered

// Recurrence Relation
// search(arr,low,high) = mid if arr[mid] == mid where mid = (low + high) / 2; 
//                      = search(arr,low,mid-1) if arr[mid] > mid
//                      = search(arr,mid+1,high) if arr[mid] < mid

// If arr[i] > i then arr[i+1] > i+1 only if elements are 'distinct' in the array 
// Same hold for other case

vector<int> search(vector<int> arr ,int low, int high)
{
    // Index i such that arr[i] == i
    int result;

    // Smallest sub-problem defines the base-case / termination case [O(1)]
    if(low>high)
    {
        // Empty array
        result = -1;
    }
    else
    {
        // Non - empty array

        // Divide [O(1)]

        int mid = (low + high) / 2;

        // Conquer [T(n/2)]
        
        if(arr[mid] > mid)
        {
            high = mid - 1;
            result = search(arr,low,high,k);
        }
        else if(arr[mid] < mid)
        {
            low = mid + 1;
            result = search(arr,low,high,k); 
        }
        else
        {
            // Combine [O(1)]

            result = mid;
        }

    }

    return result;
}

// Time Complexity = T(n)
// T(n) = T(n/2) + O(1)
// T(n) = O(logn) for worst case, O(1) for best case

// Space Complexity = O(logn) for stack + O(n) for input 
