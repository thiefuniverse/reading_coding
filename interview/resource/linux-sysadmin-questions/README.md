Linux System Administrator/DevOps Interview Questions
====================================================

A collection of linux sysadmin/devops interview questions. Feel free to contribute via pull requests, issues or email messages.


## <a name='toc'>Table of Contents</a>

  1. [Contributors](#contributors)
  1. [General Questions](#general)
  1. [Simple Linux Questions](#simple)
  1. [Medium Linux Questions](#medium)
  1. [Hard Linux Questions](#hard)
  1. [Expert Linux Questions](#expert)
  1. [Networking Questions](#network)
  1. [MySQL Questions](#mysql)
  1. [DevOps Questions](#devop)
  1. [Fun Questions](#fun)
  1. [Demo Time](#demo)
  1. [Other Great References](#references)


####[[⬆]](#toc) <a name='contributors'>Contributors:</a>

* [moregeek](https://github.com/moregeek)
* [typhonius](https://github.com/typhonius)
* [schumar](https://github.com/schumar)
* [negesti](https://github.com/negesti)
* peter
* [andreashappe](https://github.com/andreashappe)
* [quatrix](https://github.com/quatrix)
* [biyanisuraj](https://github.com/biyanisuraj)
* [pedroguima](https://github.com/pedroguima)
* Ben
* [bharatnc](https://github.com/bharatnc)


####[[⬆]](#toc) <a name='general'>General Questions:</a>

* What did you learn yesterday/this week?

> Fix this readme.
	
* Talk about your preferred development/administration environment. (OS, Editor, Browsers, Tools etc.)
> Emacs, Arch Linux.
	
* Tell me about the last major Linux project you finished.
> Blog-minimal -- A static blog generator based on org mode in emacs. [https://github.com/thiefuniverse/blog-minimal]
	
* Tell me about the biggest mistake you've made in [some recent time period] and how you would do it differently today. What did you learn from this experience?
> Humm.... Let me think it over .... 	
	
* Why we must choose you?
> Energetic, humorous, like programming, learn quickly.
  
* What function does DNS play on a network?
> DNS is like a phone book for the Internet. If you know a person's name and don't know their telephone number, you can simply look it up in a phone book. DNS provides this same service to the Internet. When we visit website like microsoft.com, our computers use DNS to retrieve it's IP address and then send requests to this IP.
  
* What is HTTP?
> HTTP is short for HyperText Transfer Protocol. HTTP is the underlying protocol usesd by the World Wide Web and this protocol defines how messages are formatted and transmitted, and what actioins Web servers and browsers should take in response to various commands.
> When you enter a URL in your browser, this actually sends a HTTP command to the Web server directing it to fetch and transmit the requested Web page. (The other main standard that controls how the World Wide Web works is HTML, which covers how Web pages are formatted and dislpayed)
	
* What is an HTTP proxy and how does it work?
> A HTTP proxy speaks HTTP protocol. The browser sends a request to the *proxy server* and the *proxy server* will then forward the request to the *Real server*. The *Real server* will only see the proxy as connection and answer to the proxy just like a client. 
> Proxy server* receives the response and forwards it back to the client.
  
* Describe briefly how HTTPS works.
> Servers and clients will communicate with others over a secure SSL connection that encrypts and decrypts their requests and responses. (The SSL layer can verify that you are talking directly to the server that you think you are talking to and ensure that only the server can read read what you send it and only you can read what it sends back.
> SSL Connection Eastablished( 1. Hello 2. Certificate Exchange 3. KeyExchange)

* What is SMTP? Give the basic scenario of how a mail message is delivered via SMTP.
> 1. Eastablish TCP connection:
> 2. Send mail message:
> + Client sends a HELO command which identifies sender and then server responds a 250 Requested mail action okay message.
> + Client sends a MAIL command and server responses ok which means to ready to receive messages.
> + Client sends RCPT commands which identify receiver and server responses whether server receives this email or not.
> + Client sends data with DATA command and QUTI to quit.

* What is RAID? What is RAID0, RAID1, RAID5, RAID10?
> RAID: stands for Redundant Array of Independent Disks. By placing data on multiple disk, I/O operations can overlap in a balanced way, improving performance and increase fault tolerance.
> RAID0: Good speed. Bad redundant.
![raid0 ](raid0.png)

> RAID1: Get some redundancy with limited number of disks but consume a lot of storage space 
> <br>
![raid1 ](raid1.png)

> RAID5: Get a balance of redundancy and disk space, use XOR to resume data.
> <br>
![raid5 ](raid5.png)

> RAID10: Good speed and redundancy but need half of disk space
> <br>
![raid10 ](raid10.png)

* What is a level 0 backup? What is an incremental backup?
> Level 0 means full backup. Incremental backup captures oly the changes made since the last incremental backup. Saves both time and storage space and ensures that your backup is up to date. (Fast backups, low storage space but slower recovery and risk of data loss)

* Describe the general file system hierarchy of a Linux system.
>       /bin       Essential command binaries
>       /boot      Static files of the boot loader
>       /dev       Device files
>       /etc       Host-specific system configuration
>       /lib       Essential shared libraries and kernel modules
>       /media     Mount point for removeable media
>       /mnt       Mount point for mounting a filesystem temporarily
>       /opt       Add-on application software packages
>       /sbin      Essential system binaries
>       /srv       Data for services provided by this system
>       /tmp       Temporary files
>       /usr       Secondary hierarchy
>       /var       Variable data
>       /proc      Virtual filesystem (contains runtime system infomation).

####[[⬆]](#toc) <a name='simple'>Simple Linux Questions:</a>

* What is the name and the UID of the administrator user?
> root,  0
* How to list all files, including hidden ones, in a directory?
> ls -a 
* Which command will show you free/used memory? Does free memory exist on Linux?
> free
> <br>
> (total = used + free + cached/buffer)
> <br>
> Memory that is free is actually harder to use because it has to be transitioned from free to in use. Memory that is already in use is available but not free amd can easily be switched to another use.

* How to search for the string "my konfi is the best" in files of a directory recursively?
> grep -ri string directory/

* How to connect to a remote server or what is SSH?
> SSH (Secure Socket Shell) is a network protocol that provides administrators with a secure way to access a remote computer. SSH provides strong authentication and secure encrypted data communications between two computers connecting over an insecure network.
> <br>
> ssh loginName@serverIP    (login command)

* How to get all environment variables and how can you use them?
> env, printenv, set 
> <br>
> myName="thiefunvierse"; export myName
> <br>
> Then we can use *echo $myName* to show "thiefunvierse".

* I get "command not found" when I run ```ifconfig -a```. What can be wrong?
> Maybe its default path is wrong. Try to run *locate ifconfig* and find complete path for ifconfig command.
> <br>
> Or install net-tools.

* What happens if I type TAB-TAB?
> Get command completion based on curent input.

* What command will show the available disk space on the Unix/Linux system?
> df -h    # for human

* What commands do you know that can be used to check DNS records?
> nslookup domainName     (nslookup thiefuniverse.github.io)
> <br>
> dig @DNS_SERVER domainName QUERY_TYPE   ( dig @8.8.8.8 thiefuniverse.github.io A)

* What Unix/Linux commands will alter a files ownership, files permissions?
> chown newOwner fileName
> <br>
> chown newOwner:newGroup fileName
> <br>
> chgrp newGroup fileName
> <br>
> chmod +x fileName
> <br>
> chmod u+x,g=rx,o=wrx fileName
> <br>
> chmod 570 fileName

* What does ```chmod +x FILENAME```do?
> Add executable permission to file.

* What does the permission 0750 on a file mean?
> 0750 = User:rwx Group:r-x World:--- 
> <br>
> r = read
> <br>
> w = write
> <br>
> x = execute (traverse for directories)

* What does the permission 0750 on a directory mean?
> 0750 = User:rwx Group:r-x World:--- 
> <br>
> r = print a listing of all directory entries (like ls)
> <br>
> w = create new directory entries
> <br>
> x = traverse for directories, obtain the inode of directory entries


* How to add a new system user without login permissions?
> useradd -M newUser  (create a user without home)
> <br>
> usermod -L newUser  (lock this user)

* How to add/remove a group from a user?
> sudo groupadd newGroup
> <br>
> sudo groupdel newGroup

* What is a bash alias?
> A alias for linux shell command.
> <br>
> For example, I use alias *lm = "ls -l | more"*, then we can just type lm like I type "ls -l | more".

* How do you set the mail address of the root/a user?
> set mail address in ~/.forward

* What does CTRL-c do?What can be wrong
> Terminate current process.

* What is in /etc/services?
> The /etc/services file contains information regarding the known services available in the DARPA Internet. For each service, a single line should be present with the following information:
> <br>
> official_service_name  port_number/protocol_name  aliases

* How to redirect STDOUT and STDERR in bash? (> /dev/null 2>&1)
> file descriptor 1 : standard out
> <br>
> file descriptor 2 : standard error
> <br>
> 1>&-   : close 1 (close standard out)
> <br>

> 2>&1   : combine the output of 2 and 1
> <br>
> /dev/null   : prevent from showing on console

* What is the difference between UNIX and Linux.
> Unix: old, mainframes and high end computers, proprietary
> <br>
> Linux: based on Unix (new), from mainframes to low end PC, GNU license

* What is the difference between Telnet and SSH?
> ssh is a secured shell, where telnet is not a secured one.when you ssh to trasnfer data between a system, the data will be send in the encrypted form, where the hacker cannot encode or decode it. While you telnet,the data send between the system is alphabetical format(ASCII), where every one can understand. More over as per network security, telnet and ftp are prohibited. Always, trust SSL based data transfer.

* Explain the three load averages and what do they indicate. What command can be used to view the load averages?
> The averages are taken over the three time intervals ( one minute, three minutes, fifteen minutes).
> <br>
> uptime

* Can you name a lower-case letter that is not a valid option for GNU ```ls```?
> ls -j -y -z


####[[⬆]](#toc) <a name='medium'>Medium Linux Questions:</a>

* What do the following commands do and how would you use them?
 * ```tee```
> read a standard input and write to a standard output and file.
 * ```awk```
> pattern matching and processing language
 * ```tr```
> translate or delete characters 
 * ```cut```
> remove sections from each line of lines
 
 * ```tac```
> show file from last line to first line.
 * ```curl```
> transfer data from or to a server.
 * ```wget```
> network downloader
 * ```watch```
> execute a program periodically.
 * ```head```
> output the first part of files
 * ```tail```
> output the last part of files

* What does an ```&``` after a command do?
> run this command in the background.

* What does ```& disown``` after a command do?
> - &:   puts the job in the background, that is, makes it block on attempting to read input, and makes the shell not wait for its completion.
> <br>
> - disown:  removes the process from the shell's job control, but it still leaves it connected to the terminal. One of the results is that the shell won't send it a SIGHUP. Obviously, it can only be applied to background jobs, because you cannot enter it when a foreground job is running.
> <br>
> - nohup:  disconnects the process from the terminal, redirects its output to nohup.out and shields it from SIGHUP. One of the effects (the naming one) is that the process won't receive any sent NOHUP. It is completely independent from job control and could in principle be used also for foreground jobs (although that's not very useful).

* What is a packet filter and how does it work?
> 
* What is Virtual Memory?
> Virtual memory is a memory management capability of an OS that uses hardware and software to allow a computer to compensate for physical memory shortages by temppraily transferring data from random access memory to disk storage. Virtual address space is increased using active memory in RAM and inactive memory in hard disk drives to from contiguous addresses that hold both the application and its data.

* What is swap and what is it used for?
> Swap space in Linux is used when the amount of physical memory is full. If the system needs more memory resources and the RAM is full, inactive pages in memory are moved to the swap space. While swap space can help machines with a small amount of RAM, it should not be considered a replacement for more RAM. Swap space is located on hard drives, which have a slower access time than physical memory.

* What is an A record, an NS record, a PTR record, a CNAME record, an MX record?
> [wiki for DNS record](https://en.wikipedia.org/wiki/List_of_DNS_record_types)
> <br>
> A: Address record (Return a 32-bit IPv4 address, most commonly used to map hostnames to an IP address of the host) <br>
> NS: Name server record (Delegates a DNS zone to use the given authoritative name servers) <br>
> PTR: Pointer record (Pointer to a canonical name. Unlike a CNAME, DNS processing stops and just the name is returned. The most common use is for implementing reverse DNS lookups, but other uses include such things as DNS-SD). <br>
> CNAME: Canonical name record (Alias of one name to another: the DNS lookup will continue by retrying the lookup with the new name) <br>
> MX: Mail exchange record (Maps a domain name to a list of message transfer agents for that domain) <br>

* Are there any other RRs and what are they used for?
> A: Address record (Return a 128-bit IPv6 address, most commonly used to map hostnames to an IP address of the host) <br>
> TSIG: Transaction Signature, URI: Uniform Resource Identifier.

* What is a Split-Horizon DNS?
* What is the sticky bit?
* What does the immutable bit do to a file?
* What is the difference between hardlinks and symlinks? What happens when you remove the source to a symlink/hardlink?
> ![hard-soft-link](hard-soft-link.jpg)
> <br>
> Underneath the file system files are represented by inodes.
> A file in the file system is basically a link to an inode.
> A hard link then just creates another file with a link to the same underlying inode.
> 
> When you delete a file it removes one link to the underlying inode. The inode is only deleted (or deletable/over-writable) when all links to the inode have been deleted.
> 
> A symbolic link is a link to another name in the file system.
> 
> Once a hard link has been made the link is to the inode. deleting renaming or moving the original file will not affect the hard link as it links to the underlying inode. Any changes to the data on the inode is reflected in all files that refer to that inode.

* What is an inode and what fields are stored in an inode?
* How to force/trigger a file system check on next reboot?
* What is SNMP and what is it used for?
* What is a runlevel and how to get the current runlevel?
> Each runlevel designates a different system configuration and allows access to a different combination of processes.
> <br>
> + 0 - System halt; no activity, the system can be safely powered down. 
> + 1 - Single user; rarely used. 
> + 2 - Multiple users, no NFS (network filesystem); also used rarely. 
> + 3 - Multiple users, command line (i.e., all-text mode) interface; the standard runlevel for most Linux-based server hardware. 
> + 4 - User-definable 
> + 5 - Multiple users, GUI (graphical user interface); the standard runlevel for most Linux-based desktop systems. 
> + 6 - Reboot; used when restarting the system.

* What is SSH port forwarding?
> 22


* What is the difference between local and remote port forwarding?
> - Local port forwarding creates an outgoing tunnel which can be used to bring a public internet computer to local machine. 
> - Remote port forwarding creates an incoming tunnel which can be used to bring a local computer into the public internet. 

* What are the steps to add a user to a system without using useradd/adduser?
* What is MAJOR and MINOR numbers of special files?
* Describe the mknod command and when you'd use it.
* Describe a scenario when you get a "filesystem is full" error, but 'df' shows there is free space.
* Describe a scenario when deleting a file, but 'df' not showing the space being freed.
* Describe how 'ps' works.
* What happens to a child process that dies and has no parent process to wait for it and what’s bad about this?
* Explain briefly each one of the process states.
* How to know which process listens on a specific port?
* What is a zombie process and what could be the cause of it?
* You run a bash script and you want to see its output on your terminal and save it to a file at the same time. How could you do it?
* Explain what echo "1" > /proc/sys/net/ipv4/ip_forward does.
* Describe briefly the steps you need to take in order to create and install a valid certificate for the site https://foo.example.com.
* Can you have several HTTPS virtual hosts sharing the same IP?
* What is a wildcard certificate?
* Which Linux file types do you know?
* What is the difference between a process and a thread? And parent and child processes after a fork system call?
* What is the difference between exec and fork?
* What is "nohup" used for?
* What is the difference between these two commands?
 * ```myvar=hello```
 * ```export myvar=hello```
* How many NTP servers would you configure in your local ntp.conf?
* What does the column 'reach' mean in ```ntpq -p``` output?
* You need to upgrade kernel at 100-1000 servers, how you would do this?
* How can you get Host, Channel, ID, LUN of SCSI disk?
* How can you limit process memory usage?
* What is bash quick substitution/caret replace(^x^y)?
* Do you know of any alternative shells? If so, have you used any?
* What is a tarpipe (or, how would you go about copying everything, including hardlinks and special files, from one server to another)?
* How can you tell if the httpd package was already installed?
* How can you list the contents of a package?
* How can you determine which package is better: openssh-server-5.3p1-118.1.el6_8.x86_64 or openssh-server-6.6p1-1.el6.x86_64 ?

####[[⬆]](#toc) <a name='hard'>Hard Linux Questions:</a>

* What is a tunnel and how you can bypass a http proxy?
* What is the difference between IDS and IPS?
* What shortcuts do you use on a regular basis?
* What is the Linux Standard Base?
* What is an atomic operation?
* Your freshly configured http server is not running after a restart, what can you do?
* What kind of keys are in ~/.ssh/authorized_keys and what it is this file used for?
* I've added my public ssh key into authorized_keys but I'm still getting a password prompt, what can be wrong?
* Did you ever create RPM's, DEB's or solaris pkg's?
* What does ```:(){ :|:& };:``` do on your system?
* How do you catch a Linux signal on a script?
* Can you catch a SIGKILL?
* What's happening when the Linux kernel is starting the OOM killer and how does it choose which process to kill first?
* Describe the linux boot process with as much detail as possible, starting from when the system is powered on and ending when you get a prompt.
* What's a chroot jail?
* When trying to umount a directory it says it's busy, how to find out which PID holds the directory?
* What's LD_PRELOAD and when it's used?
* You ran a binary and nothing happened. How would you debug this?
* What are cgroups? Can you specify a scenario where you could use them?
* How can you remove/delete a file with file-name consisting of only non-printable/non-type-able characters?
* How can you increase or decrease the priority of a process in Linux?
* What are run-levels in Linux?


####[[⬆]](#toc) <a name='expert'>Expert Linux Questions:</a>

* A running process gets ```EAGAIN: Resource temporarily unavailable``` on reading a socket. How can you close this bad socket/file descriptor without killing the process?


####[[⬆]](#toc) <a name='network'>Networking Questions:</a>

* What is localhost and why would ```ping localhost``` fail?
* What is the similarity between "ping" & "traceroute" ? How is traceroute able to find the hops.
* What is the command used to show all open ports and/or socket connections on a machine?
* Is 300.168.0.123 a valid IPv4 address?
* Which IP ranges/subnets are "private" or "non-routable" (RFC 1918)?
* What is a VLAN?
* What is ARP and what is it used for?
* What is the difference between TCP and UDP?
* What is the purpose of a default gateway?
* What is command used to show the routing table on a Linux box?
* A TCP connection on a network can be uniquely defined by 4 things. What are those things?
* When a client running a web browser connects to a web server, what is the source port and what is the destination port of the connection?
* How do you add an IPv6 address to a specific interface?
* You have added an IPv4 and IPv6 address to interface eth0. A ping to the v4 address is working but a ping to the v6 address gives yout the response ```sendmsg: operation not permitted```. What could be wrong?
* What is SNAT and when should it be used?
* Explain how could you ssh login into a Linux system that DROPs all new incoming packets using a SSH tunnel.
* How do you stop a DDoS attack?
* How can you see content of an ip packet?
* What is IPoAC (RFC 1149)?



####[[⬆]](#toc) <a name='mysql'>MySQL questions:</a>

* How do you create a user?
* How do you provide privileges to a user?
* What is the difference between a "left" and a "right" join?
* Explain briefly the differences between InnoDB and MyISAM.
* Describe briefly the steps you need to follow in order to create a simple master/slave cluster.
* Why should you run "mysql_secure_installation" after installing MySQL?
* How do you check which jobs are running?


####[[⬆]](#toc) <a name='devop'>DevOps Questions:</a>

* Can you describe your workflow when you create a script?
* What is GIT?
* What is a dynamically/statically linked file?
* What does "./configure && make && make install" do?
* What is puppet/chef/ansible used for?
* What is Nagios/Zenoss/NewRelic used for?
* What is Jenkins/TeamCity/GoCI used for?
* What is the difference between Containers and VMs?
* How do you create a new postgres user?
* What is a virtual IP address? What is a cluster?
* How do you print all strings of printable characters present in a file?
* How do you find shared library dependencies?
* What is Automake and Autoconf?
* ./configure shows an error that libfoobar is missing on your system, how could you fix this, what could be wrong?
* What are the advantages/disadvantages of script vs compiled program?
* What's the relationship between continuous delivery and DevOps?
* What are the important aspects of a system of continuous integration and deployment?

####[[⬆]](#toc) <a name='fun'>Fun Questions:</a>

* A careless sysadmin executes the following command: ```chmod 444 /bin/chmod ``` - what do you do to fix this?
* I've lost my root password, what can I do?
* I've rebooted a remote server but after 10 minutes I'm still not able to ssh into it, what can be wrong?
* If you were stuck on a desert island with only 5 command-line utilities, which would you choose?
* You come across a random computer and it appears to be a command console for the universe. What is the first thing you type?
* Tell me about a creative way that you've used SSH?
* You have deleted by error a running script, what could you do to restore it?
* What will happen on 19 January 2038?
* How to reboot server when reboot command is not responding?


####[[⬆]](#toc) <a name='demo'>Demo Time:</a>

* Unpack test.tar.gz without man pages or google.
* Remove all "*.pyc" files from testdir recursively?
* Search for "my konfu is the best" in all *.py files.
* Replace the occurrence of "my konfu is the best" with "I'm a linux jedi master" in all *.txt files.
* Test if port 443 on a machine with IP address X.X.X.X is reachable.
* Get http://myinternal.webserver.local/test.html via telnet.
* How to send an email without a mail client, just on the command line?
* Write a ```get_prim``` method in python/perl/bash/pseudo.
* Find all files which have been accessed within the last 30 days.
* Explain the following command ```(date ; ps -ef | awk '{print $1}' | sort | uniq | wc -l ) >> Activity.log```
* Write a script to list all the differences between two directories.
* In a log file with contents as ```<TIME> : [MESSAGE] : [ERROR_NO] - Human readable text``` display summary/count of specific error numbers that occurred every hour or a specific hour.


####[[⬆]](#toc) <a name='references'>Other Great References:</a>

Some questions are 'borrowed' from other great references like:

* https://github.com/darcyclarke/Front-end-Developer-Interview-Questions
* https://github.com/kylejohnson/linux-sysadmin-interview-questions/blob/master/test.md
* http://slideshare.net/kavyasri790693/linux-admin-interview-questions
