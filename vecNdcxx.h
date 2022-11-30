//Implementation of our vecNd class
// now we have to include our header
// file!!!

#include "vecNd.h"
#include <iostream>
#include <cmath>

using namespace std;

double vecNd::ScalarProduct()
{
  double product = 0;
  x = new double[ndim];

  for (int i;i<(int) ndim; i++)
  {
    product = product + (x[i]);
  }
 
  return product;
} 

vecNd vecNd::operator=(vecNd &v)
{
  //cout << "vecNd: user defined = operator:" << endl;
  ndim=(int) v.GetDimension();
  x=new double[ndim];

  for (int i=0;i<(int) ndim;i++)
    x[i]=v.GetComponents(i);

  return *this;
}

vecNd vecNd::operator=(vecNd *v)
{
  //cout << "vecNd: user defined = operator *:" << endl;
  ndim=(int) v->GetDimension();
  x=new double[ndim];

  for (int i=0;i<(int) ndim;i++)
    x[i]=v->GetComponents(i);

  return *this;
}

vecNd::vecNd()
{
  //default constructor
  //DEBUG:
  cout << "vecNd: default constructor called" << endl;
  ndim=0;
  // create an "array" so that we can use the
  //generic delete in the destructor
  x=new double[1];
}

vecNd::vecNd(double mx, double my)
{
  //user defined constructor for nd vector as a 2d vector
  //cout << "vecNd: user defined 2d constructor called" << endl;
  ndim=2;
  x=new double[2];
  x[0]=mx; x[1]=my;
}

vecNd::vecNd(double mx, double my, double mz)
{
  ndim=3;
  x=new double[3];

  x[0]=mx; x[1]=my; x[2]=mz;
}

vecNd::vecNd(vecNd& v)
{
  //cout <<" vecNd: user defined copy constructor called!"<< endl;

  ndim=(int) v.GetDimension();
  x=new double[(int) v.GetDimension()];

  for (int i=0;i<(int) v.GetDimension(); i++)
    x[i]=v.GetComponents(i);
}

vecNd::~vecNd()
{
  //cout <<" vecNd: default destructor called" << endl;
  delete [] x;
};

vecNd::vecNd(int m_ndim)
{
  ndim=m_ndim;
  x = new double[ndim];
}

void vecNd::Print()
{
  //cout <<"VecNd class:"<<endl;
  cout <<" dimension = "<<ndim<<endl;
  for (int i=0;i<ndim;i++)
    cout <<"x["<<i<<"] = "<<x[i]<<endl;
}

double vecNd::Length()
{
  double l2=0;
  for (int i=0;i<ndim;i++)
    l2 += (GetComponents(i)*GetComponents(i));

  return sqrt(l2);//sqrt(x*x+y*y);
}

vecNd& vecNd::operator+(vecNd &v)
{
  //cout << "vecNd:user defined + operator:"<<endl;
  ndim=(int) v.GetDimension();
  vecNd vresult(ndim);
  
  for (int i=0;i<(int) v.GetDimension(); i++)
  {
    vresult.SetComponent(i,x[i]+v.GetComponents(i));
  }
  
  return *(new vecNd(vresult));
}
  
vecNd vecNd::operator+=(vecNd &v)
{
  //cout << "vecNd:user defined += operator:"<<endl;
  ndim=(int) v.GetDimension();

   for (int i=0;i<(int) v.GetDimension(); i++)
   {
     x[i]+=v.GetComponents(i);
   }

  return *this;
}

vecNd& vecNd::operator-(vecNd &v)
{
  //cout << "vecNd:user defined - operator:"<<endl;
  ndim=(int) v.GetDimension();
  vecNd vresult(ndim);
  
  for (int i=0;i<(int) v.GetDimension(); i++)
  {
    vresult.SetComponent(i,x[i]-v.GetComponents(i));
  }
  
  return *(new vecNd(vresult));
}

vecNd vecNd::operator-=(vecNd &v)
{
  //cout << "vecNd:user defined -= operator:"<<endl;
  ndim=(int) v.GetDimension();

   for (int i=0;i<(int) v.GetDimension(); i++)
   {
     x[i]-=v.GetComponents(i);
   }

  return *this;
}

vecNd& vecNd::operator*(vecNd &v)
{
  //cout << "vecNd:user defined * operator:"<<endl;
  ndim=(int) v.GetDimension();
  vecNd vresult(ndim);
  
  for (int i=0;i<(int) v.GetDimension(); i++)
  {
    vresult.SetComponent(i,x[i]*v.GetComponents(i));
  }
  
  return *(new vecNd(vresult));
}

vecNd vecNd::operator*=(vecNd &v)
{
  //cout << "vecNd:user defined *= operator:"<<endl;
  ndim=(int) v.GetDimension();

   for (int i=0;i<(int) v.GetDimension(); i++)
   {
     x[i]*=v.GetComponents(i);
   }

  return *this;
}

vecNd& vecNd::operator/(vecNd &v)
{
  //cout << "vecNd:user defined / operator:"<<endl;
  ndim=(int) v.GetDimension();
  vecNd vresult(ndim);
  
  for (int i=0;i<(int) v.GetDimension(); i++)
  {
    vresult.SetComponent(i,x[i]/v.GetComponents(i));
  }
  
  return *(new vecNd(vresult));
}

vecNd vecNd::operator/=(vecNd &v)
{
  //cout << "vecNd:user defined /= operator:"<<endl;
  ndim=(int) v.GetDimension();

   for (int i=0;i<(int) v.GetDimension(); i++)
   {
     x[i]/=v.GetComponents(i);
   }

  return *this;
}
