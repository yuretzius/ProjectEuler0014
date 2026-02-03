#from tqdm import trange
from time import perf_counter

def Collatz(n):
  length = 1
  while n > 1:
    if n%2 == 0:
      n = n//2
    else:
      n = 3*n+1
    length += 1
    # if n > 1: print(n, end = ',')
    # else: print(n)
  return length


start = perf_counter()
max_collatz = 0
max_num = 0
for n in range(1,1000000):
#for n in trange(1,1000000):
  l = Collatz(n)
  if l > max_collatz:
    max_collatz = l
    max_num = n

end = perf_counter()
print(max_num, max_collatz) # 837799 525
print(end - start,'sec')

# 0.421462 sec with pypy
# 24.7589382 sec with python

print(chr(3),chr(3),chr(3),chr(1),chr(2),chr(1),chr(3),chr(3),chr(3),chr(7),chr(7),chr(7)) # beep!
