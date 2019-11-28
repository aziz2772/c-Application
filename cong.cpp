#include "cong.h"


cong::cong()
{

}
QDate cong::get_datec(){return datecc;}
QDate cong::get_datee(){return dateee;}
bool cong::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);

query.prepare("INSERT INTO cong (ID_cong,ID_EMPLOYER,DATECC,DATEEE)"" VALUES (:id, :id_employer, :datecc, :dateee)");
query.bindValue(":id", res);
query.bindValue(":id_employer", id_employer);

query.bindValue(":datecc", datecc);
query.bindValue(":dateee", dateee);





return    query.exec();
}

QSqlQueryModel * cong::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from cong");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID EMPLOYER"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Debut  Conge "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Fin de  Conge "));


    return model;
}
QSqlQueryModel * cong::afficher_employer()
{QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery("select ID from employer");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;

}

bool cong::modifier(QString a,QDate date,QDate date2){
    QSqlQuery query;
    query.prepare("update cong set id_cong=:id_cong ,datecc=:datecc,dateee=:dateee,where id_cong = :id_cong;");
    query.bindValue(":id_cong", a);

    query.bindValue(":datecc", date);
    query.bindValue(":dateee", date2);


    return query.exec();
}
bool cong::rech(QString x){
    QSqlQuery query;
    query.prepare("select * from cong where ID_cong = :id_cong;");
    query.bindValue(":id_cong", x);
    return query.exec();
}

int cong::get_idemployer()
{
    return id_employer;
}
int cong::get_id()
{
    return id;
}
bool cong::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from cong where ID_cong = :id_cong ");
query.bindValue(":id_cong", res);
return    query.exec();
}
QSqlQueryModel * cong::afficher_id()
{QSqlQueryModel * model = new QSqlQueryModel;
model->setQuery("select ID_cong from cong");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;

}

QSqlQueryModel * cong :: recherche(QString id)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_cong, ID_EMPLOYER, DATECC, DATEEE from cong where ID_cong='"+id+"'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID EMPLOYER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE Creation "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE Expiration "));



    return model;
}

