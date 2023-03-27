#include "loadcomtrade.h"
#include "unistd.h"
#include <QDebug>
#include <QTextCodec>
#include <QByteArray>
#include <QRegExp>

loadComtrade::loadComtrade()
{
    p_cmtdFile = new CCmtdFile();
}

QMap<QVector<float>, QVector<float>> loadComtrade::getSampleValue(QString strPath, int chseq)
{
    //一周波采样点
    QVector<float> aChanelat1;
    QVector<float> chopBefore1zhou;
    QVector<float> chopAfter1zhou;

    QMap<QVector<float>, QVector<float>> chopMap;

    if(Func_LoadCmtdFile(p_cmtdFile, strPath)){
        int wavePoints = p_cmtdFile->m_pSegment->m_nWavePoints;
        int segmentCount = p_cmtdFile->m_nSegCount;
        int segmentWaveCount = p_cmtdFile->m_pSegment->m_nCount;
        int segmentStartPos = p_cmtdFile->m_pSegment->m_nStartPos;
        int segmentSecCount = p_cmtdFile->m_pSegment->m_nSecCount;
        float dTimeSpan = p_cmtdFile->m_dTimeSpan;
        int nTbPos = p_cmtdFile->m_nTbPos;
        QString strStartTime = p_cmtdFile->m_strStartTime;
        QDateTime tmStart = p_cmtdFile->m_tmStart;
        QVector<double> pSampleTime = p_cmtdFile->m_pSampleTime;
        QString strLeftTime = p_cmtdFile->m_strLeftTime;
        unsigned int wFaultMiniSec = p_cmtdFile->m_wFaultMiniSec;

        int totalPoints = p_cmtdFile->m_nTotalPoints;

//        qDebug() << segmentCount << "采样段" << endl;
//        qDebug() << totalPoints << "总采样点数" << endl;
//        qDebug() << segmentWaveCount << "本段点数" << endl;
//        qDebug() << segmentStartPos << "起始点" << endl;
//        qDebug() << segmentSecCount << "每秒采样点数" << endl;
//        qDebug() << nTbPos << "突变点序号";
//        qDebug() << dTimeSpan << "突变时间";
//        qDebug() << strStartTime << "录波判启动的时间";
//        qDebug() << tmStart << "录波启动时刻";
//        qDebug() << wFaultMiniSec << "启动时刻的毫秒";
//        qDebug() << strLeftTime << "最左时刻";

        aChanelat1 = p_cmtdFile->m_arAChanel.at(chseq)->m_pData;

        //突变前两个周波
        for(int i= nTbPos - 2*wavePoints; i<=nTbPos; i++){
            chopBefore1zhou.append(aChanelat1.at(i));
        }

        //突变后两个周波
        for(int i= nTbPos; i<=nTbPos + 5*wavePoints; i++){
            chopAfter1zhou.append(aChanelat1.at(i));
        }

        chopMap.insert(chopBefore1zhou, chopAfter1zhou);
    }
    return chopMap;
}

QList<QString> loadComtrade::getChName(QString strPath)
{
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    if(Func_LoadCmtdFile(p_cmtdFile, strPath)){
        foreach(CEleAChanel* varCh, p_cmtdFile->m_arAChanel){

//            QString nameStr = QString::fromLocal8Bit(varCh->m_chName, 128);

//            QByteArray arr = nameStr.toLocal8Bit();

//            char *str = arr.data();

            QString tmp = codec->toUnicode(varCh->m_chName);

            chNameList.append(tmp);
        }
    }
    return chNameList;
}

bool loadComtrade::Func_LoadCmtdFile(CCmtdFile *pFile, const QString &strPath)
{
    if(!pFile->ReadComtradeFile(strPath))
    {
        return false;
    }

    const int Max_LoadFileTime = 60000;
    int nTimess = 0;
    while(!pFile->FileLoadFinished())
    {
        usleep(10);
        nTimess += 10;
        if(nTimess >= Max_LoadFileTime){
            break;
        }
    }

    if(!pFile->FileLoadFinished())
    {
        return false;
    }
    else
    {
        return true;
    }
}

QMap<QDateTime, int> loadComtrade::getWavePoints(QString strPath)
{
    QDateTime tmStart;
    int wavePoints = 0;
    if(Func_LoadCmtdFile(p_cmtdFile, strPath)){
        wavePoints = p_cmtdFile->m_pSegment->m_nWavePoints;
        tmStart = p_cmtdFile->m_tmStart;
    }

//        QRegExp rx("-?(([1-9]\\d*\\.\\d*)|(0\\.\\d*[1-9]\\d*))");
//        int p = 0;
//        QStringList data_list;
//        while((p = rx.indexIn(strStartTime, p)) != -1)
//        {
//            data_list.append(rx.cap(1));
//            p += rx.matchedLength();
//        }

    QMap<QDateTime, int> chopFactor;
    chopFactor.insert(tmStart, wavePoints);

    return chopFactor;
}

int loadComtrade::getPointsSeqNum(QString strPath, int wavePoints)
{
    int startPosition = 0;
    int nTbPos = 0;
    if(Func_LoadCmtdFile(p_cmtdFile, strPath)){
        nTbPos = p_cmtdFile->m_nTbPos;
    }

    if(nTbPos - 2*wavePoints >0){
        startPosition = nTbPos - 2*wavePoints - 1;
    }

    return startPosition;
}

