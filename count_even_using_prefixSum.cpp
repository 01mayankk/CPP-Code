#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Question:
    // Given an array and a range [left, right],
    // find the count of even numbers in that range
    // using Prefix Sum.

    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input array elements
    for(int i = 0; i < n; i++)
    {
        cout << "Enter Element at Index " << i << ": ";
        cin >> arr[i];
    }

    // Prefix array:
    // prefix[i] stores the count of even numbers
    // from index 0 to index i.
    vector<int> prefix(n);

    // If arr[0] is even, store 1 otherwise 0
    prefix[0] = (arr[0] % 2 == 0);

    // Build Prefix Sum Array
    for(int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + (arr[i] % 2 == 0);
    }

    int left, right;

    // Input query range
    cout << "Enter Left Index: ";
    cin >> left;

    cout << "Enter Right Index: ";
    cin >> right;

    int evenCount;

    // If range starts from index 0,
    // answer is directly available in prefix[right]
    if(left == 0)
        evenCount = prefix[right];

    // Otherwise,
    // Count in [left, right]
    // = prefix[right] - prefix[left - 1]
    else
        evenCount = prefix[right] - prefix[left - 1];

    cout << "\nEven numbers in range = " << evenCount;

    return 0;
}
