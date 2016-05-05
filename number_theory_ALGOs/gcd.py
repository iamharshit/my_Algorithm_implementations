#Implemention is based on Euclid's Algorithm

def order(a,b):
    if a<b: return a,b
    else: return b,a
    
def gcd(x,y):
    if y%x==0: return x
    else: return gcd(y%x,x)
    
a,b=input('Enter the no.s sepreated by commas: ')
a,b=order(a,b)

print 'gcd: %d' % gcd(a,b)
