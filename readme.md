Solovay-Strassen Prime Test C++
Visual Studio 2015

Input:
> ss.exe n i 

n - number to check
i - how many operation (iterator)

NWD(a,p)=1
a^(p-1)= 1 mod p

Check: n
Algorithm:
	1) Rand 0 < a < n 
	2) Check a^((n-1)/2) = (a | n) <- Legender Symbol
		true: n - prime number
		false: n - not
	===========================================* probability 1/4
	return: 0 - prime
			1 - not