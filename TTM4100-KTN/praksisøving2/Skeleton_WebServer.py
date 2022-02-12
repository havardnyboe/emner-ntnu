# Import socket module
from multiprocessing import Condition
from socket import *

# Create a TCP server socket
# (AF_INET is used for IPv4 protocols)
# (SOCK_STREAM is used for TCP)
serverSocket = socket(AF_INET, SOCK_STREAM)

# Prepare a server socket.
# FILL IN START

# Assign a port number
serverPort = 5000
serverAddress = "127.0.0.1"

# Bind the socket to server address and server port
serverSocket.bind((serverAddress, serverPort))

# Listen to at most 1 connection at a time (max. number of threads in the connection queue)
serverSocket.listen(1)

# FILL IN END

# Server should be up and running and listening to the incoming connections
while True:
    print('Ready to serve...')

    # Set up a new connection from the client
    connectionSocket, addr = serverSocket.accept()

    # If an exception occurs during the execution of try clause
    # the rest of the clause is skipped
    # If the exception type matches the word after except
    # the except clause is executed
    try:
        # Receives the request message from the client
        message = connectionSocket.recv(1024).decode()
        # print(message)
        # Extract the path of the requested object from the message
        # The path is the second part of HTTP header, identified by [1]
        filepath = message.split()[1]
        # print(filepath)
        # filepath variable now contains the path to the requested object
        # e.g. /HelloWorld.html
        # Remember that the requested file must be in the same folder as the server code.

        # Because the extracted path of the HTTP request includes
        # a character '\', we read the path from the second character
        f = open(filepath[1:])
        # print(f)
        # f variable now contains the file specified by the filepath

        # Read the file "f" and store the entire content of the requested file in a temporary buffer
        outputdata = f.read()
        # outputdata variable now contains the html code that the server is to send to the requesting client

        # FILL IN START

        # Send the HTTP response header line to the connection socket
        # The response should be in the following format: "HTTP/1.1 *code-for-successful-request*\r\n\r\n"
        connectionSocket.send("HTTP/1.1 200\r\n\r\n".encode())
        # FILL IN END

        # Send the content of the requested file to the connection socket
        response = outputdata + "\r\n"
        # connectionSocket.send(response)  # Python 2.7
        connectionSocket.send(response.encode())  # Python 3

        # Close the client connection socket
        connectionSocket.close()

    except (IOError, IndexError):
        # FILL IN START

        # Send HTTP response message for file not found
        # Same format as the successful request, but with code for "Not Found" (see outputdata variable)
        connectionSocket.send("HTTP/1.1 404\r\n\r\n".encode())

        # FILL IN END
        connectionSocket.send(
            "<html><head></head><body><h1>404 Not Found</h1></body></html>\r\n".encode())

    # FILL IN START
    # Close the client connection socket
    connectionSocket.close()

    # FILL IN END

serverSocket.close()
