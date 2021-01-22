#include <iostream>
#include <vector>
#include <time.h>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, int> imap;

void print_map(imap arg){
 for(auto i = arg.begin(); i != arg.end(); i++){
     cout << i->first << ": " << i->second << endl;
 }
}

imap randomize(){
    imap temp;
    srand(time(0));
    for(int i = 0; i < 10; i++){
        temp[i] = rand()%99;
    }
    return temp;
}

int main(){
    imap test;
    int a;
    test = randomize();
    print_map(test);
    cin >> a;
    cout << test[a];
    return 0;
}