import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("35.234.105.190", 1234))

def set_pixel(x, y, color):
    s.send(f"CC {x} {y} {color}\n".encode())

for x in range(1920):
    for y in range(1080):
        set_pixel(x, y, "AAAAAA")