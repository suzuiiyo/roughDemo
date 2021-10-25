#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <mytablemodel.h>
#include <resultmodel.h>
#include <QMessageBox>
#include <math.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , transFlag(false)
{
    ui->setupUi(this);
    model = new myTableModel(this);
    extModel = new resultModel(this);

    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(model);

    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->setModel(model);

    ui->tableView_3->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_3->setModel(extModel);

    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(doSelectFont(int)));

    connect(ui->comboBox_2, SIGNAL(activated(int)), this, SLOT(doSelectFont2(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getAlignPosition(QVector<float> chopBefore1zhou, QVector<float> chopBefore1zhou2, QVector<float> chopAfter1zhou, QVector<float> chopAfter1zhou2)
{
    alignPosition = 0;

    uint stime = tmStart.toTime_t();
    uint etime = tmStart2.toTime_t();

    int tRet = stime - etime;

    if(tRet !=0){
//    //被对齐序列
        QList<float> beforePeakList = this->getVectorPeak(chopBefore1zhou);
        QList<float> before2PeakList = this->getVectorPeak(chopBefore1zhou2);

        auto beforePeakMin = std::min_element(std::begin(beforePeakList), std::end(beforePeakList));
        auto before2PeakMin = std::min_element(std::begin(before2PeakList), std::end(before2PeakList));

        int beforeAlign = 0;
        for(int i=0; i<chopBefore1zhou.size(); i++){
            if(chopBefore1zhou.at(i) == *beforePeakMin)
               beforeAlign = i;
        }

        int before2Align = 0;
        for(int i=0; i<chopBefore1zhou2.size(); i++){
            if(chopBefore1zhou2.at(i) == *before2PeakMin)
               before2Align = i;
        }

        alignPosition = beforeAlign*(multipleRate/wavePoints) - before2Align*(multipleRate/wavePoints2);

        qDebug() << alignPosition << "BEFOREBEFOREBEFORE";

        if(abs(alignPosition) > chopBefore1zhou.size()*(multipleRate/wavePoints) || abs(alignPosition) < multipleRate/wavePoints){
        QVector<float> chopAfter1zhou_half;
            QVector<float> chopAfter1zhou2_half;

            for(int i=0; i<2*wavePoints; i++){
            chopAfter1zhou_half.append(chopAfter1zhou.at(i));
            }

            for(int i=0; i<2*wavePoints2; i++){
            chopAfter1zhou2_half.append(chopAfter1zhou2.at(i));
            }

        //    //被对齐序列
            QList<float> afterPeakList = this->getVectorPeak(chopAfter1zhou_half);
            QList<float> afterPeak2List = this->getVectorPeak(chopAfter1zhou2_half);

            auto afterPeakMin = std::min_element(std::begin(chopAfter1zhou_half), std::end(chopAfter1zhou_half));
            auto after2PeakMin = std::min_element(std::begin(chopAfter1zhou2_half), std::end(chopAfter1zhou2_half));

            int afterAlign = 0;
            for(int i=chopAfter1zhou.size() - 1; i>0; i--){
                if(chopAfter1zhou.at(i) == *afterPeakMin)
                   afterAlign = i;
            }

            int after2Align = 0;
            for(int i=chopAfter1zhou2.size() - 1; i>0; i--){
                if(chopAfter1zhou2.at(i) == *after2PeakMin)
                   after2Align = i;
            }

            alignPosition = afterAlign*(multipleRate/wavePoints) - after2Align*(multipleRate/wavePoints2);

            qDebug() << alignPosition << "AFTERAFTERAFTERAFTER";
        }

        if(alignPosition < 0){
            transFlag = true;
        }else {
             transFlag = false;
        }

        return	alignPosition;
    }
    else{
        alignPosition = 0;
        return alignPosition;
    }
}

int MainWindow::getMultipleRate(int wavePoints, int wavePoints2)
{
    int m = 0;
    int n = 0;
    int k = 0;

    if(wavePoints < wavePoints2)
    {
        m = wavePoints2;
        n = wavePoints;
    }
    else
    {
        m = wavePoints;
        n = wavePoints2;
    }

    for(int i=m; i>0; i++){
        if(i%m == 0 && i%n == 0)
        {
            k = i;
            break;
        }
    }
    return k;
}


QList<float> MainWindow::getVectorPeak(QVector<float> var)
{
    QList<float> peakList;
    for(int i = 2; i < var.size()-3; i++)
    {
        if(var.at(i-2) >= var.at(i-1) && var.at(i-1) >= var.at(i) && var.at(i) <= var.at(i+1) && var.at(i + 1) <= var.at(i+2))
        {
            peakList.append(var.at(i));
        }
    }
    return peakList;
}

QVector<float> MainWindow::getBeforeCompareData(int alignBeforeDelta)
{
    QVector<float> beforeCompareData;

    int compareValue = multipleRate/wavePoints;
    int compareValue2 = multipleRate/wavePoints2;;
    int valueFactor = compareValue/compareValue2;
    int totalComparePoints = 0;

    seqNumList1.clear();
    seqNumList2.clear();
    if(transFlag == true){
        totalComparePoints = sampleBefore.size() + alignBeforeDelta;
        qDebug() << totalComparePoints << "OOOOOOOOOOOOOOOOOOOO";
    }else{
        totalComparePoints = sampleBefore.size();
    }

    for(int i=0; i < totalComparePoints / compareValue; i++)
    {
       float comparision1 = (sampleBefore.at(compareValue*i) - sampleBefore2.at(compareValue2*valueFactor*i))/sampleBefore2.at(compareValue2*valueFactor*i);
       float comparision2 = (sampleBefore.at(compareValue*i) - sampleBefore2.at(compareValue2*(valueFactor*i + 1)))/sampleBefore2.at(compareValue2*(valueFactor*i+1));

       seqNumList1.append(startPos1 + i);
          if(abs(comparision1) > abs(comparision2)){
          beforeCompareData.append(comparision2);
          seqNumList2.append(startPos2 + valueFactor*i + 1);
        }else
        {
            beforeCompareData.append(comparision1);
            seqNumList2.append(startPos2 + valueFactor*i);
        }
    }
    return beforeCompareData;
}

QVector<float> MainWindow::getAfterCompareData(int alignAfterDelta)
{
    QVector<float> afterCompareData;

    int compareValue = multipleRate/wavePoints;
    int compareValue2 = multipleRate/wavePoints2;
    int valueFactor = compareValue/compareValue2;
    int totalComparePoints = 0;

    int afterStartPos = 0;
    int afterStartPos2 = 0;
    if(transFlag == true){
        totalComparePoints = sampleAfter.size() + alignAfterDelta;
    }else
    {
        totalComparePoints = sampleAfter.size();
    }

    if(!seqNumList1.isEmpty())
    {
        afterStartPos = seqNumList1.last() + 1;
    }

    if(!seqNumList2.isEmpty())
    {
        afterStartPos2 = seqNumList2.last() + 1;
    }

    for(int i=0; i < totalComparePoints/compareValue; i++)
    {
        float comparision1 = (sampleAfter.at(compareValue*i) - sampleAfter2.at(compareValue2*valueFactor*i))/sampleAfter2.at(compareValue2*valueFactor*i);
        float comparision2 = (sampleAfter.at(compareValue*i) - sampleAfter2.at(compareValue2*(valueFactor*i + 1)))/sampleAfter2.at(compareValue2*(valueFactor*i + 1));

        qDebug() << sampleAfter.at(compareValue*i) << "111111111111";
        qDebug() << sampleAfter2.at(compareValue2*valueFactor*i) << "222222222222";
        qDebug() << sampleAfter2.at(compareValue2*(valueFactor*i + 1)) << "3333333333333";

        seqNumList1.append(afterStartPos + i);
        if(abs(comparision1) > abs(comparision2)){
           afterCompareData.append(comparision2);
           seqNumList2.append(afterStartPos2 + valueFactor*i + 1);
        }
        else
        {
           afterCompareData.append(comparision1);
           seqNumList2.append(afterStartPos2 + valueFactor*i);
        }
    }
    return afterCompareData;
}

void MainWindow::on_pushButton_clicked()
{
    filePath1 = QFileDialog::getOpenFileName(NULL, "标题", ".", "*.cfg");
    if(filePath1 != NULL){
        loadComtrade* loadFile = new loadComtrade();
        QList<QString> nameList = loadFile->getChName(filePath1);
        chopFactor = loadFile->getWavePoints(filePath1);
        wavePoints = chopFactor.begin().value();
        tmStart = chopFactor.begin().key();

        startPos1 = loadFile->getPointsSeqNum(filePath1, wavePoints);

        ui->comboBox->clear();
        for(int i=0; i<nameList.size(); i++){
            ui->comboBox->insertItem(i, tr(nameList.at(i).toLocal8Bit().constData()));
        }

        int chseq = 0;
        QMap<QVector<float>, QVector<float>> chopMap = loadFile->getSampleValue(filePath1, chseq);
        QMap<QVector<float>, QVector<float>>::const_iterator chopIter = chopMap.begin();

        chopBefore1zhou.clear();
        chopAfter1zhou.clear();
        foreach(float var, chopIter.key()){
            chopBefore1zhou.append(var);
        }

        foreach(float var, chopIter.value()){
            chopAfter1zhou.append(var);
        }

        QList<MyModelItem> itemList;


        for(int i=0; i < chopAfter1zhou.size(); i++){
            MyModelItem item;
            if(i< 2*wavePoints){
                item.m_beforeValue = chopBefore1zhou.at(i);
            }
            item.m_afterValue = chopAfter1zhou.at(i);
            itemList.append(item);
        }

        model = new myTableModel(this);
        model->setModelData(itemList);

        ui->tableView->setModel(model);
        }
        else
        {
            QMessageBox::information(NULL, "警告", "请选择一个cfg文件",
                                     QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        }
}

void MainWindow::on_pushButton_2_clicked()
{
    filePath2 = QFileDialog::getOpenFileName(NULL, "标题", ".", "*.cfg");
    if(filePath2 != NULL){
        loadComtrade* loadFile = new loadComtrade();
        QList<QString> nameList = loadFile->getChName(filePath2);
        chopFactor2 = loadFile->getWavePoints(filePath2);
        wavePoints2 = chopFactor2.begin().value();
        tmStart2 = chopFactor2.begin().key();

        startPos2 = loadFile->getPointsSeqNum(filePath2, wavePoints2);

        ui->comboBox_2->clear();
        for(int i=0; i<nameList.size(); i++){
            ui->comboBox_2->insertItem(i, tr(nameList.at(i).toLocal8Bit().constData()));
        }

        int chseq = 0;
        QMap<QVector<float>, QVector<float>> chopMap = loadFile->getSampleValue(filePath2, chseq);
        QMap<QVector<float>, QVector<float>>::const_iterator chopIter = chopMap.begin();

        chopBefore1zhou2.clear();
        chopAfter1zhou2.clear();
        foreach(float var, chopIter.key()){
            chopBefore1zhou2.append(var);
        }

        foreach(float var, chopIter.value()){
            chopAfter1zhou2.append(var);
        }

        QList<MyModelItem> itemList;

        for(int i=0; i < chopAfter1zhou2.size(); i++){
            MyModelItem item;
            if(i < 2*wavePoints2){
                item.m_beforeValue = chopBefore1zhou2.at(i);
            }
            item.m_afterValue = chopAfter1zhou2.at(i);

            itemList.append(item);
        }
        model = new myTableModel(this);
        model->setModelData(itemList);

        ui->tableView_2->setModel(model);
    }
    else
    {
        QMessageBox::information(NULL, "警告", "请选择一个cfg文件",
                                     QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }

    multipleRate = getMultipleRate(wavePoints, wavePoints2);
}

void MainWindow::doSelectFont(int)
{
    int chseq = ui->comboBox->currentIndex();
    loadComtrade* loadFile = new loadComtrade();
    QMap<QVector<float>, QVector<float>> chopMap = loadFile->getSampleValue(filePath1, chseq);

    chopBefore1zhou.clear();
    chopAfter1zhou.clear();
    QMap<QVector<float>, QVector<float>>::const_iterator chopIter = chopMap.begin();
    foreach(float var, chopIter.key())
    {
        chopBefore1zhou.append(var);
    }

    foreach(float var, chopIter.value())
    {
        chopAfter1zhou.append(var);
    }

    QList<MyModelItem> itemList;

    for(int i = 0; i < chopAfter1zhou.size(); i++){
        MyModelItem item;
        if(i < 2*wavePoints){
            item.m_beforeValue = chopBefore1zhou.at(i);
        }
        item.m_afterValue = chopAfter1zhou.at(i);

        itemList.append(item);
    }
    model = new myTableModel(this);
    model->setModelData(itemList);

    ui->tableView->setModel(model);
}

void MainWindow::doSelectFont2(int)
{
    int chseq = ui->comboBox_2->currentIndex();
    loadComtrade* loadFile = new loadComtrade();

    QList<MyModelItem> itemList;
    QMap<QVector<float>, QVector<float>> chopMap = loadFile->getSampleValue(filePath2, chseq);

    chopBefore1zhou2.clear();
    chopAfter1zhou2.clear();
    QMap<QVector<float>, QVector<float>>::const_iterator chopIter = chopMap.begin();
    foreach(float var, chopIter.key())
    {
        chopBefore1zhou2.append(var);
    }

    foreach(float var, chopIter.value())
    {
        chopAfter1zhou2.append(var);
    }

    for(int i = 0; i < chopAfter1zhou2.size(); i++){
        MyModelItem item;
        if(i < 2*wavePoints2){
            item.m_beforeValue = chopBefore1zhou2.at(i);
        }
        item.m_afterValue = chopAfter1zhou2.at(i);

        itemList.append(item);
    }
    model = new myTableModel(this);
    model->setModelData(itemList);

    ui->tableView_2->setModel(model);

    //获得对齐点位置
//    if(alignPosition == 0){
        alignPosition = getAlignPosition(chopBefore1zhou, chopBefore1zhou2, chopAfter1zhou, chopAfter1zhou2);
//    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString filePath = "/home/youpub/Downloads/py3/before.csv";
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "错误", "文件打开失败，信息没有保存！","确定");
    }
    file.close();

    sampleBefore.clear();
    file.setFileName(filePath);


    if(file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&file);
        qDebug() << alignPosition << "XXXXXXXXXXXX";
        if(transFlag == false){
            for(int i= alignPosition/(multipleRate/wavePoints); i< chopBefore1zhou.size(); i++)
            {
                out << chopBefore1zhou[i] << "\n";
                sampleBefore.append(chopBefore1zhou[i]);
                    for(int i = 0; i<multipleRate/wavePoints-1; i++){
                        out << "0" << "\n";
                        sampleBefore.append(0);
                    }
            }
        }else {
            for(int i= 0; i< chopBefore1zhou.size(); i++)
            {
                out << chopBefore1zhou[i] << "\n";
                sampleBefore.append(chopBefore1zhou[i]);
                    for(int i = 0; i<multipleRate/wavePoints-1; i++){
                        out << "0" << "\n";
                        sampleBefore.append(0);
                    }
            }
        }
    }
    file.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString filePath = "/home/youpub/Downloads/py3/after.csv";
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this,"错误", "文件打开失败，信息没有保存！","确定");
    }
    file.close();

    sampleAfter.clear();
    file.setFileName(filePath);
    if(file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&file);
        qDebug() << alignPosition << "YYYYYYYYYYYYY";
        if(transFlag == false){
            for(int i= alignPosition/(multipleRate/wavePoints); i< chopAfter1zhou.size(); i++)
            {
                out << chopAfter1zhou[i] << "\n";
                sampleAfter.append(chopAfter1zhou[i]);
                    for(int i = 0; i<multipleRate/wavePoints-1; i++){
                        out << "0" << "\n";
                        sampleAfter.append(0);
                    }
            }
        }else {
            for(int i= 0; i< chopAfter1zhou.size(); i++)
            {
                out << chopAfter1zhou[i] << "\n";
                sampleAfter.append(chopAfter1zhou[i]);
                    for(int i = 0; i<multipleRate/wavePoints-1; i++){
                        out << "0" << "\n";
                        sampleAfter.append(0);
                    }
            }
        }
    }

    file.close();
}

