#include "../../inc/21sh.h"

static t_bincmd    init_bincmd(char *file, char **argv)
{
    t_bincmd bcmd;
    int i;
    char *tmp;

    i = 0;
    if (!file || !argv)
    {
        bcmd.file = NULL;
        bcmd.argv = NULL;
        return (bcmd);
    }
    bcmd.file = ft_strdup(file);
    while (argv[i])
    {
        tmp = argv[i];
        argv[i] = remove_occ(argv[i], '"');
        free(tmp);
        i++;
    }
    bcmd.argv = argv;
    return (bcmd);
}

void        free_bincmd(t_bincmd bcmd)
{
    if (bcmd.file)
        free(bcmd.file);
    if (bcmd.argv)
        ft_free_twodm(bcmd.argv);
}

t_bincmd    solve_bincmd(t_term *te, char *cmd)
{
    t_bincmd    bcmd;
    char		**envpaths;
    char        **qu;
    int         i;

    i = -1;
    bcmd.file = NULL;
    bcmd.argv = NULL;
    qu = ft_strsplit_many(cmd, ARR_WHITE_SPACES);
    if (qu)
    {
        if ((envpaths = get_envpaths(te, qu[0])))
        {
            while (envpaths[++i])
                if (access(envpaths[i], F_OK) == 0)
                {
                    free(qu[0]);
                    qu[0] = ft_strdup(envpaths[i]);
                    bcmd = init_bincmd(envpaths[i], qu);
                    ft_free_twodm(envpaths);
                    return (bcmd);
                }
            ft_free_twodm(envpaths);
        }
        ft_putstr("unkown command\n");
        bcmd.argv = NULL;
        bcmd.file = NULL;
        return (bcmd);
    }
}