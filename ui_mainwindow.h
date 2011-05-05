/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu May 5 10:14:59 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open_Sequence;
    QAction *action_About;
    QAction *actionEvaluation;
    QAction *actionNavigation;
    QAction *actionExit;
    QAction *actionApply_to_Entire_Dataset;
    QAction *actionExport_Dataset;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QWidget *tabPreprocess;
    QPushButton *pushButtonDrawTripwire;
    QSpinBox *spinBox;
    QLabel *label_7;
    QLabel *label_15;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QWidget *tabCorrelation;
    QLabel *labelConstOffset;
    QSpinBox *spinBoxConstOffset;
    QLabel *labelSearchRadius;
    QSpinBox *spinBoxSearchRadius;
    QLabel *labelSearchLevels;
    QSpinBox *spinBoxSearchLevels;
    QLabel *labelMinSample;
    QLabel *labelFovealKernelBaseConstant;
    QLabel *labelFovealKernelNumLevels;
    QLabel *labelFovealKernelTypeSpacing;
    QCheckBox *checkBoxDisplayFovealKernel;
    QDoubleSpinBox *doubleSpinBoxMinSample;
    QDoubleSpinBox *doubleSpinBoxFovealKernelBaseConstant;
    QSpinBox *spinBoxFovealKernelNumLevels;
    QComboBox *comboBoxFovealKernelTypeSpacing;
    QLabel *labelCorrErrorThresh;
    QLabel *labelDegeneracyThresh;
    QLabel *labelShapeChangeThresh;
    QLabel *labelRejectionRateTimeConstant;
    QLabel *labelRejectionRateThresh;
    QLabel *labelConstExpansionThresh;
    QLabel *labelInverseConstellationExpansionThresh;
    QLabel *labelStarOutOfBounds;
    QLabel *labelCenterOutOfBounds;
    QDoubleSpinBox *doubleSpinBoxCorrErrorThresh;
    QDoubleSpinBox *doubleSpinBoxDegeneracyThresh;
    QDoubleSpinBox *doubleSpinBoxShapeChangeThresh;
    QDoubleSpinBox *doubleSpinBoxRejectionRateTimeConstant;
    QDoubleSpinBox *doubleSpinBoxRejectionRateThresh;
    QSpinBox *spinBoxConstExpansionThresh;
    QDoubleSpinBox *doubleSpinBoxInverseConstellationExpansionThresh;
    QSpinBox *spinBoxStarOutOfBounds;
    QSpinBox *spinBoxCenterOutOfBounds;
    QWidget *tabOpticalFlow;
    QComboBox *comboBoxOFAlgorithm;
    QLabel *label;
    QCheckBox *checkBoxOFShowFeatures;
    QWidget *tabBlob;
    QWidget *tabNavigation;
    QWidget *tab;
    QPlainTextEdit *plainTextEditTrace;
    QGraphicsView *graphicsView;
    QPushButton *pushButtonTrack;
    QScrollBar *imageScrollBar;
    QCheckBox *checkBoxFitToWindow;
    QGraphicsView *graphicsView_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QWidget *tab_5;
    QLabel *label_6;
    QComboBox *comboBox_3;
    QWidget *tab_3;
    QCheckBox *checkBoxGLTNegative;
    QCheckBox *checkBoxLogarithm;
    QCheckBox *checkBoxPowerLaw;
    QCheckBox *checkBoxGLTPiecewise;
    QCheckBox *checkBoxBitPlaneSlicing;
    QSlider *horizontalSliderR1;
    QSlider *horizontalSliderR1_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QSlider *horizontalSliderR1_3;
    QSlider *horizontalSliderR1_4;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_14;
    QWidget *tab_6;
    QComboBox *comboBoxReduceGraylevels;
    QLabel *label_3;
    QWidget *tab_7;
    QCheckBox *checkBoxHistogramEqualization;
    QWidget *tab_8;
    QWidget *tab_9;
    QComboBox *comboBoxSecondWindow;
    QLabel *label_2;
    QCheckBox *checkBoxSwapRedBlue;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QMenu *menuDataset_Actions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1311, 1050);
        action_Open_Sequence = new QAction(MainWindow);
        action_Open_Sequence->setObjectName(QString::fromUtf8("action_Open_Sequence"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        actionEvaluation = new QAction(MainWindow);
        actionEvaluation->setObjectName(QString::fromUtf8("actionEvaluation"));
        actionNavigation = new QAction(MainWindow);
        actionNavigation->setObjectName(QString::fromUtf8("actionNavigation"));
        actionNavigation->setCheckable(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionApply_to_Entire_Dataset = new QAction(MainWindow);
        actionApply_to_Entire_Dataset->setObjectName(QString::fromUtf8("actionApply_to_Entire_Dataset"));
        actionExport_Dataset = new QAction(MainWindow);
        actionExport_Dataset->setObjectName(QString::fromUtf8("actionExport_Dataset"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(650, 570, 560, 310));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tabPreprocess = new QWidget();
        tabPreprocess->setObjectName(QString::fromUtf8("tabPreprocess"));
        pushButtonDrawTripwire = new QPushButton(tabPreprocess);
        pushButtonDrawTripwire->setObjectName(QString::fromUtf8("pushButtonDrawTripwire"));
        pushButtonDrawTripwire->setGeometry(QRect(20, 170, 111, 27));
        spinBox = new QSpinBox(tabPreprocess);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(240, 27, 59, 27));
        label_7 = new QLabel(tabPreprocess);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 30, 211, 17));
        label_15 = new QLabel(tabPreprocess);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 90, 101, 17));
        checkBox = new QCheckBox(tabPreprocess);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(150, 90, 98, 22));
        checkBox_2 = new QCheckBox(tabPreprocess);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(150, 120, 98, 22));
        tabWidget->addTab(tabPreprocess, QString());
        tabCorrelation = new QWidget();
        tabCorrelation->setObjectName(QString::fromUtf8("tabCorrelation"));
        labelConstOffset = new QLabel(tabCorrelation);
        labelConstOffset->setObjectName(QString::fromUtf8("labelConstOffset"));
        labelConstOffset->setGeometry(QRect(10, 20, 101, 16));
        spinBoxConstOffset = new QSpinBox(tabCorrelation);
        spinBoxConstOffset->setObjectName(QString::fromUtf8("spinBoxConstOffset"));
        spinBoxConstOffset->setGeometry(QRect(190, 20, 41, 20));
        labelSearchRadius = new QLabel(tabCorrelation);
        labelSearchRadius->setObjectName(QString::fromUtf8("labelSearchRadius"));
        labelSearchRadius->setGeometry(QRect(10, 50, 81, 16));
        spinBoxSearchRadius = new QSpinBox(tabCorrelation);
        spinBoxSearchRadius->setObjectName(QString::fromUtf8("spinBoxSearchRadius"));
        spinBoxSearchRadius->setGeometry(QRect(190, 50, 42, 22));
        labelSearchLevels = new QLabel(tabCorrelation);
        labelSearchLevels->setObjectName(QString::fromUtf8("labelSearchLevels"));
        labelSearchLevels->setGeometry(QRect(10, 90, 71, 16));
        spinBoxSearchLevels = new QSpinBox(tabCorrelation);
        spinBoxSearchLevels->setObjectName(QString::fromUtf8("spinBoxSearchLevels"));
        spinBoxSearchLevels->setGeometry(QRect(190, 80, 42, 22));
        labelMinSample = new QLabel(tabCorrelation);
        labelMinSample->setObjectName(QString::fromUtf8("labelMinSample"));
        labelMinSample->setGeometry(QRect(10, 120, 111, 16));
        labelFovealKernelBaseConstant = new QLabel(tabCorrelation);
        labelFovealKernelBaseConstant->setObjectName(QString::fromUtf8("labelFovealKernelBaseConstant"));
        labelFovealKernelBaseConstant->setGeometry(QRect(10, 160, 151, 16));
        labelFovealKernelNumLevels = new QLabel(tabCorrelation);
        labelFovealKernelNumLevels->setObjectName(QString::fromUtf8("labelFovealKernelNumLevels"));
        labelFovealKernelNumLevels->setGeometry(QRect(10, 190, 141, 16));
        labelFovealKernelTypeSpacing = new QLabel(tabCorrelation);
        labelFovealKernelTypeSpacing->setObjectName(QString::fromUtf8("labelFovealKernelTypeSpacing"));
        labelFovealKernelTypeSpacing->setGeometry(QRect(10, 220, 141, 16));
        checkBoxDisplayFovealKernel = new QCheckBox(tabCorrelation);
        checkBoxDisplayFovealKernel->setObjectName(QString::fromUtf8("checkBoxDisplayFovealKernel"));
        checkBoxDisplayFovealKernel->setGeometry(QRect(50, 250, 141, 18));
        doubleSpinBoxMinSample = new QDoubleSpinBox(tabCorrelation);
        doubleSpinBoxMinSample->setObjectName(QString::fromUtf8("doubleSpinBoxMinSample"));
        doubleSpinBoxMinSample->setGeometry(QRect(170, 120, 62, 22));
        doubleSpinBoxFovealKernelBaseConstant = new QDoubleSpinBox(tabCorrelation);
        doubleSpinBoxFovealKernelBaseConstant->setObjectName(QString::fromUtf8("doubleSpinBoxFovealKernelBaseConstant"));
        doubleSpinBoxFovealKernelBaseConstant->setGeometry(QRect(170, 160, 62, 22));
        spinBoxFovealKernelNumLevels = new QSpinBox(tabCorrelation);
        spinBoxFovealKernelNumLevels->setObjectName(QString::fromUtf8("spinBoxFovealKernelNumLevels"));
        spinBoxFovealKernelNumLevels->setGeometry(QRect(190, 190, 42, 22));
        comboBoxFovealKernelTypeSpacing = new QComboBox(tabCorrelation);
        comboBoxFovealKernelTypeSpacing->setObjectName(QString::fromUtf8("comboBoxFovealKernelTypeSpacing"));
        comboBoxFovealKernelTypeSpacing->setGeometry(QRect(150, 220, 81, 22));
        labelCorrErrorThresh = new QLabel(tabCorrelation);
        labelCorrErrorThresh->setObjectName(QString::fromUtf8("labelCorrErrorThresh"));
        labelCorrErrorThresh->setGeometry(QRect(260, 10, 141, 16));
        labelDegeneracyThresh = new QLabel(tabCorrelation);
        labelDegeneracyThresh->setObjectName(QString::fromUtf8("labelDegeneracyThresh"));
        labelDegeneracyThresh->setGeometry(QRect(260, 40, 121, 16));
        labelShapeChangeThresh = new QLabel(tabCorrelation);
        labelShapeChangeThresh->setObjectName(QString::fromUtf8("labelShapeChangeThresh"));
        labelShapeChangeThresh->setGeometry(QRect(260, 70, 131, 16));
        labelRejectionRateTimeConstant = new QLabel(tabCorrelation);
        labelRejectionRateTimeConstant->setObjectName(QString::fromUtf8("labelRejectionRateTimeConstant"));
        labelRejectionRateTimeConstant->setGeometry(QRect(260, 100, 151, 16));
        labelRejectionRateThresh = new QLabel(tabCorrelation);
        labelRejectionRateThresh->setObjectName(QString::fromUtf8("labelRejectionRateThresh"));
        labelRejectionRateThresh->setGeometry(QRect(260, 130, 131, 16));
        labelConstExpansionThresh = new QLabel(tabCorrelation);
        labelConstExpansionThresh->setObjectName(QString::fromUtf8("labelConstExpansionThresh"));
        labelConstExpansionThresh->setGeometry(QRect(260, 160, 171, 16));
        labelInverseConstellationExpansionThresh = new QLabel(tabCorrelation);
        labelInverseConstellationExpansionThresh->setObjectName(QString::fromUtf8("labelInverseConstellationExpansionThresh"));
        labelInverseConstellationExpansionThresh->setGeometry(QRect(260, 190, 211, 16));
        labelStarOutOfBounds = new QLabel(tabCorrelation);
        labelStarOutOfBounds->setObjectName(QString::fromUtf8("labelStarOutOfBounds"));
        labelStarOutOfBounds->setGeometry(QRect(260, 220, 101, 16));
        labelCenterOutOfBounds = new QLabel(tabCorrelation);
        labelCenterOutOfBounds->setObjectName(QString::fromUtf8("labelCenterOutOfBounds"));
        labelCenterOutOfBounds->setGeometry(QRect(260, 250, 111, 16));
        doubleSpinBoxCorrErrorThresh = new QDoubleSpinBox(tabCorrelation);
        doubleSpinBoxCorrErrorThresh->setObjectName(QString::fromUtf8("doubleSpinBoxCorrErrorThresh"));
        doubleSpinBoxCorrErrorThresh->setGeometry(QRect(480, 10, 62, 22));
        doubleSpinBoxDegeneracyThresh = new QDoubleSpinBox(tabCorrelation);
        doubleSpinBoxDegeneracyThresh->setObjectName(QString::fromUtf8("doubleSpinBoxDegeneracyThresh"));
        doubleSpinBoxDegeneracyThresh->setGeometry(QRect(481, 40, 61, 22));
        doubleSpinBoxShapeChangeThresh = new QDoubleSpinBox(tabCorrelation);
        doubleSpinBoxShapeChangeThresh->setObjectName(QString::fromUtf8("doubleSpinBoxShapeChangeThresh"));
        doubleSpinBoxShapeChangeThresh->setGeometry(QRect(480, 70, 62, 22));
        doubleSpinBoxRejectionRateTimeConstant = new QDoubleSpinBox(tabCorrelation);
        doubleSpinBoxRejectionRateTimeConstant->setObjectName(QString::fromUtf8("doubleSpinBoxRejectionRateTimeConstant"));
        doubleSpinBoxRejectionRateTimeConstant->setGeometry(QRect(480, 100, 62, 22));
        doubleSpinBoxRejectionRateThresh = new QDoubleSpinBox(tabCorrelation);
        doubleSpinBoxRejectionRateThresh->setObjectName(QString::fromUtf8("doubleSpinBoxRejectionRateThresh"));
        doubleSpinBoxRejectionRateThresh->setGeometry(QRect(480, 130, 62, 22));
        spinBoxConstExpansionThresh = new QSpinBox(tabCorrelation);
        spinBoxConstExpansionThresh->setObjectName(QString::fromUtf8("spinBoxConstExpansionThresh"));
        spinBoxConstExpansionThresh->setGeometry(QRect(500, 160, 42, 22));
        doubleSpinBoxInverseConstellationExpansionThresh = new QDoubleSpinBox(tabCorrelation);
        doubleSpinBoxInverseConstellationExpansionThresh->setObjectName(QString::fromUtf8("doubleSpinBoxInverseConstellationExpansionThresh"));
        doubleSpinBoxInverseConstellationExpansionThresh->setGeometry(QRect(480, 190, 62, 22));
        spinBoxStarOutOfBounds = new QSpinBox(tabCorrelation);
        spinBoxStarOutOfBounds->setObjectName(QString::fromUtf8("spinBoxStarOutOfBounds"));
        spinBoxStarOutOfBounds->setGeometry(QRect(500, 220, 42, 22));
        spinBoxCenterOutOfBounds = new QSpinBox(tabCorrelation);
        spinBoxCenterOutOfBounds->setObjectName(QString::fromUtf8("spinBoxCenterOutOfBounds"));
        spinBoxCenterOutOfBounds->setGeometry(QRect(500, 250, 42, 22));
        tabWidget->addTab(tabCorrelation, QString());
        tabOpticalFlow = new QWidget();
        tabOpticalFlow->setObjectName(QString::fromUtf8("tabOpticalFlow"));
        comboBoxOFAlgorithm = new QComboBox(tabOpticalFlow);
        comboBoxOFAlgorithm->setObjectName(QString::fromUtf8("comboBoxOFAlgorithm"));
        comboBoxOFAlgorithm->setGeometry(QRect(110, 18, 85, 27));
        label = new QLabel(tabOpticalFlow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 81, 21));
        checkBoxOFShowFeatures = new QCheckBox(tabOpticalFlow);
        checkBoxOFShowFeatures->setObjectName(QString::fromUtf8("checkBoxOFShowFeatures"));
        checkBoxOFShowFeatures->setGeometry(QRect(20, 240, 141, 22));
        tabWidget->addTab(tabOpticalFlow, QString());
        tabBlob = new QWidget();
        tabBlob->setObjectName(QString::fromUtf8("tabBlob"));
        tabWidget->addTab(tabBlob, QString());
        tabNavigation = new QWidget();
        tabNavigation->setObjectName(QString::fromUtf8("tabNavigation"));
        tabWidget->addTab(tabNavigation, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        plainTextEditTrace = new QPlainTextEdit(tab);
        plainTextEditTrace->setObjectName(QString::fromUtf8("plainTextEditTrace"));
        plainTextEditTrace->setGeometry(QRect(7, 10, 541, 251));
        tabWidget->addTab(tab, QString());
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 642, 482));
        graphicsView->setMouseTracking(true);
        pushButtonTrack = new QPushButton(centralWidget);
        pushButtonTrack->setObjectName(QString::fromUtf8("pushButtonTrack"));
        pushButtonTrack->setGeometry(QRect(780, 910, 80, 23));
        imageScrollBar = new QScrollBar(centralWidget);
        imageScrollBar->setObjectName(QString::fromUtf8("imageScrollBar"));
        imageScrollBar->setGeometry(QRect(10, 490, 641, 16));
        imageScrollBar->setOrientation(Qt::Horizontal);
        checkBoxFitToWindow = new QCheckBox(centralWidget);
        checkBoxFitToWindow->setObjectName(QString::fromUtf8("checkBoxFitToWindow"));
        checkBoxFitToWindow->setGeometry(QRect(10, 530, 161, 20));
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(660, 0, 642, 482));
        graphicsView_2->setMouseTracking(true);
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 570, 560, 310));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 34, 67, 17));
        comboBox = new QComboBox(tab_4);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(100, 30, 131, 27));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 90, 67, 17));
        comboBox_2 = new QComboBox(tab_4);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(120, 90, 85, 27));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 50, 67, 17));
        comboBox_3 = new QComboBox(tab_5);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(140, 40, 85, 27));
        tabWidget_2->addTab(tab_5, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        checkBoxGLTNegative = new QCheckBox(tab_3);
        checkBoxGLTNegative->setObjectName(QString::fromUtf8("checkBoxGLTNegative"));
        checkBoxGLTNegative->setGeometry(QRect(31, 20, 98, 22));
        checkBoxLogarithm = new QCheckBox(tab_3);
        checkBoxLogarithm->setObjectName(QString::fromUtf8("checkBoxLogarithm"));
        checkBoxLogarithm->setGeometry(QRect(30, 60, 98, 22));
        checkBoxPowerLaw = new QCheckBox(tab_3);
        checkBoxPowerLaw->setObjectName(QString::fromUtf8("checkBoxPowerLaw"));
        checkBoxPowerLaw->setGeometry(QRect(30, 100, 98, 22));
        checkBoxGLTPiecewise = new QCheckBox(tab_3);
        checkBoxGLTPiecewise->setObjectName(QString::fromUtf8("checkBoxGLTPiecewise"));
        checkBoxGLTPiecewise->setGeometry(QRect(30, 140, 141, 22));
        checkBoxBitPlaneSlicing = new QCheckBox(tab_3);
        checkBoxBitPlaneSlicing->setObjectName(QString::fromUtf8("checkBoxBitPlaneSlicing"));
        checkBoxBitPlaneSlicing->setGeometry(QRect(30, 220, 141, 22));
        horizontalSliderR1 = new QSlider(tab_3);
        horizontalSliderR1->setObjectName(QString::fromUtf8("horizontalSliderR1"));
        horizontalSliderR1->setGeometry(QRect(240, 140, 111, 29));
        horizontalSliderR1->setMaximum(255);
        horizontalSliderR1->setOrientation(Qt::Horizontal);
        horizontalSliderR1_2 = new QSlider(tab_3);
        horizontalSliderR1_2->setObjectName(QString::fromUtf8("horizontalSliderR1_2"));
        horizontalSliderR1_2->setGeometry(QRect(418, 140, 111, 29));
        horizontalSliderR1_2->setMaximum(255);
        horizontalSliderR1_2->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(390, 146, 21, 17));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(209, 145, 21, 17));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(209, 179, 21, 17));
        horizontalSliderR1_3 = new QSlider(tab_3);
        horizontalSliderR1_3->setObjectName(QString::fromUtf8("horizontalSliderR1_3"));
        horizontalSliderR1_3->setGeometry(QRect(240, 174, 111, 29));
        horizontalSliderR1_3->setMaximum(255);
        horizontalSliderR1_3->setOrientation(Qt::Horizontal);
        horizontalSliderR1_4 = new QSlider(tab_3);
        horizontalSliderR1_4->setObjectName(QString::fromUtf8("horizontalSliderR1_4"));
        horizontalSliderR1_4->setGeometry(QRect(418, 174, 111, 29));
        horizontalSliderR1_4->setMaximum(255);
        horizontalSliderR1_4->setOrientation(Qt::Horizontal);
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(390, 180, 21, 17));
        doubleSpinBox = new QDoubleSpinBox(tab_3);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(300, 60, 62, 27));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(201, 64, 67, 17));
        doubleSpinBox_2 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(299, 96, 62, 27));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(200, 100, 67, 17));
        doubleSpinBox_3 = new QDoubleSpinBox(tab_3);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(479, 92, 62, 27));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(380, 96, 67, 17));
        tabWidget_2->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        comboBoxReduceGraylevels = new QComboBox(tab_6);
        comboBoxReduceGraylevels->setObjectName(QString::fromUtf8("comboBoxReduceGraylevels"));
        comboBoxReduceGraylevels->setGeometry(QRect(200, 36, 85, 27));
        label_3 = new QLabel(tab_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 40, 161, 17));
        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        checkBoxHistogramEqualization = new QCheckBox(tab_7);
        checkBoxHistogramEqualization->setObjectName(QString::fromUtf8("checkBoxHistogramEqualization"));
        checkBoxHistogramEqualization->setGeometry(QRect(20, 30, 241, 22));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        tabWidget_2->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        tabWidget_2->addTab(tab_9, QString());
        comboBoxSecondWindow = new QComboBox(centralWidget);
        comboBoxSecondWindow->setObjectName(QString::fromUtf8("comboBoxSecondWindow"));
        comboBoxSecondWindow->setGeometry(QRect(780, 485, 191, 27));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(660, 490, 121, 17));
        checkBoxSwapRedBlue = new QCheckBox(centralWidget);
        checkBoxSwapRedBlue->setObjectName(QString::fromUtf8("checkBoxSwapRedBlue"));
        checkBoxSwapRedBlue->setGeometry(QRect(170, 530, 161, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1311, 25));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        menuDataset_Actions = new QMenu(menuBar);
        menuDataset_Actions->setObjectName(QString::fromUtf8("menuDataset_Actions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuDataset_Actions->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_Open_Sequence);
        menu_File->addAction(actionExit);
        menu_Help->addAction(action_About);
        menuDataset_Actions->addAction(actionApply_to_Entire_Dataset);
        menuDataset_Actions->addAction(actionExport_Dataset);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Computer Vision Toolkit", 0, QApplication::UnicodeUTF8));
        action_Open_Sequence->setText(QApplication::translate("MainWindow", "&Open Sequence or Movie", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        actionEvaluation->setText(QApplication::translate("MainWindow", "Evaluation", 0, QApplication::UnicodeUTF8));
        actionNavigation->setText(QApplication::translate("MainWindow", "Navigation", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionApply_to_Entire_Dataset->setText(QApplication::translate("MainWindow", "Apply to Entire Dataset", 0, QApplication::UnicodeUTF8));
        actionExport_Dataset->setText(QApplication::translate("MainWindow", "Export Dataset", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Stablization", 0, QApplication::UnicodeUTF8));
        pushButtonDrawTripwire->setText(QApplication::translate("MainWindow", "Draw Tripwire", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Ignore pixels smaller than NxN", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Classification:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Vehicles", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "People", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabPreprocess), QApplication::translate("MainWindow", "Persistent Stare", 0, QApplication::UnicodeUTF8));
        labelConstOffset->setText(QApplication::translate("MainWindow", "Constellation Offset", 0, QApplication::UnicodeUTF8));
        labelSearchRadius->setText(QApplication::translate("MainWindow", "Search Radius", 0, QApplication::UnicodeUTF8));
        labelSearchLevels->setText(QApplication::translate("MainWindow", "Search Levels", 0, QApplication::UnicodeUTF8));
        labelMinSample->setText(QApplication::translate("MainWindow", "Min Sample Proportion", 0, QApplication::UnicodeUTF8));
        labelFovealKernelBaseConstant->setText(QApplication::translate("MainWindow", "Foveal Kernel Base Constant", 0, QApplication::UnicodeUTF8));
        labelFovealKernelNumLevels->setText(QApplication::translate("MainWindow", "Foveal Kernel Number Levels", 0, QApplication::UnicodeUTF8));
        labelFovealKernelTypeSpacing->setText(QApplication::translate("MainWindow", "Foveal Kernel Type Spacing", 0, QApplication::UnicodeUTF8));
        checkBoxDisplayFovealKernel->setText(QApplication::translate("MainWindow", "Display Foveal Kernel", 0, QApplication::UnicodeUTF8));
        comboBoxFovealKernelTypeSpacing->clear();
        comboBoxFovealKernelTypeSpacing->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Exponential", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Geometric", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Linear", 0, QApplication::UnicodeUTF8)
        );
        labelCorrErrorThresh->setText(QApplication::translate("MainWindow", "Correlation Error Threshold", 0, QApplication::UnicodeUTF8));
        labelDegeneracyThresh->setText(QApplication::translate("MainWindow", "Degeneracy Threshold", 0, QApplication::UnicodeUTF8));
        labelShapeChangeThresh->setText(QApplication::translate("MainWindow", "Shape Change Threshold", 0, QApplication::UnicodeUTF8));
        labelRejectionRateTimeConstant->setText(QApplication::translate("MainWindow", "Rejection Rate Time Constant", 0, QApplication::UnicodeUTF8));
        labelRejectionRateThresh->setText(QApplication::translate("MainWindow", "Rejection Rate Threshold", 0, QApplication::UnicodeUTF8));
        labelConstExpansionThresh->setText(QApplication::translate("MainWindow", "Constellation Expansion Threshold", 0, QApplication::UnicodeUTF8));
        labelInverseConstellationExpansionThresh->setText(QApplication::translate("MainWindow", "Inverse Constellation Expansion Threshold", 0, QApplication::UnicodeUTF8));
        labelStarOutOfBounds->setText(QApplication::translate("MainWindow", "Star Out of Bounds", 0, QApplication::UnicodeUTF8));
        labelCenterOutOfBounds->setText(QApplication::translate("MainWindow", "Center Out of Bounds", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCorrelation), QApplication::translate("MainWindow", "Correlation", 0, QApplication::UnicodeUTF8));
        comboBoxOFAlgorithm->clear();
        comboBoxOFAlgorithm->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "KLT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Horn-Schunck", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Farneback", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "Algorithm", 0, QApplication::UnicodeUTF8));
        checkBoxOFShowFeatures->setText(QApplication::translate("MainWindow", "Show Features?", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabOpticalFlow), QApplication::translate("MainWindow", "Optical Flow", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabBlob), QApplication::translate("MainWindow", "Blob", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabNavigation), QApplication::translate("MainWindow", "Navigation", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Debug Messages", 0, QApplication::UnicodeUTF8));
        pushButtonTrack->setText(QApplication::translate("MainWindow", "Track", 0, QApplication::UnicodeUTF8));
        checkBoxFitToWindow->setText(QApplication::translate("MainWindow", "Fit to window", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Filter", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Mean Filter :: Arithmetic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mean Filter :: Geometric", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mean Filter :: Contraharmonic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mean Filter :: Harmonic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Order Statistics :: Median", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Order Statistics :: Max", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Order Statistics :: Min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Order Statistics :: Midpoint", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Order Statistics :: Alpha Trimmed", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Adaptive Local Noise Reduction Filter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Adaptive Median Filter", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "Mask Size", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1x1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3x3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5x5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7x7", 0, QApplication::UnicodeUTF8)
        );
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Smoothing", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Algorithm", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Highboost Laplacian", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Gradient", 0, QApplication::UnicodeUTF8)
        );
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Sharpening", 0, QApplication::UnicodeUTF8));
        checkBoxGLTNegative->setText(QApplication::translate("MainWindow", "Negative", 0, QApplication::UnicodeUTF8));
        checkBoxLogarithm->setText(QApplication::translate("MainWindow", "Logarithm", 0, QApplication::UnicodeUTF8));
        checkBoxPowerLaw->setText(QApplication::translate("MainWindow", "Power Law", 0, QApplication::UnicodeUTF8));
        checkBoxGLTPiecewise->setText(QApplication::translate("MainWindow", "Piecewise Linear", 0, QApplication::UnicodeUTF8));
        checkBoxBitPlaneSlicing->setText(QApplication::translate("MainWindow", "Bit Plane Slicing", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "S1", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "R1", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "R2", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "S2", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Constant", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Constant", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Gamma", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Gray Level Transformations", 0, QApplication::UnicodeUTF8));
        comboBoxReduceGraylevels->clear();
        comboBoxReduceGraylevels->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "128", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "64", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MainWindow", "Number of Gray levels", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Reduce Graylevels", 0, QApplication::UnicodeUTF8));
        checkBoxHistogramEqualization->setText(QApplication::translate("MainWindow", "Apply histogram equalization?", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "Histogram Equalization", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "Noise", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("MainWindow", "Edge Filters", 0, QApplication::UnicodeUTF8));
        comboBoxSecondWindow->clear();
        comboBoxSecondWindow->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Blank", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Show Processed Image", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Show Previous Frame", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "Second Window", 0, QApplication::UnicodeUTF8));
        checkBoxSwapRedBlue->setText(QApplication::translate("MainWindow", "Swap red and blue?", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        menuDataset_Actions->setTitle(QApplication::translate("MainWindow", "Dataset Actions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
