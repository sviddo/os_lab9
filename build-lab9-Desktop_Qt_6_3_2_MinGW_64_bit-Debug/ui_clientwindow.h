/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QAction *subsWeatherAction;
    QAction *subsStocksAction;
    QAction *subsValAction;
    QAction *unsubsWeatherAction;
    QAction *unsubsStocksAction;
    QAction *undubsValAction;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QFrame *line_2;
    QLabel *label_5;
    QLabel *label_19;
    QLabel *label_6;
    QLabel *label_20;
    QLabel *label_9;
    QLabel *amazonLabel;
    QLabel *appleLabel;
    QLabel *teslaLabel;
    QFrame *line_6;
    QFrame *line_7;
    QPushButton *pushButton_2;
    QPushButton *weatherButton;
    QGridLayout *gridLayout_5;
    QLabel *dollarLabel;
    QLabel *label_13;
    QLabel *euroLabel;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_18;
    QLabel *label_16;
    QLabel *label_21;
    QFrame *line_3;
    QLabel *poundLabel;
    QFrame *line_8;
    QFrame *line_9;
    QPushButton *pushButton_4;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *label_11;
    QLabel *label_2;
    QLabel *label;
    QLabel *tempLabel;
    QLabel *dateTimeLabel;
    QLabel *label_7;
    QLabel *cityLabel;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line;
    QFrame *line_10;
    QFrame *line_11;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(852, 434);
        ClientWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color: rgb(106, 110, 113);\n"
"}"));
        subsWeatherAction = new QAction(ClientWindow);
        subsWeatherAction->setObjectName(QString::fromUtf8("subsWeatherAction"));
        subsStocksAction = new QAction(ClientWindow);
        subsStocksAction->setObjectName(QString::fromUtf8("subsStocksAction"));
        subsValAction = new QAction(ClientWindow);
        subsValAction->setObjectName(QString::fromUtf8("subsValAction"));
        unsubsWeatherAction = new QAction(ClientWindow);
        unsubsWeatherAction->setObjectName(QString::fromUtf8("unsubsWeatherAction"));
        unsubsStocksAction = new QAction(ClientWindow);
        unsubsStocksAction->setObjectName(QString::fromUtf8("unsubsStocksAction"));
        undubsValAction = new QAction(ClientWindow);
        undubsValAction->setObjectName(QString::fromUtf8("undubsValAction"));
        centralwidget = new QWidget(ClientWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI Semilight")});
        font.setPointSize(11);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: white;\n"
"    border-radius: 7px;\n"
"}"));

        gridLayout_6->addWidget(label_4, 3, 0, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_2, 1, 1, 5, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(100, 0));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: white;\n"
"    border-radius: 7px;\n"
"}"));

        gridLayout_6->addWidget(label_5, 4, 0, 1, 1);

        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(110, 0));
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(160, 160, 160);\n"
"	color: rgb(255, 255, 255);\n"
"    border-radius: 7px;\n"
"}"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_19, 1, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(100, 0));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: white;\n"
"    border-radius: 7px;\n"
"}"));

        gridLayout_6->addWidget(label_6, 5, 0, 1, 1);

        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(160, 160, 160);\n"
"	color: rgb(255, 255, 255);\n"
"    border-radius: 7px;\n"
"}"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_20, 1, 2, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_9, 0, 0, 1, 3);

        amazonLabel = new QLabel(centralwidget);
        amazonLabel->setObjectName(QString::fromUtf8("amazonLabel"));
        amazonLabel->setMinimumSize(QSize(100, 0));
        amazonLabel->setFont(font);
        amazonLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"    /*border-radius: 10px;*/\n"
"}"));

        gridLayout_6->addWidget(amazonLabel, 5, 2, 1, 1);

        appleLabel = new QLabel(centralwidget);
        appleLabel->setObjectName(QString::fromUtf8("appleLabel"));
        appleLabel->setMinimumSize(QSize(100, 0));
        appleLabel->setFont(font);
        appleLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"    /*border-radius: 10px;*/\n"
