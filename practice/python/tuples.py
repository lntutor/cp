# https://www.hackerrank.com/challenges/python-tuples
n = (int) (raw_input())
array = map(int, raw_input().split())
print hash(tuple(array))