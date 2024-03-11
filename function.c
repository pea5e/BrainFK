#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void brainfuck(const char *code, const char *input) {
  char * Buffer = calloc(256,sizeof(char));
  int index=0,read=0,sym,brack=0;

  for(sym=0;sym<strlen(code);sym++)
  {
      switch(code[sym])
      {
          case ',':
            Buffer[index] = input[read++];
            break;
          case '.':
            //*(output++) = Buffer[index];
            printf("%c",Buffer[index]);
            //printf("%c %d\n",Buffer[index],Buffer[index]);
            break;
          case '>':
            index++;
            break;
          case '<':
            index--;
            break;
          case '+':
            Buffer[index]++;
            Buffer[index] %= 256;
            break;
          case '-':
            Buffer[index]--;
            Buffer[index] %= 256;
            break;
          case '[':
            if (Buffer[index] == 0)
            {
              brack++;
              while(brack!=0){
                sym++;
                if(code[sym]==']')
                    brack--;
                else if(code[sym]=='[')
                    brack++;
              }
            }
            break;
          case ']' :
            if (Buffer[index]!=0)
            {
              brack--;
              while(brack!=0){
                sym--;
                if(code[sym]==']')
                    brack--;
                else if(code[sym]=='[')
                    brack++;
              }
            }
            break;
        default:
            //printf("index : %d\n",index);
            break;


      }
  }
    //*output  = '\0';
    //printf("%s",Buffer);

}


int main() {
    
    
    brainfuck("\
++++[>++>>+>+>>++++++++<<<<<[>++++++++++<-]<-]>>++.\
>[<---->-]<-.[<+<+>>-]>>[<<<<+++>>>>-]<<<<.>.+++.---.<+.>>>>>>.<<<<<<---.>.<+++++++.>++++..<-----.\
", "");
    

    return 0;
}
