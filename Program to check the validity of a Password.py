#https://www.naukri.com/code360/problem-of-the-day/easy

def isValid(str):
    # Write your code here.
    if len(str)<8 or len(str)>15:
        return False
    digit=0
    lower=0
    upper=0
    special=0
    for i in str:
        if i==' ':
            return False
        elif digit==1 and lower==1 and upper==1 and special==1:
            pass
        else:
            if ord(i)>=48 and ord(i)<=58:
                digit=1
            elif ord(i)>=97 and ord(i)<=97+26:
                lower=1
            elif ord(i)>=65 and ord(i)<=65+26:
                upper=1
            else:
                special=1
    if digit==1 and lower==1 and upper==1 and special==1:
        return True
    return False
