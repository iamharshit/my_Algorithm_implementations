class linkedList:
    def __init__(self,head=None):
        self.head=head

class Element:
    def __init__(self,value):
        self.value=value
        self.next=None

def append(self,new_element):
    if self.head:
        curr=self.head
        while curr.next:
            curr=curr.next
        curr.next=new_element
    else:
        self.head=new_element

first=Element(3)
second=Element(5)

my_linkedList=linkedList(first)

append(my_linkedList,second)
