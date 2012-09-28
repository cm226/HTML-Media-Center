/*
 * TCPTransever.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: craig
 */

#include "TCPTransever.h"

TCPTransever::TCPTransever() {

//	this->socketFd = socket(AF_INET, SOCK_STREAM, 0);
	//	if(this->socketFd ==0)
		//	this->error("Error CreatingSocket");
}

TCPTransever::~TCPTransever()
{
   // close(newsockfd);
    //close(sockfd);
}

bool TCPTransever::startComms(int port)
{
	/*struct sockaddr_in serv_addr = {0},cli_addr = {0} ;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(this->PORT);

	if (bind(this->socketFd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR on binding");

	 listen(this->socketFd,5);

	 socklen_t clilen = sizeof(cli_addr);
	 this->newSocketFd = accept(this->socketFd,(struct sockaddr *) &cli_addr, &clilen);

	 if (this->newSocketFd < 0)
		 error("ERROR on accept");*/
}
