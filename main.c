#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//need to add the -lm flag to compilation because of math.h

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Você não digitou suficiente :(\n");
        return 1;
    }

    //atoi / atof convets values to respectvely int and float
    double base = atof(argv[1]);
    int power = atoi(argv[2]);

    for(int i = 0; i < power + 1; i++){
        double number = pow(base, i);

        printf("%.2f\n", number);
    }
    return 0;
}