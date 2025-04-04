#https://www.naukri.com/code360/problems/minimum-jumps_1062693

def minimumJumps(arr, n):
    #SIMILAR TO LONGEST INCREASING SUBSEQUENCE
    # write your code here
    dp=[0 for _ in range(n)]


    for i in range(n):
        for j in range(0,i):
            #from the j can it reach i?
            if arr[j]+j>=i:
                #if dp[j]==-1 means that j was not able to reach
                if dp[i]==0 and dp[j]!=-1:
                    dp[i]=dp[j]+1
                else:
                    dp[i]=min(dp[i],dp[j]+1)
        #if after looping value remains 0 means cant be reached in that index
        if dp[i]==0 and i!=0:
                dp[i]=-1
    return dp[n-1]
