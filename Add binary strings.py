#https://www.naukri.com/code360/problem-of-the-day/easy

def addBinaryString(a, b, n, m):
    # Write your code here.
    if n<m:
        small=a
        large=b
    else:
        small=b
        large=a
    i=len(small)-1
    j=len(large)-1
    ans=''
    carry='0'
    
    while i>=0:
        if small[i]=='0' and large[j]=='0' and carry=='0':
            ans='0'+ans
            carry='0'
        elif small[i]=='0' and large[j]=='0' and carry=='1':
            ans='1'+ans
            carry='0'
        elif small[i]=='0' and large[j]=='1' and carry=='0':
            ans='1'+ans
            carry='0'
        elif small[i]=='0' and large[j]=='1' and carry=='1':
            ans='0'+ans
            carry='1'
        elif small[i]=='1' and large[j]=='0' and carry=='0':
            ans='1'+ans
            carry='0'
        elif small[i]=='1' and large[j]=='1' and carry=='0':
            ans='0'+ans
            carry='1'
        elif small[i]=='1' and large[j]=='1' and carry=='1':
            ans='1'+ans
            carry='1'
        elif small[i]=='1' and large[j]=='0' and carry=='1':
            ans='0'+ans
            carry='1'

        i-=1
        j-=1
    
    while j>=0:
        if large[j]=='0' and carry=='0':
            ans='0'+ans
        elif large[j]=='1' and carry=='0':
            ans='1'+ans
        elif large[j]=='0' and carry=='1':
            ans='1'+ans
            carry='0'
        elif large[j]=='1' and carry=='1':
            ans='0'+ans
            carry='1'
        j-=1

    if carry=='1':
        ans='1'+ans
    return ans
    
