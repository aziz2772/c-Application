#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abonne.h"

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
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->tababonne->setModel(tmpabonne.afficher());
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{

         QString ch;
        int id = ui->lineEdit_id->text().toInt();
        QString nom= ui->lineEdit_nom->text();
        QString prenom= ui->lineEdit_prenom->text();
        QString job= ui->lineEdit_job->text();
        QString adresse= ui->lineEdit_adresse->text();
        int age=ui->lineEdit_age->text().toInt();


      abonne e(id,nom,prenom,age,job,adresse);


      bool test=e.ajouter();
      if(test)
    {ui->tababonne->setModel(tmpabonne.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                      QObject::tr("Etudiant ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



}
