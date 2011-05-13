/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri May 13 12:24:21 2011
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
    QGraphicsView *graphicsView;
    QScrollBar *imageScrollBar;
    QCheckBox *checkBoxFitToWindow;
    QGraphicsView *graphicsView_2;
    QTabWidget *tabWidget;
    QWidget *tabSmoothing;
    QLabel *label_4;
    QComboBox *comboBoxSmoothingFilter;
    QLabel *label_5;
    QComboBox *comboBoxSmoothingMask;
    QCheckBox *checkBoxSmoothing;
    QWidget *tabSharpening;
    QLabel *label_6;
    QComboBox *comboBoxSharpeningAlgorithm;
    QCheckBox *checkBoxSharpening;
    QWidget *tabGLT;
    QCheckBox *checkBoxNegative;
    QCheckBox *checkBoxLogarithm;
    QCheckBox *checkBoxPowerLaw;
    QCheckBox *checkBoxContrastStretching;
    QCheckBox *checkBoxBitPlaneSlicing;
    QSlider *horizontalSliderR1;
    QSlider *horizontalSliderS1;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QSlider *horizontalSliderR2;
    QSlider *horizontalSliderS2;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBoxLogarithmConstant;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBoxPowerLawConstant;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBoxPowerLawGamma;
    QLabel *label_14;
    QComboBox *comboBoxBitPlane;
    QLabel *label_17;
    QWidget *tabReduceGraylevels;
    QComboBox *comboBoxReduceGraylevels;
    QLabel *label_3;
    QWidget *tabHistogram;
    QCheckBox *checkBoxHistogramEqualization;
    QWidget *tabNoise;
    QCheckBox *checkBoxAddGaussianNoise;
    QSpinBox *spinBoxImpulseNoise;
    QSpinBox *spinBoxGammaVar;
    QLabel *label_21;
    QLabel *label_22;
    QSpinBox *spinBoxGammaAlpha;
    QLabel *label_23;
    QLabel *label_24;
    QCheckBox *checkBoxAddGammaNoise;
    QCheckBox *checkBoxAddImpulseNoise;
    QWidget *tabEdgeFilters;
    QComboBox *comboBoxEdgeFilter;
    QLabel *label_16;
    QWidget *tabPS;
    QLabel *label_7;
    QPushButton *pushButtonDrawTripwire;
    QCheckBox *checkBox_2;
    QLabel *label_15;
    QCheckBox *checkBox;
    QSpinBox *spinBox;
    QWidget *tabStabilization;
    QWidget *tabCorr;
    QCheckBox *checkBoxDisplayFovealKernel;
    QDoubleSpinBox *doubleSpinBoxInverseConstellationExpansionThresh;
    QLabel *labelFovealKernelTypeSpacing;
    QSpinBox *spinBoxConstOffset;
    QLabel *labelRejectionRateThresh;
    QSpinBox *spinBoxFovealKernelNumLevels;
    QSpinBox *spinBoxConstExpansionThresh;
    QLabel *labelStarOutOfBounds;
    QDoubleSpinBox *doubleSpinBoxFovealKernelBaseConstant;
    QDoubleSpinBox *doubleSpinBoxCorrErrorThresh;
    QLabel *labelConstExpansionThresh;
    QSpinBox *spinBoxSearchLevels;
    QDoubleSpinBox *doubleSpinBoxRejectionRateTimeConstant;
    QLabel *labelCorrErrorThresh;
    QDoubleSpinBox *doubleSpinBoxDegeneracyThresh;
    QLabel *labelCenterOutOfBounds;
    QLabel *labelInverseConstellationExpansionThresh;
    QSpinBox *spinBoxStarOutOfBounds;
    QLabel *labelFovealKernelBaseConstant;
    QDoubleSpinBox *doubleSpinBoxRejectionRateThresh;
    QLabel *labelShapeChangeThresh;
    QLabel *labelConstOffset;
    QLabel *labelMinSample;
    QLabel *labelDegeneracyThresh;
    QLabel *labelFovealKernelNumLevels;
    QLabel *labelSearchLevels;
    QSpinBox *spinBoxCenterOutOfBounds;
    QSpinBox *spinBoxSearchRadius;
    QComboBox *comboBoxFovealKernelTypeSpacing;
    QDoubleSpinBox *doubleSpinBoxMinSample;
    QDoubleSpinBox *doubleSpinBoxShapeChangeThresh;
    QLabel *labelRejectionRateTimeConstant;
    QLabel *labelSearchRadius;
    QWidget *tabOpticalFlow;
    QComboBox *comboBoxOFAlgorithm;
    QLabel *label;
    QCheckBox *checkBoxOFShowFeatures;
    QPushButton *pushButtonTrack;
    QWidget *tabSegmentation;
    QCheckBox *checkBoxSegmentation;
    QDoubleSpinBox *doubleSpinBoxSigma;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QSpinBox *spinBoxK;
    QSpinBox *spinBoxMinSize;
    QWidget *tabDebug;
    QPlainTextEdit *plainTextEditTrace;
    QComboBox *comboBoxSecondWindow;
    QLabel *label_2;
    QCheckBox *checkBoxSwapRedBlue;
    QLabel *label_25;
    QComboBox *comboBoxGrayscaleAlgorithm;
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
        MainWindow->resize(1311, 949);
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
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 642, 482));
        graphicsView->setMouseTracking(true);
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
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 570, 1291, 310));
        tabSmoothing = new QWidget();
        tabSmoothing->setObjectName(QString::fromUtf8("tabSmoothing"));
        label_4 = new QLabel(tabSmoothing);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 84, 67, 17));
        comboBoxSmoothingFilter = new QComboBox(tabSmoothing);
        comboBoxSmoothingFilter->setObjectName(QString::fromUtf8("comboBoxSmoothingFilter"));
        comboBoxSmoothingFilter->setGeometry(QRect(100, 80, 221, 27));
        label_5 = new QLabel(tabSmoothing);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 140, 67, 17));
        comboBoxSmoothingMask = new QComboBox(tabSmoothing);
        comboBoxSmoothingMask->setObjectName(QString::fromUtf8("comboBoxSmoothingMask"));
        comboBoxSmoothingMask->setGeometry(QRect(100, 137, 85, 27));
        checkBoxSmoothing = new QCheckBox(tabSmoothing);
        checkBoxSmoothing->setObjectName(QString::fromUtf8("checkBoxSmoothing"));
        checkBoxSmoothing->setGeometry(QRect(20, 30, 98, 22));
        tabWidget->addTab(tabSmoothing, QString());
        tabSharpening = new QWidget();
        tabSharpening->setObjectName(QString::fromUtf8("tabSharpening"));
        label_6 = new QLabel(tabSharpening);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 95, 81, 17));
        comboBoxSharpeningAlgorithm = new QComboBox(tabSharpening);
        comboBoxSharpeningAlgorithm->setObjectName(QString::fromUtf8("comboBoxSharpeningAlgorithm"));
        comboBoxSharpeningAlgorithm->setGeometry(QRect(140, 90, 171, 27));
        checkBoxSharpening = new QCheckBox(tabSharpening);
        checkBoxSharpening->setObjectName(QString::fromUtf8("checkBoxSharpening"));
        checkBoxSharpening->setGeometry(QRect(40, 40, 111, 22));
        tabWidget->addTab(tabSharpening, QString());
        tabGLT = new QWidget();
        tabGLT->setObjectName(QString::fromUtf8("tabGLT"));
        checkBoxNegative = new QCheckBox(tabGLT);
        checkBoxNegative->setObjectName(QString::fromUtf8("checkBoxNegative"));
        checkBoxNegative->setGeometry(QRect(30, 20, 98, 22));
        checkBoxLogarithm = new QCheckBox(tabGLT);
        checkBoxLogarithm->setObjectName(QString::fromUtf8("checkBoxLogarithm"));
        checkBoxLogarithm->setEnabled(true);
        checkBoxLogarithm->setGeometry(QRect(30, 60, 98, 22));
        checkBoxPowerLaw = new QCheckBox(tabGLT);
        checkBoxPowerLaw->setObjectName(QString::fromUtf8("checkBoxPowerLaw"));
        checkBoxPowerLaw->setEnabled(true);
        checkBoxPowerLaw->setGeometry(QRect(30, 100, 111, 22));
        checkBoxContrastStretching = new QCheckBox(tabGLT);
        checkBoxContrastStretching->setObjectName(QString::fromUtf8("checkBoxContrastStretching"));
        checkBoxContrastStretching->setEnabled(true);
        checkBoxContrastStretching->setGeometry(QRect(30, 140, 161, 22));
        checkBoxBitPlaneSlicing = new QCheckBox(tabGLT);
        checkBoxBitPlaneSlicing->setObjectName(QString::fromUtf8("checkBoxBitPlaneSlicing"));
        checkBoxBitPlaneSlicing->setEnabled(true);
        checkBoxBitPlaneSlicing->setGeometry(QRect(30, 211, 141, 22));
        horizontalSliderR1 = new QSlider(tabGLT);
        horizontalSliderR1->setObjectName(QString::fromUtf8("horizontalSliderR1"));
        horizontalSliderR1->setGeometry(QRect(240, 140, 111, 29));
        horizontalSliderR1->setMaximum(255);
        horizontalSliderR1->setOrientation(Qt::Horizontal);
        horizontalSliderS1 = new QSlider(tabGLT);
        horizontalSliderS1->setObjectName(QString::fromUtf8("horizontalSliderS1"));
        horizontalSliderS1->setGeometry(QRect(418, 140, 111, 29));
        horizontalSliderS1->setMaximum(255);
        horizontalSliderS1->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(tabGLT);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(390, 146, 21, 17));
        label_9 = new QLabel(tabGLT);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(209, 145, 21, 17));
        label_10 = new QLabel(tabGLT);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(209, 179, 21, 17));
        horizontalSliderR2 = new QSlider(tabGLT);
        horizontalSliderR2->setObjectName(QString::fromUtf8("horizontalSliderR2"));
        horizontalSliderR2->setGeometry(QRect(240, 174, 111, 29));
        horizontalSliderR2->setMaximum(255);
        horizontalSliderR2->setOrientation(Qt::Horizontal);
        horizontalSliderS2 = new QSlider(tabGLT);
        horizontalSliderS2->setObjectName(QString::fromUtf8("horizontalSliderS2"));
        horizontalSliderS2->setGeometry(QRect(418, 174, 111, 29));
        horizontalSliderS2->setMaximum(255);
        horizontalSliderS2->setOrientation(Qt::Horizontal);
        label_11 = new QLabel(tabGLT);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(390, 180, 21, 17));
        doubleSpinBoxLogarithmConstant = new QDoubleSpinBox(tabGLT);
        doubleSpinBoxLogarithmConstant->setObjectName(QString::fromUtf8("doubleSpinBoxLogarithmConstant"));
        doubleSpinBoxLogarithmConstant->setGeometry(QRect(300, 55, 62, 27));
        doubleSpinBoxLogarithmConstant->setSingleStep(0.1);
        doubleSpinBoxLogarithmConstant->setValue(0.5);
        label_12 = new QLabel(tabGLT);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(201, 60, 67, 17));
        doubleSpinBoxPowerLawConstant = new QDoubleSpinBox(tabGLT);
        doubleSpinBoxPowerLawConstant->setObjectName(QString::fromUtf8("doubleSpinBoxPowerLawConstant"));
        doubleSpinBoxPowerLawConstant->setGeometry(QRect(299, 96, 62, 27));
        doubleSpinBoxPowerLawConstant->setSingleStep(0.1);
        doubleSpinBoxPowerLawConstant->setValue(1);
        label_13 = new QLabel(tabGLT);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(200, 100, 67, 17));
        doubleSpinBoxPowerLawGamma = new QDoubleSpinBox(tabGLT);
        doubleSpinBoxPowerLawGamma->setObjectName(QString::fromUtf8("doubleSpinBoxPowerLawGamma"));
        doubleSpinBoxPowerLawGamma->setGeometry(QRect(479, 95, 62, 27));
        doubleSpinBoxPowerLawGamma->setSingleStep(0.01);
        doubleSpinBoxPowerLawGamma->setValue(0.67);
        label_14 = new QLabel(tabGLT);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(380, 100, 67, 17));
        comboBoxBitPlane = new QComboBox(tabGLT);
        comboBoxBitPlane->setObjectName(QString::fromUtf8("comboBoxBitPlane"));
        comboBoxBitPlane->setGeometry(QRect(270, 210, 51, 27));
        label_17 = new QLabel(tabGLT);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(200, 214, 67, 17));
        tabWidget->addTab(tabGLT, QString());
        tabReduceGraylevels = new QWidget();
        tabReduceGraylevels->setObjectName(QString::fromUtf8("tabReduceGraylevels"));
        comboBoxReduceGraylevels = new QComboBox(tabReduceGraylevels);
        comboBoxReduceGraylevels->setObjectName(QString::fromUtf8("comboBoxReduceGraylevels"));
        comboBoxReduceGraylevels->setEnabled(false);
        comboBoxReduceGraylevels->setGeometry(QRect(200, 36, 85, 27));
        label_3 = new QLabel(tabReduceGraylevels);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 40, 161, 17));
        tabWidget->addTab(tabReduceGraylevels, QString());
        tabHistogram = new QWidget();
        tabHistogram->setObjectName(QString::fromUtf8("tabHistogram"));
        checkBoxHistogramEqualization = new QCheckBox(tabHistogram);
        checkBoxHistogramEqualization->setObjectName(QString::fromUtf8("checkBoxHistogramEqualization"));
        checkBoxHistogramEqualization->setGeometry(QRect(20, 30, 241, 22));
        tabWidget->addTab(tabHistogram, QString());
        tabNoise = new QWidget();
        tabNoise->setObjectName(QString::fromUtf8("tabNoise"));
        checkBoxAddGaussianNoise = new QCheckBox(tabNoise);
        checkBoxAddGaussianNoise->setObjectName(QString::fromUtf8("checkBoxAddGaussianNoise"));
        checkBoxAddGaussianNoise->setGeometry(QRect(20, 78, 141, 22));
        spinBoxImpulseNoise = new QSpinBox(tabNoise);
        spinBoxImpulseNoise->setObjectName(QString::fromUtf8("spinBoxImpulseNoise"));
        spinBoxImpulseNoise->setGeometry(QRect(170, 175, 59, 27));
        spinBoxGammaVar = new QSpinBox(tabNoise);
        spinBoxGammaVar->setObjectName(QString::fromUtf8("spinBoxGammaVar"));
        spinBoxGammaVar->setGeometry(QRect(250, 126, 59, 27));
        spinBoxGammaVar->setMinimum(100);
        spinBoxGammaVar->setMaximum(400);
        spinBoxGammaVar->setSingleStep(10);
        label_21 = new QLabel(tabNoise);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(170, 130, 67, 17));
        label_22 = new QLabel(tabNoise);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(360, 130, 67, 17));
        spinBoxGammaAlpha = new QSpinBox(tabNoise);
        spinBoxGammaAlpha->setObjectName(QString::fromUtf8("spinBoxGammaAlpha"));
        spinBoxGammaAlpha->setGeometry(QRect(420, 126, 59, 27));
        spinBoxGammaAlpha->setMinimum(1);
        spinBoxGammaAlpha->setMaximum(6);
        label_23 = new QLabel(tabNoise);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(170, 80, 67, 17));
        label_24 = new QLabel(tabNoise);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(330, 80, 67, 17));
        checkBoxAddGammaNoise = new QCheckBox(tabNoise);
        checkBoxAddGammaNoise->setObjectName(QString::fromUtf8("checkBoxAddGammaNoise"));
        checkBoxAddGammaNoise->setGeometry(QRect(20, 130, 141, 22));
        checkBoxAddImpulseNoise = new QCheckBox(tabNoise);
        checkBoxAddImpulseNoise->setObjectName(QString::fromUtf8("checkBoxAddImpulseNoise"));
        checkBoxAddImpulseNoise->setGeometry(QRect(20, 180, 141, 22));
        tabWidget->addTab(tabNoise, QString());
        tabEdgeFilters = new QWidget();
        tabEdgeFilters->setObjectName(QString::fromUtf8("tabEdgeFilters"));
        comboBoxEdgeFilter = new QComboBox(tabEdgeFilters);
        comboBoxEdgeFilter->setObjectName(QString::fromUtf8("comboBoxEdgeFilter"));
        comboBoxEdgeFilter->setGeometry(QRect(110, 26, 121, 27));
        label_16 = new QLabel(tabEdgeFilters);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 30, 81, 17));
        tabWidget->addTab(tabEdgeFilters, QString());
        tabPS = new QWidget();
        tabPS->setObjectName(QString::fromUtf8("tabPS"));
        label_7 = new QLabel(tabPS);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 23, 211, 17));
        pushButtonDrawTripwire = new QPushButton(tabPS);
        pushButtonDrawTripwire->setObjectName(QString::fromUtf8("pushButtonDrawTripwire"));
        pushButtonDrawTripwire->setGeometry(QRect(20, 163, 111, 27));
        checkBox_2 = new QCheckBox(tabPS);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(150, 113, 98, 22));
        label_15 = new QLabel(tabPS);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 83, 101, 17));
        checkBox = new QCheckBox(tabPS);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(150, 83, 98, 22));
        spinBox = new QSpinBox(tabPS);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(240, 20, 59, 27));
        tabWidget->addTab(tabPS, QString());
        tabStabilization = new QWidget();
        tabStabilization->setObjectName(QString::fromUtf8("tabStabilization"));
        tabWidget->addTab(tabStabilization, QString());
        tabCorr = new QWidget();
        tabCorr->setObjectName(QString::fromUtf8("tabCorr"));
        checkBoxDisplayFovealKernel = new QCheckBox(tabCorr);
        checkBoxDisplayFovealKernel->setObjectName(QString::fromUtf8("checkBoxDisplayFovealKernel"));
        checkBoxDisplayFovealKernel->setGeometry(QRect(70, 250, 141, 18));
        doubleSpinBoxInverseConstellationExpansionThresh = new QDoubleSpinBox(tabCorr);
        doubleSpinBoxInverseConstellationExpansionThresh->setObjectName(QString::fromUtf8("doubleSpinBoxInverseConstellationExpansionThresh"));
        doubleSpinBoxInverseConstellationExpansionThresh->setGeometry(QRect(500, 190, 62, 22));
        labelFovealKernelTypeSpacing = new QLabel(tabCorr);
        labelFovealKernelTypeSpacing->setObjectName(QString::fromUtf8("labelFovealKernelTypeSpacing"));
        labelFovealKernelTypeSpacing->setGeometry(QRect(30, 220, 141, 16));
        spinBoxConstOffset = new QSpinBox(tabCorr);
        spinBoxConstOffset->setObjectName(QString::fromUtf8("spinBoxConstOffset"));
        spinBoxConstOffset->setGeometry(QRect(210, 20, 41, 20));
        labelRejectionRateThresh = new QLabel(tabCorr);
        labelRejectionRateThresh->setObjectName(QString::fromUtf8("labelRejectionRateThresh"));
        labelRejectionRateThresh->setGeometry(QRect(280, 130, 131, 16));
        spinBoxFovealKernelNumLevels = new QSpinBox(tabCorr);
        spinBoxFovealKernelNumLevels->setObjectName(QString::fromUtf8("spinBoxFovealKernelNumLevels"));
        spinBoxFovealKernelNumLevels->setGeometry(QRect(210, 190, 42, 22));
        spinBoxConstExpansionThresh = new QSpinBox(tabCorr);
        spinBoxConstExpansionThresh->setObjectName(QString::fromUtf8("spinBoxConstExpansionThresh"));
        spinBoxConstExpansionThresh->setGeometry(QRect(520, 160, 42, 22));
        labelStarOutOfBounds = new QLabel(tabCorr);
        labelStarOutOfBounds->setObjectName(QString::fromUtf8("labelStarOutOfBounds"));
        labelStarOutOfBounds->setGeometry(QRect(280, 220, 101, 16));
        doubleSpinBoxFovealKernelBaseConstant = new QDoubleSpinBox(tabCorr);
        doubleSpinBoxFovealKernelBaseConstant->setObjectName(QString::fromUtf8("doubleSpinBoxFovealKernelBaseConstant"));
        doubleSpinBoxFovealKernelBaseConstant->setGeometry(QRect(190, 160, 62, 22));
        doubleSpinBoxCorrErrorThresh = new QDoubleSpinBox(tabCorr);
        doubleSpinBoxCorrErrorThresh->setObjectName(QString::fromUtf8("doubleSpinBoxCorrErrorThresh"));
        doubleSpinBoxCorrErrorThresh->setGeometry(QRect(500, 10, 62, 22));
        labelConstExpansionThresh = new QLabel(tabCorr);
        labelConstExpansionThresh->setObjectName(QString::fromUtf8("labelConstExpansionThresh"));
        labelConstExpansionThresh->setGeometry(QRect(280, 160, 171, 16));
        spinBoxSearchLevels = new QSpinBox(tabCorr);
        spinBoxSearchLevels->setObjectName(QString::fromUtf8("spinBoxSearchLevels"));
        spinBoxSearchLevels->setGeometry(QRect(210, 80, 42, 22));
        doubleSpinBoxRejectionRateTimeConstant = new QDoubleSpinBox(tabCorr);
        doubleSpinBoxRejectionRateTimeConstant->setObjectName(QString::fromUtf8("doubleSpinBoxRejectionRateTimeConstant"));
        doubleSpinBoxRejectionRateTimeConstant->setGeometry(QRect(500, 100, 62, 22));
        labelCorrErrorThresh = new QLabel(tabCorr);
        labelCorrErrorThresh->setObjectName(QString::fromUtf8("labelCorrErrorThresh"));
        labelCorrErrorThresh->setGeometry(QRect(280, 10, 141, 16));
        doubleSpinBoxDegeneracyThresh = new QDoubleSpinBox(tabCorr);
        doubleSpinBoxDegeneracyThresh->setObjectName(QString::fromUtf8("doubleSpinBoxDegeneracyThresh"));
        doubleSpinBoxDegeneracyThresh->setGeometry(QRect(501, 40, 61, 22));
        labelCenterOutOfBounds = new QLabel(tabCorr);
        labelCenterOutOfBounds->setObjectName(QString::fromUtf8("labelCenterOutOfBounds"));
        labelCenterOutOfBounds->setGeometry(QRect(280, 250, 111, 16));
        labelInverseConstellationExpansionThresh = new QLabel(tabCorr);
        labelInverseConstellationExpansionThresh->setObjectName(QString::fromUtf8("labelInverseConstellationExpansionThresh"));
        labelInverseConstellationExpansionThresh->setGeometry(QRect(280, 190, 211, 16));
        spinBoxStarOutOfBounds = new QSpinBox(tabCorr);
        spinBoxStarOutOfBounds->setObjectName(QString::fromUtf8("spinBoxStarOutOfBounds"));
        spinBoxStarOutOfBounds->setGeometry(QRect(520, 220, 42, 22));
        labelFovealKernelBaseConstant = new QLabel(tabCorr);
        labelFovealKernelBaseConstant->setObjectName(QString::fromUtf8("labelFovealKernelBaseConstant"));
        labelFovealKernelBaseConstant->setGeometry(QRect(30, 160, 151, 16));
        doubleSpinBoxRejectionRateThresh = new QDoubleSpinBox(tabCorr);
        doubleSpinBoxRejectionRateThresh->setObjectName(QString::fromUtf8("doubleSpinBoxRejectionRateThresh"));
        doubleSpinBoxRejectionRateThresh->setGeometry(QRect(500, 130, 62, 22));
        labelShapeChangeThresh = new QLabel(tabCorr);
        labelShapeChangeThresh->setObjectName(QString::fromUtf8("labelShapeChangeThresh"));
        labelShapeChangeThresh->setGeometry(QRect(280, 70, 131, 16));
        labelConstOffset = new QLabel(tabCorr);
        labelConstOffset->setObjectName(QString::fromUtf8("labelConstOffset"));
        labelConstOffset->setGeometry(QRect(30, 20, 101, 16));
        labelMinSample = new QLabel(tabCorr);
        labelMinSample->setObjectName(QString::fromUtf8("labelMinSample"));
        labelMinSample->setGeometry(QRect(30, 120, 111, 16));
        labelDegeneracyThresh = new QLabel(tabCorr);
        labelDegeneracyThresh->setObjectName(QString::fromUtf8("labelDegeneracyThresh"));
        labelDegeneracyThresh->setGeometry(QRect(280, 40, 121, 16));
        labelFovealKernelNumLevels = new QLabel(tabCorr);
        labelFovealKernelNumLevels->setObjectName(QString::fromUtf8("labelFovealKernelNumLevels"));
        labelFovealKernelNumLevels->setGeometry(QRect(30, 190, 141, 16));
        labelSearchLevels = new QLabel(tabCorr);
        labelSearchLevels->setObjectName(QString::fromUtf8("labelSearchLevels"));
        labelSearchLevels->setGeometry(QRect(30, 90, 71, 16));
        spinBoxCenterOutOfBounds = new QSpinBox(tabCorr);
        spinBoxCenterOutOfBounds->setObjectName(QString::fromUtf8("spinBoxCenterOutOfBounds"));
        spinBoxCenterOutOfBounds->setGeometry(QRect(520, 250, 42, 22));
        spinBoxSearchRadius = new QSpinBox(tabCorr);
        spinBoxSearchRadius->setObjectName(QString::fromUtf8("spinBoxSearchRadius"));
        spinBoxSearchRadius->setGeometry(QRect(210, 50, 42, 22));
        comboBoxFovealKernelTypeSpacing = new QComboBox(tabCorr);
        comboBoxFovealKernelTypeSpacing->setObjectName(QString::fromUtf8("comboBoxFovealKernelTypeSpacing"));
        comboBoxFovealKernelTypeSpacing->setGeometry(QRect(170, 220, 81, 22));
        doubleSpinBoxMinSample = new QDoubleSpinBox(tabCorr);
        doubleSpinBoxMinSample->setObjectName(QString::fromUtf8("doubleSpinBoxMinSample"));
        doubleSpinBoxMinSample->setGeometry(QRect(190, 120, 62, 22));
        doubleSpinBoxShapeChangeThresh = new QDoubleSpinBox(tabCorr);
        doubleSpinBoxShapeChangeThresh->setObjectName(QString::fromUtf8("doubleSpinBoxShapeChangeThresh"));
        doubleSpinBoxShapeChangeThresh->setGeometry(QRect(500, 70, 62, 22));
        labelRejectionRateTimeConstant = new QLabel(tabCorr);
        labelRejectionRateTimeConstant->setObjectName(QString::fromUtf8("labelRejectionRateTimeConstant"));
        labelRejectionRateTimeConstant->setGeometry(QRect(280, 100, 151, 16));
        labelSearchRadius = new QLabel(tabCorr);
        labelSearchRadius->setObjectName(QString::fromUtf8("labelSearchRadius"));
        labelSearchRadius->setGeometry(QRect(30, 50, 81, 16));
        tabWidget->addTab(tabCorr, QString());
        tabOpticalFlow = new QWidget();
        tabOpticalFlow->setObjectName(QString::fromUtf8("tabOpticalFlow"));
        comboBoxOFAlgorithm = new QComboBox(tabOpticalFlow);
        comboBoxOFAlgorithm->setObjectName(QString::fromUtf8("comboBoxOFAlgorithm"));
        comboBoxOFAlgorithm->setGeometry(QRect(100, 20, 85, 27));
        label = new QLabel(tabOpticalFlow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 22, 81, 21));
        checkBoxOFShowFeatures = new QCheckBox(tabOpticalFlow);
        checkBoxOFShowFeatures->setObjectName(QString::fromUtf8("checkBoxOFShowFeatures"));
        checkBoxOFShowFeatures->setGeometry(QRect(10, 242, 141, 22));
        pushButtonTrack = new QPushButton(tabOpticalFlow);
        pushButtonTrack->setObjectName(QString::fromUtf8("pushButtonTrack"));
        pushButtonTrack->setGeometry(QRect(100, 180, 80, 23));
        tabWidget->addTab(tabOpticalFlow, QString());
        tabSegmentation = new QWidget();
        tabSegmentation->setObjectName(QString::fromUtf8("tabSegmentation"));
        checkBoxSegmentation = new QCheckBox(tabSegmentation);
        checkBoxSegmentation->setObjectName(QString::fromUtf8("checkBoxSegmentation"));
        checkBoxSegmentation->setGeometry(QRect(40, 30, 98, 22));
        doubleSpinBoxSigma = new QDoubleSpinBox(tabSegmentation);
        doubleSpinBoxSigma->setObjectName(QString::fromUtf8("doubleSpinBoxSigma"));
        doubleSpinBoxSigma->setGeometry(QRect(160, 76, 62, 27));
        doubleSpinBoxSigma->setSingleStep(0.1);
        doubleSpinBoxSigma->setValue(0.5);
        label_18 = new QLabel(tabSegmentation);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(50, 80, 67, 17));
        label_19 = new QLabel(tabSegmentation);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(50, 120, 67, 17));
        label_20 = new QLabel(tabSegmentation);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(50, 160, 67, 17));
        spinBoxK = new QSpinBox(tabSegmentation);
        spinBoxK->setObjectName(QString::fromUtf8("spinBoxK"));
        spinBoxK->setGeometry(QRect(160, 113, 59, 27));
        spinBoxK->setMaximum(1500);
        spinBoxK->setSingleStep(10);
        spinBoxK->setValue(500);
        spinBoxMinSize = new QSpinBox(tabSegmentation);
        spinBoxMinSize->setObjectName(QString::fromUtf8("spinBoxMinSize"));
        spinBoxMinSize->setGeometry(QRect(160, 156, 59, 27));
        spinBoxMinSize->setMaximum(200);
        spinBoxMinSize->setSingleStep(5);
        spinBoxMinSize->setValue(50);
        tabWidget->addTab(tabSegmentation, QString());
        tabDebug = new QWidget();
        tabDebug->setObjectName(QString::fromUtf8("tabDebug"));
        plainTextEditTrace = new QPlainTextEdit(tabDebug);
        plainTextEditTrace->setObjectName(QString::fromUtf8("plainTextEditTrace"));
        plainTextEditTrace->setGeometry(QRect(8, 9, 1271, 261));
        tabWidget->addTab(tabDebug, QString());
        comboBoxSecondWindow = new QComboBox(centralWidget);
        comboBoxSecondWindow->setObjectName(QString::fromUtf8("comboBoxSecondWindow"));
        comboBoxSecondWindow->setGeometry(QRect(780, 485, 191, 27));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(660, 490, 121, 17));
        checkBoxSwapRedBlue = new QCheckBox(centralWidget);
        checkBoxSwapRedBlue->setObjectName(QString::fromUtf8("checkBoxSwapRedBlue"));
        checkBoxSwapRedBlue->setGeometry(QRect(170, 530, 161, 20));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(360, 530, 141, 17));
        comboBoxGrayscaleAlgorithm = new QComboBox(centralWidget);
        comboBoxGrayscaleAlgorithm->setObjectName(QString::fromUtf8("comboBoxGrayscaleAlgorithm"));
        comboBoxGrayscaleAlgorithm->setGeometry(QRect(510, 526, 301, 27));
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

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(11);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Computer Vision Toolkit", 0, QApplication::UnicodeUTF8));
        action_Open_Sequence->setText(QApplication::translate("MainWindow", "Open Sequence or Movie", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionEvaluation->setText(QApplication::translate("MainWindow", "Evaluation", 0, QApplication::UnicodeUTF8));
        actionNavigation->setText(QApplication::translate("MainWindow", "Navigation", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionApply_to_Entire_Dataset->setText(QApplication::translate("MainWindow", "Apply to Entire Dataset and Export", 0, QApplication::UnicodeUTF8));
        actionExport_Dataset->setText(QApplication::translate("MainWindow", "Export Dataset", 0, QApplication::UnicodeUTF8));
        checkBoxFitToWindow->setText(QApplication::translate("MainWindow", "Fit to window", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Filter", 0, QApplication::UnicodeUTF8));
        comboBoxSmoothingFilter->clear();
        comboBoxSmoothingFilter->insertItems(0, QStringList()
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
        comboBoxSmoothingMask->clear();
        comboBoxSmoothingMask->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1x1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3x3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5x5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7x7", 0, QApplication::UnicodeUTF8)
        );
        checkBoxSmoothing->setText(QApplication::translate("MainWindow", "Smooth?", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSmoothing), QApplication::translate("MainWindow", "Smoothing", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Algorithm", 0, QApplication::UnicodeUTF8));
        comboBoxSharpeningAlgorithm->clear();
        comboBoxSharpeningAlgorithm->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Highboost Laplacian", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Gradient", 0, QApplication::UnicodeUTF8)
        );
        checkBoxSharpening->setText(QApplication::translate("MainWindow", "Sharpen?", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSharpening), QApplication::translate("MainWindow", "Sharpening", 0, QApplication::UnicodeUTF8));
        checkBoxNegative->setText(QApplication::translate("MainWindow", "Negative", 0, QApplication::UnicodeUTF8));
        checkBoxLogarithm->setText(QApplication::translate("MainWindow", "Logarithm", 0, QApplication::UnicodeUTF8));
        checkBoxPowerLaw->setText(QApplication::translate("MainWindow", "Power Law", 0, QApplication::UnicodeUTF8));
        checkBoxContrastStretching->setText(QApplication::translate("MainWindow", "Contrast Stretching", 0, QApplication::UnicodeUTF8));
        checkBoxBitPlaneSlicing->setText(QApplication::translate("MainWindow", "Bit Plane Slicing", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "S1", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "R1", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "R2", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "S2", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Constant", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Constant", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Gamma", 0, QApplication::UnicodeUTF8));
        comboBoxBitPlane->clear();
        comboBoxBitPlane->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
        );
        label_17->setText(QApplication::translate("MainWindow", "Plane", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabGLT), QApplication::translate("MainWindow", "Gray Level Transformations", 0, QApplication::UnicodeUTF8));
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
        tabWidget->setTabText(tabWidget->indexOf(tabReduceGraylevels), QApplication::translate("MainWindow", "Reduce Graylevels", 0, QApplication::UnicodeUTF8));
        checkBoxHistogramEqualization->setText(QApplication::translate("MainWindow", "Apply histogram equalization?", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabHistogram), QApplication::translate("MainWindow", "Histogram Equalization", 0, QApplication::UnicodeUTF8));
        checkBoxAddGaussianNoise->setText(QApplication::translate("MainWindow", "Gaussian noise?", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Variance", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Alpha", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "Mean", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "Variance", 0, QApplication::UnicodeUTF8));
        checkBoxAddGammaNoise->setText(QApplication::translate("MainWindow", "Gamma noise?", 0, QApplication::UnicodeUTF8));
        checkBoxAddImpulseNoise->setText(QApplication::translate("MainWindow", "Impulse noise?", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabNoise), QApplication::translate("MainWindow", "Noise", 0, QApplication::UnicodeUTF8));
        comboBoxEdgeFilter->clear();
        comboBoxEdgeFilter->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Canny", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Sobel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Vertical", 0, QApplication::UnicodeUTF8)
        );
        label_16->setText(QApplication::translate("MainWindow", "Edge Filter", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabEdgeFilters), QApplication::translate("MainWindow", "Edge Filters", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Ignore pixels smaller than NxN", 0, QApplication::UnicodeUTF8));
        pushButtonDrawTripwire->setText(QApplication::translate("MainWindow", "Draw Tripwire", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "People", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Classification:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Vehicles", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabPS), QApplication::translate("MainWindow", "Persistent Stare", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabStabilization), QApplication::translate("MainWindow", "Stabilization", 0, QApplication::UnicodeUTF8));
        checkBoxDisplayFovealKernel->setText(QApplication::translate("MainWindow", "Display Foveal Kernel", 0, QApplication::UnicodeUTF8));
        labelFovealKernelTypeSpacing->setText(QApplication::translate("MainWindow", "Foveal Kernel Type Spacing", 0, QApplication::UnicodeUTF8));
        labelRejectionRateThresh->setText(QApplication::translate("MainWindow", "Rejection Rate Threshold", 0, QApplication::UnicodeUTF8));
        labelStarOutOfBounds->setText(QApplication::translate("MainWindow", "Star Out of Bounds", 0, QApplication::UnicodeUTF8));
        labelConstExpansionThresh->setText(QApplication::translate("MainWindow", "Constellation Expansion Threshold", 0, QApplication::UnicodeUTF8));
        labelCorrErrorThresh->setText(QApplication::translate("MainWindow", "Correlation Error Threshold", 0, QApplication::UnicodeUTF8));
        labelCenterOutOfBounds->setText(QApplication::translate("MainWindow", "Center Out of Bounds", 0, QApplication::UnicodeUTF8));
        labelInverseConstellationExpansionThresh->setText(QApplication::translate("MainWindow", "Inverse Constellation Expansion Threshold", 0, QApplication::UnicodeUTF8));
        labelFovealKernelBaseConstant->setText(QApplication::translate("MainWindow", "Foveal Kernel Base Constant", 0, QApplication::UnicodeUTF8));
        labelShapeChangeThresh->setText(QApplication::translate("MainWindow", "Shape Change Threshold", 0, QApplication::UnicodeUTF8));
        labelConstOffset->setText(QApplication::translate("MainWindow", "Constellation Offset", 0, QApplication::UnicodeUTF8));
        labelMinSample->setText(QApplication::translate("MainWindow", "Min Sample Proportion", 0, QApplication::UnicodeUTF8));
        labelDegeneracyThresh->setText(QApplication::translate("MainWindow", "Degeneracy Threshold", 0, QApplication::UnicodeUTF8));
        labelFovealKernelNumLevels->setText(QApplication::translate("MainWindow", "Foveal Kernel Number Levels", 0, QApplication::UnicodeUTF8));
        labelSearchLevels->setText(QApplication::translate("MainWindow", "Search Levels", 0, QApplication::UnicodeUTF8));
        comboBoxFovealKernelTypeSpacing->clear();
        comboBoxFovealKernelTypeSpacing->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Exponential", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Geometric", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Linear", 0, QApplication::UnicodeUTF8)
        );
        labelRejectionRateTimeConstant->setText(QApplication::translate("MainWindow", "Rejection Rate Time Constant", 0, QApplication::UnicodeUTF8));
        labelSearchRadius->setText(QApplication::translate("MainWindow", "Search Radius", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCorr), QApplication::translate("MainWindow", "Correlation Tracker", 0, QApplication::UnicodeUTF8));
        comboBoxOFAlgorithm->clear();
        comboBoxOFAlgorithm->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "KLT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Horn-Schunck", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Farneback", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "Algorithm", 0, QApplication::UnicodeUTF8));
        checkBoxOFShowFeatures->setText(QApplication::translate("MainWindow", "Show Features?", 0, QApplication::UnicodeUTF8));
        pushButtonTrack->setText(QApplication::translate("MainWindow", "Track", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabOpticalFlow), QApplication::translate("MainWindow", "Optical Flow", 0, QApplication::UnicodeUTF8));
        checkBoxSegmentation->setText(QApplication::translate("MainWindow", "Segment?", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "sigma", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "k", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "min size", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSegmentation), QApplication::translate("MainWindow", "Segmentation", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabDebug), QApplication::translate("MainWindow", "Debug Messages", 0, QApplication::UnicodeUTF8));
        comboBoxSecondWindow->clear();
        comboBoxSecondWindow->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Blank", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Show Processed Image", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Show Previous Frame", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "Second Window", 0, QApplication::UnicodeUTF8));
        checkBoxSwapRedBlue->setText(QApplication::translate("MainWindow", "Swap red and blue?", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "Grayscale Algorithm", 0, QApplication::UnicodeUTF8));
        comboBoxGrayscaleAlgorithm->clear();
        comboBoxGrayscaleAlgorithm->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "OpenCV default", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Grab single plane", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Lightness (max(R,G,B) + min(R,G,B))/2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Average (R+B+G)/3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Luminosity (0.21R + 0.71G + 0.07B)", 0, QApplication::UnicodeUTF8)
        );
        menu_File->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuDataset_Actions->setTitle(QApplication::translate("MainWindow", "Dataset Actions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
