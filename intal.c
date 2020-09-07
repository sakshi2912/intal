#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//ADDITION

char* intal_add(const char* a, const char* b)
{
int x = strlen(a)>strlen(b)?strlen(a):strlen(b);
char * sum = malloc((x+1)*sizeof(char));
     int i,j,carry=0,l1,l2,s,k;
    
     l1=strlen(a);
     l2=strlen(b);
     
     i=l1-1;
     j=l2-1;
     
     k=l1>l2?l1:l2;
     sum[k]='\0';
     k--;
     
     while(i>=0 && j>=0)
     {
            
            s=(a[i]-48)+(b[j]-48)+carry;
            sum[k]=s%10+48;
            carry=s/10;
            i--;
            j--;
            k--;
     }
     
     if(i>=0)
     {
            while(i>=0)
           {
                  
                  s=(a[i]-48)+carry;
                  sum[k]=s%10+48;
                  carry=s/10;
                  i--;
                  k--;
           }
     
     }
     else if(j>=0)
     {
           while(j>=0)
           {
                  
                  s=(b[j]-48)+carry;
                  sum[k]=s%10+48;
                  carry=s/10;
                  j--;
                  k--;
           }
           
     }
     
     if(carry>0)
     
     {
     for(i=strlen(sum);i>=0;i--)
    
      sum[i+1]=sum[i];
          sum[0]=carry+48;
     
     }

 
    return sum;
    
}


    

//COMPARE
int intal_compare(const char* intal1, const char* intal2)
{
  int l1=strlen(intal1);
  int l2=strlen(intal2);
  
    if(l1==l2)
    {
          for(int i=0;i<l1;i++)
          {
            if((intal1[i]-48)>(intal2[i]-48))
              return +1;
           
            if((intal1[i]-48)<(intal2[i]-48))
              return -1;
            
          }
      return 0;
    }
    
    else if(l1<l2)
        
        return -1;
  
    else
        return 1;
  

}

//SUBTRACTION

char* intal_diff(char* intal1, char* intal2) 
{
        int cmp = intal_compare(intal1, intal2);
        
        if(cmp == 0) 
        {
                char* diff = (char*)malloc(2 * sizeof(char));
                diff[0] = '0';
                diff[1] = '\0';
                return diff;
        } 
        
        else if(cmp == -1) 
        {
                char* tmp = intal1;
                intal1 = intal2;
                intal2 = tmp;
        }

        int l1 = strlen(intal1);
        int l2 = strlen(intal2);

        int l = (l1 > l2)? l1: l2;
        int s = l1 + l2 - l;
        
        int i, d1, d2, sub, c = 0;
        char* diff = (char*)malloc((l + 1) * sizeof(char));

        for(i = 0 ; i < s; ++i) 
        {
          d1 = (intal1[l1 - 1 - i]-48) - c;
          d2 = (intal2[l2 - 1 - i]-48);

          c = (d2 > d1)? 1: 0;
          d1 = (d2 > d1)? d1 + 10: d1;
          sub = d1 - d2;

          diff[l - 1 - i] = (sub+48);
      }

        while(i < l) 
        {
          sub = (intal1[l1 - 1 - i]-48) - c;
          c = (sub > -1)? 0: 1;
          sub = (sub > -1)? sub: sub + 10;

          diff[l - 1 - i] = (sub+48);

          ++i;
        }

        for(i = 0; i < l; ++i) 
        {
          if(diff[i] != '0')
            break;
        }

        diff[l] = '\0';
        
        int x = i;
        
        if(x != 0) 
        {
          for(i = 0; i <= l - x; ++i)
            diff[i] = diff[i + x];

          diff = realloc(diff, (l - x + 1) * sizeof(char));
        }

  return diff;
}

//MULTIPLY

static char* removezeroes(char* a,int n) 
{ 
       int count = 0; 
       for (int i = 0; i < n; i++)
       {
              if(a[i] == '0')
              
               count++;
              
              else
              
               break;
              
       }
       
       for (int i = 0; i < n; i++)
       {
        a[i] = a[i+count];
       }
       int j = 0;
       
       while(count)
       {
              a[n-j] = '\0';
              count--;
              j++;
       }
       
  return a;
}

