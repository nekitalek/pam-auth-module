# pam-auth-module
PAM module for Linux authentication
Implemented its own authentication module, adding user authentication using the module to its own application using PAM. For convenience, a makefile has been created that compiles both the module and the program. The commands included in the makefile. 

To install all the components, it was necessary to execute the command: ```sudo apt-get install build-essential libpam0g-dev libcurl4-openssl-dev```. After the assembly, the ```.o``` and ```.so``` object files are obtained, and then they need to be linked, ```.so``` file with PAM, placing the created module in the directory to other modules
