seq  = [0,1]
seq2 = [0,1]

total = 1
position = 9
for i in range(2,position+1):
    total = seq[i-1] 
    total += seq[i-2]
    seq.append(total)

def fib(n):
    if n <= 1:
        return seq2[n]

    if len(seq2) > n:
        return seq2[n]
    
    seq2.append(fib(n-1) + fib(n-2))
    return seq2[-1]

fib(position)
    
print(seq)
print(seq2)
