#include "SuperEnergy.h"
#include <Eigen/Sparse>

void test(Parameter& para);

void test(Parameter& para)
{
        SparseMatrix<double> A(5,5);

        for(int i=0;i<5;i++)A.insert(i, i+1)=sqrt(i+1);

        A.makecompressed();
        
        cout<<A<<endl;
        
}