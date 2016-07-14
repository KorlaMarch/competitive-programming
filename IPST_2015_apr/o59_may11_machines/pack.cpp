#include <cstdio>

#define NUMCASE 10

main()
{
  char fname[100];
  char buffer[1000];
  FILE* fcombined = fopen("machines-pack.out","w");

  for(int i=0; i<NUMCASE; i++) {
    fprintf(fcombined,"---start %d\n",i+1);

    sprintf(fname,"machines%d.out",i+1);
    FILE* fout = fopen(fname,"r");
    if(fout) {
      while(fgets(buffer,1000,fout)!=0)
        fprintf(fcombined,"%s",buffer);
      fclose(fout);
    }
    fprintf(fcombined,"---end %d\n",i+1);
  }
  fclose(fcombined);
}


