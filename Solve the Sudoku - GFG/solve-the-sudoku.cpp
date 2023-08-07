//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution
{
public:
  bool getCell(int grid[N][N],int &i,int &j){
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(grid[i][j]==0)
                return true;
            }
        }
        return false;
    }
    bool valid(int grid[N][N],int row,int col,int num){
        for(int i=0;i<9;i++){
            if(grid[row][i]==num)
            return false;
            
           if(grid[i][col]==num)
            return false;
        }
        
        int rf=(row/3)*3;
        int cf=(col/3)*3;
        
        for(int i=rf;i<rf+3;i++){
            for(int j=cf;j<cf+3;j++){
                if(grid[i][j]==num)
                return false;
            }
        }
        return true;
        
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        int row,col;
        if(!getCell(grid,row,col)){
            return true;
        }
        for(int i=1;i<=9;i++){
            if(valid(grid,row,col,i)){
                grid[row][col]=i;
                if(SolveSudoku(grid))
                return true;
                grid[row][col]=0;
            }
        }
        return false;
    }
    
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends