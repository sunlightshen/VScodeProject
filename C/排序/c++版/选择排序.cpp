#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr, int n){

    for(int i = 0 ; i < arr.size() ; i ++){
        // 寻找[i, n)区间里的最小值
        int minIndex = i;
        for( int j = i + 1 ; j < arr.size() ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }

}

int main() {

    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    selectionSort(vec,10);
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}