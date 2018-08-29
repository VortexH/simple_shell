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

## Compiling source code
* Compile with gcc and these flags:
	* -Wall
	* -Wextra
	* -Werror
	* -pedantic
Example: gcc -Wall -Wextra -Werror -pedantic \*.c -o shell

## Running the program
After compiling, you can run the executable by doing ./shell


