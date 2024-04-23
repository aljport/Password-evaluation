#include <iostream>
#include "heapSort.h"
#include "binarySearch.h"
#include "mergeSort.h"
#include "dpEditDistance.h"
#include "FileParser.h"
#include <vector>
#include <iomanip>
#include <chrono>
//References used for file
//https://cplusplus.com/reference/chrono/high_resolution_clock/now/ for calculating time taken for algorithms
//Written by Andrew Goldstein
int main()
{
    
    std::vector<std::string> passwords;
    FileParser parser;
    if (parser.FileToVector("10millionPasswords", 100000, passwords) == true)
    {
        std::cout << passwords.size() << std::endl;
    }
    

    //Menu display
    std::cout << "Password Evaluator" << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "Welcome to the Password Evaluator Program!" << std::endl;
    std::cout << "1. View the top most common passwords" << std::endl;
    std::cout << "2. View sorted password list" << std::endl;
    std::cout << "3. Search your password in top 100,000 most common passwords" << std::endl;
    std::cout << "4. Compare your password with top 100,000 most common passwords" << std::endl;
    std::cout << "5. Show Sorting Algorithm Results" << std::endl;
    std::cout << "6. Quit" << std::endl;
    std::cout << "Please enter a number corresponding to which menu option you'd like to select." << std::endl;

    int input;
    std::cin >> input;

    //While user has not entered 4 to quit, continue asking and interpretting input
    while (input != 6)
    {
        //If user selects 1, then show the top most common passwords
        if (input == 1)
        {
            std::cout << "------------------" << std::endl;
            std::cout << "Please enter how many of the top passwords you would like to see." << std::endl;
            std::cout << "Note: enter a number between 1-100000." << std::endl;
            int numPasswords;
            std::cin >> numPasswords;

            std::cout << "_________________" << std::endl;
            std::cout << "rank  |  password" << std::endl;
            std::cout << "-----------------" << std::endl;

            //iterate through each password up to the given value and print them out in rank order
            for (int i = 0; i < numPasswords; i++)
            {
                std::cout << i+1 << "." << std::setw(8 + passwords[i].length() - std::to_string(i+1).length()) << passwords[i] << std::endl;
            }
            std::cout << "------------------" << std::endl;
        }
        //If user selects 2, then show a list of the passwords in alphabetical (sorted) order
        else if (input == 2)
        {
            std::cout << "------------------" << std::endl;
            std::cout << "Please enter how many of the sorted passwords you would like to see." << std::endl;
            std::cout << "Note: enter a number between 1-100000." << std::endl;
            int numPasswords;
            std::cin >> numPasswords;

            std::cout << "Select which sorting algorithm will be used for the sort. Type 1 for merge sort and type 2 for heap sort." << std::endl;
            int sortChoice;
            std::cin >> sortChoice;
            std::vector<std::string> passwordsSorted = passwords;

            //If user selects 1 choose merge sort, if user selects 2 choose heap sort
            if (sortChoice == 1)
            {
                mergeSort mergeSort;
                mergeSort.mSort(passwordsSorted, 0, passwordsSorted.size() - 1);
            }
            else if (sortChoice == 2)
            {
                heapSort heapSort;
                heapSort.sort(passwordsSorted);
            }

            std::cout << "________" << std::endl;
            std::cout << "password" << std::endl;
            std::cout << "--------" << std::endl;

            for (int i = 0; i < numPasswords; i++)
            {
                std::cout << passwordsSorted[i] << std::endl;
            }
            std::cout << "--------" << std::endl;
        }
        //If user selects 3, then ask user for password to search for and display if it exists in top 100,000 most common passwords
        else if (input == 3)
        {
            std::cout << "Please enter a password to search for." << std::endl;
            std::string userPassword;
            std::cin >> userPassword;
            std::vector<std::string> passwordsSorted = passwords;
            
            std::chrono::high_resolution_clock::time_point tStart = std::chrono::high_resolution_clock::now();
            
            //======Algorithm 1======//
            mergeSort mergeSort;
            mergeSort.mSort(passwordsSorted, 0, passwordsSorted.size()-1);


            std::chrono::high_resolution_clock::time_point tEnd = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> timeElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(tEnd - tStart);
            auto mergeTimeElapsed = timeElapsed.count();

            passwordsSorted = passwords;
            tStart = std::chrono::high_resolution_clock::now();

            //======Algorithm 2======//
            heapSort heapSort;
            heapSort.sort(passwordsSorted);
            
            tEnd = std::chrono::high_resolution_clock::now();
            timeElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(tEnd - tStart);
            auto heapTimeElapsed = timeElapsed.count();
            
            // Search for user input password
            binarySearch bs;
            if (bs.isFound(userPassword, passwordsSorted)) {
                std::cout << userPassword << " is found in the top 100,000 most common passwords."  << std::endl;
                std::cout << "You may want to create a more uncommon password." << std::endl;
            } else {
                std::cout << userPassword << " is not found in the top 100,000 most common passwords."  << std::endl;
                std::cout << "That's great! You're password is not super common!" << std::endl;
            }

            std::cout << std::endl << "Results:" << std::endl;
            //Results here
            std::cout << "Analysis of sorting algorithms" << std::endl;
            std::cout << "------------------------------" << std::endl;
            std::cout << "The Merge Sort Algorithm Took: " << mergeTimeElapsed << " seconds." << std::endl;
            std::cout << "The Heap Sort Algorithm Took: " << heapTimeElapsed << " seconds." << std::endl;

        }
        //If user selects 4, compare the given password with each password in list and return the password with the most similarities.
        else if (input == 4)
        {
            std::cout << "Please enter a password to compare." << std::endl;
            std::string userPassword;
            std::cin >> userPassword;
            int minDist = 10000;
            int minIndex = 0;
            for (int i = 0; i < passwords.size(); i++)
            {
                int currentVal = editDistance(userPassword, passwords[i]);
                if (currentVal < minDist)
                {
                    minDist = currentVal;
                    minIndex = i;
                }
            }

            std::cout << userPassword << " is closest to " << passwords[minIndex] << " by " << minDist << " characters." << std::endl;
        }
        //If user selects 5, then calculate each sorting algorithm's time elapsed and display results
        else if (input == 5)
        {
            std::vector<std::string> passwordsSorted = passwords;
            std::cout << std::endl << "Results: " << std::endl;
            std::chrono::high_resolution_clock::time_point tStart = std::chrono::high_resolution_clock::now();

             //======Algorithm 1======//
            mergeSort mergeSort;
            mergeSort.mSort(passwordsSorted, 0, passwordsSorted.size()-1);

            std::chrono::high_resolution_clock::time_point tEnd = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> timeElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(tEnd-tStart);
            std::cout << "The Merge Sort Algorithm Took: " << timeElapsed.count() << " seconds." << std::endl;

            passwordsSorted = passwords;
            tStart = std::chrono::high_resolution_clock::now();
            
            //======Algorithm 2======//
            heapSort heapSort;
            heapSort.sort(passwordsSorted);

            tEnd = std::chrono::high_resolution_clock::now();
            timeElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(tEnd - tStart);
            std::cout << "The Heap Sort Algorithm Took: " << timeElapsed.count() << " seconds." << std::endl;
        }
        //If user did not select any of the options, then ask for a new number
        else
        {
            std::cout << "Please enter a number between 1-6." << std::endl;
        }

        std::cout << std::endl;
        std::cout << "1. View the top most common passwords" << std::endl;
        std::cout << "2. View sorted password list" << std::endl;
        std::cout << "3. Search your password in top 100,000 most common passwords" << std::endl;
        std::cout << "4. Compare your password with top 100,000 most common passwords" << std::endl;
        std::cout << "5. Show Sorting Algorithm Results" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cout << "Please enter a number corresponding to which menu option you'd like to select." << std::endl;
        std::cin >> input;
    }
    return 0;
}
