# In python we can use built-in fuctions to turn a List into a Stack.
# In that case <list-name>.pop() can used to remove the most recent item and 
# <list-name>.append(<item>) can be used to insert an item at the top.

class Element:
    def __init__(self,value):
        self.value=value
        self.next=None

class Stack:
    def __init__(self,top=None):
       self.top=top
       
    def push(self,new_element):
        if self.top:
            new_element.next=self.top
            self.top=new_element
        else:
            self.top=new_element

    def pop(self):
        if self.top:
            temp=self.top.value
            self.top=self.top.next
            return temp
        else:
            print "Stack is already empty, Nothing to pop!!!"

e1=Element(20)
e2=Element(30)

my_stack=Stack(e1)
my_stack.push(e2)

print my_stack.top.value
