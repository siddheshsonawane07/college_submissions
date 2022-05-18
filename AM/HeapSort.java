/*
*  *
* Use Java-14 To run 😎
* This is Generic Heap Sort Program demostrate -
*   Integer Heap Sort
*   Character Heap Sort
*   Double Heap Sort
*   String Heap Sort
* */

// // Heap Sort Class using T data type as place holder and extends Comparable Class to compare two generic class
// public class HeapSort<T extends Comparable<T>> {

//     private T data[];
//     private int length;

//     HeapSort(T data[]) {
//         this.data = data;
//         this.length = this.data.length;
//     }

//     public T[] buildMaxHeap(T[] tempData) {
//         for(int i = (int) Math.floor(length/2); i >= 0 ; i--) {
//             tempData = heapify(tempData, i);
//         }
//         return tempData;
//     }

//     public T[] heapify(T[] tempData, int node) {
//         int leftNode = node*2+1;
//         int rightNode = node*2+2;

//         int maxNode = node;

//         if(leftNode < length) {
//             if(tempData[leftNode].compareTo(tempData[maxNode]) > 0){
//                 maxNode = leftNode;
//             }
//         }

//         if(rightNode < length) {
//             if((tempData[rightNode].compareTo(tempData[maxNode])) > 0) {
//                 maxNode = rightNode;
//             }
//         }

//         if(maxNode != node) {
//             T temp = tempData[node];
//             tempData[node] = tempData[maxNode];
//             tempData[maxNode] = temp;
//             tempData = heapify(tempData, maxNode);
//         }
//         return tempData;
//     }

//     public void sort(){
//         this.data = buildMaxHeap(this.data);
//         while(length > 0) {
//             this.length--;

//             T temp = this.data[0];
//             this.data[0] = this.data[length];
//             this.data[length] = temp;

//             this.data = heapify(this.data, 0);
//         }
//     }

//     public void printData() {
//         for(T i : this.data) {
//             System.out.print(i + " ");
//         }
//         System.out.println();
//     }

//     public static void main(String[] args) {
//         /* Sorting Integer Data using Heap Sort */
// //        Integer[] dataToBeSorted = {2, 8, 5, 3, 9, 1};
// //        HeapSort heapSort = new HeapSort<Integer>(dataToBeSorted);

//         /* Sorting Double Data using Heap Sort */
// //        Double[] dataToBeSorted = {1.2, 4.3, 6.7, 7.1, 3.9};
// //        HeapSort heapSort = new HeapSort<Double>(dataToBeSorted);

//         /* Sorting Character Data using Heap Sort */
// //        Character[] dataToBeSorted = {'b', 'a', 'z', 'v', 'T'};
// //        HeapSort heapSort = new HeapSort<Character>(dataToBeSorted);

//         /* Sorting String Data using Heap Sort */
//         String[] dataToBeSorted = {"lalu", "vivek", "kia", "priya", "jui"};
//         HeapSort heapSort = new HeapSort<String>(dataToBeSorted);

//         System.out.println("Given Data - ");
//         heapSort.printData();

//         heapSort.sort();

//         System.out.println("Sorted Data - ");
//         heapSort.printData();
//     }
// }

import java.io.*;
import java.util.*;
public class heapsort {
 public int[] heap;
 public int count;
 public void downadjust(int i) {
 int j, temp, n;
 n = heap[0];
 if (2 * i <= n) {
 j = 2 * i;// j on left child of i
 if (j + 1 <= n && heap[j + 1] > heap[j]) // j points to larger of left and right child
 j = j + 1;
 if (heap[i] < heap[j]) {
 temp = heap[i];
 heap[i] = heap[j];
 heap[j] = temp;
 downadjust(j);
 }
 }
 }
 public void upadjust(int i) {
 int temp;
 while (i > 1 && heap[i] > heap[i / 2]) {
 temp = heap[i];
 heap[i] = heap[i / 2];
 heap[i / 2] = temp;
 i = i / 2;
 }
 }
 public void insert(int x) {
 heap[++heap[0]] = x;
 upadjust(heap[0]);
 }
 public void create() {
 int i, x, n;
 heap = new int[30];
 heap[0] = 0;
 Scanner reader = new Scanner(System.in);
 System.out.println("\nEnter No. of elements : ");
 n = reader.nextInt();
 count = n;
 System.out.println("\nEnter heap data : ");
 for (i = 0; i < n; i++) {
 x = reader.nextInt();
 insert(x);
 }
 }
 public void sort() {
 int last, temp;
 while (heap[0] > 1) {
 last = heap[0];
 temp = heap[1];
 heap[1] = heap[last];
 heap[last] = temp;
 heap[0]--;
 downadjust(1);
 }
 }
 public void print() {
 int n, i;
 n = count;
 System.out.println("\nsorted data : ");
 for (i = 1; i <= n; i++)
 System.out.print(" " + heap[i]);
 }
 public static void main(String[] args) {
 int x;
 heapsort myobject = new heapsort();
 myobject.create();
 myobject.sort();
 myobject.print();
 }
}
