#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

int main(){
    ArrayList alist;
    AL_init_list(&alist);
    AL_insert(&alist, 0, 10);
    AL_insert(&alist, AL_get_length(&alist), 30);
    AL_insert(&alist, 1, 20);
    AL_insert(&alist, AL_get_length(&alist), 40);
    AL_print_list(&alist);
    AL_delete(&alist, 0);
    AL_replace(&alist, 2, 50);
    AL_replace(&alist, AL_get_pos(&alist, 20), 10);
    AL_print_list(&alist);
}