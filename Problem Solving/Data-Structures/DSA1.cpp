#include <iostream> 
#include <cstdlib> 
#include<string.h> 
using namespace std;


class DSA{
	
	int size;	
	int *Data;
	public:
	
	DSA(){
		size=0;;
		Data = new int[size];
		memset(Data, 0, sizeof(int)*size);
	}
	
	//constructor
	DSA(int col){
		size=col;
		Data = new int[size];
		memset(Data, 0,sizeof(int)*size);
	}
	
	//destructor
	~DSA(){
		delete [] Data;
		Data = 0;
		size = 0;
	}
	
	//user inserting elements in 1d array 
	void fillArray()
	{	
		for (int in=0;in<size;++in){	
			int value;
			cout<<"enter value";
			cin>>value;
			Data[in] = value;
		}
	}
	
	
	//bound checking-safe array implementation 
	int &operator [](int i){
		if( i<0 || i>size-1 ) {
			cout << "Boundary Error\n";
			exit(1);		
		}
		return Data[i];		
	}
	
	void Resize(int nsize)
	{
		if(size < nsize)
		{
			int *temp;
			temp = new int[size];
			for(int i=0; i<size; i++)
			{
				temp[i] = Data[i];
			}
			
			delete [] Data;
			Data = new int [nsize];
			
			for(int i=0; i<size; i++)
			{
				Data[i] = temp[i];
			}
			
			delete [] temp;
			temp = 0;
			size= nsize;
		}
	}
	
	DSA(const DSA& rhs) //copy constructor 
	{
		size = rhs.size;
		Data = new int[size];
		memcpy(Data,rhs.Data, sizeof(int)*size);		
	}
	
	
	DSA& operator=(const DSA& rhs)
	{
		//assignment operator
	
		if (this == &rhs)
		return *this;
		
		delete[] Data;
		Data = 0;
		size = 0;
		
		size = rhs.size;
		Data = new int[size];
		memcpy(Data,rhs.Data, sizeof(int)*size);
		
		return *this;
	}
	
	DSA& operator!=(const DSA& rhs){ 
		for (int i=0;i<size;i++){
			if(Data[i]!=rhs.Data[i]){ 
				cout<<"not equal";
				break;	
			}
		}
	}
	
	
	  
	friend istream &operator>> (istream &input, const DSA &array)
	{
		int cols;
	
		cols=array.size;
	
		for (int i = 0; i < cols; i++) {		
		input >> array.Data[i];
		}
	
		return input;
	}
	
};




int main()
{
	int columns;
	
	cout<<"enter cols"<<endl;
	cin>>columns;
	DSA ob1(columns);   
	
	//ob1.Resize(9);
	
	//ob1.fillArray();
	
	cin>>ob1; //if not using fill array option, this will call friend function declared for taking input
	
	DSA ob2=ob1;
	DSA ob3;
	
	ob3=ob1;
	cout << ob1[1] << endl;
	cout<<ob1[1]<<endl;
	cout<<ob3[1];
	
	//checking bounds of array
	
	ob1!=ob3;	
	
	return 0;
}
