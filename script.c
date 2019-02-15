#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <image> <# instances> <starting port #>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = strtol(argv[2], NULL, 0);
    int port = strtol(argv[3], NULL, 0);
    char command[100];
    for (int i = 0; i < n; ++i) {
        sprintf(command, "docker run -d -p %d:80 %s", port, argv[1]);
        system(command);
        ++port;
    }

    return EXIT_SUCCESS;
}
