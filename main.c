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


    float end_time  = (float)clock();
    float total_time = end_time - start_time;
    printf("Total cycles elapsed for copy: %d\n", total_time);

    //Testing memcopy speeds
    start_time = (float) clock();
    string memcpySTR = create_copy_memcpy(&test);
    destroy_string(&memcpySTR);

    for (int i= 0; i < 10000; i++){
        string memcpySTR = create_copy_memcpy(&test);
        destroy_string(&memcpySTR);
    }
    end_time = (float) clock();
    total_time = end_time - start_time;
    printf("Total cycles elapsed for memcpy: %d\n", total_time);

    destroy_string(&test);
}
