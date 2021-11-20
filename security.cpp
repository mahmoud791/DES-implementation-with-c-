#include<iostream>
using namespace std;


string makePermutation(string s, int permutationKey [],int permutationkeysize);
string Hexa2Binary(string s);
string Binary2Hexa(string s);
string shift_left(string previouskey, int shiftamount);
string permutedchoice1(string key);
string permutedchoice2(string key);
string initialpermutation(string plaintext);
string inverseinitialpermutation(string text);
string expansionpermutation(string text);
string * generate_all_keys(string key);
string dec2bin(int x);
int column(string four_bits);
int row(string two_bits);
string s_box_permutation(string s);
string straightpermutation(string text);
string XOR(string x, string y);
string F(string Ri,string Ki);
string encryption_round(string text,string key);
string decryption_round(string cipher, string key);
string swap_32_bit(string text);
string encrypt(string plaintext, string key);
string decrypt(string cipher, string key);



int main(int argc, char** argv)
{

    string operation = argv[1];
    string data = argv[2];
    string key = argv[3];




    if(operation == "encrypt")
    {
        cout<<"cipher: "<<encrypt(data,key);
    }
    else if(operation == "decrypt")
    {
        cout<<"plain: "<<decrypt(data,key);
    }
    return 0;

}











string makePermutation(string s, int permutationKey [],int permutationkeysize)
{
    string permuted_text = "";

    for(int i=0;i<permutationkeysize;i++)
    {
       int index = permutationKey[i] - 1;
       permuted_text += s[index];
    }
    return permuted_text;
}

string Hexa2Binary(string s)
{
    string binary = "";
    int l = s.size();
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0') binary += "0000";
        else if (s[i]=='1') binary += "0001";
        else if (s[i]=='2') binary += "0010";
        else if (s[i]=='3') binary += "0011";
        else if (s[i]=='4') binary += "0100";
        else if (s[i]=='5') binary += "0101";
        else if (s[i]=='6') binary += "0110";
        else if (s[i]=='7') binary += "0111";
        else if (s[i]=='8') binary += "1000";
        else if (s[i]=='9') binary += "1001";
        else if (s[i]=='A') binary += "1010";
        else if (s[i]=='B') binary += "1011";
        else if (s[i]=='C') binary += "1100";
        else if (s[i]=='D') binary += "1101";
        else if (s[i]=='E') binary += "1110";
        else if (s[i]=='F') binary += "1111";

    }
    return binary;
}

string Binary2Hexa(string s)
{
    string hexa = "";
    for (int i = 0; i < 16; i++)
    {
        string val = s.substr(i*4,4);

        if(val=="0000")hexa+="0";
        else if(val=="0001")hexa+="1";
        else if(val=="0010")hexa+="2";
        else if(val=="0011")hexa+="3";
        else if(val=="0100")hexa+="4";
        else if(val=="0101")hexa+="5";
        else if(val=="0110")hexa+="6";
        else if(val=="0111")hexa+="7";
        else if(val=="1000")hexa+="8";
        else if(val=="1001")hexa+="9";
        else if(val=="1010")hexa+="A";
        else if(val=="1011")hexa+="B";
        else if(val=="1100")hexa+="C";
        else if(val=="1101")hexa+="D";
        else if(val=="1110")hexa+="E";
        else if(val=="1111")hexa+="F";


    }
    return hexa;

}

string shift_left(string previouskey, int shiftamount)
{
    string left_key = previouskey.substr(0,28);
    string right_key = previouskey.substr(28,28);

    string shifted_left = "";
    string shifted_right = "";

    for(int i=0;i<shiftamount;i++)
    {
        for(int j=1;j<28;j++)
        {
            shifted_left += left_key[j];
        }

        shifted_left += left_key[0];
        left_key =shifted_left;
        shifted_left = "";
    }

    for(int i=0;i<shiftamount;i++)
    {
        for(int j=1;j<28;j++)
        {
            shifted_right += right_key[j];
        }

        shifted_right += right_key[0];
        right_key =shifted_right;
        shifted_right = "";
    }

    return left_key+right_key;

}

