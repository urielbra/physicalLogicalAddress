#include <stdio.h>
#include <stdlib.h>

void showAddr(int a){
    printf("%p\n",  &a);
}

int main() {
    int a;
    printf("%p\n",  &a);
    showAddr(a);
    return 0;
}