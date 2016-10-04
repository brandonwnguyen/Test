// Brandon Nguyen
// Homework 2
// Professor Gomez
// September 22 2016

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
	int child_pid;
	child_pid = getpid();
	int x = 0;

	printf("Enter how many zombies to be created. \n");
	scanf("%d", &x);
	for (int i = 0; i < x; i++)
	{
		child_pid = fork();	// Creates processes

		if(child_pid > 0)
		{
			printf("Zombie Count: %d \n", i + 1);
			printf("Creating Zombie Child Process... \n");
			printf("Process ID: %d \n", child_pid);
			sleep(2); // 2 second delay per process. If 0, it will look weird
			kill -SIGSTOP; // Pauses
		}

		else if (child_pid == 0)
		{
			kill -SIGCONT; // Sends signal to continue from where SIGSTOP paused.
			printf("\n");
			exit(0);
		}

		else
		{
			kill -SIGCONT; // Sends signal to continue
			exit(0);
		}
	}
	printf("End Program \n");
	return 0;
}
