#define _CRT_SECURE_NO_WARNINGS

#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define ascii_num 127

#define ascii_a 97
#define ascii_z 122

int sub_f1_1(void) {
    char str1[256];
    scanf("%s", str1);
    for (int i = 0; str1[i] != '\0'; i++) {
        printf("%c ", str1[i]);
    }
    return 0;
}

int sub_f1_2(void) {
    char str1[256];
    scanf("%s", str1);
    for (int i = 0; str1[i] != '\0'; i++) {
        str1[i] = toupper(str1[i]);
        printf("%c ", str1[i]);
    }
    return 0;
}

int sub_f3(void) {


    for (int i = 32; i < ascii_num; i++) {
        printf("%c %d %x \n", i, i, i);
    }



    return 0;
}

void binary_search(int start, int end, int* length, char* tmp_str) {

    if(start < end){
        int mid = (start + end) / 2;
        bool palin = true;

        if (mid < end) {
            for (int i = start; i < mid; i++) {
                if (tmp_str[i] != tmp_str[end - i]) {
                    palin = false;
                }
            }
        }


        binary_search(start, mid - 1, &length, tmp_str);
        binary_search(mid + 1, end, &length, tmp_str);


        if (palin == true) {
            *length = mid - start;
        }
    }
}

void sub_f4(void) {
    char tmp_str1[] = "aabcbaa";
    char tmp_str2[] = "aga";
    int start = 0;
    int end = sizeof(tmp_str1) / sizeof(char) - 1;
    int length = 0;


    binary_search(start, end, &length, tmp_str1);

    printf("%d", length);
}




int euclid_recursion(int a, int b) {

    if (b == 0) {

        //return a;
        printf("%d", a);
    }
    else {
        euclid_recursion(b, a%b);
    }
}



int sub_f5(int a, int b) {

    if (a > b) {
        return euclid_recursion(a, b);
    }
    else {
        return euclid_recursion(b, a);
    }
}




void sub_f6(void) {

    char alpha_char;

    scanf("%c", &alpha_char);

    if ((alpha_char < ascii_z) && (ascii_a < alpha_char)) {
        for (int i = 0; i < alpha_char - ascii_a + 1; i++) {
            for (int j = ascii_a; j < (alpha_char + 1) - i; j++) {
                printf("%c",j);
            }
            printf("\n");
        }
    }
}


void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void ch_swap(char* x, char* y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void sub_f7(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);

    printf("a: %d b: %d", a, b);
    swap(&a, &b);
    printf("\n");
    printf("a: %d b: %d", a, b);

}


void sub_f8(void) {

    int num_list[8] = { 3, 2, 1, 4, 7, 6, 5, 8 };
    int length = 8;
    int tmp;

    int min_index;
    for (int i = 0; i < length; i++) {

        min_index = i;
        for (int j = i; j < length; j++) {
            if (num_list[min_index] > num_list[j]) {
                min_index = j;
            }
        }
        if (num_list[min_index] < num_list[i]) {
            tmp = num_list[i];
            num_list[i] =  num_list[min_index];
            num_list[min_index] = tmp;
        }
    }
    for (int i = 0; i < length; i++) {
        printf("%d", num_list[i]);
    }
}

void sub_f9(void) {
    
    int n;
    
    scanf("%d", &n);

    for (int i = 0; i < (n / 2) + 1; i++) {
        for (int j = 0; j < (2 * i) + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void sub_combination(void) {

    int n = 3;
    int r = 2;
    char (*str[3])[];
    str[0] = "Â¥Àå¸é";
    str[1] = "¿ìµ¿";
    str[2] = "Â«»Í";
    int cost[3] = {1000, 2000, 3000};

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%s, %s \n", str[i], str[j]);
        }
    }

    printf("all combination case number : %d", factorial(n) / (factorial(r) * factorial(n - r)));
}


void permutation_recursion(char* str, int l, int r) {
    if (l == r) {
        printf("%s", str);
    }
    for (int i = l; i < r + 1; i++) {
        ch_swap((str + l), (str + i));
        permutation_recursion(str, l + 1, r);
        ch_swap((str + i), (str + l));
    }
}


void sub_permu(void) {

    char str[] = "ABC";

    permutation_recursion(str, 0, 2);
    printf("all permutation case number : %d", factorial(3) / factorial(2));
}

int factorial(int n) {

    int num;

    for (num = 1; n > 1; n--) {

        num *= n;
    }
    return num;
}


int main(void) {
    //sub_f1_1();
    //sub_f1_2(); 
    //sub_f3();
    //sub_f4();
    //sub_f5(12, 4);
    //sub_f6();
    //sub_f7();
    //sub_f8();
    //sub_f9();
    //sub_permu();
    //sub_combination();
    return 0;
}