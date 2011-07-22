#include "terminal_client.h"

QTextStream terminal_Client::cout(stdout); //Redirect output to stdout

terminal_Client::terminal_Client(QObject *parent) :
    QThread(parent)
{
}
terminal_Client::terminal_Client(QObject *parent, int socketDescriptor)
{
    sock = new QTcpSocket(parent);

    if(!sock->setSocketDescriptor(socketDescriptor))
        cout << "Error setting the socket descriptor for the new client";

    connect(sock,SIGNAL(readyRead()),this,SLOT(incomingData()));

    message_length = 0;
    message_type = 0;
    message_body = NULL;
}
void terminal_Client::run()
{
    exec();
}
void terminal_Client::incomingData()
{
    QDataStream in(sock);
    //in.setVersion(QDataStream::Qt_4_0);

    if(message_length == 0)
    {
        if(sock->bytesAvailable() < (int)sizeof(quint32))
            return;

        in >> message_length;
    }
    if(message_type == 0)
    {
        if(sock->bytesAvailable()<(int)sizeof(quint8))
            return;
        in >> message_type;
    }
    if(sock->bytesAvailable() < (message_length - sizeof(quint8)))
        return;
    uint t = (uint)(message_length - sizeof(quint8));
    in.readBytes(message_body,t);

    cout<<"Message size: "<< message_length << endl;
    cout<<"Message type: "<< message_type << endl;
    cout <<"Message body: "<< QString(message_body).toStdString().c_str() << endl;
}