"}"));

        gridLayout_6->addWidget(appleLabel, 3, 2, 1, 1);

        teslaLabel = new QLabel(centralwidget);
        teslaLabel->setObjectName(QString::fromUtf8("teslaLabel"));
        teslaLabel->setMinimumSize(QSize(100, 0));
        teslaLabel->setFont(font);
        teslaLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"    /*border-radius: 10px;*/\n"
"}"));

        gridLayout_6->addWidget(teslaLabel, 4, 2, 1, 1);

        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_6, 2, 0, 1, 1);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_7, 2, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_6, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 100));
        pushButton_2->setMaximumSize(QSize(100, 100));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(135, 194, 50);\n"
"   border: 5px #000000;\n"
"   padding: 7px;\n"
"   border-radius: 50px;\n"
"border-image:  url(:money.ico);\n"
"}\n"
""));

        gridLayout_2->addWidget(pushButton_2, 0, 4, 1, 1, Qt::AlignHCenter);

        weatherButton = new QPushButton(centralwidget);
        weatherButton->setObjectName(QString::fromUtf8("weatherButton"));
        weatherButton->setMinimumSize(QSize(100, 100));
        weatherButton->setMaximumSize(QSize(100, 100));
        weatherButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(135, 194, 50);\n"
"    border: 5px #000000;\n"
"    padding: 5px;\n"
"    border-radius: 50px;\n"
"	border-image:  url(:weather.ico);\n"
"\n"
"}\n"
""));

        gridLayout_2->addWidget(weatherButton, 0, 0, 1, 1, Qt::AlignHCenter);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        dollarLabel = new QLabel(centralwidget);
        dollarLabel->setObjectName(QString::fromUtf8("dollarLabel"));
        dollarLabel->setMinimumSize(QSize(100, 0));
        dollarLabel->setFont(font);
        dollarLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"    /*border-radius: 10px;*/\n"
"}"));

        gridLayout_5->addWidget(dollarLabel, 3, 2, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_13, 0, 0, 1, 3);

        euroLabel = new QLabel(centralwidget);
        euroLabel->setObjectName(QString::fromUtf8("euroLabel"));
        euroLabel->setMinimumSize(QSize(100, 0));
        euroLabel->setFont(font);
        euroLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"    /*border-radius: 10px;*/\n"
"}"));

        gridLayout_5->addWidget(euroLabel, 4, 2, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(100, 0));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: white;\n"
"    border-radius: 7px;\n"
"}"));

        gridLayout_5->addWidget(label_14, 4, 0, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(100, 0));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: white;\n"
"    border-radius: 7px;\n"
"}"));

        gridLayout_5->addWidget(label_12, 3, 0, 1, 1);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(120, 0));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(160, 160, 160);\n"
"	color: rgb(255, 255, 255);\n"
"    border-radius: 7px;\n"
"}"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_18, 1, 0, 1, 1);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(100, 0));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: white;\n"
"    border-radius: 7px;\n"
"}"));

        gridLayout_5->addWidget(label_16, 5, 0, 1, 1);

        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(160, 160, 160);\n"
"	color: rgb(255, 255, 255);\n"
"    border-radius: 7px;\n"
"}"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_21, 1, 2, 1, 1);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_3, 1, 1, 5, 1);

        poundLabel = new QLabel(centralwidget);
        poundLabel->setObjectName(QString::fromUtf8("poundLabel"));
        poundLabel->setMinimumSize(QSize(100, 0));
        poundLabel->setFont(font);
        poundLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"    /*border-radius: 10px;*/\n"
"}"));

        gridLayout_5->addWidget(poundLabel, 5, 2, 1, 1);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_8, 2, 0, 1, 1);

        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_9, 2, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_5, 1, 4, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(100, 100));
        pushButton_4->setMaximumSize(QSize(100, 100));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   background-color: rgb(135, 194, 50);\n"
