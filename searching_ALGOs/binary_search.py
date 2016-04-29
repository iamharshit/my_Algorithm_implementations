def binary_search(li,item):
    start=0
    end=len(li)-1
    while start<=end:
        mid=int((start+end)/2)
        if li[mid]==item:
            return mid
        elif li[mid]>item:
            end=mid-1
        else:
            start=mid+1
            
    return -1
    
my_list=[12,24,39,44,56]
index_of_item=binary_search(my_list,44)
