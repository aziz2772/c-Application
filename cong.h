#ifndef CONVENTION_H
#define CONVENTION_H
#include "employer.h"
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class cong
{

public:
    cong();
    void set_datec(QDate date1){this->datecc=date1;}
    void set_datee(QDate date2){this->dateee=date2;}
    void set_id(int id){this->id=id;}
    void set_idemployer(int id){this->id_employer=id;}
    QDate get_datee();
   QDate get_datec();
   int get_idemployer();
   bool ajouter();
   bool modifier(QString,QDate,QDate);
   bool supprimer(int idd);
   QSqlQueryModel * afficher_id();
   int get_id();
   bool rech(QString x);
   QSqlQueryModel * afficher();
   QSqlQueryModel * afficher_employer();

   QSqlQueryModel * recherche(QString id);
private:
    int id,id_employer;
    QString type;
    QDate datecc,dateee;
};

#endif // CONVENTION_H