void MainWindow::on_pushButton_5_clicked()
{
    QString filePath = "/home/youpub/Downloads/py3/before2.csv";
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "错误", "文件打开失败，信息没有保存!","确定");
    }
    file.close();

    sampleBefore2.clear();
    file.setFileName(filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        if(transFlag == true){
            for(int i = abs(alignPosition)/(multipleRate/wavePoints2); i<chopBefore1zhou2.size(); i++)
            {
                out << chopBefore1zhou2[i] << "\n";
                sampleBefore2.append(chopBefore1zhou2[i]);
                for(int i = 0; i<multipleRate/wavePoints2-1; i++){
                    out << "0" << "\n";
                    sampleBefore2.append(0);
                }
            }
        }
        else
        {
            for(int i = 0; i<chopBefore1zhou2.size(); i++)
            {
                out << chopBefore1zhou2[i] << "\n";
                sampleBefore2.append(chopBefore1zhou2[i]);
                for(int i = 0; i<multipleRate/wavePoints-1; i++){
                    out << "0" << "\n";
                    sampleBefore2.append(0);
                }
            }
        }
    }
    file.close();

    beforeCompareDataList = getBeforeCompareData(alignPosition);
}

void MainWindow::on_pushButton_6_clicked()
{
    QString filePath = "/home/youpub/Downloads/py3/after2.csv";
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "错误", "文件打开失败，信息没有保存!","确定");
    }
    file.close();

    sampleAfter2.clear();
    file.setFileName(filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        if(transFlag == true){
            for(int i = abs(alignPosition) / (multipleRate/wavePoints2); i<chopAfter1zhou2.size(); i++)
            {
                out << chopAfter1zhou2[i] << "\n";
                sampleAfter2.append(chopAfter1zhou2[i]);
                for(int i = 0; i<multipleRate/wavePoints2-1; i++){
                    out << "0" << "\n";
                    sampleAfter2.append(0);
                }
            }
        }
        else
        {
            for(int i = 0; i<chopAfter1zhou2.size(); i++)
            {

                out << chopAfter1zhou2[i] << "\n";
                sampleAfter2.append(chopAfter1zhou2[i]);
                for(int i = 0; i<multipleRate/wavePoints2+1; i++){
                    out << "0" << "\n";
                    sampleAfter2.append(0);
                }
            }
        }
     }
     file.close();

     afterCompareDataList = getAfterCompareData(alignPosition);
}

