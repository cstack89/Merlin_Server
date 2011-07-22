#ifndef MERLIN_SERVER_H
#define MERLIN_SERVER_H

#include <QTcpServer>

class merlin_server : public QTcpServer
{
    Q_OBJECT
public:
    explicit merlin_server(QObject *parent = 0);

signals:

public slots:

};

#endif // MERLIN_SERVER_H
