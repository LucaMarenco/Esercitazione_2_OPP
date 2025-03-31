#include <iostream>

#define STACK_SIZE 8

template<typename T>
class complex_number 
{
	T a;
	T b;
		
	
public:
	complex_number()  // Costruttore default
		: a(0),b(0) {}
	
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
	
	
	// Operatore += tra due complessi
	complex_number<T>& operator+=(const complex_number<T>& other) {
	    a += other.a;
		b += other.b;
		return *this;
	}
	
	// Operatore + tra due complessi
	complex_number<T> operator+(const complex_number<T>& other) const {
		complex_number<T> ret = *this;
		ret += other;
		return ret;
	}

	// Operatore += tra complesso e T 
	complex_number<T>& operator+=(const T& other) {
        a += other;
        return *this;
	}
	
	// Operatore + tra complesso e T 
	complex_number<T> operator+(const T& other) const {
        complex_number<T> ret = *this;
        ret += other;
        return ret;
	}
	
	// Operatore *= tra due complessi
	complex_number<T>& operator*=(const complex_number<T>& other) {
        T rt = other.a; // Parte reale secondo numero
		T it = other.b;   // Parte immaginaria secondo numero
		T pr = (a*rt) - (b*it);
		T pi = (a*it) + (b*rt);
        a = pr;
        b = pi;
        return *this;
    }
	
	// Operatore * tra due complessi
	complex_number<T> operator*(const complex_number<T>& other) const {
		T rt = other.a; // Parte reale secondo numero
		T it = other.b;   // Parte immaginaria secondo numero
		T pr = (a*rt) - (b*it);
		T pi = (a*it) + (b*rt);
		return complex_number<T>(pr, pi);
	}
	
	// Operatore *= tra complesso e T 
	complex_number<T>& operator*=(const T& other) {
        a = other*a;
        b = other*b;
        return *this;
    }
	
	// Operatore * tra complesso e T 
	complex_number<T> operator*(const T& other) const {
		return complex_number<T>(other*a, other*b);
	}
};	

template <typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& c) {
	os << c.real();
    if (c.imag() >= 0)
        os << "+" << c.imag() << "i";
    else
        os << c.imag() << "i";
	return os;
};


template <typename T>
complex_number<T> operator+(const T& i, const complex_number<T>& r)
{
	return r + i ;
}

template <typename T>
complex_number<T>
operator*(const T& i, const complex_number<T>& r)
{
    return r * i;
}


 int main(void) {

	complex_number<float> c1(1.1f, 2.0f);
    complex_number<float> c2(3.0f, -4.3f);
    float t = 3.0;
    complex_number<float> c3 = t + c1 ;
    complex_number<float> c4 = c1 * c2;
    
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3 (c1 + 3.0): " << c3 << std::endl;
    std::cout << "c4 (c1 * c2): " << c4 << std::endl;
    std::cout << "Coniugato di c1: " << c1.conju() << std::endl;
    std::cout << "Parte reale di c1: " << c1.real() << std::endl;
    std::cout << "Parte immaginaria di c1: " << c1.imag() << std::endl;
    
	
	return 0;
 }