with open("input.txt","r") as f:
    data=f.read

def xor_cipher(plaintext, key):
    ciphertext = ""
    for i in range(len(plaintext)):
        # 将明文的每个字符与密钥的对应字符进行异或运算
        ciphertext += chr(ord(plaintext[i]) ^ ord(key[i % len(key)]))
    return ciphertext

encrypted=xor_cipher(data,20237876)
with open("encrypted.txt","w") as f:
    f.write(encrypted)
