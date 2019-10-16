#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/mman.h>


int main()
{
	const int SIZE = 4096;
	const char *name = "shared_memory";

	int shm_fd;
	char *ptr, *start;
	srand(time(0));


	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);


	ftruncate(shm_fd,SIZE);


	ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("Map failed\n");
		return -1;
	}

	char c;
	int contador = 0;


    for (contador = 0; contador < 50;  contador++, ptr++) {
        *ptr = 'a' + rand()%26;
        printf("%02d|Saving on memory: %c\n" ,contador, *ptr);			
    }
       	
	*ptr = '\0';
	ptr++;

	printf("%s\n",(char*)ptr);
	

	//*ptr=10;
	
	//memcpy(ptr,"conteudo",tamanho);
	return 0;
}