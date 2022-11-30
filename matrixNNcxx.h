//implementation of our matrixNN class
#include "matrixNNH.h"
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

matrixNN::matrixNN()
{
  //default constructor
  //DEBUG:
  //cout <<"matrixNN: default constructor called"<< endl;
  ndim=0;
  matrix = new double *[ndim];
  for (int i=0;i<ndim;i++)
    matrix[i]=new double [ndim];
}

matrixNN::matrixNN(double a1, double a2, double a3, double a4)
{
  //cout <<"matrixNN: 2x2 constructor called" << endl;
  ndim=2;
  matrix = new double *[ndim];
  for (int i=0; i<ndim; i++)
    matrix[i]=new double [ndim];
 
  matrix[0][0]=a1; matrix[0][1]=a2; matrix[1][0]=a3; matrix[1][1]=a4;
}

matrixNN::matrixNN(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9)
{
  //cout << "matrixNN: 3x3 constructor called" << endl;
  ndim=3;
  matrix = new double *[ndim];
  for (int i=0; i<ndim; i++)
    matrix[i]=new double [ndim];

  matrix[0][0]=a1; matrix[0][1]=a2; matrix[0][2]=a3; matrix[1][0]=a4; matrix[1][1]=a5; matrix[1][2]=a6; matrix[2][0]=a7; matrix[2][1]=a8; matrix[2][2]=a9;
}
matrixNN::~matrixNN()
{
  //cout <<" matrix: default destructor called" << endl;
  for(int i=0; i<ndim;i++)
    {
      delete []matrix[i];
    }
  delete [] matrix;
};

matrixNN::matrixNN(int m_ndim)
{
  ndim=m_ndim;

  for (int i=0; i<ndim; i++)
    matrix[i]= new double [ndim];
}

matrixNN::matrixNN(matrixNN& v)
{
  //cout<<"matrixNN: user defined copy constructor called!" << endl;
  ndim=(int) v.GetDimension();

  matrix = new double *[ndim];

  for (int i=0; i<ndim;i++)
    matrix[i]=new double [ndim];

  for(int i=0;i<(int) v.GetDimension();i++)
  {
    for(int j=0;j<(int) v.GetDimension();j++)
    {
      matrix[i][j]=v.GetComponent(i,j);
    }
  }
}

void matrixNN::Print()
{
  cout <<"matrixNN Class:"<<endl;
  cout <<" dimension = " << ndim<<endl;
  cout << endl;
  for(int i=0; i<ndim;i++)
  {
    for(int j=0; j<ndim;j++)
    {
      cout << matrix[i][j] << " ";
    }
      cout << endl;
  }
}

matrixNN& matrixNN::operator*(matrixNN &v)
{
  //cout << "matrixNN: user defined * operator:"<< endl;
  ndim=(int) v.GetDimension();
  matrixNN matrixresult(ndim);

  for(int i=0;i<(int) v.GetDimension();i++)
  {
     for(int j=0;j<(int) v.GetDimension();j++)
    {
      matrixresult.SetComponent(i,j,matrix[i][0]*v.GetComponent(0,j)+matrix[i][1]*v.GetComponent(1,j));
    }
  }

  return *(new matrixNN(matrixresult));
}

double matrixNN::determinant()
{
  double deter=0;
  
  if (ndim==2)
  {
    return ((matrix[0][0]*matrix[1][1])-(matrix[1][0]*matrix[0][1]));
  }
  else
  {
    for (int i = 0; i<3; i++)
    {
      deter = deter + (matrix[0][i] * (matrix[1][(i+1)%3] * matrix[2][(i+2)%3] - matrix[1][(i+2)%3] * matrix[2][(i+1)%3]));
    }
  return deter;
  }
}




