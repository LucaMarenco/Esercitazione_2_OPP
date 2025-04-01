#include <iostream>
#include "complex_number.hpp"

int main(void) {

	complex_number<float> c1 = complex_number<float>(1.1f, 2.0f);
    complex_number<float> c2 = complex_number<float>(3.0f, -4.3f);
    complex_number<float> c3 =  3.5f + c1 ;
    complex_number<float> c4 = 2.0f * c2 ;
	complex_number<float> c4b = c1 * c2 ;
    
	std::cout << "Coniugato di c1: " << c1.conju() << std::endl;
    std::cout << "Parte reale di c1: " << c1.real() << std::endl;
    std::cout << "Parte immaginaria di c1: " << c1.imag() << std::endl;
	
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3 (c1 + 3.0): " << c3 << std::endl;
    std::cout << "c4 (c1 * c2): " << c4 << std::endl;
	
	c1 *= 2.0;
	std::cout << "c1 *= 2.0: " << c1 << std::endl;
    c2 += c1;
	std::cout << "c2+= c1: " << c2 << std::endl;
	
	
	complex_number<double> c5 =  complex_number<double>();
    complex_number<double> c6 = complex_number<double>(2.0, 8.0);
    complex_number<double> c7 =  3.7 + c5 ;
    complex_number<double> c8 = 2.0 * c6 ;
    
	std::cout << "c5: " << c1 << std::endl;
    std::cout << "c6: " << c2 << std::endl;
    std::cout << "c7 (3.7 + c5): " << c7 << std::endl;
    std::cout << "c8 (2.0 * c6): " << c8 << std::endl;
	
	return 0;
 }



