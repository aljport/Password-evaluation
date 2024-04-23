#include <iostream>
#include <vector>
#include <string>
using namespace std;

// tabulation/bottom-up method
// referenced https://www.geeksforgeeks.org/edit-distance-dp-5/
void editDistance(string firstWord, string secondWord){
    vector<vector<int>> dpTable(firstWord.length() + 1, vector<int>(secondWord.length() + 1));

    for(int i = 1; i <= firstWord.length(); i++){
        dpTable[i][0] = i;
    }
    for(int j = 1; j <= secondWord.length(); j++){
        dpTable[0][j] = j;
    }
    for(int i = 1; i <= firstWord.length(); i++){
        for(int j = 1; j <= secondWord.length(); j++){
            if(firstWord[i - 1] == secondWord[j - 1]){
                dpTable[i][j] = dpTable[i - 1][j - 1];
            }
            else{
                dpTable[i][j] = min({dpTable[i - 1][j - 1], dpTable[i - 1][j], dpTable[i][j - 1]}) + 1;
            }
        }
    }

    cout << dpTable[firstWord.length()][secondWord.length()];
}