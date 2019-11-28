#ifndef ABONNE_H
#define ABONNE_H


#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class employer
{public:
    employer();
    employer(int,QString,QString,int,QString,QString);
    QString get_nom();
    void set_datec(QDate date1){this->datec=date1;}
    void set_datee(QDate date2){this->datee=date2;}
    void set_nom(QString nom){this->nom=nom;}
    void set_adresse(QString adresse){this->adresse=adresse;}
    void set_prenom(QString prenom){this->prenom=prenom;}
    void set_job(QString job){this->job=job;}
    void set_age(int age){this->age=age;}
    QString get_prenom();
    QString get_job();
    QString get_adresse();
     QDate get_datee();
    QDate get_datec();
    int get_id();
    void set_id(int);
    int get_age();
    bool ajouter();
    bool rech(QString);
        bool modifier(QString,QString,QString,QString,QString,QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_employer();
    QSqlQueryModel * afficher_jobb();
    QSqlQueryModel * afficher_tri();
    bool supprimer(int);
     QSqlQueryModel * recherche(QString);
private:
    QString nom,prenom,job,adresse,date2;
    QDate datec,datee;
    int age;

    int id;

};

#endif // ABONNE_H
