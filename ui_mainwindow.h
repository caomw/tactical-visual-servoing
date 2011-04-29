/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Apr 29 08:43:32 2011
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
    QWidget *tabPreprocess;
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
    QWidget *tabBlob;
    QWidget *tabNavigation;
    QGraphicsView *graphicsView;
    QPlainTextEdit *plainTextEditTrace;
    QPushButton *pushButtonTrack;
    QScrollBar *imageScrollBar;
    QCheckBox *checkBoxFitToWindow;
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
        MainWindow->resize(1246, 653);
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
        tabWidget->setGeometry(QRect(10, 20, 561, 311));
        tabPreprocess = new QWidget();
        tabPreprocess->setObjectName(QString::fromUtf8("tabPreprocess"));
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
        tabWidget->addTab(tabOpticalFlow, QString());
        tabBlob = new QWidget();
        tabBlob->setObjectName(QString::fromUtf8("tabBlob"));
        tabWidget->addTab(tabBlob, QString());
        tabNavigation = new QWidget();
        tabNavigation->setObjectName(QString::fromUtf8("tabNavigation"));
        tabWidget->addTab(tabNavigation, QString());
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(590, 40, 640, 480));
        graphicsView->setMouseTracking(true);
        plainTextEditTrace = new QPlainTextEdit(centralWidget);
        plainTextEditTrace->setObjectName(QString::fromUtf8("plainTextEditTrace"));
        plainTextEditTrace->setGeometry(QRect(10, 340, 561, 181));
        pushButtonTrack = new QPushButton(centralWidget);
        pushButtonTrack->setObjectName(QString::fromUtf8("pushButtonTrack"));
        pushButtonTrack->setGeometry(QRect(1150, 570, 80, 23));
        imageScrollBar = new QScrollBar(centralWidget);
        imageScrollBar->setObjectName(QString::fromUtf8("imageScrollBar"));
        imageScrollBar->setGeometry(QRect(590, 540, 651, 16));
        imageScrollBar->setOrientation(Qt::Horizontal);
        checkBoxFitToWindow = new QCheckBox(centralWidget);
        checkBoxFitToWindow->setObjectName(QString::fromUtf8("checkBoxFitToWindow"));
        checkBoxFitToWindow->setGeometry(QRect(590, 570, 161, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1246, 25));
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TACTICAL :: Tracking Algorithm Comparison Testbed for Comprehensive Analysis and Learning", 0, QApplication::UnicodeUTF8));
        action_Open_Sequence->setText(QApplication::translate("MainWindow", "&Open Sequence or Movie", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        actionEvaluation->setText(QApplication::translate("MainWindow", "Evaluation", 0, QApplication::UnicodeUTF8));
        actionNavigation->setText(QApplication::translate("MainWindow", "Navigation", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionApply_to_Entire_Dataset->setText(QApplication::translate("MainWindow", "Apply to Entire Dataset", 0, QApplication::UnicodeUTF8));
        actionExport_Dataset->setText(QApplication::translate("MainWindow", "Export Dataset", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabPreprocess), QApplication::translate("MainWindow", "Preprocess", 0, QApplication::UnicodeUTF8));
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
        tabWidget->setTabText(tabWidget->indexOf(tabOpticalFlow), QApplication::translate("MainWindow", "Optical Flow", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabBlob), QApplication::translate("MainWindow", "Blob", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabNavigation), QApplication::translate("MainWindow", "Navigation", 0, QApplication::UnicodeUTF8));
        pushButtonTrack->setText(QApplication::translate("MainWindow", "Track", 0, QApplication::UnicodeUTF8));
        checkBoxFitToWindow->setText(QApplication::translate("MainWindow", "Fit to window", 0, QApplication::UnicodeUTF8));
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
