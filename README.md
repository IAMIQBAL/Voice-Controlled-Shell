# Voice Controlled Shell

Voice Controlled Shell is a client-server based program implemented in C and Python, that listens to the user commands and executes them in the linux terminal. VCS uses ZeroMQ in order to carry messages between C and Python programs through TCP using request-reply pattern.

## Dependencies
1. ZeroMQ (ZMQ)
2. gTTS
3. speech_recognition
4. pydub

## Clone
```
git clone https://github.com/iamiqbal/Voice-Controlled-Shell
cd Voice-Controlled-Shell

```

Open two terminals side by side and execute:
#### For C:
```
gcc -o main server.c -lzmq
./main
```
#### For Python
```
python3 client.py
```

## Commands

| Commands | Details | Code |
|----------|---------|------|
| System Summary Information | Show the system load in batch mode of top | Runs the top.sh |
| print data of (file name) | displays the contents of file| `cat (filename)` |
| all running processes | list down all active processes| `ps -e` |
| current processes | list down current processes | `ps` |
| calendar | display the calendar of current month | `cal` |
| quote of the day | fetch and display quote of the day | Quote_of_the_Day.sh |
| gedit | open gedit editor | `gedit` |
| print the date | displays the date | `date +%c` |
| current user | displays the current username | `whoami` |
| users currently logged in | displays the current active users | `who` |
| uptime | shows how long the system has been running | `uptime` |
| get username (username) | shows if the (username) exists on facebook | getuname.sh |
| open firefox | opens a new tab in firefox | `firefox` |
| search (term) | googles the (search term) in firefox | `firefox -new-tab http://www.google.com/search?q=(search term)` |
| go to (site) | opens the site in firefox | `firefox -new-tab (site)` |
| shutdown | power off the machine | `shutdown now` |
| restart | restart the machine | `shutdown -r now` |
| disk usage | shows file system disk space usage | `df -h` |
| network information | shows network information | `ifconfig` |
| make file (file name) | makes a file with (file name) | `touch (file name)` |
| remove file (file name) | remove a file with (file name) | `rm -rf (file name)` |
| make directory (dir name) | makes a directory with (dir name) | `mkdir (dir name)` |
| remove directory (dir name) | remove a directory with (dir name) | `rmdir (dir name)` |
| list files of current directory | list directory contents | `ls .` |
| list hidden files | list files starting with . | `ls -la` |
| list files of root directory | list directory contents of root | `ls /` |
| list files of home directory | list directory contents of home | `ls /home/` |
| change directory | changes directory one level upwards | `cd ../` |