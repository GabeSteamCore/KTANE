#ifndef UTILITY
#define UTILITY

int roundToNearest(int x, int nearest){
    return (x + nearest/2) - ((x + nearest/2) % nearest);
}

#endif
