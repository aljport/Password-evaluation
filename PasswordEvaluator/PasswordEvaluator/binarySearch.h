#include <string>
#include <vector>
using namespace std;
// Written by Anna Portugal
class binarySearch {
public:
    bool isFound(string& input, vector<string>& data);
};

bool binarySearch::isFound(string& input, vector<string>& data)  {
    // Initialize search boundaries
    int right = data.size() - 1;
    int left = 0;

    while (right >= left) {
        // Find middle of search area
        int middle = (right - left) / 2 + left;

        // Exit loop if input is found
        if (data.at(middle) == input) {
            return true;
        }

        // If string at midpoint is less than the input, the right half gets searched
        if (input > data.at(middle)) {
            left = 1 + middle;

        // If string at midpoint is greater than the input, the left half gets searched
        } else {
            right = middle - 1;
        }
    }
    return false;
}