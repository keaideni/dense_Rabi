#ifndef Q_WAVE_H
#define Q_WAVE_H
#include<vector>
#include "Sub.h"

class QWave
{
private:

        MatrixXd _Wave;

public:

        const MatrixXd& Wave()const{return _Wave;};
        QWave(){};
        ~QWave(){};
        QWave(const QWave&a):
        _Wave(a._Wave)
        {};
        QWave(const int& sys, const int& env):
        _Wave(MatrixXd::Zero(sys, env))
        {};

        const MatrixXd& LOPWave(const MatrixXd&);//wave=L*wave
        const MatrixXd& ROPWave(const MatrixXd&);//wave=wave*R
        const MatrixXd& LROPWave(const MatrixXd&, const MatrixXd&);//wave=L*wave*R
        void add(const QWave& a){_Wave+=a._Wave;};//wave+=a;
        void time(const double& J){_Wave*=J;};


        const vector<double>& Wave2f(vector<double>& f)const;
        const MatrixXd& f2Wave(const vector<double>& f);
        const MatrixXd& f2Wave(const VectorXd& f);

        const QWave& operator=(const QWave& a)
        {
                _Wave=a.Wave();
                return *this;
        }


        const MatrixXd& TruncL(MatrixXd& truncU, const int& D)const;
        const MatrixXd& TruncR(MatrixXd& truncV, const int& D)const;





};


#endif // Q_WAVE_H
