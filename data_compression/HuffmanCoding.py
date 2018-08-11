
class Node:
	def __init__(self, freq, char, left=None, right=None):
		self.freq = freq
		self.char = char
		self.left = left
		self.right = right

def print_codes(node,code=""):
	if node.left == None:
		print node.char," : ",code
	else:
		print_codes(node.left,code+"0")
		print_codes(node.right,code+"1")


def HuffmanCoding(char_vs_freq):
	items = []
	for i in range(len(char_vs_freq.items() )):
		item = Node(char_vs_freq.items()[i][1], char_vs_freq.items()[i][0])
		items.append(item)

	while len(items):
		x1 = min(items, key=lambda x: x.freq) 
		items.remove(x1)

		if len(items)==0:
			return x1

		x2=min(items, key=lambda x: x.freq) 
		items.remove(x2)

		new_node = Node(x1.freq+x2.freq,'Internal Node',x1,x2)
		items.append(new_node)



#main
char_vs_freq = { 'a':5, 'b':9, 'c':12, 'd':13, 'e':16, 'f':45 }

huffman_tree = HuffmanCoding(char_vs_freq)

print_codes(huffman_tree)
'''
Output:
f    :     0
c    :     100
d    :     101
a    :     1100
b    :     1101
e    :     111
'''
