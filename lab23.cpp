#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double ,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber operator+(double z, const ComplexNumber &c){
	return ComplexNumber(z+c.real,c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber operator-(double z, const ComplexNumber &c){
	return ComplexNumber(z-c.real,-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),((real*c.imag)+(c.real*imag)));
}

ComplexNumber operator*(double z,const ComplexNumber &c){
	return ComplexNumber((z*c.real),((z*c.imag)));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber( ((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2)),((imag*c.real)-(real*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}

ComplexNumber operator/(double z,const ComplexNumber &c){
	return ComplexNumber( ((z*c.real)+(0*c.imag))/(pow(c.real,2)+pow(c.imag,2)),((0*c.real)-(z*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real and imag == c.imag){
    return true;
  }else{
    return false;
  }
}

bool operator==(double z,const ComplexNumber &c){
	if(z == c.real and 0 == c.imag){
    return true;
  }else{  
    return false;
  }
}
 double ComplexNumber::abs(){
  return sqrt(pow(real,2)+pow(imag,2));
}
  double ComplexNumber::angle(){
    return atan2(imag,real)*(180/M_PI);
  }
ostream & operator<<(ostream &os,const ComplexNumber &c){
    if(c.imag == 0){
        return os << c.real;
      }
    else if(c.real == 0 and c.imag != 0){
      return os << c.imag << "i";
      }
     else{
        if(c.imag > 0)
        return os << c.real << "+" << c.imag << "i";
        else return os << c.real << c.imag << "i";
        
      }
}




