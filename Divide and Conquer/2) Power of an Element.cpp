// Divide and Conquer
// Power of an element

// Input : 2 integers x and y
// Output : x^y

// We will use 'Recursion'

// Recurrence relation 
// pow(x,y) =  1                                       if y == 0
//          = (x^(y/2))^2       = (pow(x,y/2))^2       if y is even
//          = (x^(y-1/2))^2 * x = (pow(x,y/2))^2 * x   if y is odd

vector<int> power(int x ,int y)
{
    // Store x^y
    int result;

    // Smallest sub-problem defines the base-case / termination case [O(1)]
    if((y == 0) || (y == 1))
    {
        if(y == 0)
        {
            // x^0
            result =1;
        }
        else
        {
            // x^1
            result = x;
        }
    }
    else
    {
        // Power more than 2 

        // Divide [O(1)]
        
        y = y / 2;

        // Conquer [T(n/2)]
        
        int temp = pow(x,y/2);
        temp = temp * temp;

        // Combine [O(1)]

        if(y % 2 == 0)
        {
            // y is even

            result = temp;
        }
        else
        {
            // y is odd

            result = temp * x;
        }

    }

    return result;
}

// Time Complexity = T(n)
// T(n) = T(n/2) + O(1)
// T(n) = O(logn) for every case

// Space Complexity = O(logn) for stack + O(1) for input 
