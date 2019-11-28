#ifndef CONTRAT_H
#define CONTRAT_H

#include <QDialog>
#include "employer.h"
#include "cong.h"
#include <QMainWindow>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include "statistique.h"
#include "cong.h"
#include <QDebug>
#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtMultimedia/QMediaPlayer>

#include <QDialog>

#include "QPixmap"
#include "QMessageBox"
#include "QPixmap"
#include <QtMultimedia/QMediaPlayer>
#include <QPixmap>
#include <QSystemTrayIcon>

#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QtSql>
#include<QMap>
#include <iostream>
#include <QString>
#include<time.h>
#include <QTime>
#include <QDialog>
#include <qdialog.h>
#include <ctime>
#include<vector>
#include <QLineEdit>
#include <cstring>
#include <QSharedPointer>
#include<QSharedDataPointer>
//#include<qsharedpointer.h>
#include <QSharedPointer>
#include"qcustomplot.h"
namespace Ui {
class conge;
}

class conge : public QDialog
{
    Q_OBJECT

public:
    explicit conge(QWidget *parent = nullptr);
    ~conge();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_2_userDateChanged(const QDate &date);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pb_supprimer_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::conge *ui;
    cong tmpconge;
};

#endif // CONTRAT_H
