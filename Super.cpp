#include "Super.h"

void Super::f1tof2(const vector<double>& f, vector<double>& g)
{
        _Wave.f2Wave(f);
        OneIteration();
        _Wave.Wave2f(g);
}

void Super::OneIteration()
{
        QWave temp(_Wave);
        _Wave.LOPWave(Sys.System());
        QWave temp1(temp);
        temp1.ROPWave(Env.System());

        _Wave.add(temp1);
        temp1=temp;

        temp1.LROPWave(Sys.SysAdag(), Env.SysA1());
        temp1.time(-1*Jr);
        _Wave.add(temp1);

        temp1=temp;
        temp1.LROPWave(Sys.SysA(), Env.SysAdag1());
        temp1.time(-1*Jr);
        _Wave.add(temp1);

        temp1=temp;
        temp1.LROPWave(Sys.SysAdag(), Env.SysAdag1());
        temp1.time(-1*Jcr);
        _Wave.add(temp1);

        temp1=temp;
        temp1.LROPWave(Sys.SysA(), Env.SysA1());
        temp1.time(-1*Jcr);
        _Wave.add(temp1);

//=============for the periodic bound condition=====================
        temp1=temp;

        temp1.LROPWave(Sys.SysAdag1(), Env.SysA());
        temp1.time(-1*Jr);
        _Wave.add(temp1);

        temp1=temp;
        temp1.LROPWave(Sys.SysA1(), Env.SysAdag());
        temp1.time(-1*Jr);
        _Wave.add(temp1);

        temp1=temp;
        temp1.LROPWave(Sys.SysAdag1(), Env.SysAdag1());
        temp1.time(-1*Jcr);
        _Wave.add(temp1);

        temp1=temp;
        temp1.LROPWave(Sys.SysA1(), Env.SysA1());
        temp1.time(-1*Jcr);
        _Wave.add(temp1);



        
}


void Super::f1tof2(double* f, double* g)
{
        vector<double> ff, gg;
        for(int i=0; i<Dim; ++i)
        {
                ff.push_back(f[i]);
        }
        f1tof2(ff,gg);
        for(int i=0; i<Dim; ++i)
        {
                g[i]=gg.at(i);
        }
}