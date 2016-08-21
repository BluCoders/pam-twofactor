#define PAM_SM_AUTH

#include <security/pam_modules.h>

// How to complain: use pam_syslog(..)

// use_first_pass - The module should not prompt the user for a password. Instead, it should
//                  obtain the previously typed password (by a call to pam_get_item() for the
//                  PAM_AUTHTOK item), and use that. If that doesn't work, then the user will
//                  not be authenticated. (This option is intended for auth and passwd modules
//                  only).
//                  In other words:
//                  * If it's unset, we can ask separately for the one time code (+ empty to get push auth)
//                  * If it's set, we can extract it from password
//                      * ,pin - the password contains
//                      * no match - we have to push auth
//                  PS: always use use_first_pass with dovecot etc.

// Next question: Where are our API keys?!?!?!?!
//    - we'll see. Possibly require a config file with argc,argv

// Next question: How do we know who goes where?!?!
//    - /etc/aliases style database kthx
//    - /etc/twofactor
//    Considerations:
//       Pam modules seem to favor human readable names rather than self-based naming
//       But we can change the module name to pam_twofactor!
//       why no acronyms: Short enough name that we can avoid the vagueness of acronyms

// Valid flags (any combination): PAM_SILENT                - Do not emit any messages.
//  				  PAM_DISALLOW_NULL_AUTHTOK - Return PAM_AUTH_ERR if the database has NULL for this user. Without this flag, NULL will lead to a success.
PAM_EXTERN int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {

	/* return values:
	 * PAM_AUTH_ERR          - Authentication failure.
	 * PAM_CRED_INSUFFICIENT - For some reason the application does not have sufficient credentials to authenticate the user.
	 * PAM_AUTHINFO_UNAVAIL  - The modules were not able to access the authentication information. This might be due to a network or hardware failure etc.
	 * PAM_SUCCESS           - The authentication token was successfully updated.
	 * PAM_USER_UNKNOWN      - The supplied username is not known to the authentication service.
	 * PAM_MAXTRIES          - One or more of the authentication modules has reached its limit of tries authenticating the user. Do not try again.
	 * */
	return PAM_AUTH_ERR;
}

PAM_EXTERN int pam_sm_setcred(pam_handle_t *pamh __attribute__((unused)),
		              int flags __attribute__((unused)),
		              int argc __attribute__((unused)),
		              const char *argv[] __attribute__((unused))) {
	  return PAM_SUCCESS;
}

