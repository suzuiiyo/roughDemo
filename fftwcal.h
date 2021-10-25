#ifndef FFTWCAL_H
#define FFTWCAL_H

#include <QVector>
#include <math.h>
#include "fftw3.h"

class fftwCal
{
public:
    fftwCal();

    QMap<QList<QString>, QList<QString>> startCal(QVector<float>);

public:
    int len;
    double* in = NULL;
    fftw_complex *out = NULL;
    fftw_plan p;
};

#endif // FFTWCAL_H
