#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    int tc=0;
    for(int step=0; step<size; ++step){
        for(int j=0; j<(size-step); ++j){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print(int arr[], int size){
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<< "\n";
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    bubbleSort(arr,size);
    print(arr,size);
    
    return 0;
}