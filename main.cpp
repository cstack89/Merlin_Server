#include <QtCore/QCoreApplication>
#include "merlin_server.h"



int main(int argc, char *argv[])
{
    QTextStream cout(stdout); //Redirect output to stdout
    QCoreApplication a(argc, argv);

    merlin_server *serv = new merlin_server(1);
    QString ip = "10.10.10.1";
    QHostAddress host(ip);
    if(!serv->listen(host,quint16(5002)))
        cout<<"Could not start server"<<endl;
    return a.exec();
}
