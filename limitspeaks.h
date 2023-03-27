#ifndef LIMITSPEAKS_H
#define LIMITSPEAKS_H
#include <QVector>
#include <QList>

class limitsPeaks
{
public:
    limitsPeaks();
    QList<float> findAllMaxPeaks(QVector<float> var);
};

#endif // LIMITSPEAKS_H
