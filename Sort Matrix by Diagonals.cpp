//https://leetcode.com/problems/sort-matrix-by-diagonals/description/?envType=daily-question&envId=2025-08-28


class Solution {
public:
    void matrixSort(vector<vector<int>>& grid,int row,int col,int size,int low){
        int key;
        int r;
        int c;
        while(row<size && col<size){
            key=grid[row][col];
            r=row-1;
            c=col-1;
            cout<<key<<endl;
            while(r>-1 && c>-1){
                if (low==1){
                    if(grid[r][c]<key){
                        grid[r+1][c+1]=grid[r][c];
                        cout<<grid[r][c]<<endl;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(grid[r][c]>key){
                        grid[r+1][c+1]=grid[r][c];
                        cout<<grid[r][c]<<endl;
                    }
                    else{
                        break;
                    }
                }
                
                r--;
                c--;
            }
            grid[r+1][c+1]=key;
            row++;
            col++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        //left to right..... insertion sort
        int size=grid.size();

        for(int col=1;col<size-1;col++){
            matrixSort(grid,1,col+1,size,0);
        }
        for(int row=0;row<size-1;row++){
            matrixSort(grid,row+1,1,size,1);
        }

        return grid;
    }
    
};
