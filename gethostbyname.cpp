#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(void)
{
    int i = 0;
    char str[32] = {0};
     struct hostent* phost = NULL;
 
    phost = gethostbyname("www.google.com");
    if (NULL == phost)
    {
        return -1;    
    }
    
    printf("---Offical name:\n\t%s\n", phost->h_name);

    printf("---Alias name:\n");    
    for (i = 0;  phost->h_aliases[i]; i++)
    {
        printf("\t%s\n", phost->h_aliases[i]);
    }

    printf("---Address list:\n");
    for (i = 0; phost->h_addr_list[i]; i++)
    {
        printf("\t%s\n", inet_ntop(phost->h_addrtype,  phost->h_addr_list[i], str, sizeof(str)-1));
    }

    return 0;
}