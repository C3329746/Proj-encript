#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[1024];
    int chV;  //individual character associated value
    int i;    //individual character position in string
    int type; //determine if the program is encoding/decoding with rotation/substitution
    int y=0;  //finished with the program or not
    int key; //number to rotate by, forward/backwards
    char Ckey[30]; //string of alphabetic letters to substitute in
    int kV; //character value for Ckey
    printf ("please enter a number, 1, 2, 3, or 4\n");
    printf ("1 will encode with rotation\n2 will decode with rotation\n");
    printf ("3 will encode with substitution\n4 will decode with substitution\n");
    scanf ("%d", &type); //determine the process
    printf("Type: %d\n", type);
    
    switch(type) {
        case 1 : //encoding by rotation
            printf ("please enter a key to rotate by\n");
            scanf("%d", &key); //number to rotate by
            printf ("please enter your message\n");
            printf ("please use : instead of spaces, as the program will not recognise spaces\n");
            scanf("%s", message); //message to be encoded
            
            for (i=0; message[i] != '\0'; i++){
                chV=message[i]; //take character value from the characters string position
                if ((chV >= 97) && (chV <= 122)){ //charater value between 'a' and 'z'
        
                    chV = (((chV - 97 + key)%26)+97); //modulating the character value. ('a' = 97, key =1) (97-97+1)=1 1%26=1 1+97=98 (98= 'b')
                    message[i] = chV; //sub character value back into the string position

                }
                if ((chV >= 65) && (chV <= 90)){ //character vaule between 'A' and 'Z'

                    chV = (((chV - 65 + key)%26)+65); //modulating the character value. ('A' = 65, key =1) (65-65+1)=1 1%26=1 1+65=66 (66= 'B')
                    message[i] = chV; //sub character value back into the string position
                
                }
            }
            printf("%s\n", message); //print the encoded message
            i=0; //resets the value of i to be used again
            break;
        
        case 2 : //decoding by rotation
            printf ("please enter a key to rotate by\n");
            scanf("%d", &key); //key to rotate back by
            printf ("please enter your message\n");
            printf ("please use : instead of spaces, as the program will not recognise spaces\n");
            scanf("%s", message); //message to be decoded
            
            for (i=0; message[i] != '\0'; i++){
                chV=message[i]; //take character value from the characters string position
                if ((chV >= 97) && (chV <= 122)){ //character value between 'a' and 'z'
        
                    chV = ((chV - 97-key)%26)+97; //98-97-1=0 0%26=0 0+97=97 ('a') 
                    if (chV < 97) { //if the character value is below the value of 'a', increase it be 26 (end of the alphabet)
                        chV = chV + 26;
                    }
                message[i] = chV; //sub character value back into the string position
                }
                if ((chV >= 65) && (chV <= 90)){ //character vaule between 'A' and 'Z'

                    chV = (((chV - 65 - key)%26)+65); //modulating the character value. ('B' = 66, key =1) (66-65-1)=0 0%26=0 0+65=65 ('A')
                    if (chV < 65){ //if the character value is below the value of 'a', increase it be 26 (end of the alphabet)
                        chV=chV+26;
                    }
                message[i] = chV; //sub character value back into the string position;
                //i++;
                }
            }
            printf("%s\n", message); //print decoded message
            i=0; //resets the value of i to be used again
            break;
        
        case 3 : //encoding by substitution
            printf ("please enter a key to rotate by\n");
            printf ("make sure to include every single letter\n");
            scanf("%s", Ckey); //string of alphabetic letters
            printf ("please enter your message\n");
            printf ("please use : instead of spaces, as the program will not recognise spaces\n");
            scanf("%s", message); //message to be encoded by substitution
            
            for (i=0; message[i] != '\0'; i++){
                chV=message[i]; //take character value from the characters string position
                if ((chV >= 97) && (chV <= 122)){ //character value between 'a' and 'z'
        
                    chV = (((chV - 97)%26)); //finds respective position along the key string
                    message[i] = Ckey[chV]; //substitutes the value of the key string value for the character value in the message
                }
                if ((chV >= 65) && (chV <= 90)){//character value between 'A' and 'Z'

                    chV = (((chV - 65 )%26)); //finds respective position along the key string
                    message[i] = Ckey[chV]; //substitutes the value of the key string value for the character value in the message (will only return lowercase letters if the key only contains lowercase letters)
        
                }
            }
            printf("%s\n", message); //print encoded message
            i=0; //resets the value of i to be used again
            break;
        
        case 4 : //decoding by substition
            printf ("please enter a key to rotate by\n");
            printf ("make sure to include every single letter\n");
            scanf("%s", Ckey); //string of alphabetic letters
            printf ("please enter your message\n");
            printf ("please use : instead of spaces, as the program will not recognise spaces\n");
            scanf("%s", message); //message to be decoded by substitution
            char ABC[] = "abcdefghijklmnopqrstuvwxyz"; //standard alphabet
            int x=0;
            
            for (i=0; message[i] != '\0'; i++){
                chV = message[i]; //take character value from the characters string position
                if ((chV >= 97) && (chV <= 122)){ //character value between 'a' and 'z'
                    kV=Ckey[x]; // takes the character value of the key
                    if (x>0){ //setting value x to 0
                        x=0;
                    }
                    while (chV != kV){ //compareing the chracter value for the message to the keys character value
                        x++; //move up the key series
                        kV=Ckey[x];
                    }
                    chV=ABC[x]; //the position within the key is found and can be substituted into the alphabet (key[10] ABC[10]; key[23] ABC[23])
                    x=0; //make x zero for next cycle
                }
    
            message[i] = chV; //sub in character value taken from the alphabet
            }

            printf("%s\n", message); //print decoded message
            i=0; //resets the value of i to be used again
            break;
        
        default:{ //did not insert a number which could be used
            printf ("please enter a number, 1, 2, 3, or 4\n");
        }
    }
    printf ("thank you for using this program\n"); //programs goodbye message
    return 0;
}

    
