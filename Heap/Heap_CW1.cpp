#include <iostream>
using namespace std;

class Heap{ // Max Heap
  public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity){
      this->arr = new int[capacity];
      this->capacity = capacity;
      this->size = 0; // Current elements in Heap
    }

    void insert(int value){ // TC: O(LogN) // Since this is a complete binary tree, it's height is LogN
      if(size==capacity){
        cout<<"Overflow"<<endl;
        return;
      }

      // Increase the size and insert the value (increase first as we will be using 1 based indexing)
      size++;
      int index = size;
      arr[index] = value;

      // Check and take the value to it's correct position
      while(index>1){ // Following 1-Based Indexing
        int parentIndex = index/2;
        
        if(arr[index]>arr[parentIndex]){
          swap(arr[index],arr[parentIndex]);
          index = parentIndex;
        }
        else{
          break;
        }
      }
    }

    int deleteHeapVal(){ // TC: O(LogN) // Since this is a complete binary tree, it's height is LogN
      // Now, we can only delete from root node
      int answer = arr[1];

      // Now, place last element at the root place
      arr[1] = arr[size];
      size--;

      int index = 1; 
      // Check and take the root value to it's correct position
      while(index<size){
        int leftIndex = 2*index;
        int rightIndex = 2*index + 1;
        
        int maxIndex = index;

        if(leftIndex <=size && arr[maxIndex]<arr[leftIndex]){
          maxIndex = leftIndex;
        }
        if(rightIndex <=size && arr[maxIndex]<arr[rightIndex]){
          maxIndex = rightIndex;
        }

        if(index==maxIndex){ // Means no change
          break;
        } 
        else{
          swap(arr[index],arr[maxIndex]);
          index = maxIndex;
        }
      }

      return answer;
    }

    void printHeap(){
      for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
      }
    }

    ~Heap(){
      delete arr;
    }

};

void heapify(int *arr, int size, int index){ // V.IMP
  // Recursive Method
  int leftIndex = 2*index;
  int rightIndex = 2*index + 1;
  int maxIndex = index;

   // Finding out the max of the above three indexes
   if(leftIndex <= size && arr[maxIndex]<arr[leftIndex]){
    maxIndex = leftIndex;
   }
   if(rightIndex <= size && arr[maxIndex]<arr[rightIndex]){
    maxIndex = rightIndex;
   }

   if(maxIndex!=index){
    swap(arr[maxIndex],arr[index]);
    index = maxIndex;

    // Now, the rest will be handeled by recursion
    heapify(arr,size,index);
   }

}

void buildHeap(int arr[],int size){
  // All leaf nodes of a CBT lie betweeen (n/2 + 1) and n, where n is the size of CBT

  for(int index = size/2;index>0;index--){ // Since all leaf nodes are valid heaps, we do not process them
    heapify(arr,size,index);
  }
}

void HeapSort(int arr[],int size){ // TC: O(NLogN)
  // Insert root element at the last and then heapify the first element.

  while(size!=1){
    swap(arr[1],arr[size]); // 1-based indexing hai isliye swap with size, not (size-1)
    size--;
    heapify(arr,size,1);
  }

}

int main() {
  int arr[] = {-1,5,10,15,20,25,12}; // Basically, since we are using 1-based indexing, we put dummy value at 0th index
  int n = 6;

  buildHeap(arr,n);
  cout<<"Current Heap : ";
  for(int i = 1;i<=n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  HeapSort(arr,n);
  cout<<"Sorted Heap : ";
  for(int i = 1;i<=n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  cout<<"-------------------------------"<<endl;

  Heap h(10);
  h.insert(10);
  h.insert(20);
  h.insert(5);
  h.insert(11);
  h.insert(6);

  cout<<"Current Heap : ";
  h.printHeap();
  cout<<endl;
  int ans = h.deleteHeapVal();
  cout<<"Deleting from Heap : "<<ans<<endl;
  cout<<"Current Heap : ";
  h.printHeap();
  cout<<endl;
  int ans2 = h.deleteHeapVal();
  cout<<"Deleting from Heap : "<<ans2<<endl;
  cout<<"Current Heap : ";
  h.printHeap();
  cout<<endl;

  cout<<"-------------------------------"<<endl;

  return 0;
}