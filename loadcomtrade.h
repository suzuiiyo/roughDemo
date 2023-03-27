#ifndef LOADCOMTRADE_H
#define LOADCOMTRADE_H
#include "CmtdFile.h"
#include <QString>

class loadComtrade
{
public:
    loadComtrade();
    QMap<QVector<float>, QVector<float>> getSampleValue(QString strPath, int chseq);
    QList<QString> getChName(QString strPath);
    bool Func_LoadCmtdFile(CCmtdFile* pFile, const QString& strPath);
    QMap<QDateTime, int> getWavePoints(QString strPath);
    int getPointsSeqNum(QString strPath, int wavePoints);

private:
    CCmtdFile* p_cmtdFile;
    QList<QString> chNameList;
};

#endif // LOADCOMTRADE_H
