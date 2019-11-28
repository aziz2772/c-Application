#include "employer.h"
#include <QDebug>
#include <qcustomplot.h>
employer::employer()
{
id=0;
nom="";
prenom="";
}

employer::employer(int id,QString nom,QString prenom,int age,QString job,QString adresse)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
    this->job=job;
    this->adresse=adresse;
    this->age=age;




}
QString employer::get_nom(){return  nom;}
QString employer::get_prenom(){return prenom;}
QString employer::get_job(){return  job;}
int employer::get_age(){return  age;}
QString employer::get_adresse(){return adresse;}
int employer::get_id(){return  id;}
QDate employer::get_datec(){return datec;}
QDate employer::get_datee(){return datee;}


void employer::set_id(int id)
{this->id=id;}
bool employer::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);

query.prepare("INSERT INTO employer (ID, NOM, PRENOM,JOB,ADRESSE,AGE,DATEC,DATEE)"" VALUES (:id, :nom, :prenom, :job, :adresse, :age, :datec, :datee)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":job", job);

query.bindValue(":adresse", adresse);
query.bindValue(":age", age);
query.bindValue(":datec", datec);
query.bindValue(":datee", datee);





return    query.exec();
}

QSqlQueryModel * employer::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employer");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
//model->setHeaderData(3, Qt::Horizontal, QObject::tr("JOB"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE "));
//model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("JOB "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUM tel"));

model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATE Experation CONTRAT"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE CREATION CONTRAT"));


    return model;
}

bool employer::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from employer where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool employer::rech(QString x){
    QSqlQuery query;
    query.prepare("select * from employer where ID = :id;");
    query.bindValue(":id", x);
    return query.exec();
}

bool employer::modifier(QString a,QString b,QString c,QString d,QString e,QString f){
    QSqlQuery query;
    query.prepare("update employer set nom=:nom ,prenom=:prenom,age=:age,job=:job,adresse=:adresse  where id = :id;");
    query.bindValue(":id", a);
    query.bindValue(":nom", b);
    query.bindValue(":prenom", c);
    query.bindValue(":age", d);
    query.bindValue(":job", e);
    query.bindValue(":adresse", f);

    return query.exec();
}
QSqlQueryModel * employer::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employer order by ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    //model->setHeaderData(3, Qt::Horizontal, QObject::tr("JOB"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE "));
    //model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("JOB "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUM tel"));

    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATE Experation CONTRAT"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE CREATION CONTRAT"));
    return model;
}

QSqlQueryModel * employer :: recherche(QString id)
{


    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID, NOM, PRENOM, JOB, ADRESSE, AGE, DATEC, DATEE from EMPLOYER where ID='"+id+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("JOB"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE Creation "));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATE Expiration "));


    return model;
}

QSqlQueryModel * employer::afficher_employer()
{QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery("select ID from employer");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;

}
QSqlQueryModel * employer::afficher_jobb()
{QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery("select NOM from jobb");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    return model;

}
