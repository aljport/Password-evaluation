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
    int start = data.size() - 1, middle, end = 0;

    while (start >= end) {
        // Find middle of search area
        middle = (start - end) / 2 + end;

        // Exit loop if input is found
        if (data.at(middle) == input) {
            return true;
        }

        // If string at midpoint is less than the input, the right half gets searched
        if (input > data.at(middle)) {
            end = 1 + middle;

        // If string at midpoint is greater than the input, the left half gets searched
        } else {
            start = middle - 1;
        }
    }
    return false;
}
