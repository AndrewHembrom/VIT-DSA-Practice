#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int l, int h)
{
	while (l <= h) {
	    int mid = l+(h-l)/2;
		if (arr[mid] == key){
			return mid;
		}
		if (arr[mid] < key){
			l = mid + 1;
		}
		else{
			h = mid - 1;
		}
	}
	return -1;
}

int main(void)
{   
    int size;
    cin>>size;
	int arr[size];
	for(int i=0; i<size;i++){
	    cin>>arr[i];
	}
	int key;
	cin>>key;
	int tc;
	int result = binarySearch(arr, key, 0, size-1);
	
    if(result!=-1){
        for(int i=0;i<size;i++){
            if(arr[i]==result){
                tc=i+1;
                break;
            }
        }
    }
    else{
        tc = (size-1)/2;
    }

	
	cout<<result<<endl;
	cout<<tc<<endl;
	return 0;
}