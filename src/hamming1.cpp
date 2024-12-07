#include "hamming1.h"


namespace hamming1
{
    char sum_mod_2(char a, char b)
    {
        if(a==b) return '0';
        else if(a!=b) return '1';
        return '0';
    }
    string EncodeString(string b_string)
    {
        char d1=b_string[0];
        char d2=b_string[1];
        char d3=b_string[2];
        char d4=b_string[3];
        char p1=sum_mod_2('1',sum_mod_2(d1,sum_mod_2(d3,d4)));
        char p2=sum_mod_2('1',sum_mod_2(d1,sum_mod_2(d2,d4)));
        char p3= sum_mod_2('1',sum_mod_2(d1,sum_mod_2(d2,d3)));
        char p4= sum_mod_2('1',sum_mod_2(p1,sum_mod_2(d1,sum_mod_2(p2,sum_mod_2(d2,sum_mod_2(p3,sum_mod_2(d3,d4)))))));
        string res={p1,d1,p2,d2,p3,d3,p4,d4};
        return res;

    }

    std::vector<string> Encode(std::vector<string> string_bytes)
    {
        int i=1;
        std::vector<string> enc_string;
        for(string s:string_bytes)
        {
            string enc_s = EncodeString(s);
            cout<<i<<". "<<s<<"-->"<<enc_s<<std::endl;
            enc_string.push_back(enc_s);
            i++;
        }
       cout<<std::endl;
        return enc_string;
    }
    std::vector<string> Encode2(std::vector<string> string_bytes)
    {
        std::vector<string> enc_string;
        for(string s:string_bytes)
        {
            string enc_s = EncodeString(s);
            enc_string.push_back(enc_s);
        }
        return enc_string;
    }

    string DecodeString(string string_byte)
    {
        char p1=string_byte[0];
        char p2=string_byte[2];
        char p3=string_byte[4];
        char p4=string_byte[6];
        char d1=string_byte[1];
        char d2=string_byte[3];
        char d3=string_byte[5];
        char d4=string_byte[7];
        bool A = sum_mod_2(p1,sum_mod_2(d1,sum_mod_2(d3,d4))) == '1';
        bool B = sum_mod_2(p2,sum_mod_2(d1,sum_mod_2(d2,d4))) == '1';
        bool C = sum_mod_2(d1,sum_mod_2(d2,sum_mod_2(d3,p3))) == '1';
        bool D = sum_mod_2(p1,sum_mod_2(p2,sum_mod_2(p3,sum_mod_2(p4,sum_mod_2(d1,sum_mod_2(d2,sum_mod_2(d3,d4))))))) == '1';
        if ((!A || !B || !C) && D) { return "Double error";}

        int err_pos = !C*5+!B*3+!A+7*(A&&B&&C&&!D);
        if(err_pos>0) cout<<"Error found in "<<err_pos<< "th position\n";
        string_byte[err_pos-1]=sum_mod_2(string_byte[err_pos-1],'1');
        d1=string_byte[1];
        d2=string_byte[3];
        d3=string_byte[5];
        d4=string_byte[7];
        string res={d1,d2,d3,d4};
        return res;
    }

    std::vector<string> Decode(std::vector<string> bytes)
    {
        std::vector<string> res;
        int i=1;
        for(string s:bytes)
        {
            string res_s = DecodeString(s);
            if(res_s=="Double error") {cout<<"Double error\n";break;}
            else{
            cout<<i<<". "<<s<<"-->"<<res_s<<std::endl;
            res.push_back(res_s);
            i++;}
        }
        cout<<"Decoded message: ";
        for(string s:res)
        {
            cout<<s;
        }
        cout<<"\n";
        return res;
    }

    std::vector<std::string> ChangeBit(std::vector<string> encoded_message, int element_index, int bit_index)
    {
        if(element_index>=1 && element_index<=encoded_message.size() && bit_index>=1 && bit_index<=8)
        {
            encoded_message[element_index-1][bit_index-1] = sum_mod_2('1',encoded_message[element_index-1][bit_index-1]);
            cout<<"***Message changed***\n";
        }
        else cout<<"***Enter valid values***\n";
        return encoded_message;
    }

}
