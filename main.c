/**********************************************************Library*************************************************************************/

extern int  g_signal;

typedef struct s_mshell
{
    char    *env[];
    int     exit_code;
}   t_mshell;


/**************************************************************Loop Shell*******************************************************************/



/**************************************************************Init Shell*******************************************************************/

static char    **dup_env(char *env[])
{
    char    *new_env[];
    int     i;

    i = 0;
    while (env[i])
        i++;
    new_env = malloc(sizeof(char *) * i + 1);
    if (!new_env)
        return (NULL);
    i = 0;
    while (env[i])
    {
        new_env[i] = ft_strdup(env[i]);
        i++;
    }
    new_env[i] = '\0';
    return (new_env);
}

/*Used to save the enviroment variables (why?, ex: at the case there is and unset of one of those variables, y can still find it's locations (supongo)*/
static int init_shell(t_mshell *shell, char *env[], int argc)
{
    if (argc != 1)
    {
        write(1, "Error: no arguments allowed\n", 28);
        return (1);
    }
    shell->exit_code = 0;
    shell->env = dup_env(env);
    if (!shell->env)
        return (1);
    return (0);
}
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

/*Handles the values for the signals delivereds by the keyboard (EX: SIGINT "signal interruption" = ctr + c), (ex: SIGQUIT "signal quit" = ctr + /)*/
static void steup_signals(void)
{
    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN);
}

int main(int argc, char *argv[], char *env[])
{
    t_mshell shell;

    if (init_shell(argc, env, &shell))
        return(1);
    setup_signals();
    loop_shell

}
