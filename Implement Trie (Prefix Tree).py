#https://leetcode.com/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=leetcode-75

class Node:
    def __init__(self):
        self.children={}
        self.endofWord=False
class Trie:

    def __init__(self):
        self.root=Node()
    def insert(self, word: str) -> None:
        curr=self.root

        for w in word:
            if w not in curr.children:
                curr.children[w]=Node()
            curr=curr.children[w]
        curr.endofWord=True

    def search(self, word: str) -> bool:
        curr=self.root

        for w in word:
            if w not in curr.children:
                return False
            curr=curr.children[w]
        if curr.endofWord==True:
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        curr=self.root
        for w in prefix:
            if w not in curr.children:
                return False
            curr=curr.children[w]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
