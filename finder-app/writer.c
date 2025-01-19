#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<syslog.h>
#include<errno.h>
#include<string.h>

int main(int argc, const char* argv[]){
	openlog("assignment2-writer", LOG_CONS | LOG_PERROR, LOG_USER);
	if(argc != 3){
		syslog(LOG_ERR,"%s","2 parameters expected, file path and string to write");
		closelog();
		return 1;
	}
	
	const char* filename;
	const char* strToWrite;

	filename = argv[1];
	strToWrite = argv[2];

	int fd;

	fd = creat(filename,0644);

	if(fd == -1){
		syslog(LOG_ERR, "Error opening the file %s: (%d) %s", filename, errno, strerror(errno));
		return errno;
	}

	int nr;
	int msglen = strlen(strToWrite);
	nr = write(fd, strToWrite, msglen);
	
	if(nr == -1){
		syslog(LOG_ERR, "Error writing the file %s: (%d) %s", filename, errno, strerror(errno));
	}

	//int nt;
	//nt = ftruncate(fd, msglen);
	
	//if(nt == -1){
	//	syslog(LOG_ERR, "Error truncating the file %s: (%d) %s", filename, errno, strerror(errno));
	//}

	if(close(fd) == -1){
		syslog(LOG_ERR, "Error closing the file %s: (%d) %s", filename, errno, strerror(errno));
	}

	return 0;
}
