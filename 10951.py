import sys

while True:
    input_str = sys.stdin.readline().split()
    if len(input_str)==0:
         break
    A = int(input_str[0])
    B = int(input_str[1])
    print(A+B)

# use readline instead of input
# because of we should take care of eof of input
