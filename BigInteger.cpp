#include<cstring>
#include<iostream>
#include<debug/debug.h>
using namespace std;

class BigInteger{
    public:
        BigInteger();
        BigInteger(const char*);
        BigInteger(int);
        BigInteger(int*);
    public:
        int* toArray();
        void clear();
        int getSize();
        void add(BigInteger);
        void divide(BigInteger);
    public:
        BigInteger operator+(BigInteger&);
    private:
        void init();
        long long MAX_SIZE=10000001;
        int *num,len;
};
//构造函数
BigInteger::BigInteger(){
    init();
}
BigInteger::BigInteger(const char* str){
    if(MAX_SIZE<strlen(str)) MAX_SIZE=strlen(str);
    init();
    len=strlen(str);
    for(int i=0;i<len;i++) num[i]=str[len-i-1]-'0';
}
BigInteger::BigInteger(int x){
    int k=1;
    while(x){
        this->num[k++]=x%10;
        x/=10;
    }
    this->len=k;
}
BigInteger::BigInteger(int* array){
    this->num=array;
}

BigInteger BigInteger::operator+(BigInteger &x){
    
}
//成员方法
int* BigInteger::toArray(){
    return num;
}
void BigInteger::clear(){
    this->init();
}
int BigInteger::getSize(){
    return this->len;
}
//私有方法
void BigInteger::init(){
    this->num=new int[this->MAX_SIZE];
    memset(num,0,sizeof(num));
}