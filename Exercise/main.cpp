#include <iostream>

#define STACK_SIZE 8

template<typename T>
class complex_number {
	T a;
	T b;
		
	
public:
	complex_number()  // Costruttore default
		: a(0),b(0) 
	
	complex_number(T real, T imm) // Costruttore user defined 
		: a(real),b(imm) 
	{}
	
	complex_number<T> conju() const {
		return complex_number<T>(a, -b);
	}
	
	T real() const {
		return a;
	}
	
    T imag() const {
		return b;
	}
	
	
		
	complex_number<T>& operator+=(const complex_number<T>& other) {
		T r = a;   // Parte reale primo numero
		T i = b;   // Parte immaginaria primo numero
		T rt = other.a; // Parte reale secondo numero
		T it = other.b; ;   // Parte immaginaria secondo numero
	    
		a = r + rt;
		b = i + it;
		return *this;
	}
	

 