//MULTIPLY
 char* intal_multiply(const char* s1, const char* s2)
{
	int m,j;
	int temp,l3;
	int l1 = strlen(s1);
	int l2 = strlen(s2); 
	int *a = malloc(sizeof(int)*l1);
	int *b = malloc(sizeof(int)*l2);
	int *prod = calloc((l1+l2+1),sizeof(int));
	
	for(m = l1-1,j=0;m>=0;m--,j++)
    {
        a[j] = s1[m]-'0';

    }
	
    for(m = l2-1,j=0;m>=0;m--,j++)
    {
        b[j] = s2[m]-'0';
		
    }
	
    for(m = 0;m < l2;m++)
    {
        for(j = 0;j < l1;j++)
        {
            prod[m+j] += b[m]*a[j];
			
        }
    }
    for(m = 0;m < l1+l2;m++)
    {
        temp = prod[m]/10;
        prod[m] = prod[m]%10;
        prod[m+1] = prod[m+1] + temp;
		
    }
	
    for(; m>= 0;m--)
    {
        if(prod[m] >=0 && prod[m] <=9)
            break;
    }

	l3 = m;
 
	char* product = calloc(l3+1,sizeof(int));
	
    for(j=0;m >= 0;m--,j++)
    {
		if(prod[m] >=0 && prod[m] <=9)
			product[j] = prod[m] + '0';
		else
		{
			product[j] = '\0';
			break;
		}
			
		
    }
	free(prod);
	free(a);
	free(b);
	prod=NULL;
	a=NULL;
	b=NULL;
	removezeroes(product,l3);

	return product;
}

//MOD

char* intal_mod(char* intal1, char* intal2)
{
  int cmp = intal_compare(intal1, intal2);
  //intal2>intal1
  if(cmp == -1)
  {
    char* result = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
    strcpy(result, intal1);
    return result;
  }
  else if(cmp == 0)
  {
    char* result = (char*)malloc((2) * sizeof(char));
    strcpy(result, "0");
    return result;
  }

  int p = strlen(intal2);
  int stop = strlen(intal1);
  char* current = (char*)malloc((p + 2) * sizeof(char));
  for(int i = 0; i < p; ++i)
    current[i] = intal1[i];
  current[p] = '\0';

  do {
    if(intal_compare(current, intal2) == -1 && p < stop)
    {
      int len = strlen(current);
      if(strcmp(current, "0") == 0)
        len = 0;
      current[len] = intal1[p];
      current[len + 1] = '\0';
      ++p;
    }

    if(intal_compare(current, intal2) != -1)
    {
      char* result = intal_diff(current, intal2);
      while(intal_compare(result, intal2) > -1)
      {
        char* tmp = result;
        result = intal_diff(result, intal2);
        free(tmp);
      }
     
      strcpy(current, result);
      free(result);
    }    
  }
  while(p < stop);

  current = realloc(current, (strlen(current) + 1) * sizeof(char));
  current[strlen(current) + 1] = '\0';
  return current;
}

//POWER


char * intal_pow(const char *intal1,unsigned int n)
{
       if (n == 0)
      {
            char *tmp=malloc(sizeof(char)*2);
           	tmp[0]='1';
           	tmp[1]='\0';
           	return tmp;
      }
      if (intal_compare(intal1,"0")==0)
      {
            char *tmp=malloc(sizeof(char)*2);
           	tmp[0]='0';
           	tmp[1]='\0';
           	return tmp;
      }
    else if (n%2 == 0){
        return intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2));}
    else{
        return intal_multiply(intal1,intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2)));}

}


//FIBONACCI


char* intal_fibonacci(unsigned int n)
{ 
    char* fibo1=malloc(sizeof(char)*2); 
    
    fibo1[0]='0'; 
    fibo1[1]='\0'; 
    

    char* fibo2=malloc(sizeof(char)*2); 
    fibo2[0]='1'; 
    fibo2[1]='\0'; 
    
    if(n==0) return fibo1;
    if(n==1) return fibo2;
    char* temp; 
    
    for(int i=2;i<=n;i++)
    { 
       temp=fibo1; 
       fibo1=fibo2; 
       fibo2=intal_add(temp,fibo2); 
        
    } 
    
    return fibo2; 
       
}

//FACTORIAL

char * intal_factorial( unsigned int n)

{
   
   
    int s=2;
    int *arr = malloc(10001*sizeof(int));
    char *fact = malloc(10001*sizeof(char));
    
    arr[0] = 1;
    int len = 1;
    int x = 0;
    int num = 0;
    while(s<=n)
    {
        x=0;
        num =0;
        while(x<len)
        {
            arr[x] = arr[x] *s;
            arr[x] = arr[x]+num;
            num = arr[x]/10;
            arr[x] = arr[x]%10;
            x++;
        }
        while(num!=0)
        {
            arr[len] = num%10;
            num = num/10;
            len++;
        }
        s++;
    }
    len--;
    int k=0;
    while(len>=0)
    {
        fact[k++]=arr[len--]+'0';

    }
    fact[k]='\0';

    free(arr);

    return fact;
}

