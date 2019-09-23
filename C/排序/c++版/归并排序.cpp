#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*分治思想*/
void merge(vector<int> &arr, int l, int mid, int r){

    int aux[r-l+1];

    for( int i = l ; i <= r; i ++ )
        aux[i-l] = arr[i];

    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

        if( i > mid ){  
            arr[k] = aux[j-l]; j ++;
        }
        else if( j > r ){  
            arr[k] = aux[i-l]; i ++;
        }
        else if( aux[i-l] < aux[j-l] ) {  
            arr[k] = aux[i-l]; i ++;
        }
        else{  
            arr[k] = aux[j-l]; j ++;
        }
    }
}
void mergeSort(vector<int> &arr, int l,int r){
    if(l>r)
        return;
    int mid =l+(r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);

}

int main() {

    int a[10] = {1,9,8,7,6,5,4,3,2,10};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    mergeSort(vec,0,9);
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}