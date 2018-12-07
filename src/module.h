typedef enum ModuleType{
  NEEDY,
  STATIC
}ModuleType;

typedef enum ModuleState{
  UNSOLVED,
  SOLVED
}ModuleState;

typedef struct Module{
  ModuleType type;
  ModuleState state;
}Module;