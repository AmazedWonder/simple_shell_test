#ifndef SHELL_UTILS_H
#define SHELL_UTILS_H

#define _TRUE 1
#define _FALSE 0

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define NON_INTERACTIVE 0
#define INTERACTIVE 1

#define PERMISSIONS 1
#define NON_PERMISSIONS -1

#define _FILE 10
#define NON_FILE -10

#define _ENOENT "No such file or directory"
#define _EACCES "Permission denied"
#define _CMD_NOT_EXISTS "not found"
#define _ILLEGAL_NUMBER "Illegal number"

#define _CODE_ENOENT 3
#define _CODE_EACCES 13
#define _CODE_CMD_NOT_EXISTS 132
#define _CODE_ILLEGAL_NUMBER 133
typedef struct __attribute__((__packed__)) {
  int argc;            /* numbr of arguments received */
  char **argv;         /* arguments received */
  int mode;            /* INTERACTIVE or NON_INTERACTIVE mode */
  int error_code;      /* script for error message */
  char *command;       /* Cmd to execute */
  int n_commands;      /* number of comds executed */
  char *value_path;    /* command paths*/
  int is_current_path; /* checks current path or not current */
  int status_code;     /* last exit code */
  char *buffer;        /* lines read using getline func */
  char **arguments;    /* strings splited into words */
  char *environment;   /* environment variable to get */
  int pid;             /* process id */
} general_t;

typedef struct __attribute__((__packed__)) {
  char *message; /* error message */
  int code;      /* Error code to identify error msg */
} error_t;

typedef struct __attribute__((__packed__)) {
  char *command; /* arguments[0] = cmd */
  void (*func)(general_t *info, char **arguments);
} builtin_t;

#endif /* SHELL_UTILS_H */