#include "main.h"

int cust_fork(char *path, char *args[], char *envp[], int *child);


/**
 * main - Wait, Fork and Execute
 *
 * Return: 0
 */
int main(void)
{
	int child = 1;
	char *cmd_path = "/bin/ls";
	char *args[] = {cmd_path, "-l", NULL};
	char *envp[] = {NULL};
	char *dir = "/tmp";
	pid_t pid;

	if (chdir(dir) == -1)
	{
		printf("Directory could not be changed!\n");
		return (-1);
	}

	pid = getpid();
	printf("Process ID before fork is: %u\n", pid);
	pid = getppid();
	printf("Parent Process ID before fork is: %u\n", pid);

	cust_fork(cmd_path, args, envp, &child);
	cust_fork(cmd_path, args, envp, &child);
	cust_fork(cmd_path, args, envp, &child);
	cust_fork(cmd_path, args, envp, &child);
	cust_fork(cmd_path, args, envp, &child);

	return (0);
}


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
int cust_fork(char *path, char *args[], char *envp[], int *child)
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
		printf("\nChild Proccess %d\n\n", *child);
		exec = execve(path, args, envp);
		if (exec == -1)
			return (-1);
	}
	else
	{
		wait(&status);
		printf("\n");
		printf("Process ID of child is: %u\n", proc);
		printf("Process ID of parent is: %u\n", ppid);
		printf("\nExecution Completed!!!\n");
	}

	*child += 1;
	return (1);
}
