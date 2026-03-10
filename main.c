/**********************************************************Library*************************************************************************/

extern int  g_signal;

/**********************************************************Commands*******************************************************************/
typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
}	t_redir_type;

typedef struct s_redir
{
	t_redir_type	type;
	char			*file;
	struct s_redir	*next;
}	t_redir;

typedef struct s_command
{
    char    **args;
    t_redir *redirs;
    struct s_command    *next;
}   t_command;

/**************************************************************Enviroment*******************************************************/
typedef struct s_mshell
{
    char    *env[];
    int     exit_code;
}   t_mshell;

/**************************************************************END OF LIBRARY***************************************************/


/**************************************************************Loop Shell*******************************************************************/
static char *parse_input(line, shell)
{

}

static void process_line(char *line, t_minishell *shell)
{
    t_command   *cmds;

    if (*line)
    {
        add_history(line);
        cmds = parse_input(line, shell);
        if (cmds)
        {
            execute_command(shell, cmds);
            free_commands(cmds);
        }
    }
    free(line);
}

void loop_shell(t_mshell *shell)
{
    char    *line;

    while(1)
    {
        line = readline("\001\033[1;35m\002minishell"
				"\001\033[1;36m\002$ \001\033[0m\002");
        if (!line)
        {
            printf("exit\n");
            break ;
        }
        process_line(line, shell);
        if (g_signal != 0)
        {
            shell->exit_code = g_signal;
            g_signal = 0;
        }
    }
}

/**************************************************************Init Shell*******************************************************************/

static char    **dup_env(char *env[])
{
    char    **new_env;
    int     i;

    i = 0;
    while (env[i])
        i++;
    new_env = malloc(sizeof(char *) * (i + 1));
    if (!new_env)
        return (NULL);
    i = 0;
    while (env[i])
    {
        new_env[i] = ft_strdup(env[i]);
        i++;
    }
    new_env[i] = NULL;
    return (new_env);
}

/*Used to save the enviroment variables (why?, ex: at the case there is and unset of one of those variables, y can still find it's locations (supongo)*/
/*We want to be able to manipulate a list of the variables inside the program, as well as not affect the actual environment variables of the machine*/
/*This function copies all contents of the env list and passes this as a list the program can then manipulate freely*/
static int init_shell(t_mshell *shell, char *env[], int argc)
{
    if (argc != 1)
    {
        printf("Error: no arguments allowed\n");
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