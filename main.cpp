#include "hamming1.h"


void interface()
{
    cout<<"1. Encode\n2. Decode\n3. Make errors\n4. Enter new message\n5. Exit";
}

int main()
{
    A:
    cout<<"Enter a message in binary form of any length: ";
    string message;
    cin>>message;

    while(message.size()%4!=0)
    {
        message="0"+message;
    }

    //making 4-bit blocks
    std::cout<<"\n";
    std::vector<std::string> four_bites;
        for(int i=0;i<message.size();i+=4)
        {
            four_bites.push_back(message.substr(i,4));
        }
    std::vector<std::string> encoded_message = hamming1::Encode(four_bites);
    interface();
    while(true)
    {
        std::cout<<"\nChoose a command: ";
        int com;
        std::cin>>com;
        switch(com){
        case 1:
            std::cout<<"\n";
            hamming1::Encode(four_bites);
            break;
        case 2:
            std::cout<<"\n";
            hamming1::Decode(encoded_message);
            break;
        case 3:
            int element_index;
            int bit_index;
            std::cout<<"Choose one byte in your message (1-"<<encoded_message.size()<<"): ";
            std::cin>>element_index;
            std::cout<<"Choose a bit that you want to change (1-8): ";
            std::cin >> bit_index;
            encoded_message=hamming1::ChangeBit(encoded_message,element_index,bit_index);
            break;
        case 4:
            four_bites.clear();
            encoded_message.clear();
            goto A;
            break;
        case 5:
            return 0;
        default:
            std::cout<<"Enter a valid value\n";
        }
        std::cout<<std::endl;
        interface();
    }
}
