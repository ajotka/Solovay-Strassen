/* SolovayStrassen.cpp : Poni¿szy kod s³u¿y do testowania pierwszoœci liczby metod¹ probabilistyczn¹ Solovaya - Strassena. 
*/

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>

using namespace std;

class SolovayStrassen
{
private:

	// Random 0 < a < n
	//----------------------------------------
	static boost::multiprecision::cpp_int RandomLong(boost::multiprecision::cpp_int n)	{
		srand( (unsigned int)time(NULL) );
		return( (std::rand() % n) + 0 );
	}

	// Symbol Legender'a
	//----------------------------------------
	static int L(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int n){
		if (a == 1)
			return 1;

		int result;
		if ((a & 1) == 0)	{
			result = L(a >> 1, n);
			if (((n * n - 1) & 8) != 0)
				result = -result;
		}	else	{
			result = L(n % a, a);
			if (((a - 1) * (n - 1) & 4) != 0)
				result = -result;
		}
		return result;
	}

	// NWD(a,p) = 1
	//----------------------------------------
	static boost::multiprecision::cpp_int GCD(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int p)	{
		boost::multiprecision::cpp_int r;

		while (p != 0)	{
			r = a % p;
			a = p;
			p = r;
		}

		return a;
	}

	// Szybkie potegowanie modulo: a^b mod m
	//----------------------------------------
	static boost::multiprecision::cpp_int ModExp(boost::multiprecision::cpp_int num, boost::multiprecision::cpp_int pow, boost::multiprecision::cpp_int mod) {
		boost::multiprecision::cpp_int result;
		boost::multiprecision::cpp_int n = num;
		for (result = 1; pow; pow >>= 1)	{
			if (pow & 1)
				result = ((result % mod) * (n % mod)) % mod;
			n = ((n % mod) * (n % mod)) % mod;
		}

		return result;
	}


public:

	// Funkcja sprawdzajaca
	//----------------------------------------
	static bool IsPrime(boost::multiprecision::cpp_int n, boost::multiprecision::cpp_int k)	{
		if ((n & 1) == 0)
			return false;

		for (int i = 0; i < k; i++)	{
			boost::multiprecision::cpp_int a = RandomLong(n);
			boost::multiprecision::cpp_int x = L(a, n);

			if ( x == 0 || ModExp(a, (n - 1) / 2, n) != (x + n) % n)					// a^((n-1)/2) = (a | n) <- symbol jacobiego (uogólnienie Legendera)
				return false;
		}
		return true;
	}
};




int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Podaj dwie wartosci wejsciowe n oraz i" << std::endl;
	}	else {
		boost::multiprecision::cpp_int n = 0, i = 0, rand = 0;

		std::stringstream ss;

		ss << argv[1];
		ss >> n;
		ss.str("");
		ss.clear();

		ss << argv[2];
		ss >> i;
		ss.str("");
		ss.clear();

		if (n < 2) {
			std::cout << ("n < 2; 0 i 1 nie sa zlozone ani pierwsze") << std::endl;
			return 0;
		}
		if (i == 0) {
			std::cout << ("0 iteracji") << std::endl;
			return 0;
		}

		if (SolovayStrassen::IsPrime(n, i) == true ) {
			std::cout << "0 - pierwsza" << std::endl;
		} else if ( SolovayStrassen::IsPrime(n, i) == false ) {
			std::cout << "1 - zlozona" << std::endl;
		} else {
			return 0;
		}
	}

    return 0;
}

