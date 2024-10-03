#ifndef CALLBACK_H
#define CALLBACK_H

#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_OBSERVER_SIZE 10

typedef struct {
    char message[32];
    int64_t timestamp;
} message_t;

typedef struct {
    void (*callback) (message_t* message);
} observer_t;

typedef struct {
    observer_t * observers[MAX_OBSERVER_SIZE];
} subject_t;

void send_message(message_t* message);

bool subscribe(observer_t* observer);

void unsubscribe(observer_t* observer);
#endif