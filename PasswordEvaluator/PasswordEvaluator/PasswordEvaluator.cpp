#include <iostream>
#include "heapSort.h"
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
    std::cout << "2. Search your password in top 100,000 most common passwords" << std::endl;
    std::cout << "3. Show Sorting Algorithm Results" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "Please enter a number corresponding to which menu option you'd like to select." << std::endl;

    int input;
    std::cin >> input;

    //While user has not entered 4 to quit, continue asking and interpretting input
    while (input != 4)
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

            for (int i = 0; i < numPasswords; i++)
            {
                std::cout << i+1 << "." << std::setw(8 + passwords[i].length() - std::to_string(i+1).length()) << passwords[i] << std::endl;
            }
            std::cout << "------------------" << std::endl;
        }
        //If user selects 2, then ask user for password to search for and display if it exists in top 100,000 most common passwords
        else if (input == 2)
        {
            std::cout << "Please enter a password to search for." << std::endl;
            std::string userPassword;
            std::vector<std::string> passwordsSorted = passwords;
            
            std::chrono::high_resolution_clock::time_point tStart = std::chrono::high_resolution_clock::now();
            //start algorithm 1 here
            std::chrono::high_resolution_clock::time_point tEnd = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> timeElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(tEnd - tStart);
            auto mergeTimeElapsed = timeElapsed.count();

            passwordsSorted = passwords;
            tStart = std::chrono::high_resolution_clock::now();
            //start algorithm 2 here
            tEnd = std::chrono::high_resolution_clock::now();
            timeElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(tEnd - tStart);
            auto heapTimeElapsed = timeElapsed.count();
            
            //Search password here

            std::cout << "Results:" << std::endl;
            //Results here
            std::cout << "Analysis of sorting algorithms" << std::endl;
            std::cout << "------------------------------" << std::endl;
            std::cout << "The Merge Sort Algorithm Took: " << mergeTimeElapsed << "seconds." << std::endl;
            std::cout << "The Heap Sort Algorithm Took: " << heapTimeElapsed << "seconds." << std::endl;

        }
        //If user selects 3, then calculate each sorting algorithm's time elapsed and display results
        else if (input == 3)
        {
            std::cout << std::endl << "Results: " << std::endl;
            std::chrono::high_resolution_clock::time_point tStart = std::chrono::high_resolution_clock::now();
            //start algorithm 1 here


            std::chrono::high_resolution_clock::time_point tEnd = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> timeElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(tEnd-tStart);
            std::cout << "The Merge Sort Algorithm Took: " << timeElapsed.count() << "seconds." << std::endl;


            tStart = std::chrono::high_resolution_clock::now();
            //start algorithm 2 here
            tEnd = std::chrono::high_resolution_clock::now();
            timeElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(tEnd - tStart);
            std::cout << "The Heap Sort Algorithm Took: " << timeElapsed.count() << "seconds." << std::endl;
        }
        //If user did not select any of the options, then ask for a new number
        else
        {
            std::cout << "Please enter a number between 1-4." << std::endl;
        }

        std::cout << std::endl;
        std::cout << "1. View the top most common passwords" << std::endl;
        std::cout << "2. Search your password" << std::endl;
        std::cout << "3. Show Sorting Algorithm Results" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Please enter a number corresponding to which menu option you'd like to select." << std::endl;
        std::cin >> input;
    }
    return 0;
}
