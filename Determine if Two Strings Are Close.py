#https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=study-plan-v2&envId=leetcode-75

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        l1=len(word1)
        l2=len(word2)
        if l1!=l2: #length check
            return False
        if set(word1)!=set(word2): #same character check
            return False
        hashmap={}  #hash1
        for i in word1:
            if i not in hashmap:
                hashmap[i]=1
            else:
                hashmap[i]+=1
        hashmap2={} #hash2
        for i in word2:
            if i not in hashmap2:
                hashmap2[i]=1
            else:
                hashmap2[i]+=1
        list1=[] #store hash1 values to a list
        for i in hashmap:
            list1.append(hashmap[i])
        #check hash2 values are present in the list, if present pop
        #"uux" "uxx"
        # u:2 x:1    u:1 x:2
        #[2,1]...... as 1 and 2 both are present
        #            u convert to x:2... ans x can be converted to u:2
        for i in hashmap2.values():  #VALUES MATCHING
            for j in range(len(list1)):
                if i==list1[j]:
                    list1.pop(j)
                    break
        if list1: #if list1 value exists, return False
            return False
        return True
        
