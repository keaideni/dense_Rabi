#ifndef SUPER_H
#define SUPER_H
#include "QWave.h"

class Super
{
private:
        double sigma_;
        double Jr, Jcr;
        
        QWave Wave;
        int Dim;
        const Sub& Sys, Env;
public:


        int rows() { return Dim; };
        int cols() { return Dim; };
        void set_shift(double sigma) { sigma_ = sigma; }
        void perform_op(double *x_in, double *y_out)
        {
                f1tof2(x_in, y_out);
        };

        Super(const Sub& _Sys, const Sub& _Env, const Parameter& para):
        Jr(para.Jr()),
        Jcr(para.Jcr()),
        Sys(_Sys),
        Env(_Env),
        Wave(_Sys,SysEye().cols(), _Env.SysEye().rows()),
        Dim(Wave.Wave().cols()*Wave.Wave().rows())
        {};

        void f1tof2(const double* f, const double* g);
};


#endif // SUPER_H