"   border: 5px #000000;\n"
"   padding: 5px;\n"
"   border-radius: 50px;\n"
"   border-image:  url(:stocks.ico);\n"
"}\n"
"\n"
""));

        gridLayout_2->addWidget(pushButton_4, 0, 2, 1, 1, Qt::AlignHCenter);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: white;\n"
"    border-radius: 7px;\n"
"}"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_11, 0, 0, 1, 3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: white;\n"
"    border-radius: 7px;\n"
"}"));

        gridLayout_3->addWidget(label_2, 5, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: white;\n"
"    border-radius: 7px;\n"
"}"));

        gridLayout_3->addWidget(label, 4, 0, 1, 1);

        tempLabel = new QLabel(centralwidget);
        tempLabel->setObjectName(QString::fromUtf8("tempLabel"));
        tempLabel->setMinimumSize(QSize(100, 0));
        tempLabel->setFont(font);
        tempLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"    /*border-radius: 10px;*/\n"
"}"));

        gridLayout_3->addWidget(tempLabel, 5, 2, 1, 1);

        dateTimeLabel = new QLabel(centralwidget);
        dateTimeLabel->setObjectName(QString::fromUtf8("dateTimeLabel"));
        dateTimeLabel->setMinimumSize(QSize(100, 0));
        dateTimeLabel->setFont(font);
        dateTimeLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"    /*border-radius: 10px;*/\n"
"}"));

        gridLayout_3->addWidget(dateTimeLabel, 3, 2, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(160, 160, 160);\n"
"	color: rgb(255, 255, 255);\n"
"    border-radius: 7px;\n"
"}"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_7, 1, 2, 1, 1);

        cityLabel = new QLabel(centralwidget);
        cityLabel->setObjectName(QString::fromUtf8("cityLabel"));
        cityLabel->setMinimumSize(QSize(100, 0));
        cityLabel->setFont(font);
        cityLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(97, 137, 48);\n"
