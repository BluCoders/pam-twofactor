# pam-twofactor

Pam module to dynamically use different two factor services based on what the user prefers

## Documentation

Coming soon(tm)

## Setting up PAM

### Test file

in /etc/pam.d/test:
```
auth    required                        pam_unix.so nullok_secure
auth    [success=1 default=ignore]      /path/to/pam_twofactor.so use_first_pass
auth    requisite                       pam_deny.so
auth    required                        pam_permit.so
```

Remove use\_first\_pass to test that the module asks for two factor correctly..
