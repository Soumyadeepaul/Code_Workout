#https://www.naukri.com/code360/problems/binary-search_972

def search(nums: [int], target: int):
    # write your code logic !!
    if len(nums)==1 and nums[0]!=target:
        return -1
    mid=len(nums)//2
    if nums[mid]==target:
        return mid
    else:
        if target<nums[mid]:
            i=search(nums[:mid],target)
            if i==-1:
                return -1
            else:
                return i
        else:
            i=search(nums[mid:],target)
            if i==-1:
                return -1
            else:
                return mid+i

    return -1
