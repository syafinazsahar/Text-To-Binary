#include <stdio.h>
  #include <string.h>
  #define MAX 256

  int main() {
        
        FILE *f1,*f2;
	int ch, ch2;
	char string [100], *begin, *end, temp, tgt[MAX];

	/* get the output filename from the user */
        printf("Enter your output file name:");
        scanf("%s", tgt);


	
	 /* open the source file in read mode */	
	f1 = fopen("TextInput", "rt");

	if(f1==NULL)
	{
		printf("Error  couldnt open file\n");
		return(-1);
	}



	while(fgets(string, sizeof(string), f1) != NULL)
	{	
		begin = string;
		end =  begin + strlen(string) -1;

		while(end>begin)
		{
			temp = *begin;
			*begin = *end;
			*end = temp;

			++begin;
			--end;
		}

	}


	f2 = fopen(tgt, "wt");
	fprintf(f2,"%s",string);
	printf("%s\n",string);

	
        
        fclose(f1);
        fclose(f2);
        return 0;
  }
