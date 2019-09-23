#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr, int n){
    int flag=1;

    for(int i =1  ; i < arr.size() && flag ==1 ; i ++){
        flag =0;
        for( int j = 0 ; j < arr.size()-i-1 ; j ++ )
            if( arr[j] > arr[j+1] )
            {
                swap( arr[j+1] , arr[j] );
                flag =1;
            }
    }

}

int main() {

    int a[10] = {1,9,8,7,6,5,4,3,2,10};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    bubbleSort(vec,10);
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}