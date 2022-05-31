(*测试基本功能*)
program main(input);
type
    bool=boolean;
const
    PI=3.14;{数字常量}
   { STR='This is a string.';{字符串常量}
    PLUS='+';{字符常量}
var
    int1,int2,int3:integer;
    float1,float2,float3:real;
    bool0,bool1,bool2:bool;
    ch1,ch2,ch3:char;

begin

    int1:=2;
    int2:=3;
    if (int1>int2) then
        writeln('int1 > int2');
    if (int1<int2) then
        writeln('int1 < int2');
    if (int1<=int2) then
        writeln('int1 <= int2');
    if (int1>=int2) then
        writeln('int1 >= int2');
    if (int1<>int2) then
        writeln('int1 <> int2');
    if (int1=int2) then
        writeln('int1 = int2');
    
    int3:=int1 + int2;
    writeln(int3);
    int3:=int1 - int2;
    writeln(int3);
    int3:=int1 * int2;
    writeln(int3); 
    int3:=int1 div int2;
    writeln(int3);   
    int3:=int1 mod int2;
    writeln(int3);

    float1:=1.5;
    float2:=2.5;
    float3:=float1 + float2;
    writeln(float3);
    float3:=float1 - float2;
    writeln(float3);
    float3:=float1 * float2;
    writeln(float3); 
    float3:=float1 / float2;
    writeln(float3);

    bool0:=false;
    bool1:=true;
    bool2:=bool0 or bool1;
    writeln(bool2);
    bool2:=bool0 and bool1;
    writeln(bool2);

    float3:=PI * 2;
    writeln(float3);
    writeln(STR);
    ch1:=PLUS;
    writeln(ch1);
end.
