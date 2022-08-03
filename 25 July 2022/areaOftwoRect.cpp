#include<bits/stdc++.h>
using namespace std;
int area(int r1[][2],int r2[][2]){
    int res;
    //distance for rect1
                    //Ax1   Ax2
    int x1 = abs(r1[0][0] - r1[1][0]);
                    //Ay1   Ay2
    int y1 = abs(r1[0][1] - r1[1][1]);

                //Bx1       Bx2       
    int x2 = abs(r2[0][0] - r2[1][0]);
                //By1       By2
    int y2 = abs(r2[0][1] - r2[1][1]);

                    //Ax1   Bx1             //Ax2   Bx2
    int xi = min(r1[0][0],r2[0][0]) - max(r1[1][0],r2[1][0]);

                    //Ay1   By1         //Ay2    By2 
    int yi = min(r1[0][1],r2[1][1]) - max(r1[1][1],r2[1][2]);

    res = (x1 * y1) + (x2  * y2);

    //if intersection occurs the xi and yi must be not negative
    if(xi < 0 && yi <0){
        cout<<"No Intersection occurs";
    }else{
        res = res - abs(xi * yi);
    }
    return res;//// 

}

int main(){
    int r1[2][2]={{3,4},{-3,0}};
    int r2[2][2]= {{9,3},{0,-1}};

    cout<<area(r1,r2);
}