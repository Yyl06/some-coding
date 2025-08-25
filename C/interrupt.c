#include <stdio.h>
#include <windows.h>
#include <winscard.h>

static inline void memory_barrier(){
    __asm__ __volatile__("mfence" ::: "memory");
}


int main(){
    memory_barrier();
}