string permutedchoice1(string key)
{
    key = Hexa2Binary(key);
    int permutedchoice1_table [56] = { 57, 49, 41, 33, 25, 17, 9,
                                       1, 58, 50, 42, 34, 26, 18,
                                       10, 2, 59, 51, 43, 35, 27,
                                       19, 11, 3, 60, 52, 44, 36,
                                       63, 55, 47, 39, 31, 23, 15,
                                       7, 62, 54, 46, 38, 30, 22,
                                       14, 6, 61, 53, 45, 37, 29,
                                       21, 13, 5, 28, 20, 12, 4 };


    string output = makePermutation(key,permutedchoice1_table,56);
    return output;
}

string permutedchoice2(string key)
{
    int permutedchoice2_table[48] = { 14, 17, 11, 24, 1, 5,
                                  3, 28, 15, 6, 21, 10,
                                  23, 19, 12, 4, 26, 8,
                                  16, 7, 27, 20, 13, 2,
                                  41, 52, 31, 37, 47, 55,
                                  30, 40, 51, 45, 33, 48,
                                  44, 49, 39, 56, 34, 53,
                                  46, 42, 50, 36, 29, 32 };

    string output = makePermutation(key,permutedchoice2_table,48);

    return output;

}

string initialpermutation(string plaintext)
{

    int intialpermutation_table[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                                      60, 52, 44, 36, 28, 20, 12, 4,
                                      62, 54, 46, 38, 30, 22, 14, 6,
                                      64, 56, 48, 40, 32, 24, 16, 8,
                                      57, 49, 41, 33, 25, 17, 9, 1,
                                      59, 51, 43, 35, 27, 19, 11, 3,
                                      61, 53, 45, 37, 29, 21, 13, 5,
                                      63, 55, 47, 39, 31, 23, 15, 7 };

    string output = makePermutation(plaintext,intialpermutation_table,64);
    return output;
}

string inverseinitialpermutation(string text)
{
    int inverseintialpermutation_table[64] { 40, 8, 48, 16, 56, 24, 64, 32,
                           39, 7, 47, 15, 55, 23, 63, 31,
                           38, 6, 46, 14, 54, 22, 62, 30,
                           37, 5, 45, 13, 53, 21, 61, 29,
                           36, 4, 44, 12, 52, 20, 60, 28,
                           35, 3, 43, 11, 51, 19, 59, 27,
                           34, 2, 42, 10, 50, 18, 58, 26,
                           33, 1, 41, 9, 49, 17, 57, 25 };

    string output = makePermutation(text,inverseintialpermutation_table,64);
    return output;

}

string expansionpermutation(string text)
{
    int expansionpermutation_table[48] ={ 32, 1, 2, 3, 4, 5, 4, 5,
                      6, 7, 8, 9, 8, 9, 10, 11,
                      12, 13, 12, 13, 14, 15, 16, 17,
                      16, 17, 18, 19, 20, 21, 20, 21,
                      22, 23, 24, 25, 24, 25, 26, 27,
                      28, 29, 28, 29, 30, 31, 32, 1 };

    string output = makePermutation(text,expansionpermutation_table,48);
    return output;
}

string * generate_all_keys(string key)
{
    static string allkeys [16];
    key = permutedchoice1(key);

    int shiftamount[16] = { 1, 1, 2, 2,
                        2, 2, 2, 2,
                        1, 2, 2, 2,
                        2, 2, 2, 1};

    for(int i=0;i<16;i++)
    {
        string k = shift_left(key,shiftamount[i]);
        allkeys[i] = permutedchoice2(k);
        key = k;



    }
    return allkeys;
}

string dec2bin(int x)
{
   string binary [16];
   binary[0] = "0000";
   binary[1] = "0001";
   binary[2] = "0010";
   binary[3] = "0011";
   binary[4] = "0100";
   binary[5] = "0101";
   binary[6] = "0110";
   binary[7] = "0111";
   binary[8] = "1000";
   binary[9] = "1001";
   binary[10] = "1010";
   binary[11] = "1011";
   binary[12] = "1100";
   binary[13] = "1101";
   binary[14] = "1110";
   binary[15] = "1111";

   return binary[x];

}

