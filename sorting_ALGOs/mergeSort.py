# Time Complexity = O(nlog(n)) 
# Space Complexity = O(n)

def merge(left_l,right_l):
    new_l=[]
    i=0
    j=0
    while i<len(left_l) and j<len(right_l):
           if left_l[i]<right_l[j]:
                   new_l.append(left_l[i])
                   i+=1
           else:
                   new_l.append(right_l[j])
                   j+=1
    
    while i<len(left_l):
           new_l.append(left_l[i])
           i+=1

    while j<len(right_l):
           new_l.append(right_l[j])
           j+=1

    del left_l
    del right_l
    
    return new_l

def merge_sort(l):
    if len(l)==1: return l
    else:
           mid=len(l)/2
           left_l=l[:mid]
           right_l=l[mid:]

           left_l=merge_sort(left_l)
           right_l=merge_sort(right_l)
           
           return merge(left_l,right_l)

li=[4,3,2,1,6,7,8,44]
print merge_sort(li)
