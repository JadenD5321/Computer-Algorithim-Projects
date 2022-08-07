

#include <iostream>
#include <iostream>
using namespace std;

typedef double (*FUNC)(double);
// Returns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use a Riemann sum to estimate the area by dividing it into narrow rectangles (each rectangle should have a width of .0001)
// and adding up the areas of the individual rectangles.
// For a rectangle at horizontal position x, the height will be f(x).
// (when you call f(x) it'll call whatever function you passed as the first parameter)
double integrate(FUNC f, double a, double b) {
double sum = 0; 
double delta = .0001; 
	double x = a; 

	while(x < b) 
	{
		sum += f(x)*delta; 
		x = x + delta; 
	}
	return sum; 
}


double line(double x){
   return x; // this will return the value of x
}

double square(double x){
   return x*x; // this will return value of x square root 
}

double cube(double x){
   return x*x*x; // this will return the value of x cubic root
}

int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   return 0;
}