#include <iostream>
#include <fstream>

using namespace std;
int sum;
int temp_sum;
fstream Output_file;

class node{

public:
	int data;
	node *left;
	node *right;

	node(int _data = 0, node *_left = NULL, node *_right = NULL){
		data = _data;
		left = _left;
		right = _right;
	}

};

class BT{
public:
	node *root;
	node **array;
	int size;
	int count;
	
	BT(int _size = 10){
		root = NULL;
		size = _size;
		array = new node*[100];
		count = 0;
	}

	void insert(int _data){
		array[count] = new node(_data);
		count++;
	}

	void build_tree(){
		int l;
		int r;
		root = array[0];
		for(int i = 0; i < size; i++){
			l = 2*i + 1;
			r = 2*i + 2;
			if(l < size){
				array[i]->left = array[l];
			}
			if(r < size){
				array[i]->right = array[r];
			}
		}
	}

	bool check_BST(node* ptr, int min, int max){
		if (ptr == NULL){
			return true;
		}
		if (ptr->data < min || ptr->data > max){
			return false;
		}
		return (check_BST(ptr->left, min, ptr->data) && check_BST(ptr->right, ptr->data, max));
	}	

	void Preorder(node *ptr){
		if (ptr == NULL){
			return;
		}
        cout << ptr->data << endl;
        Preorder(ptr->left);
		Preorder(ptr->right);
	}
	
	void Inorder(node *ptr){
		if (ptr == NULL){
			return;
		}
		Inorder(ptr->left);
		cout << ptr->data << endl;
		Inorder(ptr->right);
	}

};

int main(){
	BT tree(15);

	for(int i = 0; i < 15; i++){
		tree.insert(i);
	}
	tree.build_tree();
    tree.Preorder(tree.root);
	Output_file.close();
	return 0;
}