import socket

# Configura il server
server_host = '127.0.0.1'
server_port = 12345

# Crea un socket TCP/IP
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Associa il socket alla porta desiderata
server_socket.bind((server_host, server_port))

# Inizia ad ascoltare le connessioni in arrivo (massimo 1 alla volta)
server_socket.listen(1)

print(f"Server in ascolto su {server_host}:{server_port}...")

# Accetta la connessione quando un client si connette
client_socket, client_address = server_socket.accept()

# Riceve i dati inviati dal client e stampa il messaggio ricevuto
data = client_socket.recv(1024).decode('utf-8')
print(f"Client {client_address} dice: {data}")

# Chiude la connessione
client_socket.close()
server_socket.close()

