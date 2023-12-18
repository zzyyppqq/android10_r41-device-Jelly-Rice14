//
// Created by aecg on 2023/12/13.
//
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/**
 * 1.创建一个类型为 pthread_key_t 类型的变量。
 * 2.调用 pthread_key_create() 来创建该变量。该函数有两个参数，第一个参数就是上面声明的 pthread_key_t 变量，
 *   第二个参数是一个清理函数，用来在线程释放该线程存储的时候被调用。该函数指针可以设成 NULL，这样系统将调用默认的清理函数。
 * 3.当线程中需要存储特殊值的时候，可以调用 pthread_setspcific() 。该函数有两个参数，
 *   第一个为前面声明的 pthread_key_t 变量，第二个为 void* 变量，这样你可以存储任何类型的值。
 * 4.如果需要取出所存储的值，调用 pthread_getspecific() 。该函数的参数为前面提到的 pthread_key_t 变量，该函数返回 void * 类型的值。
 */

static pthread_key_t key;

void echomsg(int t) {
    printf("destructor excuted in thread %d,param=%d\n", pthread_self(), t);
}

void *child1(void *arg) {
    pthread_t tid = pthread_self();
    printf("thread %d enter\n", tid);
    pthread_setspecific(key, (void *) tid);
    sleep(2);
    printf("thread %d returns %d and key %d\n", tid, pthread_getspecific(key), key);
    sleep(5);
}

void *child2(void *arg) {
    pthread_t tid = pthread_self();
    printf("thread %d enter\n", tid);
    pthread_setspecific(key, (void *) tid);
    sleep(1);
    printf("thread %d returns %d and key %d\n", tid, pthread_getspecific(key), key);
    sleep(5);
}

int main(void) {
    pthread_t tid1, tid2;
    printf("this is main thread\n");
    pthread_key_create(&key, (void (*)(void *)) echomsg);
    pthread_create(&tid1, NULL, child1, NULL);
    pthread_create(&tid2, NULL, child2, NULL);
    sleep(10);
    pthread_key_delete(key);
    printf("main thread exit\n");
    return 0;
}