int column(string four_bits)
{
    if(four_bits=="0000")return 0;
    else if(four_bits=="0001")return 1;
    else if(four_bits=="0010")return 2;
    else if(four_bits=="0011")return 3;
    else if(four_bits=="0100")return 4;
    else if(four_bits=="0101")return 5;
    else if(four_bits=="0110")return 6;
    else if(four_bits=="0111")return 7;
    else if(four_bits=="1000")return 8;
    else if(four_bits=="1001")return 9;
    else if(four_bits=="1010")return 10;
    else if(four_bits=="1011")return 11;
    else if(four_bits=="1100")return 12;
    else if(four_bits=="1101")return 13;
    else if(four_bits=="1110")return 14;
    else if(four_bits=="1111")return 15;
    else return 0;
}

int row(string two_bits)
{
    if(two_bits=="00")return 0;
    else if(two_bits=="01")return 1;
    else if(two_bits=="10")return 2;
    else if(two_bits=="11")return 3;
    else return 0;
}

string s_box_permutation(string s)
{
    int s_box_table [8][4][16] =  { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                          0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                          13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

                        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                          13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                          13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                          1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                          13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                          10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                          3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                          13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                          1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                          6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                          1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                          7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                          2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };
    string output = "";
    string key;
    string row_key;
    string column_key;
    for (int i = 0; i < 8; i++)
    {
        key = s.substr(i*6,6);
        row_key = key.substr(0,1) + key.substr(5,1);
        column_key = key.substr(1,4);
        //cout<<column_key<<endl;
        output += dec2bin(s_box_table [i][row(row_key)][column(column_key)]);

    }
    return output;

}

string straightpermutation(string text)
{
    int straightpermutation_table[32] = { 16, 7, 20, 21,
                    29, 12, 28, 17,
                    1, 15, 23, 26,
                    5, 18, 31, 10,
                    2, 8, 24, 14,
                    32, 27, 3, 9,
                    19, 13, 30, 6,
                    22, 11, 4, 25 };

    string output = makePermutation(text,straightpermutation_table,32);
    return output;
}

string XOR(string x, string y)
{
    string output = "";
    int l = x.size();
    if(x.size() == y.size())
    {

        for (int i = 0; i < l; i++)
        {
            if(x[i]==y[i])output+="0";
            else output+="1";
        }

    }
    else cout<<"Error, inputs size to xor does not match";
    return output;
}

string F(string Ri,string Ki)
{
    string x = expansionpermutation(Ri);
    x = XOR(x,Ki);
    x = s_box_permutation(x);
    x = straightpermutation(x);
    return x;
}

string encryption_round(string text,string key)
{
    string left_in = text.substr(0,32);
    string right_in = text.substr(32,32);
    string left_out = right_in;
    string right_out = XOR(left_in,F(right_in,key));
    return left_out+right_out;

}

string decryption_round(string cipher, string key)
{
    string left_in = cipher.substr(0,32);
    string right_in = cipher.substr(32,32);
    string right_out = left_in;
    string left_out = XOR(right_in,F(left_in,key));
    return left_out+right_out;

}

string swap_32_bit(string text)
{
    string left = text.substr(0,32);
    string right = text.substr(32,32);

    return  right + left ;
}

string encrypt(string plaintext, string key)
{
    string * keys = generate_all_keys(key);
    plaintext = Hexa2Binary(plaintext);
    string text = initialpermutation(plaintext);

    for (int i = 0; i < 16; i++)
    {
        text = encryption_round(text,keys[i]);
    }

    text = swap_32_bit(text);
    text = inverseinitialpermutation(text);
    text = Binary2Hexa(text);
    return text;

}

string decrypt(string cipher, string key)
{
    string * keys = generate_all_keys(key);
    cipher = Hexa2Binary(cipher);
    string plaintext = initialpermutation(cipher);
    plaintext = swap_32_bit(plaintext);

    for (int i = 15; i >= 0; i--)
    {
        plaintext = decryption_round(plaintext,keys[i]);
    }
    plaintext = inverseinitialpermutation(plaintext);
    plaintext = Binary2Hexa(plaintext);
    return plaintext;
}
