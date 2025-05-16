#https://leetcode.com/problems/total-cost-to-hire-k-workers/?envType=study-plan-v2&envId=leetcode-75

from heapq import heapify,heappop,heappush
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:

        #TLE

        # result=0
        # while k!=0:
        #     if len(costs)>=candidates:
        #         newArr=[]
        #         lastidx=0
        #         for i in range(candidates):
        #             newArr.append([costs[i],i])
        #             lastidx=i
        #         for i in range(1,candidates+1):
        #             if len(costs)-i==lastidx:
        #                 break
        #             newArr.append([costs[-i],len(costs)-i])
        #     else:
        #         newArr=[]
        #         for i in range(len(costs)):
        #             if i>=candidates:
        #                 break
        #             newArr.append([costs[i],i])
        #     heapify(newArr)
        #     value=heappop(newArr)
        #     costs.pop(value[1])
        #     result+=value[0]
        #     k-=1
        # return result
        ##########################################################
        # result=0
        # while k!=0:
        #     if len(costs)>=candidates:
        #         newArr=[]
        #         lastidx=0
        #         for i in range(candidates):
        #             newArr.append([costs[i],i])
        #             lastidx=i
        #         for i in range(1,candidates+1):
        #             if len(costs)-i==lastidx:
        #                 break
        #             newArr.append([costs[-i],len(costs)-i])
        #     else:
        #         newArr=[]
        #         for i in range(len(costs)):
        #             if i>=candidates:
        #                 break
        #             newArr.append([costs[i],i])
        #     value=min(newArr)
        #     costs.pop(value[1])
        #     result+=value[0]
        #     k-=1
        # return result
        #########################################################
        if k==len(costs):
            return sum(costs)

        leftIdx=0
        rightIdx=len(costs)-1
        newArr=[]
        if len(costs)<=candidates:
            while leftIdx!=candidates:
                newArr.append([costs[leftIdx],'left'])
                leftIdx+=1

        else:
            while leftIdx!=candidates:
                newArr.append([costs[leftIdx],'left'])
                leftIdx+=1
            
            countRight=0
            while countRight!=candidates and leftIdx<=rightIdx:
                newArr.insert(leftIdx,[costs[rightIdx],'right'])
                rightIdx-=1
                countRight+=1
        result=0
        heapify(newArr)
        while k!=0:
            ############################
            #O(n) and linear search is used to find min
            # minn=10**9+7
            # lr=''
            # idx=0
            # for n in range(len(newArr)):
            #     if newArr[n][0]<minn:
            #         minn=newArr[n][0]
            #         lr=newArr[n][1]
            #         idx=n
            # newArr.pop(idx)
            # result+=minn
            # if lr=='left':
            #     if leftIdx<=rightIdx:
            #         newArr.insert(left,[costs[leftIdx],'left'])
            #         leftIdx+=1
            # elif lr=='right':
            #     if leftIdx<=rightIdx:
            #         newArr.insert(left,[costs[rightIdx],'right'])
            #         rightIdx-=1
            ##################################
            #O(logn) and heap is used
            val=heappop(newArr)
            result+=val[0]
            if val[1]=='left' and leftIdx<=rightIdx:
                heappush(newArr,[costs[leftIdx],'left'])
                leftIdx+=1
            if val[1]=='right' and leftIdx<=rightIdx:
                heappush(newArr,[costs[rightIdx],'right'])
                rightIdx-=1
            k-=1
                
        return result
        
    ######################
    #LOGIC
    #create a new arr for candidates: keep track of left and right
    #new Arr should have element and there direction
    #heapify
    #then pop.... if the poped element if from left
    #increment leftidx + 1
    #if right..... increment rightidx+1
    #heappush
                



        
