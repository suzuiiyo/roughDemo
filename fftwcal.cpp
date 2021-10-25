#include "fftwcal.h"
#include <QMap>
#include <fftw3.h>
#include <QDebug>

#define PI 3.1415926

fftwCal::fftwCal()
{
}

QMap<QList<QString>, QList<QString>> fftwCal::startCal(QVector<float> sampleValueList)
{
    int len  = sampleValueList.size();
    in = (double*) fftw_malloc(sizeof (double)* len);
    out = (fftw_complex*)fftw_malloc(sizeof (fftw_complex)* len);

    for(int i=0; i<len; i++)
    {
       in[i] = sampleValueList.at(i);
    }

    p = fftw_plan_dft_r2c_1d(len, in, out, FFTW_ESTIMATE);
    fftw_execute(p);

    QList<QString> ranList;
    QList<QString> angList;

    for(int i=0; i<len; i++){
        float ran = sqrt(out[i][0]*out[i][0] + out[i][1]*out[i][1]);
        ranList.append(QString::number(ran));

        float ang = atan(out[i][1]/out[i][0]);
        angList.append(QString::number(ang));
    }

    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

    QMap<QList<QString>, QList<QString>> resultMap;
    resultMap.insert(ranList, angList);
    return resultMap;
}
