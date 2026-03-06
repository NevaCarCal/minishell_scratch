/**********************************************************Library*************************************************************************/

extern int  g_signal;

typedef struct s_mshell
{
    char    *env[];
    int     exit_code;
}   t_mshell;

/**************************************************************Init Shell*******************************************************************/


/**************************************************************Main*************************************************************************/

int g_signal = 0;

/*Handles sigint as specified in subject*/
static void handle_sigint(int sig)
{
    g_signal = 128 + sig;
    write(1,"\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

/*Handles the values for the signals delivereds by the keyboard (EX: SIGINT "signal interruption" = ctr + d), (ex: SIGQUIT "signal quit" = ctr + /)*/
static void steup_signals(void)
{
    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN);
}

int main(int argc, char *argv[], char *env[])
{
    t_mshell mshell;

    if (init_shell(argc, env, &mshell))
        return(1);
    setup_signals();
    loop_shell
}