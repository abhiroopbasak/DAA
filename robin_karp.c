#include <stdio.h>
#include <string.h>
#include <ctype.h>


void rabinKarp(char pattern[], char text[], int q,int d,int m)
{
  
  int n = d;
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
  {
    h = (h * d) % q;
}	

  for (i = 0; i < m; i++) 
  {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == m)
        printf("Pattern is found between %d and %d \n", i + 1 ,i+1+m);
    }

    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}

int main()
{
    
	int n,m,q;
	printf("Enter the original string size: ");
	scanf("%d",&n);
	printf("Enter the search string size: ");
	scanf("%d",&m);
	char original[n];
	char search[m];
	
	printf("Enter the original string:\n");
	scanf("%s",&original);
	printf("Enter the search string:\n");
	scanf("%s",&search);
	q=13;
    
    rabinKarp(search,original,q,n,m);


    return 0;
}
