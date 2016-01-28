#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <string.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    struct sockaddr_in my_addr, peer_addr;
    int sock, error, peer_addr_len, scom, i, j;
    char host[1024], serv[1024], inBuffer[1024], outBuffer[1024];
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) != -1) {       
        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(9999);
        my_addr.sin_addr.s_addr = INADDR_ANY;
        
        if (bind(sock, (struct sockaddr *) &my_addr, sizeof(struct sockaddr_in)) != 0) {
			printf("Error during port binding\n");
			exit(1);
		}

        if (listen(sock, 10) != 0) {
			printf("Error during port listening\n");
			exit(1);
		}
		
		printf("Listening on port %d\n", ntohs(my_addr.sin_port));
		
		while (1) {
			
			peer_addr_len = sizeof(struct sockaddr_in);
			scom = accept(sock, (struct sockaddr *)&peer_addr, &peer_addr_len);
			getnameinfo((struct sockaddr *)&peer_addr, sizeof(peer_addr), host, sizeof(host), serv, sizeof(serv), 0);
			printf("Received from %s on port %s\n", host, serv);
			
			while (1) {
				recv(scom, inBuffer, sizeof(inBuffer), 0);
	       		printf("\nReceived data: %s\n", inBuffer);
	            memset(outBuffer, 0, sizeof(outBuffer));
	            
	            printf("Vowels: %d\n", countVowel(inBuffer));
	            printf("Consonants: %d\n", countConsonants(inBuffer));
	       
	            //send(scom, outBuffer, strlen(outBuffer), 0);
	            memset(inBuffer, 0, sizeof(inBuffer));
	            //if (strcmp(inBuffer, "END") == 0) {
	            //    break; 
			    //}
            }
		};
		
		close(scom);        
        close(sock);
    } 
}
