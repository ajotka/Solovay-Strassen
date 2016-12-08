Solovay-Strassen Prime Test C++<br />
Visual Studio 2015<br />
<br />
Input:<br />
> ss.exe n i <br />
<br />
n - number to check<br />
i - how many operation (iterator)<br />
<br />
NWD(a,p)=1<br />
a^(p-1)= 1 mod p<br />
<br />
Check: n<br />
Algorithm:<br />
&ensp;1) Rand 0 < a < n <br />
&ensp;2) Check a^((n-1)/2) = (a | n) <- Legender Symbol<br />
&ensp;&ensp;true: n - prime number<br />
&ensp;&ensp;false: n - not<br />
&ensp;===========================================* probability 1/4<br />
&ensp;Return:<br />
&ensp;&ensp; 0 - prime<br />
&ensp;&ensp; 1 - not<br />
