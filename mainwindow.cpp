#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include "conge.h"

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
#include"smtp.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tababonne->setModel(tmpemployer.afficher());
ui->comboBox->setModel(tmpemployer.afficher_employer());
ui->comboBox_2->setModel(tmpemployer.afficher_jobb());
/*animation =new QPropertyAnimation(ui->pb_ajouter, "geometry");
    animation->setDuration(5000);
    animation->setStartValue(QRect(450, 250, 0, 0));
    animation->setEndValue(QRect(40, 510, 100, 30));
    animation->start();*/
connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
QPixmap pix("C:/Users/Aziz/Desktop/pic.jpg");
ui->label_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
     QString ch;

    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString job= ui->lineEdit_job->text();
    QString adresse= tmpemployer.get_adresse();
    int age=ui->lineEdit_age->text().toInt();



  tmpemployer.set_id(id);
  tmpemployer.set_nom(nom);
  tmpemployer.set_prenom(prenom);
  tmpemployer.set_job(job);
  tmpemployer.set_adresse(adresse);
  tmpemployer.set_age(age);

//e.set_datec(tmpemployer.get_datec());
//e.set_datec(tmpemployer.get_datee());
  bool test=tmpemployer.ajouter();
  if(test)
{ui->tababonne->setModel(tmpemployer.afficher());//refresh
      ui->comboBox->setModel(tmpemployer.afficher_employer());
QMessageBox::information(nullptr, QObject::tr("Ajouter un Employer"),
                  QObject::tr("Abonée ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Employer"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{



int id = tmpemployer.get_id();


bool test=tmpemployer.supprimer(id);

if(test)
{
    ui->tababonne->setModel(tmpemployer.afficher());//refresh
    ui->comboBox->setModel(tmpemployer.afficher_employer());


    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_modifier_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString age = ui->lineEdit_age->text();
      QString job = ui->lineEdit_job->text();
        QString adresse = tmpemployer.get_adresse();

   employer a;
    if(a.rech(id)){
        bool test = a.modifier(id,nom,prenom,age,job,adresse);
        if(test){
            ui->tababonne->setModel(tmpemployer.afficher());//refresh
            QMessageBox::information(nullptr,QObject::tr("Personnel modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}


void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{

  tmpemployer.set_datec(date);

}

void MainWindow::on_dateEdit_2_userDateChanged(const QDate &date)
{
     tmpemployer.set_datee(date);

}

void MainWindow::on_pushButton_20_clicked()
{
   ui->tababonne->setModel(tmpemployer.afficher_tri());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString id = ui->lineEdit_r->text();
    ui->tababonne->setModel(tmpemployer.recherche(id));
}



void MainWindow::on_pushButton_3_clicked()
{
 ui->tababonne->setModel(tmpemployer.afficher());
 ui->comboBox->setModel(tmpemployer.afficher_employer());
}



void MainWindow::on_pushButton_clicked()
{
statistique s;
s.exec();
}




void MainWindow::on_comboBox_activated(const QString &arg1)
{

    tmpemployer.set_id(arg1.toInt());



}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    tmpemployer.set_adresse(arg1);
}

void MainWindow::on_pushButton_4_clicked()
{
    conge c;
    c.exec();
}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


