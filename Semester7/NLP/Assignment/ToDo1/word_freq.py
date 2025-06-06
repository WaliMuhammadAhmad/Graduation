import os

def word_frequencies(text):
    myDict = {}
    for word in text.split():
        if word in myDict:
            myDict[word] += 1
        else:
            myDict[word] = 1
    return myDict


f= open("test.txt","r")
str = f.read()
wf = word_frequencies(str)
print(wf)
