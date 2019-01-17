#include <stdio.h>

 int main()
 {
    char str[60];
    FILE* x = freopen("board.txt","r",stdin);
    if(x==NULL){
        printf("Error opening file");
        return(-1);
    }
    while(fgets (str, 60,stdin)){
        puts(str);
    }
    return 0;
}
