#https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/?envType=study-plan-v2&envId=top-interview-150

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:



        def tree(root,leftArr,rightArr):
            if len(leftArr)!=0:
                l=len(leftArr)
                mid=l//2
                node=TreeNode(leftArr[mid])
                root.left=node
                tree(root.left,leftArr[:mid],leftArr[mid+1:])
            if len(rightArr)!=0:
                l=len(rightArr)
                mid=l//2
                node=TreeNode(rightArr[mid])
                root.right=node
                tree(root.right,rightArr[:mid],rightArr[mid+1:])


        l=len(nums)
        mid=l//2
        root=TreeNode(nums[mid])
        tree(root,nums[:mid],nums[mid+1:])
        return root
        
