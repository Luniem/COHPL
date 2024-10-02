#include "include/callback.h"

// subject with observer list
static subject* subject_instance;

void send_message(message_t* message) {
    // send message to all callbacks
    for (int i = 0; i < MAX_OBSERVER_SIZE; i++) {
        if(subject_instance->observers[i] != NULL) {
            subject_instance->observers[i]->callback(message);
        }
    }
}

bool subscribe(observer* observer) {
    // search for open space
    for (int i = 0; i < MAX_OBSERVER_SIZE; i++) {
        if(subject_instance->observers[i] == NULL) {
            subject_instance->observers[i] = observer;
            return true;
        }
    }
    
    return false;
}