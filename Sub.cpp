#include "Sub.h"

void Sub::Kron(MatrixXd& ab,const MatrixXd& a, const MatrixXd& b)
{
        ab=MatrixXd::Zero(a.rows()*b.rows(),a.cols()*b.cols());

        int sizer(b.rows()),sizec(b.cols());
        for(int i=0; i<a.rows(); ++i)
        {
                for(int j=0; j<a.cols(); ++j)
                {
                        int startr(i*b.rows()),startc(j*b.cols());

                        ab.block(startr,startc,sizer, sizec)=a(i,j)*b;
                }
        }
}





Sub::Sub(const double& gr, const double& gcr, const int& nmax):
_SysEye(MatrixXd::Identity((nmax+1)*2,(nmax+1)*2))
{
        MatrixXd adag=MatrixXd::Zero(nmax+1,nmax+1),
        a(MatrixXd::Zero(nmax+1,nmax+1)),
        eye(MatrixXd::Identity(nmax+1, nmax+1));
        Matrix2d sigmaplu, sigmamin, sigmaeye;
        sigmaplu<<0,0,1,0;sigmamin<<0,1,0,0;sigmaeye<<1,0,1,0;
        for(int i=0; i<nmax; ++i)
        {
                a(i,i+1)=sqrt(i+1);
                adag(i+1,i)=sqrt(i+1);
        }

        Kron(_SysA, a, sigmaeye);//cout<<_SysA<<endl;
        Kron(_SysAdag, adag, sigmaeye);
        _SysA1=_SysA;_SysAdag1=_SysAdag;

        Kron(_System, adag*a, sigmaeye);MatrixXd temp;
        Kron(temp, eye, sigmaplu*sigmamin); _System+=temp;
        Kron(temp, adag, sigmamin);temp*=gr; _System+=temp;
        Kron(temp, a, sigmaplu);temp*=gr; _System+=temp;
        Kron(temp, adag, sigmaplu); temp*=gcr;_System+=temp;
        Kron(temp, a, sigmamin); temp*=gcr; _System+=temp;
}


void Sub::Show()const
{
        cout<<"The System:"<<endl;
        cout<<_System<<endl;
        cout<<"The SysA:"<<endl;
        cout<<_SysA<<endl;
        cout<<"The SysAdag:"<<endl;
        cout<<_SysAdag<<endl;
        cout<<"The SysA1:"<<endl;
        cout<<_SysA1<<endl;
        cout<<"The SysAdag1:"<<endl;
        cout<<_SysAdag1<<endl;
}