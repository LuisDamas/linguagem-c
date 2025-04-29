#define ZAP(x,v1,v2) (((x)<=0) ? ((x)*(v1)) : ((x)*(-(v2))))

#define  MAX  43
#define  MIN  -1 

main()
{
  int i,j = (int) 'a';
  i = ZAP(i+j,MAX-1,MIN-1); 
}

