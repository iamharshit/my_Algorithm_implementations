def print_fun(node):
    if node:
        print node.value
        print_fun(node.left)
        print_fun(node.right)

def search_fun(self,node,value):
    if node==None: return
    elif node.value==value:
        print node.value
        self.status=True
        return
    else:
        print node.value
        search_fun(self,node.left,value)
        search_fun(self,node.right,value)      

class Node():
    def __init__(self,value,left=None,right=None):
        self.value=value
        self.left=left
        self.right=right

class BinaryTree:
    def __init__(self,head=None):
        self.head=head

    def print_all(self):
        print_fun(self.head)

    def search_it(self,element):
        self.status=False
        search_fun(self,self.head,element)
        return self.status

tree = BinaryTree(Node(1))
tree.head.left = Node(2)
tree.head.right = Node(3)
tree.head.left.left = Node(4)
tree.head.left.right = Node(5)

tree.print_all()

print tree.search_it(4)
