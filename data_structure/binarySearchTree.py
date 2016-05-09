def search_fun(node,item):
    if node.value==item:
        return 1
    elif item<node.value and node.left!=None:
        return search_fun(node.left,item)
    elif node.value<item and node.right!=None:
        return search_fun(node.right,item)
    else:
        return -1

def insert_fun(node,item):
    if item<node.value and node.left==None:
        node.left=Node(item)
    elif item<node.value and node.left!=None:
        insert_fun(node.left,item)
    elif node.value<item and node.right==None:
        node.right=Node(item)
    elif node.value<item and node.right!=None:
        insert_fun(node.right,item)

def print_fun(node):
    if node:
        print node.value
        print_fun(node.left)
        print_fun(node.right)
    

class Node:
    def __init__(self,item,left=None,right=None):
        self.value=item
        self.left=left
        self.right=right

class BST:
    def __init__(self,item=None):
        self.head=Node(item)

    def search(self,item):
        if self.head: return search_fun(self.head,item)
        else: return -1

    def insert(self,item):
        if self.head: insert_fun(self.head,item)
        else: self.head=Node(item)

    def print_all(self):
        if self.head:
            print_fun(self.head)
        else:
            print 'Empty Tree'

tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)
tree.insert(8)

# Print all elements
tree.print_all()

# Search for element
print tree.search(3)       #returns 1 if found and -1 of not found
