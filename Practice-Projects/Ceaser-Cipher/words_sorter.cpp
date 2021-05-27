#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <string>
#include <chrono> 
 
using namespace std;
using namespace chrono;

int main(){
    int count[50];
    for(int i = 0; i < 50; i++){
        count[i] = 0;
    }
    string out_file, in_str;
    fstream input, output;
    input.open("words_alpha.txt", ios::in);

    auto start = high_resolution_clock::now(); 
    while(!input.eof()){
        system("cls");
        fflush(stdin);
        getline(input, in_str);
        out_file = to_string(in_str.length());
        out_file.append(".txt");
        cout << "At: " << in_str << endl;
        if(count[in_str.length()] == 0){
            count[in_str.length()] = 1;
            output.open(out_file, ios::out);
            output << in_str << endl;
            output.close();
        }
        else{
            output.open(out_file, ios::app);
            output << in_str << endl;
            output.close();
        }
    }
    input.close();
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<minutes>(stop - start); 
    cout << "Total time taken: " << duration.count()/60 << " hours & " << duration.count()%60 << " minutes" << endl;
    system("pause");
    return 0;
    
}