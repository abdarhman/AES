#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<math.h>
#include<algorithm>
#include<vector>
#include <iomanip>
#include <sstream>
#include <stdio.h>
typedef unsigned char uint8_t;
using namespace std;
//addmixtable
//add multiplication tables
//add multiplication functions
uint8_t RCON[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 };
uint8_t S_BOX[] =
{
	0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6f, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
	0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};
const uint8_t mult_2[256] =
{
	0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
	0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e,
	0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e,
	0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e,
	0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e,
	0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe,
	0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde,
	0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe,
	0x1b, 0x19, 0x1f, 0x1d, 0x13, 0x11, 0x17, 0x15, 0x0b, 0x09, 0x0f, 0x0d, 0x03, 0x01, 0x07, 0x05,
	0x3b, 0x39, 0x3f, 0x3d, 0x33, 0x31, 0x37, 0x35, 0x2b, 0x29, 0x2f, 0x2d, 0x23, 0x21, 0x27, 0x25,
	0x5b, 0x59, 0x5f, 0x5d, 0x53, 0x51, 0x57, 0x55, 0x4b, 0x49, 0x4f, 0x4d, 0x43, 0x41, 0x47, 0x45,
	0x7b, 0x79, 0x7f, 0x7d, 0x73, 0x71, 0x77, 0x75, 0x6b, 0x69, 0x6f, 0x6d, 0x63, 0x61, 0x67, 0x65,
	0x9b, 0x99, 0x9f, 0x9d, 0x93, 0x91, 0x97, 0x95, 0x8b, 0x89, 0x8f, 0x8d, 0x83, 0x81, 0x87, 0x85,
	0xbb, 0xb9, 0xbf, 0xbd, 0xb3, 0xb1, 0xb7, 0xb5, 0xab, 0xa9, 0xaf, 0xad, 0xa3, 0xa1, 0xa7, 0xa5,
	0xdb, 0xd9, 0xdf, 0xdd, 0xd3, 0xd1, 0xd7, 0xd5, 0xcb, 0xc9, 0xcf, 0xcd, 0xc3, 0xc1, 0xc7, 0xc5,
	0xfb, 0xf9, 0xff, 0xfd, 0xf3, 0xf1, 0xf7, 0xf5, 0xeb, 0xe9, 0xef, 0xed, 0xe3, 0xe1, 0xe7, 0xe5
};
const uint8_t mult_3[256] =
{
	0x00, 0x03, 0x06, 0x05, 0x0c, 0x0f, 0x0a, 0x09, 0x18, 0x1b, 0x1e, 0x1d, 0x14, 0x17, 0x12, 0x11,
	0x30, 0x33, 0x36, 0x35, 0x3c, 0x3f, 0x3a, 0x39, 0x28, 0x2b, 0x2e, 0x2d, 0x24, 0x27, 0x22, 0x21,
	0x60, 0x63, 0x66, 0x65, 0x6c, 0x6f, 0x6a, 0x69, 0x78, 0x7b, 0x7e, 0x7d, 0x74, 0x77, 0x72, 0x71,
	0x50, 0x53, 0x56, 0x55, 0x5c, 0x5f, 0x5a, 0x59, 0x48, 0x4b, 0x4e, 0x4d, 0x44, 0x47, 0x42, 0x41,
	0xc0, 0xc3, 0xc6, 0xc5, 0xcc, 0xcf, 0xca, 0xc9, 0xd8, 0xdb, 0xde, 0xdd, 0xd4, 0xd7, 0xd2, 0xd1,
	0xf0, 0xf3, 0xf6, 0xf5, 0xfc, 0xff, 0xfa, 0xf9, 0xe8, 0xeb, 0xee, 0xed, 0xe4, 0xe7, 0xe2, 0xe1,
	0xa0, 0xa3, 0xa6, 0xa5, 0xac, 0xaf, 0xaa, 0xa9, 0xb8, 0xbb, 0xbe, 0xbd, 0xb4, 0xb7, 0xb2, 0xb1,
	0x90, 0x93, 0x96, 0x95, 0x9c, 0x9f, 0x9a, 0x99, 0x88, 0x8b, 0x8e, 0x8d, 0x84, 0x87, 0x82, 0x81,
	0x9b, 0x98, 0x9d, 0x9e, 0x97, 0x94, 0x91, 0x92, 0x83, 0x80, 0x85, 0x86, 0x8f, 0x8c, 0x89, 0x8a,
	0xab, 0xa8, 0xad, 0xae, 0xa7, 0xa4, 0xa1, 0xa2, 0xb3, 0xb0, 0xb5, 0xb6, 0xbf, 0xbc, 0xb9, 0xba,
	0xfb, 0xf8, 0xfd, 0xfe, 0xf7, 0xf4, 0xf1, 0xf2, 0xe3, 0xe0, 0xe5, 0xe6, 0xef, 0xec, 0xe9, 0xea,
	0xcb, 0xc8, 0xcd, 0xce, 0xc7, 0xc4, 0xc1, 0xc2, 0xd3, 0xd0, 0xd5, 0xd6, 0xdf, 0xdc, 0xd9, 0xda,
	0x5b, 0x58, 0x5d, 0x5e, 0x57, 0x54, 0x51, 0x52, 0x43, 0x40, 0x45, 0x46, 0x4f, 0x4c, 0x49, 0x4a,
	0x6b, 0x68, 0x6d, 0x6e, 0x67, 0x64, 0x61, 0x62, 0x73, 0x70, 0x75, 0x76, 0x7f, 0x7c, 0x79, 0x7a,
	0x3b, 0x38, 0x3d, 0x3e, 0x37, 0x34, 0x31, 0x32, 0x23, 0x20, 0x25, 0x26, 0x2f, 0x2c, 0x29, 0x2a,
	0x0b, 0x08, 0x0d, 0x0e, 0x07, 0x04, 0x01, 0x02, 0x13, 0x10, 0x15, 0x16, 0x1f, 0x1c, 0x19, 0x1a
};
vector<uint8_t> RotateWord(vector<uint8_t> word)
{
	vector<uint8_t> result;
	for (int i = 0; i < 3; i++)
	{
		result.push_back(word[i + 1]);
	}
	result.push_back(word[0]);
	return result;
}
vector<uint8_t> Substitute(vector<uint8_t>key)
{
	for (int i = 0; i < key.size(); i++)
	{
		key[i] = S_BOX[key[i]];
	}
	return key;
}
vector<vector<uint8_t>> Substitute(vector<vector<uint8_t>>key)
{
	for (int i = 0; i < key.size(); i++)
	{
		for (int k = 0; k < key.size(); k++)
		{
			key[i][k] = S_BOX[key[i][k]];
		}
	}
	return key;
}
vector<vector<uint8_t>> XOR(vector<vector<uint8_t>>text, vector<vector<uint8_t>>key)
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			text[i][k] = text[i][k] ^ key[i][k];
		}
	}
	return text;
}
vector<uint8_t> XOR(vector<uint8_t>key, uint8_t rcon)
{
	key[0] = key[0] ^ rcon;
	return key;
}
vector<uint8_t> BytesFromString(string s, int length)
{
	vector<uint8_t> hkey;
	for (int i = 0; i <length / 2; i++)
	{
		if (s[2 * i] <= 57)
		{
			hkey.push_back(16 * (s[2 * i] - 48));
		}
		else if (s[2 * i] < 91)
		{
			hkey.push_back(16 * (s[2 * i] - 55));
		}
		else if (s[2 * i] < 123)
		{
			hkey.push_back(16 * (s[2 * i] - 87));
		}
		int t;
		if (s[2 * i + 1] <= 57)
		{
			t = (s[2 * i + 1] - 48);
			hkey[i] += t;
		}
		else if (s[2 * i + 1] < 91)
		{
			t = (s[2 * i + 1] - 55);
			hkey[i] += t;
		}
		else if (s[2 * i + 1] < 123)
		{
			t = (s[2 * i + 1] - 87);
			hkey[i] += t;
		}
	}
	return hkey;
}
vector<vector<uint8_t>> ExpandKey(vector<uint8_t> key)
{
	vector<vector<uint8_t>> result;
	result.push_back(key);
	for (int k = 0; k < 10; k++)
	{
		vector<uint8_t> temp;
		for (int i = 12; i < 16; i++)
		{
			temp.push_back(key[i]);
		}
		temp = RotateWord(temp);
		temp = Substitute(temp);
		temp = XOR(temp, RCON[k]);
		for (int i = 0; i < 4; i++)
		{
			temp[i] = temp[i] ^ key[i];
		}
		for (int i = 4; i < key.size(); i++)
		{
			temp.push_back(temp[i - 4] ^ key[i]);
		}
		result.push_back(temp);
		key = temp;
	}
	return result;
}
vector<vector<uint8_t>> ShiftRows(vector<vector<uint8_t>>text)
{
	vector<vector<uint8_t>> result;
	result.push_back(text[0]);
	for (int i = 1; i < 4; i++)
	{
		vector<uint8_t>temp;
		if (i == 1)
		{
			temp.push_back(text[i][1]);
			temp.push_back(text[i][2]);
			temp.push_back(text[i][3]);
			temp.push_back(text[i][0]);
		}
		else if (i == 2)
		{
			temp.push_back(text[i][2]);
			temp.push_back(text[i][3]);
			temp.push_back(text[i][0]);
			temp.push_back(text[i][1]);
		}
		else
		{
			temp.push_back(text[i][3]);
			temp.push_back(text[i][0]);
			temp.push_back(text[i][1]);
			temp.push_back(text[i][2]);
		}
		result.push_back(temp);
	}
	return result;
}
vector<vector<uint8_t>>Transpose(vector<uint8_t>text)
{
	vector<vector<uint8_t>> result;
	for (int i = 0; i < 4; i++)
	{
		vector<uint8_t> temp;
		temp.push_back(text[i]);
		for (int k = 1; k < 4; k++)
		{
			temp.push_back(text[(k * 4) + i]);
		}
		result.push_back(temp);
	}
	return result;
}
vector<vector<uint8_t>>Transpose(vector<vector<uint8_t>>text)
{
	vector<vector<uint8_t>> result;
	for (int i = 0; i < 4; i++)
	{
		vector<uint8_t> temp;
		for (int k = 0; k < 4; k++)
		{
			temp.push_back(text[k][i]);
		}
		result.push_back(temp);
	}
	return result;
}
uint8_t mul(int i, vector<uint8_t> row)
{
	uint8_t output;
	if (i == 0)
	{
		if (row[0] & 0x80)
		{
			row[0] = row[0] << 1;
			row[0] = row[0] ^ 0x1b;
		}
		else
		{
			row[0] = row[0] << 1;
		}
		uint8_t t = row[1];
		if (row[1] & 0x80)
		{
			row[1] = row[1] << 1;
			row[1] = row[1] ^ 0x1b;
			row[1] = t ^ row[1];
		}
		else
		{
			row[1] = row[1] << 1;
			row[1] = t ^ row[1];
		}
		output = row[0] ^ row[1] ^ row[2] ^ row[3];
	}
	else if (i == 1)
	{
		if (row[1] & 0x80)
		{
			row[1] = row[1] << 1;
			row[1] = row[1] ^ 0x1b;
		}
		else
		{
			row[1] = row[1] << 1;
		}
		uint8_t t = row[2];
		if (row[2] & 0x80)
		{
			row[2] = row[2] << 1;
			row[2] = row[2] ^ 0x1b;
			row[2] = t ^ row[2];
		}
		else
		{
			row[2] = row[2] << 1;
			row[2] = t ^ row[2];
		}
		output = row[0] ^ row[1] ^ row[2] ^ row[3];
	}
	else if (i == 2)
	{
		if (row[2] & 0x80)
		{
			row[2] = row[2] << 1;
			row[2] = row[2] ^ 0x1b;
		}
		else
		{
			row[2] = row[2] << 1;
		}
		uint8_t t = row[3];
		if (row[3] & 0x80)
		{
			row[3] = row[3] << 1;
			row[3] = row[3] ^ 0x1b;
			row[3] = t ^ row[3];
		}
		else
		{
			row[3] = row[3] << 1;
			row[3] = t ^ row[3];
		}
		output = row[0] ^ row[1] ^ row[2] ^ row[3];
	}
	else if (i == 3)
	{
		if (row[3] & 0x80)
		{
			row[3] = row[3] << 1;
			row[3] = row[3] ^ 0x1b;
		}
		else
		{
			row[3] = row[3] << 1;
		}
		uint8_t t = row[0];
		if (row[0] & 0x80)
		{
			row[0] = row[0] << 1;
			row[0] = row[0] ^ 0x1b;
			row[0] = t ^ row[0];
		}
		else
		{
			row[0] = row[0] << 1;
			row[0] = t ^ row[0];
		}
		output = row[0] ^ row[1] ^ row[2] ^ row[3];
	}
	return output;
}
vector<vector<uint8_t>>MixColumns(vector<vector<uint8_t>>text)
{
	vector<vector<uint8_t>> result;
	vector<uint8_t> one;
	vector<uint8_t> two;
	vector<uint8_t> three;
	vector<uint8_t> four;
	/*for (int i = 0; i < 4; i++)
	{
	for (int k = 0; k < 4; k++)
	{
	vector<uint8_t> t;
	t.push_back(text[0][k]);
	t.push_back(text[1][k]);
	t.push_back(text[2][k]);
	t.push_back(text[3][k]);
	if (i == 0)
	{
	one.push_back(mul(i, t));
	}
	else if (i == 1)
	{
	two.push_back(mul(i, t));
	}
	else if (i == 2)
	{
	three.push_back(mul(i, t));
	}
	else
	{
	four.push_back(mul(i, t));
	}
	}
	}*/
	one.push_back(mult_2[text[0][0]] ^ mult_3[text[1][0]] ^ text[2][0] ^ text[3][0]);
	one.push_back(mult_2[text[0][1]] ^ mult_3[text[1][1]] ^ text[2][1] ^ text[3][1]);
	one.push_back(mult_2[text[0][2]] ^ mult_3[text[1][2]] ^ text[2][2] ^ text[3][2]);
	one.push_back(mult_2[text[0][3]] ^ mult_3[text[1][3]] ^ text[2][3] ^ text[3][3]);
	two.push_back(text[0][0] ^ mult_2[text[1][0]] ^ mult_3[text[2][0]] ^ text[3][0]);
	two.push_back(text[0][1] ^ mult_2[text[1][1]] ^ mult_3[text[2][1]] ^ text[3][1]);
	two.push_back(text[0][2] ^ mult_2[text[1][2]] ^ mult_3[text[2][2]] ^ text[3][2]);
	two.push_back(text[0][3] ^ mult_2[text[1][3]] ^ mult_3[text[2][3]] ^ text[3][3]);
	three.push_back(text[0][0] ^ text[1][0] ^ mult_2[text[2][0]] ^ mult_3[text[3][0]]);
	three.push_back(text[0][1] ^ text[1][1] ^ mult_2[text[2][1]] ^ mult_3[text[3][1]]);
	three.push_back(text[0][2] ^ text[1][2] ^ mult_2[text[2][2]] ^ mult_3[text[3][2]]);
	three.push_back(text[0][3] ^ text[1][3] ^ mult_2[text[2][3]] ^ mult_3[text[3][3]]);
	four.push_back(mult_3[text[0][0]] ^ text[1][0] ^ text[2][0] ^ mult_2[text[3][0]]);
	four.push_back(mult_3[text[0][1]] ^ text[1][1] ^ text[2][1] ^ mult_2[text[3][1]]);
	four.push_back(mult_3[text[0][2]] ^ text[1][2] ^ text[2][2] ^ mult_2[text[3][2]]);
	four.push_back(mult_3[text[0][3]] ^ text[1][3] ^ text[2][3] ^ mult_2[text[3][3]]);
	result.push_back(one);
	result.push_back(two);
	result.push_back(three);
	result.push_back(four);
	return result;
}
vector<uint8_t> AES(vector<uint8_t>text,vector< uint8_t>hkey)
{
	int keylength = 16;
	int textlength = 16;

	//hkey = BytesFromString(skey, keylength);	
	//text = BytesFromString(plaintext, textlength);
	vector<vector<uint8_t>> Expandedkey = ExpandKey(hkey);
	vector<vector<uint8_t>> statetext = Transpose(text);
	for (int i = 0; i < 11; i++)
	{
		vector<vector<uint8_t>> statekey = Transpose(Expandedkey[i]);

		if (i == 0)
		{
			statetext = XOR(statetext, statekey);
		}
		else
		{
			statetext = Substitute(statetext);
			statetext = ShiftRows(statetext);
			if (i != 10)
			{
				statetext = MixColumns(statetext);
			}
			statetext = XOR(statetext, statekey);
		}
	}
	vector<uint8_t> returntext;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			returntext.push_back(statetext[k][i]);
		}
	}
	return returntext;
	//stringstream rs;
	/*for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			rs << setw(2) << setfill('0') << hex << (int)statetext[k][i];
		}
	}*/
	//string r;
	//r = rs.str();
	//return r;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int te = 0; te < t; t++)
	{
		uint8_t plaintext[16];
		uint8_t skey[16];
		vector<uint8_t>hkey;
		vector<uint8_t>text;
		for (int i = 0; i < 16; i++)
		{
			scanf("%2hhx", &plaintext[i]);
		}
		for (int i = 0; i < 16; i++)
		{
			scanf("%2hhx", &skey[i]);
		}
		int m;
		cin >> m;
		for (int i = 0; i < 16; i++)
		{
			hkey.push_back(skey[i]);
			text.push_back(plaintext[i]);
		}
		for (int mi = 0; mi < m; mi++)
		{			
			text = AES(text, hkey);
			if (mi == m - 1)
			{
				for (int i = 0; i < 16; i++)
				{
					
					cout << hex << setw(2) << setfill('0') << (int)text[i];
				}
				if (te != t - 1) cout << "\n";
			}
		}
	}

	return 0;
}

