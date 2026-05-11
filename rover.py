import socket

HOST = "10.181.152.104"  # Serial Monitor'dan gelen ESP32 IP'sini yaz
PORT = 12345

mySocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print(f"Rover bağlandı → {HOST}:{PORT}")
print("Komutlar: forward, backward, left, right, stop, quit")

while True:
    try:
        cmd = input("Komut: ")
        if cmd.lower() == "quit":
            break
        mySocket.sendto(cmd.encode("utf-8"), (HOST, PORT))
    except Exception as e:
        print(f"Hata: {e}")

mySocket.close()
print("Bağlantı kapatıldı.")