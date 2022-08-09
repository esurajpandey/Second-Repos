import java.util.*;
public class longestIncreasingSequences {
    static void find(int mat[][],int x,int y,int prevSum){

        if(x<0 || x >= mat.length || y<0 || y>=mat[0].length){
            return;//if(out of boundary and not matched)
        }
        if(mat[x][y] == prevSum+1){
            System.out.print(mat[x][y] + " ");
            find(mat, x-1, y, prevSum);
            find(mat, x, y+1, prevSum);
            find(mat, x, y-1, prevSum);
            find(mat,x+1,y,prevSum);
        }
        //down
        // if(mat[x+1][y]+1 == prevSum){
        //     prevSum +=1;
        //     find(mat,x+1,y,prevSum);
        // }
        // //left
        // if(mat[x][y-1]+1 == prevSum){
        //     prevSum +=1;
        //     find(mat, x, y-1, prevSum);
            
        // }
        // //right
        // if(mat[x][y+1]+1 == prevSum){
        //     prevSum += 1;
        //     find(mat, x, y+1, prevSum);
            
        // }

        // //up
        // if(mat[x-1][y]+1 == prevSum){
        //     prevSum += 1;
        //     find(mat, x-1, y, prevSum);
        // }

    }
    public static void main(String[] args) {
        int mat[][] = {
            { 1, 2, 3, 4 },
            { 2, 2, 3, 4 },
            { 3, 2, 3, 4 },
            { 4, 5, 6, 7 },
        };
        int n = 4, m = 4;
        find(mat, 0, 0,0);
    }
}
