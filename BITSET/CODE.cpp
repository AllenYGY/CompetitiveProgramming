#include <iostream>
#include <bitset>

using namespace std;

int main() {
    const int n = 8; // Number of bits
    bitset<n> b1;              // Create bitset with all bits set to 0 (default)
    bitset<n> b2(170);         // Create bitset with value initialized to 170 (binary: 10101010)

    cout << "Initial bitset b1: " << b1 << endl;
    cout << "Initial bitset b2 (170): " << b2 << endl;

    // 1. count() - Count the number of bits set to 1
    cout << "b2 has " << b2.count() << " bits set to 1." << endl;

    // 2. size() - Return the size (number of bits)
    cout << "b2 size: " << b2.size() << " bits." << endl;

    // 3. set() - Set all bits to 1
    b1.set();
    cout << "b1 after set(): " << b1 << endl;

    // 4. set(pos) - Set a specific bit at position pos to 1
    b1.set(2); // Set bit at position 2 to 1
    cout << "b1 after set(2): " << b1 << endl;

    // 5. reset() - Set all bits to 0
    b1.reset();
    cout << "b1 after reset(): " << b1 << endl;

    // 6. reset(pos) - Set a specific bit at position pos to 0
    b2.reset(1); // Reset bit at position 1 (second bit from the right)
    cout << "b2 after reset(1): " << b2 << endl;

    // 7. flip() - Flip all bits (0 becomes 1, 1 becomes 0)
    b2.flip();
    cout << "b2 after flip(): " << b2 << endl;

    // 8. flip(pos) - Flip a specific bit at position pos
    b2.flip(0); // Flip the first bit
    cout << "b2 after flip(0): " << b2 << endl;

    return 0;
}