/*
 * tester.cpp
 */
 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
 
	ifstream test_in(argv[1]);    /* This stream reads from test's input file   */
	ifstream test_out(argv[2]);   /* This stream reads from test's output file  */
	ifstream user_out(argv[3]);   /* This stream reads from user's output file  */
 
	/* If user's output is correct, return 0, otherwise return 1       */
    
    string test_output, user_output, a, b;
	user_out >> user_output;
	test_out >> test_output;
	
	if (test_output == user_output)
		return 0;
    if (user_output.size() == test_output.size()){
        test_in >> a >> b;
        int i = 0, j = 0, k = user_output.size(), it = 0;
        while(i < a.size()){
            if (a[i] == user_output[it]){
                it++;
                if (it == k)
                    break;
            }
            i++;
        }
        if (it != k)
            return 1;
        it = 0;
        while(j < b.size()){
            if (b[j] == user_output[it]){
                it++;
                if (it == k)
                    break;
            }
            j++;
        }
        if (it != k)
            return 1;
        return 0;
    }
    return 1;
}