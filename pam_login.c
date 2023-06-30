#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

PAM_EXTERN int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
	return PAM_SUCCESS;
}
PAM_EXTERN int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
	char *cPass = NULL;
	int retval;
	const char* pUsername; // имя пользователя
	retval = pam_get_user(pamh, &pUsername, "Username: ");
	printf("Welcome %s\n", pUsername);
	pam_get_authtok(pamh, PAM_AUTHTOK, (const char**)&cPass, NULL);
	if (!strncmp(cPass, "bos_password", 12))
		return PAM_SUCCESS;
	return -1;
}
