#include "main.h"


/**
 * cust_fork - Fork a new child process
 *
 * @path: Path to command to execute
 * @args: Arguments for `execve`
 * @envp: Environment variables
 * @status: Status of child process
 *
 * Return: void
 */
int cust_fork(char *path, char *args[], char *envp[])
{
	int exec, status;
	pid_t proc = fork();
	pid_t ppid = getppid();

	if (proc == -1)
	{
		printf("Fork failed!!!\n");
		return (-1);
	}
	else if (proc == 0)
	{
		exec = execve(path, args, envp);
		if (exec == -1)
			return (-1);
	}
	else
		wait(&status);

	return (1);
}