void MainWindow::on_pushButton_7_clicked()
{
    extModel = new resultModel(this);
    QList<resultModelItem> resultList;
    for(int i = 0; i < beforeCompareDataList.size(); i++){
        resultModelItem item;
        item.beforeCompareFirSeqNum = seqNumList1.at(i);
        item.beforeCompareSecSeqNum = seqNumList2.at(i);
        item.beforeComparisionResult = beforeCompareDataList.at(i);

        item.afterCompareFirSeqNum = 0;
        item.afterCompareSecSeqNum = 0;
        item.afterComparisionResult = 0;
        resultList.append(item);
     }

    for(int i = beforeCompareDataList.size(); i < seqNumList1.size(); i++){
        resultModelItem item;
        item.beforeCompareFirSeqNum = 0;
        item.beforeCompareSecSeqNum = 0;
        item.beforeComparisionResult = 0;

        item.afterCompareFirSeqNum = seqNumList1.at(i);
        item.afterCompareSecSeqNum = seqNumList2.at(i);
        item.afterComparisionResult = afterCompareDataList.at(i - beforeCompareDataList.size());
        resultList.append(item);
    }
    extModel->setModelData(resultList);
    this->ui->tableView_3->setModel(extModel);

//    qDebug() << beforeCompareDataList << "XXXXXXXX";
//    qDebug() << afterCompareDataList << "YYYYYYYYYYY";
}
