#include <string>
#include <vector>
using namespace std;
// Written by Anna Portugal
class heapSort {
    void swap(string& a, string& b);
    void makeHeap(vector<string>& data, int size, int index);
    void sort(vector<string>& data);
};

// Helper function to swap two values
void heapSort::swap(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

// Function to re-heapify after a swap is made
void heapSort::makeHeap(vector<string>& data, int size, int index) {

    // First find indexes of parent, right child, and left child
    int parent = index;
    int right = (index * 2) + 2;
    int left = (index * 2) + 1;

    // Is the right child index within the bounds of the heap size
    if (right < size) {
        // Is right child data later in the alphabet than parent data
        if (data.at(right) > data.at(parent)) {
            // If so, reassign parent index to that of right child
            parent = right;
        }
    }
    // Is the left child index within the bounds of the heap size
    if (left < size) {
        // Is left child data later in the alphabet than parent data
        if (data.at(left) > data.at(parent)) {
            // If so, reassign parent index to that of left child
            parent = left;
        }
    }
    if (parent != index) {
        // Parent with greater value will be swapped
        // Complies with properties of a max heap
        swap(data.at(index), data.at(parent));
        makeHeap(data, size, parent);
    }
}

// Sorting function, calls makeHeap
void heapSort::sort(vector<string>& data) {

    // Build heap starting at last non-leaf index
    // Nodes without children should not be heapified
    int i = data.size() / 2 - 1;

    // Turn data vector into a heap, starting with later indexes
    // This is to make sure that all subtrees satisfy heap properties
    while (i >= 0) {
        makeHeap(data, data.size(), i);
        i--;
    }

    // One by one extract the max and move to sorted portion
    int j = data.size() - 1;
    while (j > 0) {

        // Swap the current max and the last index
        swap(data.at(j), data.at(0));

        // Re-heapify on the smaller heap
        makeHeap(data, j, 0);
        j--;
    }
}
