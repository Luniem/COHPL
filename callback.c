#include "include/callback.h"

subject_t* get_subject() {
    static subject_t* instance = NULL;

    if (instance == NULL) {
        instance = (subject_t*)malloc(sizeof(subject_t));
    }

    return instance;
}

void send_message(message_t* message) {
    subject_t* subject_instance = get_subject();

    // send message to all callbacks
    for (int i = 0; i < MAX_OBSERVER_SIZE; i++) {
        if(subject_instance->observers[i] != NULL) {
            subject_instance->observers[i]->callback(message);
        }
    }
}

bool subscribe(observer_t* observer) {
    subject_t* subject_instance = get_subject();

    // search for open space
    for (int i = 0; i < MAX_OBSERVER_SIZE; i++) {
        if(subject_instance->observers[i] == NULL) {
            subject_instance->observers[i] = observer;
            return true;
        }
    }
    
    return false;
}

void unsubscribe(observer_t* observer) {
    subject_t* subject_instance = get_subject();

    //serach for observer and remove it
    for (int i = 0; i < MAX_OBSERVER_SIZE; i++) {
        if(subject_instance->observers[i] == observer) {
            subject_instance->observers[i] = NULL;
        }
    }
}