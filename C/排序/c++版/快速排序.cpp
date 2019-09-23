#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*体现基本的分支思想*/
void quickSort(vector<int> &arr, int l,int r){
    int i=l;
    int j=r+1;
    int mid;
    if(l<r)
    {
        while (1)
        {
            do i++;
            while (arr[i]<arr[l]&&i!=l);
            do j--;
            while (arr[j]>arr[l]&&j!=r);
            if(i<j)
                swap(arr[i],arr[j]);
            else
            {
                mid=j;
                break;
            }
        }
        swap(arr[l],arr[mid]);
        quickSort(arr,l,mid-1);
        quickSort(arr,mid+1,r);
    }

}

int main() {

    int a[10] = {1,9,8,7,6,5,4,3,2,10};
    vector<int> vec(a,a+sizeof(a)/sizeof(int));
    quickSort(vec,0,9);
    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}