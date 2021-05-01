import zmq
import speech_recognition as sr

# print("Speak Now")

# r = sr.Recognizer()
# audio = sr.AudioFile('hello.wav')
# with audio as source:
#     audio = r.record(source)

# req = r.recognize_google(audio)
# print(req)

context = zmq.Context()

print("Connecting to VCS Server...")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

while(1):
    request = 0
    print(f"Sending request {request} ...")
    req = input("Enter a command: ")
    length = len(req)

    # Send Length of command
    socket.send(str(length).encode('ascii'))

    message = socket.recv()
    print(f"Received reply {request} [ {message} ]")

    # Send the command
    socket.send(req.encode('ascii'))
    
    message2 = socket.recv()
    print(f"Received reply {request} [ {message2} ]")
    request+=1