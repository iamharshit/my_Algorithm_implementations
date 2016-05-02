# Python has in-built class(in the library `collections`) for implementing a queue.
# use `from collections import deque` to import deque,
# although deque is generalistion of stack and queue, we can use it to implement queue
# use `<queue-name>.append(<what-has-to-be-appended>)` to enqueue in the queue and
# use `<queue-name>.popleft()` to dequeue from the queue.

class Element:
    def __init__(self,value):
        self.value=value
        self.next=None

class Queue:
    def __init__(self,first_element=None):
        self.head=first_element
        self.tail=first_element

    def enqueue(self,new_element):
        if self.tail:
            self.tail.next=new_element
            self.tail=new_element
        else:
            self.tail=new_element

    def dequeue(self):
        if self.head:
            temp=self.head.value
            self.head=self.head.next
            return temp
        else:
            print "No element to dequeue!!!"

    def peak(self):
        if self.head:
            return self.head.value
        else:
            print "No element to peak!!!"

e1=Element(35)
e2=Element(80)

my_queue=Queue(e1)

my_queue.enqueue(e2)

print my_queue.head.value
