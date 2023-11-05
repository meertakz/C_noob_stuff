#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// ** struct ** ///
typedef struct{
    int x1, y1, x2, y2;
    int used1, used2;
}segment_t;



/// ** prototypes ** ///
segment_t *load(char*, int*);
void connect(segment_t*, int);
void check(segment_t*, int);



/// ** main ** ///
int main(int argc, char *argv[]){
    segment_t *segments;
    int n;

    segments = load(argv[1], &n);
    connect(segments, n);
    check(segments, n);

    free (segments);

    return EXIT_SUCCESS;
}



/// ** load input && set (ignored) ** ///
segment_t *load(char *name, int *n){
    int i, j, length, x1, y1, x2, y2, skip;
    segment_t *segments;
    FILE* fp;

    fp = fopen(name, "r");
    if (fp==NULL){
        printf("file open error <%s> not found\nmaybe try something like <files/...> ?\n", name);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d", n);
    segments = (segment_t*) malloc (*n*sizeof(segment_t));
    if (segments==NULL){
        printf("memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    fprintf(stdout, "\n--------------------------------------------------------------------------------\n");
    while (i<*n && fscanf(fp, "%d %d %d %d", &x1, &y1, &x2, &y2)!=EOF){
        skip = 0;
        length = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2-y1);
        if (length==0){
            fprintf(stdout, "---------------> segment %2d %2d %2d %2d || length zero (ignored) <-----------------\n", x1, y1, x2, y2);
            skip = 1;
        }
        for (j=0; j<i && skip==0; j++){
            if ((x1==segments[j].x1 && y1==segments[j].y1 && x2==segments[j].x2 && y2==segments[j].y2)
            || (x1==segments[j].x2 && y1==segments[j].y2 && x2==segments[j].x1 && y2==segments[j].y1))
            {
                fprintf(stdout,"---------------> segment %2d %2d %2d %2d || duplicated  (ignored) <-----------------\n", x1, y1, x2, y2);
                skip = 1;
            }
        }
        if (skip==0){
            segments[i].x1 = x1;
            segments[i].y1 = y1;
            segments[i].x2 = x2;
            segments[i].y2 = y2;
            segments[i].used1 = 0;
            segments[i].used2 = 0;
            i++;
        }
    }
    *n = i;

    fclose(fp);
    fprintf(stdout, "--------------------------------------------------------------------------------\n");

    return segments;
}



/// ** search connected segments ** ///
void connect(segment_t *segments, int n){
    int i, j;

    // for each segment //
    for (i=0; i<n-1; i++){
        // check if one of the next can be connected //
        for (j=i+1; j<n; j++){
            if (segments[i].x1==segments[j].x1 && segments[i].y1==segments[j].y1){
                segments[i].used1++;
                segments[j].used1++;
            }
            if (segments[i].x1==segments[j].x2 && segments[i].y1==segments[j].y2) {
                segments[i].used1++;
                segments[j].used2++;
            }
            if (segments[i].x2==segments[j].x1 && segments[i].y2==segments[j].y1) {
                segments[i].used2++;
                segments[j].used1++;
            }
            if (segments[i].x2==segments[j].x2 && segments[i].y2==segments[j].y2) {
                segments[i].used2++;
                segments[j].used2++;
            }
        }
    }
}



/// ** check connection status of all segments ** ///
void check(segment_t *segments, int n){
    int i, disconnected, overconnected;

    disconnected = 0;
    overconnected = 0;

    for (i=0; i<n; i++){
        fprintf(stdout, "segment %2d %2d %2d %2d ", segments[i].x1, segments[i].y1, segments[i].x2, segments[i].y2);
        fprintf(stdout, "|| left extreme: ");
        if (segments[i].used1 == 0){
            fprintf(stdout, "disconnected ");
            disconnected++;
        } else if (segments[i].used1 == 1) {
            fprintf(stdout, "OK           ");
        } else {
            fprintf(stdout, "overconnected");
            overconnected++;
        }
        // ******************************* //
        fprintf(stdout, "|| right extreme: ");
        if (segments[i].used2 == 0){
            fprintf(stdout, "disconnected\n");
            disconnected++;
        } else if (segments[i].used2 == 1) {
            fprintf(stdout, "OK\n");
        } else {
            fprintf(stdout, "overconnected\n");
            overconnected++;
        }
    }
    fprintf(stdout, "--------------------------------------------------------------------------------\n");
    if (disconnected > 2){
        fprintf(stdout, "broken line with %d disconnected segments\n", disconnected/2-1);
    }
    if (overconnected > 0){
        fprintf(stdout, "broken line with %d overconnected segments\n", overconnected);
    }
    if (disconnected<=2 && overconnected==0){
        fprintf(stdout, "single broken line\n");
    }
    fprintf(stdout, "--------------------------------------------------------------------------------\n");
}
