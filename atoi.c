#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


int ft_strlen(char *str)
{
  int i;

  i = 0;
  while(str[i])
    {
      i++;
    }
  return (i);
}

int ft_check(char *base)
{
    int i;
    int j;

    i = 0;
    while(base[i])
    {
      if((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
        return (0);
      if(base[i] == '+' || base[i] == '-')
        return (0);
      j = i + 1;
      while(base[j])
        {
          if (base[i] == base[j])
            return (0);
          j++;
        }
      i++;
    }
    return (i);
}

int ft_pass_sign (char *str, char *sign)
{
  int i;

  i = 0;
  while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
    i++;
  while(str[i] == '+' || str[i] == '-')
  {
    if(str[i] == '-')
      *sign *= -1;
    i++;
  }
  return (i);
}

int check_exist(char c, char *base)
{
  int i;

  i = 0;
  while(base[i])
    {
      if(c == base[i])
        return i;
      i++;
    }
  return (-1);
}


int ft_atoi_base(char *str, char *base)
{
  int sign;
  int i;
  int base_len;
  int res;

  sign = 1;
  res = 0;
  base_len = ft_check(base);
  if(base_len < 0)
    return 0;
  i = ft_pass_sign(str, base);

  while(check_exist(str[i], base) != -1)
    {
      res = res * base_len + check_exist(str[i], base);
      i++;
    }
  return (res*sign);
}

int main(void)
{
  //ex05
	printf("< ex05 >\n");
	char buf2[] = "0123456789abcdef";
	
	char str16[] = "cabc";
	char str17[] = "  ";
	char str18[] = "        24";
	char str19[] = "--123456";
	char str20[] = "00";
	char str21[] = "+5287";
	char str22[] = "213 432";
	char str23[] = "";
	printf("-----------answer------------\n");
	printf("51900\n");
	printf("\n");
	printf("36\n");
	printf("1193046\n");
	printf("0\n");
	printf("21127\n");
	printf("531\n");
	printf("\n");
	printf("-------------------------------\n\n");
	printf("-----------output------------\n");
	printf("%d\n", ft_atoi_base(str16, buf2));
	printf("%d\n", ft_atoi_base(str17, buf2));
	printf("%d\n", ft_atoi_base(str18, buf2));
	printf("%d\n", ft_atoi_base(str19, buf2));
	printf("%d\n", ft_atoi_base(str20, buf2));
	printf("%d\n", ft_atoi_base(str21, buf2));
	printf("%d\n", ft_atoi_base(str22, buf2));
	printf("%d\n", ft_atoi_base(str23, buf2));
	printf("-------------------------------\n");

  return 0;
}
