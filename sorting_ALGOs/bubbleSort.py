# Time Complexity=O(n^2)
# Space Complexity=O(1)

def bubble_sort(l):
    for i in range(1,len(l)):
       last=len(l)-i
       for j in range(1,last+1):
           if(l[j-1]>l[j]): l[j-1],l[j]=l[j],l[j-1]
        
li=[4,3,26,7,1]
bubble_sort(li)
