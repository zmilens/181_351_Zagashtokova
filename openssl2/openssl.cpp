#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <openssl/conf.h> // �������, ��������� � ��������� ��������� OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // ���� ���������������� ������� https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // ���� ���������� ������ OpenSSL � �� �����������
#include <openssl/aes.h>
#include <fstream>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

// ���������� OpenSSL (openssl.org) ������������ ������ ����������� (��. �������� ���. �� �����������)

using namespace std;

int main()
{
	// ������ � ��������������� OpenSSL:
	// 1) �������� ������� � �����������
	// 2) ����������, ����������
	// 3) �����������
	// 4) � ����� ������������� ������

	// ��� �������, � ����������, ��������� ������������ ��� �������� ������ ������
	// �� ����� � ������� � �������������/������������
	struct name_of_my_struct // ������ ������
	{
		name_of_my_struct()
		{

		}
		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};

	unsigned char plaintext[256];
	int plaintext_len = strlen((char *)plaintext); // ����� ������
	unsigned char *key = (unsigned char *)"0123456789"; // ������ (����)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // ���������������� ������, �����������
	unsigned char cryptedtext[256]; // ������������� ���������
	unsigned char decryptedtext[256]; // �������������� ���������

	// 1. �������� ��������� �� �������������� ���������
	// ��������� - ��� ������ � C++, ������ � ������, �������� ����������
	EVP_CIPHER_CTX *ctx; // structure

	// 2. ��� ��������� �������� ������ ��������� �������� (�����, ����, ������ ������������� � �.�.)
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 3. ��������� EVP_CIPHER_CTX ����������� �����������
	EVP_EncryptInit_ex(ctx, // ������ �� ������/���������, ���� ��������� ���������
		EVP_aes_256_cbc(), // ������ �� ��������� ���� AES 256 (������� � ����������)
		NULL,
		key, // ����/������/������
		iv); // ����������� (��������� ��������� ������)

	// 4. ��� ������� ���������� - ������� EVP_EncryptUpdate
	int len;
	FILE *in, *out;
	in = fopen("in.txt", "rb");//��������� ����(������)
	out = fopen("out.txt", "wb");//������� ����(�����)
	for (;;) {
		plaintext_len = fread(plaintext, 1, 256, in);
		if (plaintext_len <= 0) {
			break;
		}
		EVP_EncryptUpdate(ctx, // ������ � �����������
			cryptedtext, // ������� ��������: ������, ���� �������� ������������� ������
			&len, // �������� ��������: ����� ����������� �����
			plaintext, // ������� ��������: ��� ���������
			plaintext_len);
		fwrite(cryptedtext, 1, len, out);// ������� �������� : ����� ������� ������
	}
	int cryptedtext_len = len;

	// 5. ����������� �������� ����������
	// ����������, ���� ��������� ���� �������� ������� �� ���������
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;
	fwrite(cryptedtext, 1, len, out);
	
	// 6. �������� ���������
	EVP_CIPHER_CTX_free(ctx);
	fclose(in);
	fclose(out);
	// ����� ������������� ������
	for (int i = 0; i < cryptedtext_len; i++)
	{
		cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) cout << endl;
	}
	cout << endl;

	// �����������

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // ������������� ������� AES, ������ � ��������

	// 3.
	  // ����������, ����������

	// 4.
	FILE *dout;
	dout = fopen("dout.txt", "wb");
	out = fopen("out.txt", "rb");
	for (;;) {
		cryptedtext_len = fread(cryptedtext, 1, 256, out);
		if (cryptedtext_len <= 0) {
			break;
		}
		EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);
		fwrite(decryptedtext, 1, len, dout);// ������� �������� : ����� ������� ������
	}
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	fwrite(decryptedtext, 1, len, dout);
	fclose(out);
	fclose(dout);

	// --- ���������� �����
	// ������������ ����� ��� ��, �� ��������, � �����
	// � �����
	/*
		1) �������� ������ � ��������� ���������� OpenSSL
		2) ���������� ������� �����
		3) while(���������_�������� > 0)
		{
			4) ���������� ����������
			5) ������ �������������� ������� � ����
			6) ���������� ���������� ���������
		}
		7) ���������� �������������� �������
		8) ������ ��������������� ����� � ����
		9) �������� ������
	*/
	getchar();
	return 0;
}