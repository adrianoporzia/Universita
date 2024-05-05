import socket

# Configura il client
server_host = '127.0.0.1'
server_port = 12345

# Crea un socket TCP/IP
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connessione al server
client_socket.connect((server_host, server_port))

# Messaggio da inviare al server
message = "Ciao, sono il client!"

# Invia il messaggio al server
client_socket.sendall(message.encode('utf-8'))

# Chiude la connessione
client_socket.close()

