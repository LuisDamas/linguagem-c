// 11.1
int isdigit(int ch)
{
  return (ch>='0' && ch<='9');
}

// 11.2
int isalpha(int ch)
{
  return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

// 11.3
int isalnum(int ch)
{
  return isalpha(ch) || isdigit(ch);
}

// 11.4
int islower(int ch)
{
  return (ch>='a' && ch<='z');
}

// 11.5
int isupper(int ch)
{
  return (ch>='A' && ch<='Z');
}

// 11.6
int isspace(int ch)
{
  return ch==' ' || ch=='\t'; /* Espaço ou TAB */
}

// 11.7
int tolower(int ch)
{
  if (isupper(ch))
    return ch + 'a' -'A';
  else
    return ch;
}

int toupper(int ch)
{
  if (islower(ch))
    return ch + 'A' -'a';
  else
    return ch;
}

int main(void) {
  return 0;
}
