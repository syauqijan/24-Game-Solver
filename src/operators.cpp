#include "operators.hpp"



void splashScreen()
{
    cout << "          Welcome to 24 SOLVER!            " << endl;
    cout << "============================================" << endl;
    cout << "     _______   ________   _______    _______ " << endl;
    cout << "    |2_  _  |  |A /\\  |  |Q  .   |  |T __   |" << endl;
    cout << "    |( \\/ ) |  | /  \\ |  | //  \\ |  | (  )  |" << endl;
    cout << "    | \\  /  |  | \\  / |  |(__,__)|  |(__X_) |" << endl;
    cout << "    |  \\/ 2 |  |  \\/ A|  |   I  Q|  |   Y  T|" << endl;
    cout << "    `-------`  `------`  `-------`  `-------`" << endl;
    cout << "    created by: Muhhamad Syauqi Jannatan" << endl;
    cout << "===============================================" << endl;
    cout << endl;

}

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

void saveFile(vector<string> solution, string a, string b, string c, string d)
{
    ofstream myfile;
    string fileName, filePath;
    cout << "Enter filename: ";
    cin >> fileName;
    filePath = "../test/" + fileName + ".txt";
    myfile.open (filePath);
    myfile <<"Your Number : " << a << " " << b << " " << c << " " << d << endl;
    myfile << "Total Solutions: " << solution.size() << endl;
    myfile << "====================" << endl;
    for(int i = 0; i < solution.size(); i++){
        myfile << solution[i] << endl;
    }
    myfile.close();
}
