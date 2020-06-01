// #include "./String.cpp"
#pragma once
#ifndef String_h
#define String_h
#include <iostream>
#include <cassert>

using namespace std;

class String
{
  int size;
  char *buffer;

public:
  String();
  String(const String &);
  String(const char *);
  int length() const;
  ~String();
  void resize(unsigned int, char);
  void insert(unsigned int, String &);
  char &operator[](unsigned int);
  void operator=(const String &);
  void operator=(const char *p);
  void operator+=(const String &);
  void operator+=(const char *p);

  // other methods
  friend bool operator==(const String &, const String &);
  friend bool operator<=(const String &, const String &);
  friend bool operator<(const String &, const String &);
  friend ostream &operator<<(ostream &, const String &);
};

String::String()
{
  buffer = nullptr;
  size = 0;
}

String::String(const String &s)
{
  size = s.size;
  buffer = new char[size];
  for (int i = 0; i < size; i++)
  {
    buffer[i] = s.buffer[i];
  }
}

String::String(const char *p)
{

  int i = 0;
  const char *t = p;

  if (p == NULL)
  {
    buffer = new char[0];
    size = 0;

    return;
  }

  while (*p++)
  {
    i++;
  }

  buffer = new char[i];
  int j = 0;

  for (; j < i; j++)
  {
    buffer[j] = *t;
  }

  size = j;
}

String::~String()
{
  delete[] buffer;
}

int String::length() const
{
  if (buffer == nullptr)
  {
    return 0;
  }
  else
  {
    return size;
  }
}

char &String::operator[](unsigned int x)
{
  return buffer[x];
}

void String::operator=(const String &s)
{
  size = s.size;
  buffer = new char[size];
  for (int i = 0; i < size; i++)
  {
    buffer[i] = s.buffer[i];
  }
}
void String::operator=(const char *p)
{
  int i = 0;
  const char *t = p;

  if (p == NULL)
  {
    buffer = new char[0];
    size = 0;

    return;
  }

  while (*p++)
  {
    i++;
  }

  buffer = new char[i];
  int j = 0;

  for (; j < i; j++)
  {
    buffer[j] = *t;
  }
  size = j;
}

ostream &operator<<(ostream &os, const String &s)
{
  for (int i = 0; i < s.size; i++)
  {
    os << s.buffer[i];
  }
  return os;
}

bool operator==(const String &s, const String &t)
{
  if (s.length() != t.length())
  {
    return false;
  }
  else
  {
    for (int i = 0; i < s.length(); i++)
    {
      if (s.buffer[i] != t.buffer[i])
      {
        return false;
      }
    }
  }
  return true;
}

void String::operator+=(const String &s)
{
  int prevSize = size;
  String prevValue = buffer;
  size = s.size + size;
  buffer = new char[size];

  for (int i = 0; i < prevSize; i++)
  {
    buffer[i] = prevValue.buffer[i];
  }
  for (int i = 0; i < s.size; i++)
  {
    buffer[i + prevSize] = s.buffer[i];
  }
}
void String::operator+=(const char *p)
{
  String s = p;
  String::operator+=(s);
}

#endif