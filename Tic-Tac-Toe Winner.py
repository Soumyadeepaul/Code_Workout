#

from os import *
from sys import *
from collections import *
from math import *

def ticTacToeWinner(moves, n):

    # Write your code here
    xcol={}
    xrow={}
    ocol={}
    orow={}
    player1=1
    grid=[[''for _ in range(3)]for _ in range(3)]
    for i,j in moves:
        if player1==1:
            if i in xrow:
                xrow[i]+=1
            else:
                xrow[i]=1
            if xrow[i]==3:
                return 'player1'
            if j in xcol:
                xcol[j]+=1
            else:
                xcol[j]=1
            if xcol[j]==3:
                return 'player1'
            player1=0
            grid[i][j]='x'
        elif player1==0:
            if i in orow:
                orow[i]+=1
            else:
                orow[i]=1
            if orow[i]==3:
                return 'player2'
            if j in ocol:
                ocol[j]+=1
            else:
                ocol[j]=1
            if ocol[j]==3:
                return 'player2'
            player1=1
            grid[i][j]='o'
    ##################
    #Diagonal check
    if grid[0][0]==grid[1][1] and grid[1][1]==grid[2][2] and grid[1][1]!='':
        if grid[0][0]=='x':
            return 'player1'
        else:
            return 'player2'
    if grid[0][2]==grid[1][1] and grid[1][1]==grid[2][0] and grid[1][1]!='':
        if grid[1][1]=='x':
            return 'player1'
        else:
            return 'player2'

    if n==9:
        return 'draw'
    return 'uncertain'
