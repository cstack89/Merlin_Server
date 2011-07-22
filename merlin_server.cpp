#include "merlin_server.h"

QTextStream merlin_server::cout(stdout); //Redirect output to stdout

merlin_server::merlin_server(QObject *parent) : QTcpServer(parent)
{
}
merlin_server::merlin_server(int bs) : QTcpServer()
{
}
void merlin_server::incomingConnection(int socketDescriptor)
{
    terminal_Client *cli = new terminal_Client(this,socketDescriptor);
    cli->start();
    clients.push_back(cli);
}
