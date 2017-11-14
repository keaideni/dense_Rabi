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
        //QWave(){};
        ~QWave(){};
        QWave(const int& sys, const int& env):
        _Wave(MatrixXd::Random(sys, env))
        {};

        const MatrixXd& LOPWave(const MatrixXd&);
        const MatrixXd& ROPWave(const MatrixXd&);
        const MatrixXd& LROPWave(const MatrixXd&, const MatrixXd&);

        const vector<double>& Wave2f(vector<double>& f)const;
        const MatrixXd& f2Wave(const vector<double>& f);


        const MatrixXd& TruncL(MatrixXd& truncU, const int& D)const;
        const MatrixXd& TruncR(MatrixXd& truncV, const int& D)const;





};


#endif // Q_WAVE_H
