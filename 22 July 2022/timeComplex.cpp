#include<iostream>
using namespace std;
/*
O(1)
-Algorithms that take the same amount of time to compute regardless of the input size.
*/
string isEvenOrOdd(int n) {
  return n % 2 ? "Odd" : "Even";
}

/*
O(n) - Linear time
Linear running time algorithms are widespread. These algorithms imply that the program visits every element from the input.

Examples of linear time algorithms:
    -Get the max/min value in an array.
    -Find a given element in a collection.
    -Print all the values in a list.
    -Linear Search
*/
int linearSearch(int arr[],int val){
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

/*
O(n^2) - Quadratic time
    -A function with a quadratic time complexity has a growth rate of n2. If the input is size 2, it will do four operations. If the input is size 8, it will take 64, and so on.

Examples of quadratic algorithms:
    -Check if a collection has duplicated values.
    -Sorting items in a collection using bubble sort, insertion sort, or selection sort.
    -Find all possible ordered pairs in an array.
    -Sorting(Bubble Sort, Selection Sort,Insertion Sort..)
*/
void bubbleSort(int arr[]){
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){   // n + 1
        for(int j=0;j<n;j++){   // n (n + 1)
            if(arr[i]>arr[j]){  //n * n
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j]= tmp;
            }
        }
    }
}
/*
O(log n) - Logarithmic time
    -Logarithmic time complexities usually apply to algorithms that divide problems in half every time.
Example:-
    - Binary Search
        -->The binary search algorithm slit n in half until a solution is found or the array is exhausted.  So, using the Master Method:
        T(n) = a T(n/b) + f(n)
*/

int binarySearch(int arr[],int l,int r,int val){
    if(r>=l){
        int mid = (l+r)/2;

        if(mid == val){
            return mid;
        }

        //If element is smaller than mid, then it can only be present in left subarray
        if(arr[mid]>val){
            return binarySearch(arr,l,mid-1,val);
        }


        //Else the element can only be present in right subarray
        if(arr[mid] < val){
            return binarySearch(arr,mid+1,r,val);
        }
    }
    //We reach here when element is not present in array
    return -1;
}

/*
O(n log n) - Linearithmic
    -The factor of 'log n' is introduced by bringing into consideration Divide and Conquer. Some of these   algorithms are the best optimized ones and used frequently.

Examples:-
    -Merge Sort
    -Heap Sort
    -Quick Sort
    -Certain Divide and Conquer Algorithms based on optimizing O(n^2) algorithms
*/

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[],int l,int r){
    int pivot = arr[r]; // pivot as last index.
    int i = (l - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = l; j <= r - 1; j++) { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}
void quickSort(int arr[], int l, int r) 
{ 
    if (l<r) { 
        // pi is partitioning index, arr[p] is now at right place 
        int pi = partition(arr, l, r); 
  
        // Separately sort elements before partition and after partition 
        quickSort(arr, l, pi - 1); 
        quickSort(arr, pi + 1, r); 
    } 
} 

/*
O(2^N)
    - O(2^N) denotes an algorithm whose growth doubles with each addition to the input data set. 
    - The growth curve of an O(2^N) function is exponential - starting off very shallow, then rising   meteorically. 
    An example of an O(2^N) function is the recursive calculation of Fibonacci numbers-
*/
int fibonacci (int number){
    if (number <= 1) 
        return number;
    return Fibonacci(number - 2) + Fibonacci(number - 1);
}

/*
O(n!) time
    - Solving the traveling salesman problem via brute-force search
    - generating all unrestricted permutations of a partially ordered set;
    - finding the determinant with Laplace expansion
    - enumerating all partitions of a set
*/




