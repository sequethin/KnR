#include <stdio.h>
#include <stdlib.h>
#include <id3.h>

typedef struct _id3tag
{
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[30];
    unsigned char track;
    unsigned char genre;
} id3tag;

int ReadID3(const char* Filename, id3tag *ID3Tag); //0==error, 1==sucess

int main(int argc, char **argv)
{
    id3tag ID3;
    if(!ReadID3("C:\\g.mp3",&ID3))
        printf("error!\n");

    printf("Genre %d\nYear %s\n",ID3.genre,ID3.year);
    return 0;
}


int ReadID3(const char* Filename, id3tag *ID3Tag)
{
    FILE *fp=fopen(Filename,"rb");
    char buffer[128];
    int x;

    fseek(fp,-128,SEEK_END);
    fread(buffer,sizeof(char),sizeof(buffer),fp);

    if(!(buffer[0]=='T' && buffer[1] == 'A' && buffer[2] == 'G'))
    {
        return 0;
    }
    //Found id3 tag, let's fill out our id3tag struct
    for(x=0;x<30;x++)
        ID3Tag->title[x] = buffer[x+3]; //take 3 off cause of TAG
        ID3Tag->title[30] = '\0';

    for(x=0;x<30;x++)
        ID3Tag->artist[x] = buffer[x+33]; //33 = TAG + title
        ID3Tag->artist[30] = '\0';

    for(x=0;x<30;x++)
        ID3Tag->album[x] = buffer[x+63]; //TAG + title + artist
        ID3Tag->album[30] = '\0';

    for(x=0;x<4;x++)
        ID3Tag->year[x] = buffer[x+93]; //TAG + title + artist + album
        ID3Tag->year[4] = '\0';

    for(x=0;x<30;x++)
        ID3Tag->comment[x] = buffer[x+97]; //TAG + title + artist + album + year
        ID3Tag->comment[30] = '\0';

    if(buffer[127] > 0 && buffer[127] < 256)
        ID3Tag->genre = buffer[127]; //If its between 1-255, put it
    else
        ID3Tag->genre = 255; //255 means unused
    //ID3 1.1 compatibility (Track field)
    if(ID3Tag->comment[28] == '\0')
        ID3Tag->track = ID3Tag->comment[29]; //If comment ends at 28.. then 29 is the track
    else
        ID3Tag->track = 0; //0 mean's unknown track
    return 1;
}

