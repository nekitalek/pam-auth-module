#include <stdio.h>
#include <security/pam_appl.h>
#include <security/pam_misc.h>

static struct pam_conv conv = { misc_conv, NULL };

void goodfunc()
{
	printf("░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░\n");
	printf("░░░░░░░░░░░░░░░░░▄████▄░░░░░░░░░░░░░░░░░\n");
	printf("░░░░░░░░░░░░░░░░▄██████▄░░░░░░░░░░░░░░░░\n");
	printf("░░░░░░████▄▄▄▄▄▄████████▄▄▄▄▄▄████░░░░░░\n");
	printf("░░░░░░████████████████████████████░░░░░░\n");
	printf("░░░░░░████████████████████████████░░░░░░\n");
	printf("░░░░░░██████▀▀░░▄▄▀▀▀▀▄▄░▀▀███████░░░░░░\n");
	printf("░░░▄▄██████░░░░▀▀░░░░░░▀▀░░░░██████▄▄░░░\n");
	printf("▄▄█████▀████▄█████▄░░▄█████▄████▀█████▄▄\n");
	printf("▀██████▄░░██▀░░░░░▀██▀░░░░░▀█▀░░▄██████▀\n");
	printf("░░▀█████░░██░░░░░██████░░░░░██░░▀████▀░░\n");
	printf("░░░░▀███░░▀█▄░░░░▀████▀░░░░▄█▀░░░██▀░░░░\n");
	printf("░░░░░░▀█░░░▀██▄▄▄██████▄▄▄██▀░░░▄▀░░░░░░\n");
	printf("░░░░░░░██░░░░░▀▀▀░░██░░▀▀▀░░░░░░█░░░░░░░\n");
	printf("░░░░░░░███▄░░░░░░░▀██▀░░░░░░░░░▄█░░░░░░░\n");
	printf("░░░░░▄▀░███▄░░░░░░░░░░░░░░░░░░▄█░▀▄░░░░░\n");
	printf("░░░░░█░░█░▀███▄▄░░░░░░░░░░░░▄▀░█░░█░░░░░\n");
	printf("░░░░░█░░▀▄░░▀██████▄▄▄▄▄▄██▀░░▄▀░░█░░░░░\n");
	printf("░░░░░░▀▄▄▀░░░░░▀███▀▀███▀░░░░░▀▄▄▀░░░░░░\n");
	printf("░░░░░░░░░░░░░░▄▀░░█░░█░░▀▄░░░░░░░░░░░░░░\n");
	printf("░░░░░░░░░░░░░░▀▀▀▀▀░░▀▀▀▀▀░░░░░░░░░░░░░░\n");

}

int main()
{

	pam_handle_t *pamh=NULL;
	int retval;
	char user[32];
	printf("Enter username: ");
	scanf("%s", user);
	printf("\n");

	retval = pam_start("Lab6", user, &conv, &pamh);
	if (retval == PAM_SUCCESS) 
	{
		retval = pam_authenticate(pamh, 0);
	}
	if (retval == PAM_SUCCESS) 
	{
		retval = pam_acct_mgmt(pamh, 0); 
	}
	if (retval == PAM_SUCCESS) 
	{
		goodfunc();
	}	
	else
	{
		printf("⠰⡿⠿⠛⠛⠻⠿⣷\n");
	printf("⠀⠀⠀⠀⠀⠀⣀⣄⡀⠀⠀⠀⠀⢀⣀⣀⣤⣄⣀⡀\n");
	printf("⠀⠀⠀⠀⠀⢸⣿⣿⣷⠀⠀⠀⠀⠛⠛⣿⣿⣿⡛⠿⠷\n");
	printf("⠀⠀⠀⠀⠀⠘⠿⠿⠋⠀⠀⠀⠀⠀⠀⣿⣿⣿⠇\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁\n");
	printf("\n");
	printf("⠀⠀⠀⠀⣿⣷⣄⠀⢶⣶⣷⣶⣶⣤⣀\n");
	printf("⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠈⠙⠻⠗\n");
	printf("⠀⠀⠀⣰⣿⣿⣿⠀⠀⠀⠀⢀⣀⣠⣤⣴⣶⡄\n");
	printf("⠀⣠⣾⣿⣿⣿⣥⣶⣶⣿⣿⣿⣿⣿⠿⠿⠛⠃\n");
	printf("⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄\n");
	printf("⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁\n");
	printf("⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁\n");
	printf("⠀⠀⠛⢿⣿⣿⣿⣿⣿⣿⡿⠟\n");
	printf("⠀⠀⠀⠀⠀⠉⠉⠉ \n");
		printf("password is not correct\n");
	}
	if (pam_end(pamh,retval) != PAM_SUCCESS)
	{
		pamh = NULL;
		printf("Failed.\n");
		exit(1);
	}

	return ( retval == PAM_SUCCESS ? 0:1 );

}
