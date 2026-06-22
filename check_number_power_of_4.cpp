#include <iostream>
using namespace std;

int main()
{
    // Question:
    // Given an integer n, determine whether it is a power of 4.
    // Print "YES" if n is a power of 4, otherwise print "NO".

    int n;
    cin >> n;

    // A power of 4 must be:
    // 1. Positive
    // 2. A power of 2 => (n & (n - 1)) == 0
    // 3. Its only set bit must be at an even position
    //    => (n & 0x55555555) != 0
  //0x55555555 is a hexadecimal number where each represent the pair of 0101  means 1 at even place 

    if (n > 0 &&
        ((n & (n - 1)) == 0) &&
        ((n & 0x55555555) != 0))
    {
        cout << "YES";
        return 0;
    }

    cout << "NO";

    return 0;
}
