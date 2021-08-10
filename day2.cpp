int i=0,j=0;
int *p=&i,*q=&j;
q=p;
*q=2;
cout<<i<<" "<<j;
// Answer: 2 0
