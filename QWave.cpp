#include "QWave.h"
struct Eigstruct
{
        double lamda;
        VectorXd state;
};



bool comp(const Eigstruct& a, const Eigstruct& b);
bool comp(const Eigstruct& a, const Eigstruct& b)
{
        return (a.lamda > b.lamda);
}





const MatrixXd& QWave::LOPWave(const MatrixXd& sys)
{
        _Wave=sys*_Wave;

        return _Wave;
}

const MatrixXd& QWave::ROPWave(const MatrixXd& Env)
{
        _Wave=_Wave*Env.transpose();

        return _Wave;
}


const MatrixXd& QWave::LROPWave(const MatrixXd& Sys, const MatrixXd& Env)
{
        _Wave=Sys*_Wave*Env.transpose();
        return _Wave;
}


const vector<double>& QWave::Wave2f(vector<double>& f)const
{
        for(int i=0; i<_Wave.rows(); ++i)
        {
                for(int j=0; j<_Wave.cols(); ++j)
                {
                        f.push_back(_Wave(i,j));
                }
        }

        return f;
}


const MatrixXd& QWave::f2Wave(const vector<double>& f)
{
        for(int i=0; i<_Wave.rows(); ++i)
        {
                for(int j=0; j<_Wave.cols(); ++j)
                {
                        _Wave(i, j)=f.at(i*_Wave.cols()+j);
                }
        }

        return _Wave;
}


const MatrixXd& QWave::f2Wave(const VectorXd& f)
{
        for(int i=0; i<_Wave.rows(); ++i)
        {
                for(int j=0; j<_Wave.cols(); ++j)
                {
                        _Wave(i, j)=f(i*_Wave.cols()+j);
                }
        }

        return _Wave;
}




const MatrixXd& QWave::TruncL(MatrixXd& truncU, const int& D)const
{
        vector<Eigstruct> denmat;

        if(_Wave.cols()*_Wave.rows()>16)
        {
                BDCSVD<MatrixXd> svd(_Wave, ComputeFullU);
                for(int i=0; i<svd.singularValues().rows(); ++i)
                {
                        Eigstruct base;
                        base.lamda=svd.singularValues()(i);
                        base.state=svd.matrixU().col(i);

                        denmat.push_back(base);
                }
        }else
        {
                JacobiSVD<MatrixXd> svd(_Wave, ComputeFullU);
                for(int i=0; i<svd.singularValues().rows(); ++i)
                {
                        Eigstruct base;
                        base.lamda=svd.singularValues()(i);
                        base.state=svd.matrixU().col(i);

                        denmat.push_back(base);
                }
        }

        sort(denmat.begin(), denmat.end(), comp);

        int nrow(_Wave.rows());
        int ncol(D<denmat.size()?D:denmat.size());
        truncU=MatrixXd::Zero(nrow, ncol);

        for(int i=0; i<ncol; ++i)
        {
                truncU.col(i)=denmat.at(i).state;
        }

        return truncU;

}
const MatrixXd& QWave::TruncR(MatrixXd& truncV, const int& D)const
{
        vector<Eigstruct> denmat;

        if(_Wave.cols()*_Wave.rows()>16)
        {
                BDCSVD<MatrixXd> svd(_Wave, ComputeFullV);
                for(int i=0; i<svd.singularValues().rows(); ++i)
                {
                        Eigstruct base;
                        base.lamda=svd.singularValues()(i);
                        base.state=svd.matrixV().col(i);

                        denmat.push_back(base);
                }
        }else
        {
                JacobiSVD<MatrixXd> svd(_Wave, ComputeFullV);
                for(int i=0; i<svd.singularValues().rows(); ++i)
                {
                        Eigstruct base;
                        base.lamda=svd.singularValues()(i);
                        base.state=svd.matrixV().col(i);

                        denmat.push_back(base);
                }
        }

        sort(denmat.begin(), denmat.end(), comp);

        int nrow(_Wave.cols());
        int ncol(D<denmat.size()?D:denmat.size());
        truncV=MatrixXd::Zero(nrow, ncol);

        for(int i=0; i<ncol; ++i)
        {
                truncV.col(i)=denmat.at(i).state;
        }

        return truncV;
}