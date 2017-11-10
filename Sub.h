#ifndef SUB_H
#define SUB_H
#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <cmath>

using  namespace std; 
using namespace Eigen;

class Sub
{
private:
        MatrixXd _System;
        MatrixXd _SysA;
        MatrixXd _SysAdag;
        MatrixXd _SysEye;
        MatrixXd _SysA1;
        MatrixXd _SysAdag1;

        void MatrixSave(const MatrixXd& A, ofstream outfile);
        void MatrixRead(const MatrixXd& A, ifstream infile);
        void Kron(MatrixXd& ab,const MatrixXd& a, const MatrixXd& b);
public:
        const MatrixXd& System()const{return _System;};
        const MatrixXd& SysA()const{return _SysA;};
        const MatrixXd& SysAdag()const{return _SysAdag;};
        const MatrixXd& SysA1()const{return _SysA1;};
        const MatrixXd& SysAdag1()const{return _SysAdag1;};
        const MatrixXd& SysEye()const{return _SysEye;};

        Sub(const Sub& a):
        _System(a._System),
        _SysA(a._SysA),
        _SysAdag(a._SysAdag),
        _SysA1(a._SysA1),
        _SysAdag1(a._SysAdag1)
        {}

        Sub(const double& gr, const double& gcr, const int& nmax);
        void Show()const;

};

#endif // SUB_H
