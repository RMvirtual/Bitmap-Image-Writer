namespace Maths
{
  class Column
  {
    public:
      Column(double* columnArray, int length);
      Column();
      
      double operator [] (int index);

    private:
      double* values;
      int length;
  };

  class Matrix
  {
    public:
      Matrix();
      
      int width();
      int height();

      double operator [] (int index);

    private:
      int matrixWidth;
      int matrixHeight;
      Column *columns;
  };
}