#include "../Matrix/matrix.h"
#include "../Matrix/vector.h"
#include <cmath>

class EVD
{
public:

    void timesJ(Matrix& A, int p, int q, double theta)
    {
        double c = cos(theta);
        double s = sin(theta);

        for (int i = 0; i < A.getRows(); i ++)
        {
            double aip = A[i][p];
            double aiq = A[i][q];

            A[i][p] = c * aip - s * aiq;
            A[i][q] = s * aip - c * aiq;
        }
    }
    void Jtimes(Matrix& A, int p, int q, double theta)
    {
        double c = cos(theta);
        double s = sin(theta);

        for (int i = 0; i < A.getRows(); i++)
        {
            double api = A[p][i];
            double aqi = A[q][i];

            A[p][i] = c * api - s * aqi;
            A[q][i] = -s* api + c * aqi;
        }
    }
    void cyclic(Matrix M)
    {
        
    }
};