//GCD
char* intal_gcd(char* intal1, char* intal2) 
{
  char* x = (char*)malloc((strlen(intal1) + 1) * sizeof(char));
  strcpy(x, intal1);
  char* y = (char*)malloc((strlen(intal2) + 1) * sizeof(char));
  strcpy(y, intal2);

  int flag = strcmp(x, "0");
  while(flag != 0) 
  {
    char* temp = y;
    y = x;
    x = intal_mod(temp, x);

    free(temp);
    flag = strcmp(x, "0");
  }

  free(x);
  return y;
}

//BIN COEFF


static int minimum(int a, int b)
{
      return a<b?a:b;   
}
char* intal_bincoeff(unsigned int n, unsigned int k)
{
      char **c = (char**) malloc((k+1) * sizeof(char*));
      if(k>n-k)
      {
        k=n-k;
      }
      char*myzero=(char*)malloc(sizeof(char)*2);
      myzero[0]='0';
      myzero[1]='\0';
      if(n == 0)
      	return myzero;
      c[0]=(char*)malloc(sizeof(char)*2);
      c[0][0]='1';
      c[0][1]='\0';
      if(k==0)
      {
            return c[0];
      }  
      for(int i=1;i<k+1;i++)
      {
            c[i]=myzero;
      }
      for(int j=1;j<=n;j++)
      {
            for(int m=minimum(j,k);m>0;m--)
            {
                  c[m]=intal_add(c[m],c[m-1]);
                  if(j==n && m==k)
                  {
                        free(myzero);
                        for(int g=0;g<k;g++)
                        {
                              free(c[g]);
                              c[g]=NULL;
                        }
                        return c[k];
                  }

            }
      }
      
free(myzero);
return c[k];
}

//MAX
int intal_max(char **arr, int n)
{
	int max = 0;
	for(int i = 0;i<n; i++)
	{
		if(intal_compare(arr[i],arr[max]) == 1)
			max = i;
	}
	return max;
}

//MIN
int intal_min(char **arr, int n)
{
	int min = 0;
	for(int i = 0;i<n; i++)
	{
		if(intal_compare(arr[i],arr[min]) == -1)
			min = i;
	}
	return min;
}

//SEARCH
int intal_search(char **arr, int n, const char* key)
{
	for(int i=0;i<n;i++)
	{
		if(intal_compare(arr[i],key) == 0)
			return i;		
	}
	return -1;
}



//BIN SEARCH

int intal_binsearch(char **arr,int n,const char* key){
int answer = -1;
int low=0;
int high=n-1;
    while (high>=low){
        int mid = low + (high - low )/ 2;
        if (intal_compare(arr[mid],key)==-1) {
            low = mid + 1;
        }
        else if (intal_compare(arr[mid],key)==1) {
            high = mid - 1;
        }
        else if (intal_compare(arr[mid],key)==0) {
            answer = mid;
            high = mid - 1;
        }
    }
    return answer;
}





//SORT
static void max_heapify(char **arr, int i , int n) 
{ 
    int left, right , largest; 
    left = 2*i + 1; 
    right = 2*i + 2; 
 
    if(left <= (n-1) && (intal_compare(arr[left],arr[i])==1)) 
    { 
        largest = left; 
    } 
 
    else 
    { 
        largest = i; 
    } 
 
    if(right <= (n-1) && (intal_compare(arr[right],arr[largest])==1)) 
    { 
        largest = right; 
    } 
 
    if(largest != i) 
    {
         char *temp;
         temp=arr[i];
         arr[i]=arr[largest];
         arr[largest]=temp;
         
        max_heapify(arr,largest,n); 
    } 
     
}

void intal_sort(char **arr, int n){

 int i; 
    for(i = (n-2)/2 ; i>=0 ; i--) 
    { 
        max_heapify(arr,i,n); 
    }
  for(int i=n-1;i>0;i--){
      char *temp_1;
      temp_1=arr[0];
      arr[0]=arr[i];
      arr[i]=temp_1;
      max_heapify(arr,0,i);
      
    }

}

//COIN ROW
char* coin_row_problem(char **arr, int n){
    if(n ==0)
    {
      char *tmp=malloc(sizeof(char)*2);
     	tmp[0]='0';
     	tmp[1]='\0';
     	return tmp;
 return tmp;
 }
   char* prev = "0";
    char *cur = arr[0];
   char*next;
    for(int i=2;i<=n;i++){
          char*arrvalue=arr[i-1];
          char*temp=intal_add(prev,arrvalue);
          int value=intal_compare(temp,cur);
          if(value==1){
               next=temp;
              }
         else{
               next=cur;
            }
        prev=cur;
        cur=next;
 
  
       }
   return cur;

 }


