#include "SuperEnergy.h"

void testSub(Parameter& para);

void testSub(Parameter& para)
{
        Sub suba(para,1);

        Sub subb(para, 2);

        Sub subc(suba, subb, para, 3);
        
        
        Super sup(subc, subc, para);

        SuperEnergy supp(para, sup);

        cout<<para.Energy<<endl;
        MatrixXd truncU;
        
        supp.wave.TruncL(truncU, para.D());

        //cout<<truncU.rows()<<"X"<<truncU.cols()<<endl;
        subc.Trunc(truncU);
        subc.Show();
        
        
        //suba.Show();
        
}