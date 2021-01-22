#include <iostream>
#include <cmath>
using namespace std;

int armstrong(int sum, int num, int digits){
	
	if(num%10 == num){
	 	return (sum+pow(num%10, digits)); 
	}
	
	armstrong(sum+pow(num%10, digits), num/10, digits);
}
	
int main(){
	
	int N, num, temp, nod = 0;
	cout << "Enter number to check for armstrong number: ";
	cin >> N;
	temp = N;
	while(temp != 0){
		nod++;
		temp /=10;
	}
	num = armstrong(0, N, nod, nod);
	if(num == N){
		cout << N << " :is a armstrong number";
	}
	else{
		cout << N << " :is not a armstrong number";
	}
	return 0;
}
