#include <stdio.h>
#include <malloc.h>
#include <string.h>

void sort(const char *input, const char *output);

int main(int argc, char *argv[])
{
    sort("input.txt", "output.txt");
    return 0;
}

#define BUF_SIZE 1250000

void sort(const char *input, const char *output)
{
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");
    
    char *bitmap = (char*)malloc(BUF_SIZE);

    char line[32];
    int n = 0;
    
    memset(bitmap, 0, BUF_SIZE);

    while (fgets(line, 31, in) != NULL) {
        n = atoi(line);
        bitmap[n / 8] |= (1 << (7 - n % 8));
    }
    

    for (n = 0; n < BUF_SIZE * 8; n++) {
        if (bitmap[n / 8] & (1 << (7 - n % 8))) {
            sprintf(line, "%d\n", n);
            fputs(line, out);
        }
    }
    
    free(bitmap);
    fclose(in);
    fclose(out);
}
