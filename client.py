import zmq
import speech_recognition as sr
import os
from gtts import gTTS
from pydub import AudioSegment
from pydub.playback import play

def speak(string):
    language = 'en-US'
    tts = gTTS(text=string, lang=language)
    tts.save("Sounds/output.mp3")

    sound = AudioSegment.from_mp3("Sounds/output.mp3")
    sound.export("Sounds/output.wav", format="wav")
    os.system("mpg123 Sounds/output.mp3")

def recognizeSpeech(mic, recognizer):
    if not isinstance(recognizer, sr.Recognizer):
        raise TypeError("recognizer must be 'Recognizer' instance")
    if not isinstance(mic, sr.Microphone):
        raise TypeError("microphone must be 'Microphone' instance")

    with mic as source:
        recognizer.adjust_for_ambient_noise(source)
        audio = recognizer.listen(source)

    response = {
        "success": True,
        "error": None,
        "transcription": None
    }

    try:
        response["transcription"] = recognizer.recognize_google(audio)
    except sr.RequestError:
        response["success"] = False
        response["error"] = "API unavailable"
    except sr.UnknownValueError:
        response["error"] = "Unable to recognize speech"
    return response

speak("Hello there. How may I help you.")
os.system("mpg123 Sounds/speak.mp3")

context = zmq.Context()

print("Connecting to VCS Server...")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

r = sr.Recognizer()
m = sr.Microphone()

while(1):
    res = recognizeSpeech(m, r)

    if res["error"]:
        print("Error: {}".format(res["error"]))
        continue;
    
    txt = str(format(res["transcription"])).lower()
    print("You said: " + txt)

    while(1):
        request = 0
        print(f"Sending request {request} ...")
        # req = input("Enter a command: ")
        length = len(res)

        # Send Length of command
        socket.send(str(length).encode('ascii'))

        message = socket.recv()
        print(f"Received reply {request} [ {message} ]")

        # Send the command
        socket.send(txt.encode('ascii'))
        
        message2 = socket.recv()
        print(f"Received reply {request} [ {message2} ]")
        request+=1
        os.system("mpg123 Sounds/executing.mp3")
        break

    if 'exit' in txt:
        speak("Have a nice day")
        speak("Good bye")
        break