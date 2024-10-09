#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("Usage: %s record1 [record2 ...]\n", argv[0]);
        return 1;
    }

    
    for (int i = 1; i < argc; i++) {
         FILE*file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Error: no such file or directory  %s\n", argv[i]);
            continue;
        }

       
        char buffer[BUFFER_SIZE];
        size_t bytes_read;

        
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
            fwrite(buffer, 1, bytes_read, stdout);
        }

        fclose(file);
    }

    return 0;
}