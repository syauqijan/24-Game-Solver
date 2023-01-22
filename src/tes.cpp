#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <chrono>
#include <fstream>


using namespace std;

int convertString(string s)
{
    if(s=="A"){
        return 1;
    }
    else if(s=="J"){
        return 11;
    }
    else if(s=="Q"){
        return 12;
    }
    else if(s=="K"){
        return 13;
    }
    else{
        return stoi(s);
    }
}

string convertOp(int op)
{
    if (op == 0){
        return "+";
    }
    else if (op == 1){
        return "-";
    }
    else if (op == 2){
        return "*";
    }
    else if (op == 3){
        return "/";
    }
    else{
        return "error";
    }
}

float operation(float a, float b, int op)
{
    if(op==0){
        return a+b;
    }
    else if(op==1){
        return a-b;
    }
    else if(op==2){
        return a*b;
    }
    else if(op==3){
        if (b==0){
            return 0;
        }
        else{
            return a/b;
        }
    }
    else{
        return 999;
    }
}

void printSolution(vector<string> v)
{
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
    cout << endl;
}

bool isDuplicate(vector<string> v, string s)
{
    for(int i=0; i<v.size(); i++){
        if(v[i]==s){
            return true;
        }
    }
    return false;
}

bool checkInput(string s)
{
    if(s=="A" || s=="J" || s=="Q" || s=="K" || s=="2" || s=="3" || s=="4" || s=="5" || s=="6" || s=="7" || s=="8" || s=="9" || s=="10"){
        return true;
    }
    else{
        return false;
    }
}
vector<vector<int>> permutation(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return {nums};
    }

    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> sol(nums.begin(), nums.end());
        sol.erase(sol.begin() + i);
        auto res = permutation(sol);

        for (int j = 0; j < res.size(); j++)
        {
            vector<int> sol_ = res[j];
            sol_.insert(sol_.begin(), nums[i]);
            result.push_back(sol_);
        }
    }
    return result;
}

void solve24(int a, int b, int c, int d, vector<int> numbers, vector<string> *solution)
{
    int counter = 0;
    vector<vector<int>> nums_res = permutation(numbers);
    string temp = "";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int x = 0; x < 24; x++)
                {
                    int a = nums_res[x][0];
                    int b = nums_res[x][1];
                    int c = nums_res[x][2];
                    int d = nums_res[x][3];

                    // a _ (b _ (c _ d))
                    if (operation(a,operation(b,operation(c,d,k),j),i) == 24.0){
                        temp = to_string(a) + " " + convertOp(i) + " (" + to_string(b) + " " + convertOp(j) + " (" + to_string(c) + " " + convertOp(k) + " " + to_string(d) + "))";
                        if(!isDuplicate(*solution, temp)){
                            (*solution).push_back(temp);
                            counter++;
                        }
                     }

                    // a _ ((b _ c) _ d)
                    if (operation(a,operation(operation(b,c,j),d,k),i) == 24.0){
                        temp = to_string(a) + " " + convertOp(i) + " ((" + to_string(b) + " " + convertOp(j) + " " + to_string(c) + ") " + convertOp(k) + " " + to_string(d) + ")";
                        if(!isDuplicate(*solution, temp)){
                            (*solution).push_back(temp);
                            counter++;
                        }
                    }

                    // (a _ (b _ c)) _ d
                    if (operation(operation(a,operation(b,c,j),i),d,k) == 24.0){
                        temp = "(" + to_string(a) + " " + convertOp(i) + " (" + to_string(b) + " " + convertOp(j) + " " + to_string(c) + ")) " + convertOp(k) + " " + to_string(d);
                        if(!isDuplicate(*solution, temp)){
                            (*solution).push_back(temp);
                            counter++;
                        }
                    }

                    // ((a _ b) _ c) _ d
                    if (operation(operation(operation(a,b,i),c,j),d,k) == 24.0){
                        temp = "((" + to_string(a) + " " + convertOp(i) + " " + to_string(b) + ") " + convertOp(j) + " " + to_string(c) + ") " + convertOp(k) + " " + to_string(d);
                        if(!isDuplicate(*solution, temp)){
                            (*solution).push_back(temp);
                            counter++;
                        }
                    }

                    // (a _ b) _ (c _ d)
                    if (operation(operation(a,b,i),operation(c,d,k),j) == 24.0){
                        temp = "(" + to_string(a) + " " + convertOp(i) + " " + to_string(b) + ") " + convertOp(j) + " (" + to_string(c) + " " + convertOp(k) + " " + to_string(d) + ")";
                        if(!isDuplicate(*solution, temp)){
                            (*solution).push_back(temp);
                            counter++;
                        }
                    }
                } 
            }
        }      
    }
    printSolution(*solution);
    cout << counter << " solutions found" << endl;
}

void saveFile(vector<string> solution, string a, string b, string c, string d){
    ofstream myfile;
    string fileName, filePath;
    cout << "Enter filename: ";
    cin >> fileName;
    filePath = "../test/" + fileName + ".txt";
    myfile.open (filePath);
    myfile <<"Your Number : " << a << " " << b << " " << c << " " << d << endl;
    myfile << "Solutions: " << endl;
    for(int i = 0; i < solution.size(); i++){
        myfile << solution[i] << endl;
    }
    myfile.close();
}

int main()
{
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
        cout << "Input 4 numbers: ";
        cin >> input[0] >> input[1] >> input[2] >> input[3];
        while (!checkInput(input[0])&&!checkInput(input[1])&&!checkInput(input[2])&&!checkInput(input[3]))
        {
            cout << "Invalid Input" << endl;
            cout << "Input 4 numbers: ";
            cin >> input[0] >> input[1] >> input[2] >> input[3];
        }
        for (int i = 0; i < 4; i++)
        {
            numbers.push_back(convertString(input[i]));
        }
        
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
    solve24(numbers[0], numbers[1], numbers[2], numbers[3], numbers, &solution);
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