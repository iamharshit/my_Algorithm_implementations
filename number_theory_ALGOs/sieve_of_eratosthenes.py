def create_sieve(size):
    l=[1]*(size+1)
    l[0]=0
    for i in range(2,size+1):
        if l[i]==1:
            j=2
            while(i*j<=size):
                l[i*j]=0
                j+=1
    return l

size=input('Enter the sieve size: ')
sieve=create_sieve(size)
