//To build the heap in input array to minimise space complexity
#include<iostream>
using namespace std;

void inplaceHeapSort(int pq[],int n)
{
    //assuming 0th element sorted
    for(int i = 1; i < n; i++)
    {
        //insert ith element in heap
        int childIndex = i;

            while (childIndex > 0)
            {
                int parentIndex = (childIndex - 1) / 2;

                if (pq[childIndex] < pq[parentIndex])
                {
                    int temp = pq[childIndex];
                    pq[childIndex] = pq[parentIndex];
                    pq[parentIndex] = temp;
                }
                else
                {
                    break;
                }

                childIndex = parentIndex;
            }
    }


            //Remove lements
            int size = n;
            while(size > 1)
            {
            int temp = pq[0];
            pq[0] = pq[size-1];
            pq[size-1] = temp;
            //swap first then down heapify
            size--;
            //size is decreased

            //perform down heapify
            //  if (isEmpty())
            //     {
            //         return 0;
            //     };
                //down heapify
                int parentIndex = 0;
                int leftChildIndex = 2*parentIndex + 1;
                int rightChildIndex = 2*parentIndex + 2;
                while(leftChildIndex < size){
                int minIndex = parentIndex;
                    if(pq[minIndex] > pq[leftChildIndex])
                    {
                        minIndex = leftChildIndex;
                    }
                    if(rightChildIndex < size && pq[minIndex] > pq[rightChildIndex]){
                        minIndex = rightChildIndex;
                    }
                    if(parentIndex == minIndex)
                    {
                        break;
                    }
                    int temp = pq[minIndex];
                    pq[minIndex] = pq[parentIndex];
                    pq[parentIndex] = temp;

                    parentIndex = minIndex;
                    leftChildIndex = 2 * parentIndex + 1;
                    rightChildIndex = 2 * parentIndex + 2;
                }
            
    }
    
}
int main()
{
    int input[]= {5,1,2,0,8};
    inplaceHeapSort(input,5);
    for(int i = 0 ;i < 5 ; i++)
    {
        cout<<input[i]<<" ";
    }
}