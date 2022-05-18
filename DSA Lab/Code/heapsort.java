/*
    heap : a complete binary tree that satisfies heap's property
    max heap's property: the children nodes are smaller than root
    min heap's property: the children nodes are greater than root
    in the last level of complete binary tree, preference must be given to left side
    heap is created to represent it as array
    if the current node's index is i, then to calculate:
        parent's index = (i/2)
        left child = 2 * i + 1
        right child = 2 * i + 2
        height of the tree is logn

    Time complexity of heapify is O(Logn). 
    Time complexity of createAndBuildHeap() is O(n) 
    And, hence the overall time complexity of Heap Sort is O(nLogn).
    1. Convert unsorted array into max heap using heapify function

*/

import java.util.Scanner;


public class heapsort {
	
	void heapify(int arr[], int n, int i)
	{
		int largest = i; 
		int left = 2 * i + 1; 
		int right = 2 * i + 2; 

		// If left child is larger than root
		if (left < n && arr[left] > arr[largest])
			largest = left;

		// If right child is larger than largest so far
		if (right < n && arr[right] > arr[largest])
			largest = right;

		// If largest is not root
		if (largest != i) {
			int swap = arr[i];
			arr[i] = arr[largest];
			arr[largest] = swap;

			// Recursively heapify the affected sub-tree
			heapify(arr, n, largest);
		}
	}

    public void sort(int arr[])
	{
		int n = arr.length;

		// Build heap (rearrange array)
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);

		// One by one extract an element from heap
		for (int i = n - 1; i > 0; i--) {

			// Move current root to end
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;

			// call max heapify on the reduced heap
			heapify(arr, i, 0);
		}
	}

    void printArray(int arr[])
    {
        for (int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

	public static void main(String args[])
	{

		heapsort h = new heapsort();
        Scanner sc = new Scanner(System.in);
        
        System.out.println("MENU");
        System.out.println("1. Input ");
        System.out.println("2. Sort ");
        System.out.println("3. Print");

        System.out.println("Enter the number of elements: ");
        int no = sc.nextInt();
        int heap[] = new int[no];

        for (int i = 0; i < no; i++) {
            System.out.print("Enter element: ");
                heap[i] = sc.nextInt();
        }

        h.sort(heap);

        System.out.println("Heap sorted array: ");
        h.printArray(heap);

        
    }
}
