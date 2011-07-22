#ifndef TERMINAL_CLIENT_H
#define TERMINAL_CLIENT_H

#include <QThread>
#include <QTcpSocket>
#include <QString>
class terminal_Client : public QThread
{
    Q_OBJECT
public:
    explicit terminal_Client(QObject *parent = 0);
    terminal_Client(QObject *parent,int socketDescriptor);
    void run();

private:
    static QTextStream cout; //Redirect output to stdout
    QTcpSocket *sock;
    quint32 message_length;
    quint8 message_type;
    char * message_body;
signals:

public slots:
    void incomingData();
};

#endif // TERMINAL_CLIENT_H
