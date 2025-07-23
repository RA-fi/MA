#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// Class for performing operations on an integer array
class ArrayOps {
    int a[100]; // Fixed-size array for storage
    int size;   // Current size of the array

public:
    ArrayOps() : size(0) {} // Initialize size to 0

    // Input method to read 'n' integers into the array
    void input() {
        cout << "Enter the number of elements (max 100): ";
        cin >> size;
        if (size > 100) {
            cout << "Size exceeds maximum limit of 100.\n";
            size = 0;
            return;
        }
        cout << "Enter the elements: ";
        for (int i = 0; i < size; ++i) cin >> a[i];
    }

    // Print the minimum and maximum values in the array
    void printMinMax() const {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }
        cout << "Min: " << *min_element(a, a + size) 
             << ", Max: " << *max_element(a, a + size) << endl;
    }

    // Print the second minimum and second maximum values in the array
    void printSecondMinMax() const {
        set<int> s(a, a + size); // Use a set to remove duplicates
        if (s.size() < 2) { // Check if there are at least two distinct elements
            cout << "Not enough elements\n";
            return;
        }
        auto it = s.begin();
        cout << "Second Min: " << *next(it) 
             << ", Second Max: " << *prev(s.end(), 2) << endl;
    }

    // Remove duplicate elements from the array
    void removeDuplicates() {
        set<int> uniqueSet(a, a + size);
        size = 0;
        for (int x : uniqueSet) a[size++] = x;
        cout << "Duplicates removed.\n";
    }

    // Print the sum and product of all elements in the array
    void printSumProduct() const {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }
        int sum = 0, product = 1;
        for (int i = 0; i < size; ++i) sum += a[i], product *= a[i];
        cout << "Sum: " << sum << ", Product: " << product << endl;
    }

    // Print the element at a specific index, or "Invalid" if out of bounds
    void printAt(int i) const {
        cout << (i >= 0 && i < size ? to_string(a[i]) : "Invalid index") << endl;
    }

    // Print all elements in the array
    void printAll() const {
        if (size == 0) {
            cout << "Array is empty\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i) cout << a[i] << " ";
        cout << endl;
    }

    // Static method to merge two ArrayOps objects into a new one
    static ArrayOps merge(const ArrayOps &x, const ArrayOps &y) {
        ArrayOps z;
        z.size = x.size + y.size;
        if (z.size > 100) {
            cout << "Merged array exceeds maximum size of 100.\n";
            z.size = 0;
            return z;
        }
        for (int i = 0; i < x.size; ++i) z.a[i] = x.a[i];
        for (int i = 0; i < y.size; ++i) z.a[x.size + i] = y.a[i];
        return z;
    }
};

int main() {
    ArrayOps a1, a2; // Create two ArrayOps objects
    int idx;

    cout << "Input for first array:\n";
    a1.input(); // Input elements into the first array

    a1.printMinMax(); // Print min and max
    a1.printSecondMinMax(); // Print second min and max
    a1.removeDuplicates(); // Remove duplicates
    a1.printAll(); // Print all elements
    a1.printSumProduct(); // Print sum and product

    cout << "Enter index to print element: ";
    cin >> idx; // Input index
    a1.printAt(idx); // Print element at the index

    cout << "Input for second array:\n";
    a2.input(); // Input elements into the second array

    cout << "Merged array:\n";
    ArrayOps::merge(a1, a2).printAll(); // Merge the two arrays and print the result

    return 0;
}
