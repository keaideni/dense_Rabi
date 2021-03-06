#ifndef SUPER_H
#define SUPER_H
#include "QWave.h"

class Super
{
private:
        double sigma_;
        double Jr, Jcr;
        
        QWave _Wave;
        
        const Sub& Sys;
        const Sub& Env;
public:


        int rows() { return Dim; };
        int cols() { return Dim; };
        void set_shift(double sigma) { sigma_ = sigma; }
        void perform_op(double *x_in, double *y_out)
        {
                f1tof2(x_in, y_out);
        };
        const QWave& Wave()const{return _Wave;};
        int Dim;
        Super(const Parameter& para, const Sub& _Sys, const Sub& _Env):
        Jr(para.Jr()),
        Jcr(para.Jcr()),
        Sys(_Sys),
        Env(_Env),
        _Wave(_Sys.SysEye().cols(), _Env.SysEye().rows()),
        Dim(_Wave.Wave().cols()*_Wave.Wave().rows())
        {};

        void f1tof2(double* f, double* g);
        void f1tof2(const vector<double>& f, vector<double>& g);

        void OneIteration();


};


#endif // SUPER_H
