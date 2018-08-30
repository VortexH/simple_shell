# A Unix Shell Implementation
As part of the Holberton School curriculum, we were tasked with implementing a shell to cement our understanding of the C language and its deep links with the Unix operating system. Such a project required us to pull knowledge from the fundamentals of the C programming language and the tools that the Linux operating system works with on a daily to implement system functionality.

A great deal was learned during this project, from memory allocation on the heap to the complexity of interactions under the hood of the operating system. Working on a project of this scope and collaborating with a partner were excellent ways to undertand how to approach projects in team and deliver a product at the end.

## Prerequisites
We recommend installing Vagrant on your machine and editing your VagrantFile to boot an ubuntu/trusty64 image. All code was compiled on GCC 4.8.4, so try these settings to ensure one-to-one comparisons with the source code.

## Installation
* Download VirtualBox from this link: https://www.virtualbox.org/wiki/Downloads
* Install VirtualBox (please consult the documentation on proper installation)
* Download Vagrant from this link: https://www.vagrantup.com/downloads.html
* Install Vagrant (check the documentation for more information)
* Open the terminal on OSX (or the command prompt, if you're on Windows)
* Once you're in the terminal and see a terminal prompt (starting with a $ sign), execute these commands
	* "vagrant box add ubuntu/trusty64" (this adds the Ubuntu 14.04 Trusty image to the vagrant box list (without the quotes)
	* "vagrant init ubuntu/trusty64" --generates a VagrantFile with "base" set to "ubuntu/trusty64"
	* "vagrant up" -- starts the virtual machine
	* "vagrant ssh" -- drops you right into the virtual machine

## Getting the source code to your machine
* Assuming that you are new to git, please follow:
	* cd into home directory
	* git clone url\_of\_repository
	* cd into the repository

## Compiling the source code
* Compile with gcc and these flags:
	* -Wall
	* -Wextra
	* -Werror
	* -pedantic
Example: gcc -Wall -Wextra -Werror -pedantic \*.c -o shell

## Running the program
After compiling, you can run the executable by doing ./shell

# Shell functionality
The shell that you are running from this source has a few basic features. You can run any built-in command without specifying the absolute path of the file. For example, `/bin/ls` will execute identically to `ls`. You can specify the absolute path of a command or specify just the name of the executable (as shown above with /bin/ls vs ls). This also goes for the non-interactive mode, or more specifically, the shell called from the command line. For instance, running the command this way, `echo "ls" | ./shell` will generate the same output as running `ls` within the executing shell. By default, the shell will print $ as the default prompt and waits for input from the user. From there, any executable command that can be found within the environment path will be executed as it normally would from the command line. This includes any options added to commands, such as `ls -la`. If a command is found and cannot be executed due to lack of permissions or cannot be found at all, the appropriate error message will print and a new prompt will be aded. This same process will apply to any other possible errors to command execution. The shell function will continue to run until an exit call is made. This can be done either through the explicit typing of `exit` or through the command `CTRL + D`. Both will exit to a newline, no errors will be printed, and a standard error value will be set. Currently the error values will simply be 1 or 0, but will be updated in the future.

##Bugs
Through the process of this project we have ironed out a large portion of the bugs that we faced, but 3 specific ones still remain that directly affect the functionality that we have worked through thus far. Those specifically are the interaction with the arrow keys, `CTRL + C`, and the error output on exit calls/. The first is an issue as the output is very unusual and interferes with normal error printing. The second error prints out ^C and exits while it should print the ^C and then produce a new prompt and wait for input. The final one will only return an exit value of 0 or 1, success or failure. A more detailed error value should be printed to give the user a distinct understanding of the last error that occurred. All three are bugs we are confident can be fixed given time and may be updated in the near future.