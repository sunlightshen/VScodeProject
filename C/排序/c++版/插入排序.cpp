#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void insertSort(vector<int> &arr, int n){

    for(int i = 1 ; i < arr.size() ; i ++){
        for(int j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
            else
                break;
        }

    }

}

int main() {

    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    insertSort(vec,10);
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}