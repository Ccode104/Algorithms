// Divide and Conquer
// Binary Search

// Input : array of 'n' elements , integer 'k' to be found
// Output : index of 'k'

// We will use 'Recursion'

// arr[low..high] being considered

// Recurrence Relation
// binary_search(arr,low,high,k) = mid if arr[mid] == k where mid = (low + high) / 2
//                               = -1  otherwise

vector<int> binary_search(vector<int> arr ,int low, int high, int k)
{
    // Index of 'k'
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
        
        if(arr[mid] < k)
        {
            high = mid - 1;
            result = binary_search(arr,low,high,k);
        }
        else if(arr[mid] > k)
        {
            low = mid + 1;
            result = binary_search(arr,low,high,k); 
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
