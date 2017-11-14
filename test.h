#include "QWave.h"

void testSub(const Parameter& para);

void testSub(const Parameter& para)
{
        Sub suba(para,2);
        
        QWave wave(suba.System().cols(), suba.System().rows());

        cout<<wave.Wave()<<endl;
        cout<<"haha"<<endl;
        /*
        cout<<suba.SysA()<<endl;
        cout<<"hehe"<<endl;
        cout<<suba.SysAdag()<<endl;*/

        MatrixXd a;
        cout<<wave.TruncL(a, 10)<<endl<<"haha"<<endl
        <<wave.TruncR(a,10)<<endl;



        
        
        //suba.Show();
        
}