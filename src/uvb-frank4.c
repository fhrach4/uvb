#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[])
{
	struct sockaddr_in serverAddress;
	struct hostent *server;
	int port = 80;
	char* name;
	char* host;
	char request[255];
	// Argument 1 will be the name, argument 2 will be the address
	if (argc != 3)
	{
		printf("Usage: %s name address\n", argv[0]);
	}else
	{
		// Save the arguments in a more readable format
		name = argv[1];
		host = argv[2];

		// creat the request
		bzero((char*) &request, sizeof(request));
		strcat(request, "POST ");
		strcat(request, "NAME=");
		strcat(request, name);

		int sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock != 0)
		{
			fprintf(stderr, "Error connecting to %s on port 80\n", host);
			exit(1);
		}

		server = gethostbyname(host);
		if (server == NULL)
		{
			fprintf(stderr, "Host %s does not exist\n", host);
			exit(2);
		}

		// Zero out the buffer, just to be safe
		bzero((char *) &serverAddress, sizeof(serverAddress));
		serverAddress.sin_family = AF_INET;

		// set the target address
		bcopy((char*) &server->h_addr,
			(char*) &serverAddress.sin_addr.s_addr,server->h_length);
		serverAddress.sin_port = port;
	}
}
