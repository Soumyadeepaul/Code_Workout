#https://leetcode.com/problems/search-suggestions-system/?envType=study-plan-v2&envId=leetcode-75

class Trie:
    def __init__(self):
        self.child={}
        self.strings=[]
class Solution:
    def __init__(self):
        self.node=Trie()
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products=sorted(products)

        for i in products:
            curr=self.node #always start from start
            for j in i:
                if j not in curr.child:
                    curr.child[j]=Trie()
                curr=curr.child[j]
                if len(curr.strings)<3:
                    curr.strings.append(i)

        result=[[] for _ in searchWord]
        curr=self.node
        j=0
        for i in searchWord:
            if i in curr.child:
                curr=curr.child[i]
                result[j]=curr.strings
                j+=1
            else:
                break
        return result
