#include <iostream>
#include <cmath>

using namespace std;

class complexnumbers
{
  private:

  int realnum, imaginarynum;

  public:

  complexnumbers();
  complexnumbers(int a, int b);

  complexnumbers operator + (complexnumbers &);
  complexnumbers operator += (complexnumbers &);
  complexnumbers operator - (complexnumbers &);
  complexnumbers operator -= (complexnumbers &);
  complexnumbers operator * (complexnumbers &);
  complexnumbers operator *= (complexnumbers &);
  complexnumbers operator / (complexnumbers &);
  complexnumbers operator /= (complexnumbers &);
  
  void Setrealnum(int a) {realnum = a;}
  void Setimaginarynum(int b) {imaginarynum=b;}

  int Getrealnum() {return realnum;};
  int Getimaginarynum() {return imaginarynum;};

  void Print();
  double length();
};

complexnumbers::complexnumbers(int a, int b)
{
   realnum = a;
   imaginarynum = b;
}

complexnumbers complexnumbers::operator+(complexnumbers &v)
{
  return complexnumbers(realnum+v.Getrealnum(),imaginarynum+v.Getimaginarynum());
}

complexnumbers complexnumbers::operator+=(complexnumbers &v)
{
  realnum += v.Getrealnum();
  imaginarynum += v.Getrealnum();
 
  return *this;
} 

complexnumbers complexnumbers::operator-(complexnumbers &v)
{
  return complexnumbers(realnum-v.Getrealnum(),imaginarynum-v.Getimaginarynum());
}

complexnumbers complexnumbers::operator-=(complexnumbers &v)
{
  realnum -= v.Getrealnum();
  imaginarynum -= v.Getrealnum();
 
  return *this;
} 

complexnumbers complexnumbers::operator*(complexnumbers &v)
{
  return complexnumbers(realnum*v.Getrealnum(),imaginarynum*v.Getimaginarynum());
}

complexnumbers complexnumbers::operator*=(complexnumbers &v)
{
  realnum *= v.Getrealnum();
  imaginarynum *= v.Getrealnum();
 
  return *this;
} 

complexnumbers complexnumbers::operator/(complexnumbers &v)
{
  return complexnumbers(realnum/v.Getrealnum(),imaginarynum/v.Getimaginarynum());
}

complexnumbers complexnumbers::operator/=(complexnumbers &v)
{
  realnum /= v.Getrealnum();
  imaginarynum /= v.Getrealnum();
 
  return *this;
} 

void complexnumbers::Print()
{
  cout << realnum << "+" << imaginarynum << "i" << endl;
}

double complexnumbers::length()
{
  return sqrt(realnum*realnum+imaginarynum*imaginarynum);
}

int main()
{
  complexnumbers *complexnumber1 = new complexnumbers(4,5);
  complexnumbers *complexnumber2 = new complexnumbers(6,7);

  cout << "First complex number:" << endl;
  complexnumber1->Print();
  cout << endl;

  cout << "Second complex number:" << endl;
  complexnumber2->Print();
  cout << endl;

  cout << "First + second complex number:" << endl;
  (*complexnumber1 + *complexnumber2).Print();
  cout << endl;

  cout << "First - second complex number:" << endl;
  (*complexnumber1 - *complexnumber2).Print();
  cout << endl;

  cout << "First * second complex number:" << endl;
  (*complexnumber1 * *complexnumber2).Print();
  cout << endl;

  cout << "First / second complex number:" << endl;
  (*complexnumber1 / *complexnumber2).Print();
  cout << endl;

  cout << "First += second complex number:" << endl;
  (*complexnumber1 += *complexnumber2).Print();
  cout << endl;

  cout << "First complex number is now:" << endl;
  complexnumber1->Print();
  cout << endl;

   cout << "Second complex number is now:" << endl;
   complexnumber2->Print();
   cout << endl;

  cout << "First -= second complex number:" << endl;
  (*complexnumber1 -= *complexnumber2).Print();
  cout << endl;

  cout << "First complex number is now:" << endl;
  complexnumber1->Print();
  cout << endl;

  cout << "Second complex number is now:" << endl;
  complexnumber2->Print();
  cout << endl;

  cout << "First *= second complex number:" << endl;
  (*complexnumber1 *= *complexnumber2).Print();
  cout << endl;

  cout << "First complex number is now:" << endl;
  complexnumber1->Print();
  cout << endl;

  cout << "Second complex number is now:" << endl;
  complexnumber2->Print();
  cout << endl;

  cout << "First /= second complex number:" << endl;
  (*complexnumber1 /= *complexnumber2).Print();
  cout << endl;

  cout << "First complex number is now:" << endl;
  complexnumber1->Print();
  cout << endl;

  cout << "Second complex number is now:" << endl;
  complexnumber2->Print();
  cout << endl;

}
