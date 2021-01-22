#include <iostream>

using namespace std;

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


class BST{
public:
	node *root;
	
	BST(){
		root = NULL;
	}
	
	void insert(int data){
		node *current, *parent;
		if(root == NULL) {
	      root = new node(data);
	    }
		else{
	      current = root;
	      parent  = NULL;
	
	      while(1){                
	         parent = current;
	         if(data < parent->data){
	            current = current->left;                
	            if(current == NULL){
	               parent->left = new node(data);
	               return;
	            }
	         }
	         else{
	            current = current->right;
	            if(current == NULL) {
	               parent->right = new node(data);
	               return;
	            }
	         }
	      }            
	    }
	}
	
   bool search(int data){
	   node *current = root;
	   printf("Visiting elements: ");
	
	   while(current->data != data){
	      if(current != NULL)
	      printf("%d ",current->data); 
	      if(current->data > data) {
	         current = current->left;
	      }
	      else {                
	         current = current->right;
	      }
	      if(current == NULL) {
	         return false;
	      }
	   }
	return true;  
}
	
	void printPostorder(node *ptr) 
	{ 
	    if (ptr == NULL) { 
			return;
		}
	    printPostorder(ptr->left); 
	    printPostorder(ptr->right); 
	    cout << ptr->data << " "; 
	} 
	  
	void printInorder(node *ptr) 
	{ 
	    if (ptr == NULL){
	        return; 
		}
	  
	    printInorder(ptr->left); 
	    cout << ptr->data << " "; 
	    printInorder(ptr->right); 
	} 
	void printPreorder(node *ptr) 
	{ 
	    if (ptr == NULL){
			return; 
		}
	    cout << ptr->data << " "; 
	    printPreorder(ptr->left);  
	    printPreorder(ptr->right); 
	}  
	
};

int main(){
	BST tree;
	tree.insert(3);
	tree.insert(1);
	tree.insert(5);
	tree.insert(4);
	tree.insert(2);
	cout << "Preorder: " << endl;
	tree.printPreorder(tree.root);
	cout << endl << "Inorder: " << endl;
	tree.printInorder(tree.root);
	cout << endl << "Postorder: " << endl;
	tree.printPostorder(tree.root);
	return 0;
}
