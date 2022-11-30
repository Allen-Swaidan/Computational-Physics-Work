#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

void randomfunc1(int array[], int randomnum); //functions for question 1
void swap(int &x, int &y);
void bubblesort(int array[], int randomnum);

void randomfunc2(int dynamicarray[], int randomnum, int numelements); //functions for question 2
void calculatemean(int dynamicarray[], int numelements, double &mean);
void calculatedeviation(int dynamicarray[], int numelements, double &mean, double &dev);
void printvalues(int dynamicarray[], int numelements, double &mean, double &dev);

int main()
{
  //implemented a bubble sort algorithm
  int array[20], randomnum, x, y;
 
  bubblesort(array, randomnum);

  for(int i=0; i < 20; i++)
  {
    cout << "Array[" << i << "] = " << array[i] << endl;
  }

  //defined a dynamic array and calculated the mean and standard deviation of it  
  int numelements=0; 
  double mean, dev;

  cout << "Input a value for the size of the array:" << endl;
  cin >> numelements;

  int *dynamicarray = new int[numelements];
  
  randomfunc2(dynamicarray, randomnum, numelements);
  printvalues(dynamicarray, numelements, mean, dev);

}

void randomfunc1(int array[], int randomnum)
{
  for(int i=0; i < 20; i++)
  {
    randomnum = rand() % 100;
    array[i] = randomnum;
  }
}

void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

void bubblesort(int array[], int randomnum)
{
  int i, j;

  randomfunc1(array, randomnum);

  for(i = 0; i < 20; i++)
  {
    for(j = i+1; j < 20; j++)
    {
      if(array[i] > array[j])
      {
        swap(array[i], array[j]);
      }
    }
  }
}

void randomfunc2(int dynamicarray[], int randomnum, int numelements)
{
  for(int i=0; i<numelements; i++)
  {
    randomnum = rand() % 50;
    dynamicarray[i] = randomnum;
  }

  for(int i=0; i<numelements; i++)
  {
    cout << "Array[" << i << "]" << dynamicarray[i] << endl;
  }
}

void calculatemean(int dynamicarray[], int numelements, double &mean)
{
  int sum = 0;

  for(int i=0; i<numelements; i++)
  {
    sum += dynamicarray[i];
  }

  mean = (double) sum / numelements;
}

void calculatedeviation(int dynamicarray[], int numelements, double &mean, double &dev)
{
  double sum;
 
  for(int i=0; i<numelements; i++)
  {
    sum += (dynamicarray[i]-mean)*(dynamicarray[i]-mean);
  }

  dev = (double) sqrt(((double) 1/numelements)*sum);
}
   
void printvalues(int dynamicarray[], int numelements, double &mean, double &dev)
{
  calculatemean(dynamicarray, numelements, mean);
  
  cout << "mean=" << mean << endl;

  calculatedeviation(dynamicarray, numelements, mean, dev);

  cout << "Standard deviation=" << dev << endl;
}













