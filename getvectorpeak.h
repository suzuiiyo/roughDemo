#ifndef GETVECTORPEAK_H
#define GETVECTORPEAK_H
#include <QVector>
#include <QObject>

class getVectorPeak
{
public:
    getVectorPeak();
    QVector<float> getPeak(QVector<float>);
};

#endif // GETVECTORPEAK_H
