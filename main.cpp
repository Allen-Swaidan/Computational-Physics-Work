//demonstrating our two classes

#include "matrixNNcxx.h"
#include "vecNdcxx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  //declare dynamically and
  //set a new variable of type vec2d
  
  vecNd *myFirstVecNd=new vecNd(2.0,1.0);
  vecNd *mySecondVecNd=new vecNd(4.0,3.0);
  vecNd *myThirdVecNd=new vecNd();

  cout << endl;

  cout << "First Vector:" << endl;
  myFirstVecNd->Print();
  cout << endl;

  cout << "Second Vector:" << endl;
  mySecondVecNd->Print();
  cout << endl;

  cout << "First Vector + Second Vector:" << endl;
  (*myFirstVecNd + *mySecondVecNd).Print();
  *myThirdVecNd = (*myFirstVecNd +*mySecondVecNd);
  cout << endl;

  cout << "First Vector - Second Vector:" << endl;
  (*myFirstVecNd - *mySecondVecNd).Print();
  *myThirdVecNd = (*myFirstVecNd - *mySecondVecNd);
  cout << endl;

  cout << "First Vector * Second Vector:" << endl;
  (*myFirstVecNd * *mySecondVecNd).Print();
  *myThirdVecNd = (*myFirstVecNd * *mySecondVecNd);
  cout << endl;

  cout << "First Vector / Second Vector:" << endl;
  (*myFirstVecNd / *mySecondVecNd).Print();
  *myThirdVecNd = (*myFirstVecNd / *mySecondVecNd);
  cout << endl;

  cout << "First Vector += Second Vector:" << endl;
  (*myFirstVecNd += *mySecondVecNd).Print();
  *myFirstVecNd += *mySecondVecNd;
   myFirstVecNd->Print();
  cout << endl;

    cout << "First Vector -= Second Vector:" << endl;
  //(*myFirstVecNd -= *mySecondVecNd).Print();
  *myFirstVecNd -= *mySecondVecNd;
   myFirstVecNd->Print();
  cout << endl;

    cout << "First Vector *= Second Vector:" << endl;
  //(*myFirstVecNd *= *mySecondVecNd).Print();
  *myFirstVecNd *= *mySecondVecNd;
   myFirstVecNd->Print();
  cout << endl;

    cout << "First Vector /= Second Vector:" << endl;
  //(*myFirstVecNd /= *mySecondVecNd).Print();
  *myFirstVecNd /= *mySecondVecNd;
   myFirstVecNd->Print();
  cout << endl;

  matrixNN *myFirstMatrix=new matrixNN(1,2,7,4,6,8,5,6,1);
  matrixNN *mySecondMatrix=new matrixNN(5,6,7,8,6,5,4,3,2);

  //cout <<"Matrix via default constructor"<< endl;
  cout << "First Matrix: " << endl;
  myFirstMatrix->Print();
  cout << endl;

  //cout <<"Matrix via default constructor"<< endl;
  cout << "Second Matrix: " << endl;
  mySecondMatrix->Print();
  cout << endl;

  cout << "First Matrix * Second Matrix:" << endl;
  //
  (*myFirstMatrix * *mySecondMatrix).Print();

  cout << endl;
  cout << "Determinant of first matrix is:" << endl;
  cout << "Determinant = " << myFirstMatrix->determinant() << endl;
  cout << endl;
  
  cout << endl;
  cout << "Determinant of second matrix is:" << endl;
  cout << "Determinant = " << mySecondMatrix->determinant() << endl;
  cout << endl;

  delete myFirstVecNd;
  delete myFirstMatrix;

  cout << endl;
  cout<<"Program end!"<< endl;
}