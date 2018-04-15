#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char store[28]="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

void encryption(char text[],int k)
{
    int i,j,s=0;
    char new_text[100];
    for(i=0; text[i]!='\0'; i++)
    {
        for(j=0; store[j]!='\0'; j++)
        {
            if(text[i]==store[j])
            {
                s=j+k;
                if(s>26)
                {
                    s=(s-26)-1;
                }
                new_text[i]=store[s];
            }
        }
    }
    new_text[i]='\0';

    cout<<"Encrypted: "<<new_text<<"\n\n";
}
void decryption(char text[],int k)
{
    int i,j,s=0;
    char new_text[100];
    for(i=0; text[i]!='\0'; i++)
    {
        for(j=0; store[j]!='\0'; j++)
        {
            if(text[i]==store[j])
            {
                s=j-k;
                if(s<0)
                {
                    s=(s+26)+1;
                }
                new_text[i]=store[s];
            }
        }
    }
    new_text[i]='\0';

    cout<<"Decrypted: "<<new_text<<"\n\n";
}

int main()
{
    char text[100],process[5];
    int k,choose;
    while(1)
    {
        cout<<"Enter Your Text: ";
        gets(text);
        cout<<"Enter The Value of k: ";
        cin>>k;
        cout<<"\n\n1. Encryption\n2. Decryption\n\n";
        cout<<"Choose any: ";
        cin>>choose;
        if(choose==1)
            encryption(text,k);
        else
            decryption(text,k);

        cout<<"\nAgain?(yes/no): ";
        cin>>process;
        if(strcmp(process,"no")==0 || strcmp(process,"NO")==0)
            break;

        cin.ignore();
    }
    return 0;
}
