#include "general.h"
#include "main.h"
#include "inputprompt.h"

/**
 * start - fuction responsible for
 * handling the mode
 * Description: Mode can be INTERACTIVE or NON_INTERACTIVE
 *
 * @info: Struct information of the shell
 **/
void start(general_t *info) { start_prompt(info); }