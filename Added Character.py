#

from os import *
from sys import *
from collections import *
from math import *

def findAddedCharacter(s, t):
    # Write your code here.
 hashmap={}
 for i in s:
  if i not in hashmap: 
   hashmap[i]=1
  else:
   hashmap[i]+=1
 for i in t:
  if i not in hashmap:
   return i
  else:
   hashmap[i]-=1
   if hashmap[i]==-1:
    return i


# Main.
test = int(input())
for x in range(test):
	s = input()
	t = input()
	print(findAddedCharacter(s, t))
