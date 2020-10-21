typedef unsigned int UINT;

void func()
{
    UINT value = "abc"; //error c2440: 'initializing' : cannot convert from 'const char[4]' to 'UINT'

    cout << value << endl;
}