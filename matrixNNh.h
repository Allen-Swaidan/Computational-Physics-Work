// This is the header file 
// of our matrixNN class
// if we want to use our vector class
// which we should/need for matrix
// vector operations we have to include
// the header too

class vecNd;

class matrixNN
{
  private:

  int ndim;
  double **matrix;

  public:

  //constructor
  matrixNN(); //default
  matrixNN(double a1, double a2, double a3, double a4);
  matrixNN(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9);
  matrixNN(int m_ndim);
  matrixNN(matrixNN& v);
  matrixNN MatrixVector(matrixNN &v);

  // destructor
  ~matrixNN();

  matrixNN& operator * (matrixNN &v);
  double determinant();
 
  void SetDimension(int m_ndim) {ndim=m_ndim;}
  void SetComponent(double a1, double a2, double a3, double a4)
  {
     matrix[0][0]=a1;
     matrix[0][1]=a2;
     matrix[1][0]=a3;
     matrix[1][1]=a4;
  }
  void SetComponent(int i, int j, double a1) {matrix[i][j]=a1;}
  
  int GetDimension() {return ndim;};
  double GetComponent(int i, int j)
  {
    return (double) matrix[i][j];
  };
  
  void Print();
};