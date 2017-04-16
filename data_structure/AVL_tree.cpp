//Balanced BST to get time complexity of O(logn) for insertion, deletion, search

#include<bits/stdc++.h>
using namespace std;

struct node{
	int key;
	node *left, *right;
	int height;
};

class AVLtree{
	public:
		node *root;
		AVLtree(){
			root=NULL;
		}
		node *newNode(int key){
			node *temp = new node;
			temp->key = key;
			temp->left, temp->right = NULL, NULL;
			temp->height = 1;
			return temp;
		}
		int height(node *root){
			return (root==NULL)?0:root->height;
		}	
		node *rightRotate(node *root){
			node *newRoot = root->left;
			root->left = newRoot->right;
			newRoot->right = root;
			root->height = 1+ max(height(root->left), height(root->right));
			newRoot->height = 1+ max(height(newRoot->left), height(newRoot->right));
			return newRoot;
		}
		node *leftRotate(node *root){
			node *newRoot = root->right;
			root->right = newRoot->left;
			newRoot->left = root;
			root->height = 1+ max(height(root->left), height(root->right));
			newRoot->height = 1+ max(height(newRoot->left), height(newRoot->right));
			return newRoot;
		}

		node *insert(node *root,int key){
			if(root == NULL)
				return  newNode(key);

			//Standard BST insertion
			if(root->key < key)
				root->right = insert(root->right, key);
			else
				root->left = insert(root->left, key); 
	
			root->height = 1+ max(height(root->left), height(root->right));

			int balance = height(root->left)-height(root->right);	
			//left			
			if(balance>=2){
				//left-left
				if(height(root->left->left)>height(root->left->right))
					root = rightRotate(root);
				//left-right
				else{ 
					root->left = leftRotate(root->left);
					root = rightRotate(root);
				}
			}
			//right
			else if(balance<=-2){
				//right-right
				if(height(root->right->right)>height(root->right->left))
					root = leftRotate(root);
				//right-left
				else{
					root->right = rightRotate(root->right);
					root = leftRotate(root);
				}
			}
			return root;			
		}

		node *minValueNode(node *root){
			while(root->left!=NULL)
				root = root->left;
			return root;
		}

		node *delete_(node *root,int key){
			if(root==NULL)
				return root;
			//Standard BST deletion			
			if(key<root->key)
  				root->left = delete_(root->left,key);
			else if(key>root->key)
				root->right = delete_(root->right,key);
			else{ 
				if(root->left==NULL && root->right==NULL){
					root = NULL;}
				else if(root->left==NULL)
					root = root->right;
				else if(root->right==NULL)
					root = root->left;
				else{
					node *temp = minValueNode(root->right);
					root->key = temp->key;
					root->right = delete_(root->right, temp->key);	
				}
			}
			
			if(root==NULL) return root;
			
			//Check Balance at root
			root->height = 1+ max(height(root->left), height(root->right));
			
			int balance = height(root->left)-height(root->right);
			//left			
			if(balance>=2){
				//left-left
				if(height(root->left->left)>=height(root->left->right))
					root = rightRotate(root);
				//left-right
				else{ 
					root->left = leftRotate(root->left);
					root = rightRotate(root);
				}
			}
			//right
			else if(balance<=-2){
				//right-right
				if(height(root->right->right)>=height(root->right->left))
					root = leftRotate(root);
				//right-left
				else{
					root->right = rightRotate(root->right);
					root = leftRotate(root);
				}
			}
		
			return root;
		}

		void print(node *temp){	
			if(root==NULL){
				cout<<"AVL Tree is Empty"<<endl;
				return;
			}

			if(temp==NULL)
				return;
			else{
				//pre-Order printing
				cout<<temp->key<<" ";
				print(temp->left);
				print(temp->right);							
			}		
		}
};

int main(){
	AVLtree avl; 	
	avl.root = avl.insert(avl.root, 23);
	avl.root = avl.insert(avl.root, 34);
	avl.root = avl.insert(avl.root, 67);
	avl.root = avl.insert(avl.root, 59);
	
	avl.root = avl.delete_(avl.root,67);
	
	avl.print(avl.root); 
	/* 
	output: 34 23 59
	*/

	return 0;
} 
