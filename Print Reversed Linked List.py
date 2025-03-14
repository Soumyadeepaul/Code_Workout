#https://www.naukri.com/code360/problems/print-reversed-linked-list_564


from sys import stdin, setrecursionlimit
setrecursionlimit(10 ** 6)

#Following is the Node class already written for the Linked List
class Node :
    def __init__(self, data) :
        self.data = data
        self.next = None




def printReverse(head) :
    #Your code goes here
    arr=''
    temp=head
    while temp:
        arr=str(temp.data)+' '+arr
        temp=temp.next
    print(arr)
