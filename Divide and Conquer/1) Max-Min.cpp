// Divide and Conquer
// Finding the maximum and minimum element in an array

// Input : array of 'n' elements
// Output : maximum and minimum element in the array

// We will use 'Recursion'

// arr[low..high] being considered

vector<int> max_min(vector<int> arr ,int low, int high)
{
    // Get the size of the array
    int n = high - low + 1;
    
    // result[0] = max
    // result[1] = min
    vector<int> result;

    // Smallest sub-problem defines the base-case / termination case [O(1)]
    if((n == 1) || (n == 2))
    {
        // Only one element in the array
        if(n == 1)
        {
            result.append(arr[0]);
            result.append(arr[1]);
        }
        else
        {
            result.append(max(arr[0],arr[1]));
            result.append(min(arr[0],arr[1]));
        }
    }
    else
    {
        // More than 2 elements

        // Divide [O(1)]
        int mid = (low + high) / 2;

        // Conquer [2T(n/2)]
        vector<int> leftMax_Min,rightMax_Min;

        leftMax_Min = max_min(arr,p,mid);
        rightMax_Min = max_min(arr,mid + 1,q);

        // Combine [O(1)]

        result.append(max(leftMax_Min[0],rightMax_Min[0]));
        result.append(min(leftMax_Min[1],rightMax_Min[1]));

    }

    return result;
}

// Time Complexity = T(n)
// T(n) = 2T(n/2) + O(1)
// T(n) = O(n) for every case

// Space Complexity = O(logn) for stack + O(n) for input 
