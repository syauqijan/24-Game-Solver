#include "solve24.hpp"

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