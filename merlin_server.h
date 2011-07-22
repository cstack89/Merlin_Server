#ifndef MERLIN_SERVER_H
#define MERLIN_SERVER_H

#include <QTcpServer>
#include <QtNetwork>
#include "terminal_client.h"
#include <QList>



class merlin_server : public QTcpServer
{
    Q_OBJECT
public:
    explicit merlin_server(QObject *parent = 0);
    merlin_server(int);
protected:
    void incomingConnection(int socketDescriptor);
private:
    static QTextStream cout; //Redirect output to stdout
    QList<terminal_Client *> clients;
signals:

public slots:

};

#endif // MERLIN_SERVER_H
