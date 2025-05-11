#https://www.naukri.com/code360/problems/roman-number-to-integer_981308

def romanToInt(s:str) -> int:
    # Write your code here
    summ=0
    dic={'I':1,'IV':4,'V':5,'IX':9,'X':10,'XL':40,'L':50,'XC':90,'C':100,'CD':400,'D':500,'CM':900,'M':1000}
    i=0
    while i<len(s):
        if i+1 !=len(s):
            if s[i]+s[i+1] in dic:
                summ+=dic[s[i]+s[i+1]]
                i+=2
            else:
                summ+=dic[s[i]]
                i+=1
        else:
            summ+=dic[s[i]]
            i+=1
    return summ
