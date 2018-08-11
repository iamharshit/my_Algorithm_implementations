#Max heap
class max_heap:
	def __init__(self):
		self.heap_list = [0] #Garbage item at index 0

	def insert(self, val):
		self.heap_list.append(val)
		i = len(self.heap_list)-1
		while(i!=1):
			if self.heap_list[i/2]<self.heap_list[i]:
				self.heap_list[i/2],self.heap_list[i] = self.heap_list[i],self.heap_list[i/2] 
			else:
				return
			i = i/2

	def delete(self, val):
		i=1
		while i<=len(my_max_heap.heap_list)-1:
			if self.heap_list[i]==val:
				while i*2<len(my_max_heap.heap_list)-1:
					if my_max_heap.heap_list[i*2]>my_max_heap.heap_list[i*2+1]:
						self.heap_list[i*2],self.heap_list[i] = self.heap_list[i],self.heap_list[i*2] 		
					else:
						self.heap_list[i*2+1],self.heap_list[i] = self.heap_list[i],self.heap_list[i*2+1]
					i=i*2						
				del my_max_heap.heap_list[i]
			i+=1

	def print_all(self):
		for i in range(1,len(self.heap_list)):
			print self.heap_list[i]

	def print_leaves(self):
		i=1
		while i<=len(my_max_heap.heap_list)-1:
			if i*2>len(my_max_heap.heap_list)-1:
				print self.heap_list[i]
			i+=1
      
my_max_heap = max_heap()
my_max_heap.insert(15)
my_max_heap.insert(54)
my_max_heap.insert(4)
my_max_heap.insert(100)
my_max_heap.insert(5)
my_max_heap.insert(11)
my_max_heap.insert(70)

my_max_heap.delete(54)

my_max_heap.print_leaves()
'''
Output: 
5
4
11
'''
