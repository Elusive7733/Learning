// A safe array example. 
#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>
using namespace std; 

class ArrayIndexOutOfBoundException {
public:
	ArrayIndexOutOfBoundException()
		: message ("Array Index Out of Bound") {}
	~ArrayIndexOutOfBoundException() { delete message;}
	const string what() const { return message; }
private:
	char *message;
};
 
class atype{ 
	int ncols; 
	int nrows; 
	int **data; 
 
public: 
	atype(){ 
		nrows=0; 
		ncols=0; 
		data=0; } 
 
//constructor 
	atype(int row, int col)
	{ 
		nrows=row; 
		ncols=col; 
		data = new int*[nrows]; 
		for( int i = 0 ; i < nrows ; i++ )
		{ 
			data[i] = new int [ncols]; 
		} 
	} 
 
//destructor 
	~atype()
	{ 
		if (data != 0) 
		{ 
			for (int i=nrows-1; i>=0; i--) 
			{ 
				if (data[i] != 0) 
				delete data[i]; 
				data[i] = 0; 
			} 
			delete [] data; 
		} 
		data = 0; 
	} 
    	
	void ReSize(int rows, int cols){
		
		if ((nrows < rows) || (ncols < cols))  
		{
		 	int **temp= new int*[nrows]; 
		 	for( int i = 0 ; i < nrows ; i++ )
			{ 
				temp[i] = new int [ncols]; 
			}
			 	
			for (int in=0;in<nrows;in++)
			{ 
				for (int j=0;j<ncols;j++)
				{ 
					temp[in][j] = data[in][j]; 
				} 
			}	 
		    delete[] data;
		    data=0;
		    
		    data = new int*[rows]; 
			for (int in=0;in<nrows;in++)
			{ 
				for (int j=0;j<ncols;j++)
				{ 
					data[in][j] = temp[in][j]; 
				} 
			}	 
		    nrows = rows;
		    ncols = cols;
		    delete [] temp;
		    temp=0;	
		} 				
	}
		   
	unsigned int getSize() const { 
	   return (nrows * ncols);
	}
 
//user inserting elements in 2d array 
	void fillArray() 
	{ 
		for (int in=0;in<nrows;in++)
		{ 
			for (int j=0;j<ncols;j++)
			{ 
				int value; 
				cout<<"enter values"; 
				cin>>value; 
				data[in][j] = value; 
			} 
		}	 
	} 
 
//bound checking-safe array implementation 
	int &operator ()(int i, int j)
	{ 
		if(i<0 || i> nrows-1 || j<0 || j> ncols-1 ) 
		{ 
			cout << "Boundary Error\n"; 
			exit(1); 
		} 
		return data[i][j]; 
	} 
 
//copy constructor 
	atype(const atype& rhs) 
	{ 	
		nrows = rhs.nrows; 
		ncols = rhs.ncols; 
		data = new int*[nrows]; 
		for( int i = 0 ; i < nrows ; i++ )
		{ 
			data[i] = new int [ncols]; 
			memcpy(data[i],rhs.data[i],sizeof(int)*ncols); 
		} 
	} 
 
//assignment operator overloading 
	atype& operator=(const atype& rhs) 
	{ 
		if (this == &rhs) 
			return *this; 
			
		for (int i=nrows-1; i>=0; i--) 
		{ 
			delete data[i]; 
		} 
		delete [] data; 
 
		nrows = rhs.nrows; 
		ncols = rhs.ncols; 
		data = new int*[nrows]; 
		for( int i = 0 ; i < nrows ; i++ )
		{ 
			data[i] = new int [ncols]; 
			memcpy(data[i],rhs.data[i],sizeof(int)*ncols); } 
			return *this; 
	} 
 
//not equal to operator overloading 
	bool operator!=(const atype& rhs)
	{ 
		if (this->nrows != rhs.nrows || this->ncols != rhs.ncols)      
		{
			cout<<"not equal"; 
			return false;
		} 
		
		for (int i=0;i<nrows;i++)
		{ 
			for (int j=0;j<ncols;j++)
			{ 
				if(data[i][j]!=rhs.data[i][j])
				{ 
					cout<<"not equal"; 
					return false; 
				} 
			} 
			return true;
		}	 
	}

	friend istream& operator >> (istream& infile, atype & rhs)
	{
		for (int in=0;in<rhs.nrows;in++)
		{ 
			for (int j=0;j<rhs.ncols;j++)
			{ 
				int value; 
				cout<<"enter values"; 
				infile >> value; 
				rhs.data[in][j] = value; 
			} 
		}	 
	    return infile;
	}
	
	friend ostream& operator << (ostream& outfile,atype & rhs)
	{
		for (int in=0;in<rhs.nrows;in++)
		{ 
			for (int j=0;j<rhs.ncols;j++)
			{ 
				outfile << rhs.data[in][j]; 
			} outfile<<endl;
		}	 
	    return outfile;
	}
		 
}; 
 
int main() 
{ 
	int columns; 
	int rows; 
	cout<<"enter number of rows and cols"<<endl; 
	cin>>rows>>columns; 
	atype ob1(rows,columns); 
	cout << "Enter an Array ob1: "<<endl;
//	ob1.fillArray(); 
	cin >> ob1;
	cout << ob1;
	atype ob2=ob1; 
	atype ob3(3,3); 
	cout << "Enter an Array ob3: "<<endl;
//	ob3.fillArray(); 
	cin >> ob3;
	cout << ob3 <<endl;
	cout << ob1(1,1) << endl; 
	//checking bounds of array 
	bool b= ob1!=ob3;              
	return 0; 
} 
