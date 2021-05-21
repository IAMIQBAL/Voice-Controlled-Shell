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
