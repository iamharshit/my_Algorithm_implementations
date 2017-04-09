//Basically a Randomized Binary Search Tree
//insert time comlexity = delete time comlexity = O(logn)

#include<bits/stdc++.h>
using namespace std;

struct node{
	int key, priority;
	node *left, *right;
};

class Treap{
	public: 
		node *root;
		Treap(){
			root = NULL;
		}
		/*
		  			 y                               x
               / \     Right Rotation          /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3 
		*/	
		node* rightRotate(node *temp){
			node *tempLeft = temp->left;
			temp->left = tempLeft->right;
			tempLeft->right = temp;
			return tempLeft;
		}
		node* leftRotate(node *temp){
			node *tempRight = temp->right;
			temp->right = tempRight->left;
			tempRight->left = temp;
			return tempRight;
		}
		node *newNode(int key){
			node* temp = new node;
			temp->key = key;
			temp->priority = rand()%100;
			temp->left = temp->right = NULL;
			return temp;
		}
		node* insert(node *root_temp,int key){	
			//if root is NULL 	
			if(root_temp==NULL)
				return newNode(key);
			
			//otherwise
			else if(key <= root_temp->key){	
					root_temp->left = insert(root_temp->left, key);
				if(root_temp->left->priority > root_temp->priority)
					root_temp = rightRotate(root_temp);			
			}
			else{
					root_temp->right = insert(root_temp->right, key);
				if(root_temp->right->priority > root_temp->priority)
					root_temp = leftRotate(root_temp);					
			}
			return root_temp;
		}
		node* deleteNode(node* root, int key){
			 if (root == NULL)
				  return root;
		 
			 if (key < root->key)
				  root->left = deleteNode(root->left, key);
			 else if (key > root->key)
				  root->right = deleteNode(root->right, key);
		 
			 // IF KEY IS AT ROOT
			 // If left is NULL
			 else if (root->left == NULL) {
				  node *temp = root->right;
				  delete(root);
				  root = temp;  
			 }
			 // If Right is NULL
			 else if (root->right == NULL){
				  node *temp = root->left;
				  delete(root);
				  root = temp; 
			 }
			 // If key is at root and both left and right are not NULL
			 else if (root->left->priority < root->right->priority){
				  root = leftRotate(root);
				  root->left = deleteNode(root->left, key);
			 }
			 else{
				  root = rightRotate(root);
				  root->right = deleteNode(root->right, key);
			 }
		 
			 return root;
		}	
		void print(node *temp){	
			if(root==NULL){
				cout<<"Treap is Empty"<<endl;
				return;
			}

			if(temp==NULL)
				return;
			else{
				cout<<temp->key<<" ";
				print(temp->right);
				print(temp->left);							
			}		
		}
};

int main(){
	Treap t;
	
	t.root = t.insert(t.root,4); 
	t.root = t.insert(t.root,3);
	t.root = t.insert(t.root,32);
	t.root = t.insert(t.root,1);		
	
	t.root = t.deleteNode(t.root,32);

	t.print(t.root);

	return 0;
}
