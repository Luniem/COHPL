#include "include/stack_agg.h"
#include "include/stack_priv.h"

int main() {
    Stack_agg stack_agg;
    stack_agg.push(1);

    Stack_priv stack_priv;
    stack_priv.push(1);

    return 0;
}