// This is the header file
// of our vecNd class

//definition of our vecNd class
class matrixNN;

class vecNd
{
  private:

  int ndim;
  double *x;
  double *y;

  public:

  //constructor
  vecNd(); //default
  // user defined 2d constructor
  vecNd(double mx, double my);
  vecNd(double mx, double my, double mz);

  //since we have a pointer now,
  //a user implemented copy constructor is needed!
  vecNd(vecNd& v);
  vecNd(int m_ndim);

  //destructor
  ~vecNd();

  //operators
  //if a copy constructor is needed
  //so is an implementation of "="
  // needed and vice versa
  vecNd operator = (vecNd &v);
  vecNd operator = (vecNd *v);
  vecNd& operator + (vecNd &);
  vecNd operator += (vecNd &);
  vecNd& operator - (vecNd &);
  vecNd operator -= (vecNd &);
  vecNd& operator * (vecNd &);
  vecNd operator *= (vecNd &);
  vecNd& operator / (vecNd &);
  vecNd operator /= (vecNd &);

  double ScalarProduct();

  // Setter functions
  void SetComponent(double mx,double my) {x[0]=mx; x[1]=my;}
  void SetDimension(int i, double mx) {x[i]=mx;}
  void SetDimension(int m_ndim) {ndim = m_ndim;}
  //void SetX(double mx) {x=mx;}
  //void SetY(double my) {y=my;}

  // Getter functions
  int GetDimension() {return ndim;};
  double GetComponents(int i)
  {
    return (double) x[i];
  };
  //double GetX() {return x;}
  //double GetY() {return y;}
 
  //our member functions
  void Print();
  double Length();
};














