#https://www.naukri.com/code360/problems/find-character-case_1115655

#Your code goes here
inp=ord(input())
print(1 if (inp>=65 and inp<=65+26) else 0 if (inp>=97 and inp<=122) else -1)
