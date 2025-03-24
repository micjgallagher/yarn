#include <stdio.h>
#include <time.h>
#include "yarn.h"

int main(){
    float start_time = (float) clock();
    string test = construct_string(10);
    add_character(&test, 'H');
    for (int i= 0; i < 100000; i++){
            add_character(&test, 'e');
    }
    //printf("%s\n", test.body);

    //Testing copy speeds
    for (int counter = 0;counter < 10000; counter++){
        string copySTR = create_copy(&test);
        destroy_string(&copySTR);
    }

    destroy_string(&test);

    float end_time  = (float)clock();
    float total_time = end_time - start_time;
    printf("Total cycles elapsed %d\n", total_time);
    printf("Start cycle time %d\n", start_time);
    printf("End cycle time %d\n", end_time);
}
