with open("neuracecar_encrypted.txt","r") as f:
    data=f.read()

def xor_decipher(ciphertext, key):
    plaintext = ""
    for i in range(len(ciphertext)):
        # 将密文的每个字符与密钥的对应字符进行异或运算
        plaintext += chr(ord(ciphertext[i]) ^ ord(key[i % len(key)]))
    return plaintext

decrypted=xor_decipher(data,123456)

with open("neuracecar_decrypted.txt","w") as f:
    f.write(decrypted)