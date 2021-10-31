#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PACKETS "sample-packets"
#define MAXMACADD 500

struct packetStruct
{
    char mac[17];
    int size;
} packetStruct[MAXMACADD];

struct output
{
    char mac[17];
    int size;
} output[MAXMACADD];

void sortSize(struct packetStruct *macadd, int n)
{
    int j, i;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (macadd[j].size < macadd[j + 1].size)
            {
                struct packetStruct temp = macadd[j];
                macadd[j] = macadd[j + 1];
                macadd[j + 1] = temp;
            }
        }
    }
}

void mergeMac2(struct packetStruct *macadd, struct output *output, int n)
{
    int i, j, k = 0;

    for (i = 0; i < n; i++)
    {
        /*
         * If size is 0, the packet has already been processed.
         */
        if (macadd[i].size == 0)
            continue;

        memcpy(&output[k], &macadd[i], sizeof(struct packetStruct));

        for (j = i + 1; j < n; j++)
        {
            /*
             * If size is 0, the packet has already been processed.
             */
            if (macadd[j].size == 0)
                continue;

            if (strcmp(macadd[i].mac, macadd[j].mac) == 0)
            {
                output[k].size += macadd[j].size;

                /*
                 * Set size to 0 so that these packets won't be
                 * processed in the next pass.
                 */
                macadd[j].size = 0;
            }
        }
        k++;
    }
}

int readpacket()
{
    char *token;
    char buf[60];
    int size;
    FILE *packet = fopen(PACKETS, "r"); //open packet file in read mode

    int i = 0;
    int j = 0; //loop control variables
    int k = 0;

    while (fgets(buf, sizeof(buf), packet) != '\0')
    {
        token = strtok(buf, "\t");  //tokenize buf and point to time
        token = strtok(NULL, "\t"); //point to sender mac add

        token = strtok(NULL, "\t"); //point to dest mac add
        strcpy(packetStruct[i].mac, token);

        token = strtok(NULL, "\t"); //point to byte size
        packetStruct[i].size += atoi(token);

        //printf("%i. %s\t%d\n", i, packetStruct[i].mac, packetStruct[i].size);
        i++;
    }
    fclose(packet); //close packet file

    sortSize(packetStruct, i);
    mergeMac2(packetStruct, output, i);

    for (i = 0; i < 20; i++)
    {
        printf("%i. %s\t%d\n", i, packetStruct[i].mac, packetStruct[i].size);
    }

    for (i = 0; i < 20; i++)
    {
        printf("%i. %s\t%d\n", i + 1, output[i].mac, output[i].size);
    }
    return 0;
}

void main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("%s: program needs 1 argument, but there was %d\n", argv[0], argc - 1);
        exit(EXIT_FAILURE);
    }
    else
    {
        if (strcmp(argv[1], "packets") != 0)
        {
            printf("%s: program expected command 'packets', but you wrote %s\n", argv[0], argv[1]);
        }
        else
        {
            if (readpacket() != 0)
            {
                exit(EXIT_FAILURE);
            }
        }
    }
}