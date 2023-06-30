
pam_login:
	gcc -fPIC -c pam_login.c
	ld -x --shared -o pam_login.so pam_login.o
	sudo chown root:root pam_login.so
	sudo cp pam_login.so /lib/aarch64-linux-gnu/security	

pam_app:
	gcc pam_app.c -lpam -lpam_misc -o pam_app.o
