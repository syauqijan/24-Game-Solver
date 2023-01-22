#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include "operators.cpp"
#include "solve24.cpp"

using namespace std;

int main()
{   
    int counter=0;
    splashScreen();
    vector<int> numbers;
    vector<string> solution;
    using Clock = chrono::high_resolution_clock;
    cout << "1.Input Manual" << endl;
    cout << "2.Input Random" << endl;
    cout << "Choose: ";
    int choose;
    cin >> choose;
    if (choose == 1)
    {
        string input[4];
        cout << "Input 4 numbers: "<< endl;
        cin >> input[0] >> input[1] >> input[2] >> input[3];
        while (!checkInput(input[0])&&!checkInput(input[1])&&!checkInput(input[2])&&!checkInput(input[3]))
        {
            cout << "Invalid Input" << endl;
            cout << "Input 4 numbers: ";
            cin >> input[0] >> input[1] >> input[2] >> input[3];
        }
        cout << "==============================" << endl;
        cout << "Your Numbers: ";
        for (int i = 0; i < 4; i++)
        {   
            cout << input[i] << " ";
            numbers.push_back(convertString(input[i]));
        }
        cout << endl;
        cout << "The solution is: " << endl;
        
    }
    else if (choose == 2)
    {
        srand(time(NULL));
        cout << "random numbers: ";
        for (int i = 0; i < 4; i++)
            {
                numbers.push_back(rand() % 13 + 1);
                cout << numbers[i] << " ";
            }
        cout << endl;
    }
    else
    {
        cout << "Invalid Input" << endl;
        return 0;
    }
    auto start = Clock::now();
    solve24(numbers[0], numbers[1], numbers[2], numbers[3], numbers, &solution, counter);
    auto end = Clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution Time: " << duration.count() << " ms" << endl;
    cout << "Do you want to save the solution to a file? (y/n): ";
    char save;
    cin >> save;
    if(save == 'y'){
        saveFile(solution, to_string(numbers[0]), to_string(numbers[1]), to_string(numbers[2]), to_string(numbers[3]));
    }
    return 0;
}