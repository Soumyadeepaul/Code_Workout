#https://www.naukri.com/code360/problems/partition-equal-subset-sum_892980


def canPartition(arr, n):
    # Write your code here.
    
    #subset sum problem when sum=sum(arr)/2 -> only in case of even sum

    total=sum(arr)
    if (total & 1):  #if odd
        return False
    
    equal=total//2
    #arr=sorted(arr)
    dp=[[False for _ in range(equal+1)] for _ in range(n+1)]

    for i in range(1,n+1):
        for j in range(1,equal+1):
            if arr[i-1]==j:
                dp[i][j]=True
            elif j<arr[i-1]:
                dp[i][j]=dp[i-1][j]
            else:
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i-1]])
    # for i in dp:
    #     print(i)
    return dp[n][equal]
