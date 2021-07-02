import sys

num_a, num_b = map(int, sys.stdin.readline().split())

arr_a = set(map(int, sys.stdin.readline().split())) 
arr_b = set(map(int, sys.stdin.readline().split())) 

print(len(arr_a-arr_b)+len(arr_b-arr_a))
