Problem: To compare Square and multiply, Binary exponent & Conventional method of multiplication.

OS - Ubuntu 18.04 LTS
Compiler - GNU g++ COmpiler
Processor: Intel core i5 : 8th Gen 


All timings are done using Chrono



Observations

Base: 3

Exponent 		No. of mul in Bin Exp		No. of mul in Sq & Mul		No. of mul in Conventional

12				6				6				12

13			        7				7				13	

14				7				7				14				

15				8				8				15



Conclusion:

From the following observations we can clearly see that the number of multiplications for Bin Exp and Sq & Mul increases very steadiely as the power increases, on the other hand the no of multiplication for convetional method takes same as the power.

Now for multiplication of large powers Bin Exp and Sq & Mul would be preffered over conventional method as they both take less number of multiplication as compared tp cpnventional one.

Also as the power is divided by 2 in Bin Exp and Sq & Mul, the time complexity would be order of O(lg n) while that of conventional would be O(n).
