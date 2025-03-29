#include <stdio.h>
#include <time.h>
#include "yarn.h"

void check_speed(){
    clock_t start_time = clock();
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


    clock_t end_time  = clock();
    clock_t total_time = end_time - start_time;
    double real_time = (double) total_time / CLOCKS_PER_SEC;
    printf("Total cycles elapsed for copy: %d\n", real_time);

    //Testing memcopy speeds
    start_time =  clock();

    for (int i= 0; i < 10000; i++){
        string memcpySTR = create_copy_memcpy(&test);
        destroy_string(&memcpySTR);
    }
    end_time =  clock();
    total_time = end_time - start_time;
    real_time = (double) total_time / CLOCKS_PER_SEC;
    printf("Total cycles elapsed for memcpy: %d\n", real_time);

    destroy_string(&test);
}

int main(){
    string s1 = construct_string(10);
    string s2 = construct_string(10);

    for (int i=0;i<5;i++){
        add_character(&s1, 'h');
        add_character(&s2, 'h');
    }

    if(check_string_equality(&s1, &s2)){
        printf("Check passed\n");
    }else{
        printf("check failed");
    }
}

