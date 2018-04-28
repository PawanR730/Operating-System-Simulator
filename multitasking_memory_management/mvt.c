

#include <stdio.h>
#include <stdlib.h>

struct memory
{
	int size;
	int flag;

}p[100];

int np=1;

int externalfrag(int psize)
{
	int i,flag=1;
	for(i=0;i<np;i++)
	{
		if(p[i].flag==-1 && p[i].size>=psize)
		{
			flag=0; break;
		}
			
	}
          if(np==0)	return 0;
	  return flag;
}

int main()
{	
	int part,memsize,psize,c,i,j;
	int min,minblock,max,maxblock;
	scanf("%d%d",&part,&memsize);
	int fit;
	scanf("%d",&fit);
	fflush(stdin);
	p[0].size=memsize;
	p[0].flag=-1;
	printf("1\n");
	fflush(stdout);
	int freespace=memsize;
	int extfrag=0;
	while(1)	
	{	
		scanf("%d", &c);
		switch(c)
		{
			case 1: 
				
				scanf("%d", &psize);
				fflush(stdin);
				int f = 0;
				if(freespace<psize || psize<=0)
					f = 0;
				else if(freespace>=psize && externalfrag(psize)==1)
					f = 0;
				else
				{	
					f = 1;
					freespace-=psize;
					switch(fit)
					{
						case 1:
							for(i=0;i<np;i++)
							{
							if(p[i].flag==-1 && p[i].size>=psize)
							{
								if(p[i].size==psize)
								{
									p[i].flag=0;	
								}
								else
								{
									np++;
									for(j=np-1;j>i;j--)
									{
										p[j].size=p[j-1].size;
										p[j].flag=p[j-1].flag;
									}
									p[i].flag=0;
									p[i].size=psize;
									p[i+1].size-=psize;
								}
								break;
							}
							}
							break;
						case 2:
							
							min=99999;
							for(i=0;i<np;i++)
							{	
						if(p[i].size>=psize && p[i].flag==-1 &&  p[i].size<min)
								{
									min=p[i].size;
									minblock=i;
								}			
							}
							if(p[minblock].size==psize)
							{
								p[minblock].flag=0;
							}
							else
							{
								np++;
								for(j=np-1;j>minblock;j--)
								{
									p[j].size=p[j-1].size;
									p[j].flag=p[j-1].flag;
								}
								p[minblock].flag=0;
								p[minblock].size=psize;
								p[minblock+1].size-=psize;
							}
							break;

						case 3:
							max=-1,maxblock;
							for(i=0;i<np;i++)
							{
								if(p[i].flag==-1 && p[i].size>max)
								{
									max=p[i].size;
									maxblock=i;
								}
							}
							
							 if(p[maxblock].size==psize)
								p[maxblock].flag=0;
							else
							{
								np++;
								for(j=np-1;j>maxblock;j--)
								{
									p[j].size=p[j-1].size;
									p[j].flag=p[j-1].flag;
								}
								p[maxblock].flag=0;
								p[maxblock].size=psize;
								p[maxblock+1].size-=psize;

							}
							break;
					}

					
					
				}
				if(f) goto display;
				else{
					printf("~Cannot allocate!\n");
					fflush(stdout);
				}
				break;
			
			case 2: 
				if(np!=1)
				{	int db;
					scanf("%d", &db);
					fflush(stdin);
					freespace=freespace+p[db].size;
					p[db].flag=-1;
					for(i=0;i<np-1;i++)
					{
						if(p[i].flag==-1 && p[i+1].flag==-1)
						{	
							p[i].size=p[i].size+p[i+1].size;
							for(j=i+1;j<np-1;j++)
							{
								p[j].size=p[j+1].size;
								p[j].flag=p[j+1].flag;
							}
							np--;i--;
						}
						
					}
				}	
				goto display;
				break;

			case 3: 
				display:
				for(i=0;i<np;i++)
				{	
					if(p[i].flag==-1)
						printf("%d %d 0<br>",i,p[i].size);
					else
						printf("%d %d 1<br>",i,p[i].size);
				}		
				printf("\n");
				fflush(stdout);
				break;
			
			case 0:exit(0);
				
		} 
	}



 	return 0;
}
