



import socket












def test_client(serv, port):
    sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sockfd.connect((serv, port))
    sockfd.send('hello server')

test_client("127.0.0.1", 9999)
