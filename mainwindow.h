#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <loadcomtrade.h>
#include <mytablemodel.h>
#include <resultmodel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getAlignPosition(QVector<float>, QVector<float>, QVector<float>, QVector<float>);
    int getMultipleRate(int wavePoints, int wavePoints2);
    QList<float> getVectorPeak(QVector<float> var);

public:
    myTableModel* model;
    resultModel* extModel;

    QString filePath1;
    QString filePath2;

    QVector<float> getBeforeCompareData(int alignBeforeDelta);
    QVector<float> getAfterCompareData(int alignAfterDelta);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void doSelectFont(int);

    void doSelectFont2(int);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;

    int multipleRate;
    int alignPosition;

    QMap<QDateTime, int> chopFactor;
    QMap<QDateTime, int> chopFactor2;

    int wavePoints;
    int wavePoints2;

    QDateTime tmStart;
    QDateTime tmStart2;

    int startPos1;
    int startPos2;

    bool transFlag;

    QVector<float> chopBefore1zhou;
    QVector<float> chopAfter1zhou;

    QVector<float> chopBefore1zhou2;
    QVector<float> chopAfter1zhou2;

    QVector<float> sampleBefore;
    QVector<float> sampleAfter;

    QVector<float> sampleBefore2;
    QVector<float> sampleAfter2;

    QVector<float> beforeCompareDataList;
    QVector<float> afterCompareDataList;

    QList<int> seqNumList1;
    QList<int> seqNumList2;
};
#endif // MAINWINDOW_H
