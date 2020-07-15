Problem: 1 Merge Sort Analysis.

OS - Ubuntu 18.04 LTS
Compiler - GNU g++ COmpiler
Processor: Intel core i5 : 8th Gen 
----------------------------------------------------------------------------------------------------------------------------------------------

All timings are done using Chrono

-----------------------------------------------------------------------------------------------------------------------------------------------

Observations



1) Average Case:

* Data set used = 10,000

1.a) Number of swaps (Theoritical): We cant comment on the number of swaps in average case in terms of asymptotic analysis as its bit difficult to find it for large set of inputs but its cleat that the number of swaps in average case, best case and worst case are all equal for same input set.

1.b) Number of swaps (Empirical): 182294

1.c) Time Taken: 5667.57 Microsec



2) Best Case:


2.a) Number of swaps (Empirical) : 182294

-----------------------------------------------------------------------------

2.a) Time Taken (Theoritical) = O(nlgn) = K.nlgn+c  where K and C are positive real constants.

2.b) Time Taken (Empirical) 

	n=10,000 ; Time(us)=1472.73
	n=20,000 ; Time(us)=3044.63
	n=40,000 ; Time(us)=6200.30
	n=80,000 ; Time(us)=7712.34

As observed from above table. the Time imcreases in nlgn fashion as the input increases. Hence the theoritical and my own empirical analysis are in sync.



3) Worst Case:

3.a) Number of swaps (Empirical): 182294

-------------------------------------------------------------------------------

3.a) Time Taken (Thoeritical) = O(nlgn)

3.b) Time Taken (Empirically) 

	n=10,000 ; Time(us)= 1326.43
	
	
Conclusion: One interesting observation can be made from the observation set is that the time for avg case is > time for worst/best case. Why ?

The reason is, in worst or best case, one complete array gets exhausted first and then the reamining half array is copied as it is. But in average case it may be possible that the number of comparisons is more.