"	color: rgb(255, 255, 255);\n"
"    /*border-radius: 10px;*/\n"
"}"));

        gridLayout_3->addWidget(cityLabel, 4, 2, 1, 1);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_4, 2, 0, 1, 1);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_5, 2, 2, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 1, 5, 1);


        gridLayout_2->addLayout(gridLayout_3, 1, 0, 1, 1);

        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_10, 1, 1, 1, 1);

        line_11 = new QFrame(centralwidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_11, 1, 3, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        ClientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 852, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        ClientWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ClientWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ClientWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(subsWeatherAction);
        menu->addAction(subsStocksAction);
        menu->addAction(subsValAction);
        menu->addSeparator();
        menu->addAction(unsubsWeatherAction);
        menu->addAction(unsubsStocksAction);
        menu->addAction(undubsValAction);

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWindow)
    {
        ClientWindow->setWindowTitle(QCoreApplication::translate("ClientWindow", "ClientWindow", nullptr));
        subsWeatherAction->setText(QCoreApplication::translate("ClientWindow", "\320\237\321\226\320\264\320\277\320\270\321\201\320\260\321\202\320\270\321\201\321\214 \320\275\320\260 \320\277\320\276\320\263\320\276\320\264\321\203", nullptr));
        subsStocksAction->setText(QCoreApplication::translate("ClientWindow", "\320\237\321\226\320\264\320\277\320\270\321\201\320\260\321\202\320\270\321\201\321\214 \320\275\320\260 \320\272\321\203\321\200\321\201 \320\260\320\272\321\206\321\226\320\271", nullptr));
        subsValAction->setText(QCoreApplication::translate("ClientWindow", "\320\237\321\226\320\264\320\277\320\270\321\201\320\260\321\202\320\270\321\201\321\214 \320\275\320\260 \320\272\321\203\321\200\321\201 \320\262\320\260\320\273\321\216\321\202", nullptr));
        unsubsWeatherAction->setText(QCoreApplication::translate("ClientWindow", "\320\222\321\226\320\264\320\277\320\270\321\201\320\260\321\202\320\270\321\201\321\214 \320\262\321\226\320\264 \320\277\320\276\320\263\320\276\320\264\320\270", nullptr));
        unsubsStocksAction->setText(QCoreApplication::translate("ClientWindow", "\320\222\321\226\320\264\320\277\320\270\321\201\320\260\321\202\320\270\321\201\321\214 \320\262\321\226\320\264 \320\272\321\203\321\200\321\201\321\203 \320\260\320\272\321\206\321\226\320\271", nullptr));
        undubsValAction->setText(QCoreApplication::translate("ClientWindow", "\320\222\321\226\320\264\320\277\320\270\321\201\320\260\321\202\320\270\321\201\321\214 \320\262\321\226\320\264 \320\272\321\203\321\200\321\201\321\203 \320\262\320\260\320\273\321\216\321\202", nullptr));
        label_4->setText(QCoreApplication::translate("ClientWindow", " Apple", nullptr));
        label_5->setText(QCoreApplication::translate("ClientWindow", " Tesla", nullptr));
        label_19->setText(QCoreApplication::translate("ClientWindow", "\320\235\320\260\320\267\320\262\320\260 \320\272\320\276\320\274\320\277\320\260\320\275\321\226\321\227", nullptr));
        label_6->setText(QCoreApplication::translate("ClientWindow", " Amazon", nullptr));
        label_20->setText(QCoreApplication::translate("ClientWindow", "\320\246\321\226\320\275\320\260", nullptr));
        label_9->setText(QCoreApplication::translate("ClientWindow", "\320\232\321\203\321\200\321\201 \320\260\320\272\321\206\321\226\320\271", nullptr));
        amazonLabel->setText(QString());
        appleLabel->setText(QString());
        teslaLabel->setText(QString());
        pushButton_2->setText(QString());
        weatherButton->setText(QString());
        dollarLabel->setText(QString());
        label_13->setText(QCoreApplication::translate("ClientWindow", "\320\232\321\203\321\200\321\201 \320\262\320\260\320\273\321\216\321\202", nullptr));
        euroLabel->setText(QString());
        label_14->setText(QCoreApplication::translate("ClientWindow", " \320\204\320\262\321\200\320\276", nullptr));
        label_12->setText(QCoreApplication::translate("ClientWindow", " \320\224\320\276\320\273\320\260\321\200 \320\241\320\250\320\220", nullptr));
        label_18->setText(QCoreApplication::translate("ClientWindow", "\320\235\320\260\320\267\320\262\320\260 \320\262\320\260\320\273\321\216\321\202\320\270", nullptr));
        label_16->setText(QCoreApplication::translate("ClientWindow", " \320\244\321\203\320\275\321\202 \321\201\321\202\320\265\321\200\320\273\321\226\320\275\320\263\321\226\320\262", nullptr));
        label_21->setText(QCoreApplication::translate("ClientWindow", "\320\236\321\204\321\226\321\206\321\226\320\271\320\275\320\270\320\271\n"
"\320\272\321\203\321\200\321\201", nullptr));
        poundLabel->setText(QString());
        pushButton_4->setText(QString());
        label_3->setText(QCoreApplication::translate("ClientWindow", " \320\224\320\260\321\202\320\260, \321\207\320\260\321\201:", nullptr));
        label_11->setText(QCoreApplication::translate("ClientWindow", "\320\237\320\276\320\263\320\276\320\264\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWindow", " \320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260:", nullptr));
        label->setText(QCoreApplication::translate("ClientWindow", " \320\234\321\226\321\201\321\202\320\276:", nullptr));
        tempLabel->setText(QString());
        dateTimeLabel->setText(QString());
        label_7->setText(QCoreApplication::translate("ClientWindow", "\320\222\320\274\321\226\321\201\321\202 \320\264\320\260\320\275\320\270\321\205", nullptr));
        cityLabel->setText(QString());
        menu->setTitle(QCoreApplication::translate("ClientWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
