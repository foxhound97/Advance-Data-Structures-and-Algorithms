Problem 1: To perform INSERTION on a given large set of data.

OS - Ubuntu 18.04 LTS
Compiler - GNU g++ COmpiler
Processor: Intel core i5 : 8th Gen 

-----------------------------------------------------------------------------------------------------------------------------------------------

All timings are done using Chrono

-----------------------------------------------------------------------------------------------------------------------------------------------



Observations



1) Average Case:

* Data set used = 10,000

1.a) Number of swaps (Theoritical): We cant comment on the number of swaps in average case in terms of asymptotic analysis as its bit difficult to find it for large set of inputs but its cleat that the number of swaps in average case must be lesser than the number of swaps in worst case i.e O(n^2). [where n is number of data points]

1.b) Number of swaps (Empirical): 12621923 < (10,000)^2

1.c) Time Taken: 0.0828453 



2) Best Case:

2.a) Number of swaps (Theoritical): 0, as only comparisons will be there for (n-1) elements.

2.b) Number of swaps (Empirical) : 0

-----------------------------------------------------------------------------

2.a) Time Taken (Theoritical) = O(n) = K.n + c; where K & C are some real positive constants.

2.b) Time Taken (Empirical) 

	n=10,000 ; Time(us)=50.669
	n=20,000 ; Time(us)=70.055
	n=30,000 ; Time(us)=105.182
	n=40,000 ; Time(us)=140.819
	n=50,000 ; Time(us)=175.636

As observed from above table. the Time imcreases in linear fashion as the input increases. Hence the theoritical and my own empirical analysis are in sync.



3) Worst Case:

3.a) Number of swaps (Theoritical): O(n^2)

3.b) Number of swaps (Empirical): 49991700 (for n=10,000)

-------------------------------------------------------------------------------

3.a) Time Taken (Thoeritical) = O(n^2)

3.b) Time Taken (Empirically) 

	n=10,000 ; Time(us)= 153975
	n=20,000 ; Time(us)= 599188
	
As senn from above observations, as our input set doubles the time taken is approximately (due to presence of constants) quadrapules. Hence both a-priori and a-posteriority analysis are in sync.


Conclusion: Its verified that the time taken & Swaps are in best<average<worst order, both theoritically as well as practically.






