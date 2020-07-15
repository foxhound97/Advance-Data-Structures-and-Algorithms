Problem: 7 Modifying Bubble Sort and Creating My Own Sort.

OS - Ubuntu 18.04 LTS
Compiler - GNU g++ COmpiler
Processor: Intel core i5 : 8th Gen 

-----------------------------------------------------------------------------------------------------------------------------------------------


Part A: Modifying Bubble Sort

Bubble sort : A preexsisting sorting algorithm which takes O(n^2) time to sort an array od size n.

In this question an algorithm called semibubble sort is implemented that eleminates the redundant comparisons and swaps as occured in conventional bubble sort.

In bubble sort, comaprisons are done even when array becomes sorted one.(It usually happends at later stage of the algorithm).

In semibubble sort, we have created a marker and initilized it as 0 at every iteration and increment it whenever a swap occurs in a particular interation.

If the marker remains 0 after any iteration,it means no swap occured, hence array is sorted and the loop breaks and no more comparision/swap occurs, hence reduces time as compared to bubble sort.

Comparison: Bubble sort & Semi bubble sort

Input size					Bubble Sort(Time in us)				Semi Bubble Sort(Time in us)

2500						     18323						11355

5000						     69290						37821

10000						     257043						53943
  
15000						     560199						83668


All times are measured using Chrono.

Obervation & Conclusion:

From the obove observation table, its clearly seen that the time taken by semi bubble sort is much less less than the time taken by bubbe sort to sort and unordered array. Hence we have sucessfully reduces the time taken by bubble sort by more than 2 folds in semi bubble sort.

-----------------------------------------------------------------------------------------------------------------------------------------------

Part B: My Own Sort

myownsort: In this algorithm, BST is being used in a smart way for sorting. 

We know that Inorder Traversal of BST takes O(n) time to print the elements of nodes. For BST the inorder traversal prints the elemts in acending order i.e sorted order.

A slight modification is done over this idea of inorder traverse, that is, rather than printing the elements, we have stored the elements obtained from inorder travesal to a new array. Hence that new array contains a sorted series of digits.

Its not a comparision based sorting technique.

Oservation table


Input Size	Merge Sort(Time in us)	My own sort(Time in us, Without creation)   My own sort (With creation of BST) 
10000			2832				637				15048					

20000                   5894				1387				30245					

40000			12367				2704				159970					

80000			25754				5658				691430


Observation & COnclusion:

It can be seen that the myown sort varies in a linear fashion. Hence O(n) is the time complexity for My own sort WHEN CREATION OF BST IS NOT TAKEN IN ACCOUNT.

The time taken for creation of BST involves creation of link list and comparing each node before insertion of a node, i.e O(n^2). Hence the time for sorting becomes high when creation is taken into account.






