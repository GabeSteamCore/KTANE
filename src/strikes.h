#include <stdbool.h>

typedef enum Difficulty{
  Hard,
  Normal,
  Easy
}Difficulty;

typedef struct Strikes{
  int failures;
  Difficulty difficulty;
}Strikes;