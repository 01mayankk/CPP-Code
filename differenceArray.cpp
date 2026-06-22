#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    // Input size of array
    int n;
    cout << "\nEnter Number of Elements: ";
    cin >> n;

    // Original array
    vector<int> arr(n);

    // Take array input
    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter Element at Index " << i << ": ";
        cin >> arr[i];
    }

    int left, right, value;

    // Range [left, right] to be updated
    cout << "\nEnter Left Index: ";
    cin >> left;

    cout << "\nEnter Right Index: ";
    cin >> right;

    // Value to add to every element in the range
    cout << "\nEnter Value to Add: ";
    cin >> value;

    /*
        Difference Array

        Instead of updating every element from left to right,
        we only mark where the update starts and where it ends.

        Example:
        arr = [1, 2, 3, 4, 5]

        Add 10 to range [1, 3]

        Instead of:
        arr[1] += 10
        arr[2] += 10
        arr[3] += 10

        We do:
        diff[1] += 10
        diff[4] -= 10

        After taking prefix sum:
        [0, 10, 10, 10, 0]

        This tells us exactly how much to add at each index.
    */
    vector<int> diff(n, 0);

    // Mark the start of the update range
    diff[left] += value;

    /*
        Mark the position after the range ends.

        This "cancels" the effect of value
        beyond the right boundary.

        Example:
        left = 1, right = 3, value = 10

        diff:
        [0, 10, 0, 0, -10]

        The +10 starts at index 1
        The -10 stops the effect after index 3
    */
    if(right + 1 < n)
    {
        diff[right + 1] -= value;
    }

    /*
        Convert Difference Array into Actual Updates
        using Prefix Sum.

        Example:
        diff = [0, 10, 0, 0, -10]

        Prefix Sum:

        [0,
         0+10 = 10,
         10+0 = 10,
         10+0 = 10,
         10-10 = 0]

        Result:
        [0, 10, 10, 10, 0]

        Now each index contains the amount
        that should be added to arr[i].
    */
    for(int i = 1; i < n; i++)
    {
        diff[i] += diff[i - 1];
    }

    /*
        Apply the computed updates
        to the original array.
    */
    for(int i = 0; i < n; i++)
    {
        arr[i] += diff[i];
    }

    cout << "\nModified Array: ";

    for(int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}
